/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed__Samir
 */



#include <util/delay.h>
#define F_CPU 8000000UL

/* Include all your libraries (LIB, MCAL, HAL) here */
#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/DCM/DCM_Interface.h"
#include "HAL/SRV/SRV_Interface.h"
#include "MCAL/TMR/TMR_Interface.h"
#include "MCAL/UART/UART_Interface.h"
#include "MCAL/GI/GI_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "MCAL/EEPROM/EEPROM_Interface.h"
#include "HAL/KPD/KPD_Interface.h"
#include "HAL/SSD/SSD_Interface.h"

#define MCUCSR_REG *((volatile u8*)0x54)

/* Global System Variables */
volatile u8 G_u8BombSeconds = 60;
volatile u8 G_u8Units = 0;
volatile u8 G_u8Tens = 0;
volatile u8 G_u8IsBombRunning = 1; /* 1: Counting, 0: Stopped (defused or exploded) */
static SR_t sr1 = {
    .DATA_PORT = DIO_PORTC,
    .DATA_PIN = DIO_PIN0,
    .CLOCK_PORT = DIO_PORTC,
    .CLOCK_PIN = DIO_PIN1,
    .STROBE_PORT = DIO_PORTC,
    .STROBE_PIN = DIO_PIN2
};

void Bomb_TimerTick(void)
{
    static u16 Local_u16SecondsCounter = 0;
    static u8 Local_u8MuxCounter = 0;
    static u8 Local_u8CurrentDigit = 0;


    if (G_u8IsBombRunning == 0)
        {
            /* Send HIGH to Enable pins to disconnect both displays (depending on your wiring) */
            DIO_Set_Pin_Value(DIO_PORTC, DIO_PIN3, DIO_PIN_HIGH);
            DIO_Set_Pin_Value(DIO_PORTC, DIO_PIN4, DIO_PIN_HIGH);

            /* Exit interrupt immediately to maintain continuous buzzer state */
            return;
        }


    /* 1. Displays Multiplexing (always running) */
    Local_u8MuxCounter++;
    if (Local_u8MuxCounter == 2)
    {
        Local_u8MuxCounter = 0;
        DIO_Set_Pin_Direction(DIO_PORTC, DIO_PIN3, DIO_PIN_OUTPUT);
        DIO_Set_Pin_Direction(DIO_PORTC, DIO_PIN4, DIO_PIN_OUTPUT);
        DIO_Set_Pin_Value(DIO_PORTC, DIO_PIN3, DIO_PIN_LOW);
        DIO_Set_Pin_Value(DIO_PORTC, DIO_PIN4, DIO_PIN_LOW);

        if (Local_u8CurrentDigit == 0)
        {
        	ssd_display(sr1, common_anode, G_u8Units);
            DIO_Set_Pin_Value(DIO_PORTC, DIO_PIN3, DIO_PIN_HIGH);
            Local_u8CurrentDigit = 1;
        }
        else
        {
        	ssd_display(sr1, common_anode, G_u8Tens);
            DIO_Set_Pin_Value(DIO_PORTC, DIO_PIN4, DIO_PIN_HIGH);
            Local_u8CurrentDigit = 0;
        }
    }

    /* 2. Countdown and Buzzer (runs only while bomb is active) */
    if (G_u8IsBombRunning == 1)
    {
        Local_u16SecondsCounter++;

        if (Local_u16SecondsCounter == 1)
        {
            DIO_Set_Pin_Value(DIO_PORTC, DIO_PIN5, DIO_PIN_HIGH); /* Buzzer ON */
        }
        else if (Local_u16SecondsCounter == 500)
        {
            DIO_Set_Pin_Value(DIO_PORTC, DIO_PIN5, DIO_PIN_LOW);  /* Buzzer OFF */
        }
        else if (Local_u16SecondsCounter == 1000)
        {
            Local_u16SecondsCounter = 0;
            if (G_u8BombSeconds > 0)
            {
                G_u8BombSeconds--;
                G_u8Units = G_u8BombSeconds % 10;
                G_u8Tens = G_u8BombSeconds / 10;
            }
        }
    }
}


int main(void)
{
	u8 Local_u8EnteredPass[4] = {0};
	u8 Local_u8IsPassCorrect = 1;
	SET_BIT(MCUCSR_REG, 7);
	SET_BIT(MCUCSR_REG, 7);
	/* Initialize all components */
	    LCD_init();
	    KPD_voidInit();
	    ADC_init();
	    ssd_init(sr1);
	    UART_init();
	    SRVO_init();

	    DCM_t motor1 = { .port = DIO_PORTB, .pin = DIO_PIN7 };
	    motor_init(motor1);

	    /* Initialize Buzzer pins and wires */
	    DIO_Set_Pin_Direction(DIO_PORTC, DIO_PIN5, DIO_PIN_OUTPUT); /* Buzzer */
	    DIO_Set_Pin_Direction(DIO_PORTA, DIO_PIN1, DIO_PIN_INPUT);  /* Defuse Wire */
	    DIO_Set_Pin_Direction(DIO_PORTA, DIO_PIN2, DIO_PIN_INPUT);  /* Boom Wire */
	    DIO_Set_Pin_Value(DIO_PORTA, DIO_PIN1, DIO_PIN_HIGH);       /* Pull-up */
	    DIO_Set_Pin_Value(DIO_PORTA, DIO_PIN2, DIO_PIN_HIGH);       /* Pull-up */

	    /* Initialize Timer */
	    G_u8Units = G_u8BombSeconds % 10;
	    G_u8Tens = G_u8BombSeconds / 10;
	    Timer_voidSetCallBack(Bomb_TimerTick, TIMER_CTC0_INT_INDEX);
	    Timer_voidInit();
	    GI_Enble();

    u8 Local_u8PuzzleStage = 1; /* 1: ADC, 2: Password */
    u16 Local_u16ADCValue;
    u8 Local_u8SafeDial;
    u8 Local_u8Key;
    u8 Local_u8PassCounter = 0;
    u8 Local_u8StoredPass[4] = {'1', '2', '3', '4'};

    u8 Local_u8DefuseWire, Local_u8BoomWire, Local_u8VillainCmd;
    u8 CmdReceived = 0;

    /* Start the bomb immediately upon power on */
    motor_on(motor1);
    SRVO_set_angle(180);
    UART_print_data((u8*)"BOMB ARMED! Time is ticking...\r\n");

    LCD_send_command(0x01);
    LCD_send_string("Safe Dial:");

    while (1)
    {
        /* ======================================================== */
        /* 1. Check for end events (Always running in the background) */
        /* ======================================================== */

        /* Read wires and villain commands */
        Local_u8DefuseWire = DIO_Get_Pin_Value(DIO_PORTA, DIO_PIN1);
        Local_u8BoomWire   = DIO_Get_Pin_Value(DIO_PORTA, DIO_PIN2);
        CmdReceived        = UART_receive_data_unblock(&Local_u8VillainCmd);

        /* Explosion condition (Time is up, wrong wire cut, or villain command) */
        if (G_u8BombSeconds == 0 || Local_u8BoomWire == DIO_PIN_HIGH || (CmdReceived && Local_u8VillainCmd == 'K'))
        {
            G_u8IsBombRunning = 0; /* Stop Timer and Buzzer */
            motor_off(motor1);

            LCD_send_command(0x01);
            LCD_send_string("BOOM! YOU DIED");
            UART_print_data((u8*)"BOOM! Target Destroyed.\r\n");
            SRVO_set_angle(0);
            DIO_Set_Pin_Value(DIO_PORTC, DIO_PIN5, DIO_PIN_HIGH);

            while(1); /* Freeze the game */
        }

        /* Direct wire defuse condition (Risk) */
        if (Local_u8DefuseWire == DIO_PIN_HIGH)
        {
            G_u8IsBombRunning = 0;
            motor_off(motor1);


            LCD_send_command(0x01);
            LCD_send_string("DEFUSED BY WIRE!");
            UART_print_data((u8*)"System Defused.\r\n");
            DIO_Set_Pin_Value(DIO_PORTC, DIO_PIN5, DIO_PIN_LOW);

            while(1);
        }

        /* Remote defuse condition (Command S) */
                if (CmdReceived && Local_u8VillainCmd == 'S')
                {
                    G_u8IsBombRunning = 0;
                    motor_off(motor1);


                    LCD_send_command(0x01);
                    LCD_send_string("DEFUSED BY ADMIN");
                    UART_print_data((u8*)"System Defused Remotely.\r\n");
                    DIO_Set_Pin_Value(DIO_PORTC, DIO_PIN5, DIO_PIN_LOW);


                    while(1); /* Freeze the game */
                }

        /* ======================================================== */
        /* 2. Puzzles path (Runs in parallel with countdown and wires) */
        /* ======================================================== */

        if (Local_u8PuzzleStage == 1)
        {
            Local_u16ADCValue = ADC_Get_Digital_Value_Pulling(0);
            Local_u8SafeDial = (u8)((u32)Local_u16ADCValue * 100 / 1023);

            /* Update in the same position to prevent screen flickering */
            LCD_go_to_XY(0, 1);
            LCD_send_number(Local_u8SafeDial);
            LCD_send_string("   ");

            Local_u8Key = KPD_u8GetPressedKey();
            if (Local_u8Key == '=' && Local_u8SafeDial == 50)
            {
                Local_u8PuzzleStage = 2; /* Succeeded, move to password */
                LCD_send_command(0x01);
                LCD_send_string("Enter Password:");
                LCD_go_to_XY(0, 1);
            }
        }
        else if (Local_u8PuzzleStage == 2)
                {
                    Local_u8Key = KPD_u8GetPressedKey();
                    if (Local_u8Key != KPD_NO_PRESSED_KEY)
                    {
                        /* 1. Store entered character and display a star */
                        Local_u8EnteredPass[Local_u8PassCounter] = Local_u8Key;
                        LCD_send_data('*');
                        Local_u8PassCounter++;

                        /* 2. Verify only after entering 4 complete digits */
                        if (Local_u8PassCounter == 4)
                        {
                            Local_u8IsPassCorrect = 1;

                            /* Compare entered array with stored one */
                            for (u8 i = 0; i < 4; i++)
                            {
                                if (Local_u8EnteredPass[i] != Local_u8StoredPass[i])
                                {
                                    Local_u8IsPassCorrect = 0; /* If one char is wrong, the entire password is wrong */
                                    break;
                                }
                            }

                            /* 3. Make decision based on the result */
                            if (Local_u8IsPassCorrect == 1)
                            {
                                /* Safe path: Defuse bomb successfully */
                                G_u8IsBombRunning = 0;
                                motor_off(motor1);

                                DIO_Set_Pin_Value(DIO_PORTC, DIO_PIN5, DIO_PIN_LOW);
                                LCD_send_command(0x01);
                                LCD_send_string("DEFUSED BY CODE!");
                                UART_print_data((u8*)"System Defused.\r\n");

                                while(1);
                            }
                            else
                            {
                                /* Wrong password: Quick punishment then retry */
                                LCD_send_command(0x01);
                                LCD_send_string("WRONG PASS!");
                                UART_print_data((u8*)"Wrong Password entered.\r\n");

                                /* Decrease time by 5 seconds as punishment */
                                if(G_u8BombSeconds > 5) G_u8BombSeconds -= 5;
                                else G_u8BombSeconds = 1;

                                /* Short delay to read "Wrong Pass" before clearing the screen */
                                _delay_ms(700);

                                LCD_send_command(0x01);
                                LCD_send_string("Enter Password:");
                                LCD_go_to_XY(0, 1);
                                Local_u8PassCounter = 0; /* Reset counter for new attempt */
                            }
                        }
                    }
                }
        }

    return 0;
}
