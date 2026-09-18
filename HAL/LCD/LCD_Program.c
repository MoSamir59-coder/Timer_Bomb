#define F_CPU 8000000UL
#include <util/delay.h>

#include "LCD_Interface.h"
#include "LCD_Config.h"
#include "LCD_Private.h"

static void LCD_voidSend4Bits(u8 Copy_u8Value)
{
    DIO_Set_Pin_Value(LCD_D4_PORT, LCD_D4_PIN, GET_BIT(Copy_u8Value, 4));
    DIO_Set_Pin_Value(LCD_D5_PORT, LCD_D5_PIN, GET_BIT(Copy_u8Value, 5));
    DIO_Set_Pin_Value(LCD_D6_PORT, LCD_D6_PIN, GET_BIT(Copy_u8Value, 6));
    DIO_Set_Pin_Value(LCD_D7_PORT, LCD_D7_PIN, GET_BIT(Copy_u8Value, 7));
}

/* œ«·… „”«⁄œ… ·⁄„· ‰»÷… «·‹ Enable */
static void LCD_voidSendEnablePulse(void)
{
	DIO_Set_Pin_Value(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_HIGH);
    _delay_ms(2);
    DIO_Set_Pin_Value(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_LOW);
}

void LCD_send_command(u8 Copy_u8Command)
{
    /* RS = 0 ·≈—”«· √„— */
	DIO_Set_Pin_Value(LCD_RS_PORT, LCD_RS_PIN, DIO_PIN_LOW);

    /* ≈—”«· «·‹ 4 »  «··Ì ›Êﬁ √Ê·« (High Nibble) */
    LCD_voidSend4Bits(Copy_u8Command);
    LCD_voidSendEnablePulse();

    /* ≈—”«· «·‹ 4 »  «··Ì  Õ  (Low Nibble) */
    LCD_voidSend4Bits(Copy_u8Command << 4);
    LCD_voidSendEnablePulse();
}

void LCD_send_data(u8 Copy_u8Data)
{
    /* RS = 1 ·≈—”«· œ« « */
	DIO_Set_Pin_Value(LCD_RS_PORT, LCD_RS_PIN, DIO_PIN_HIGH);

    LCD_voidSend4Bits(Copy_u8Data);
    LCD_voidSendEnablePulse();

    LCD_voidSend4Bits(Copy_u8Data << 4);
    LCD_voidSendEnablePulse();
}

void LCD_init(void)
{
    /*  ÂÌ∆… «·»‰«  ﬂ‹ Output */
    DIO_Set_Pin_Direction(LCD_RS_PORT, LCD_RS_PIN, DIO_PIN_OUTPUT);
    DIO_Set_Pin_Direction(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_OUTPUT);
    DIO_Set_Pin_Direction(LCD_D4_PORT, LCD_D4_PIN, DIO_PIN_OUTPUT);
    DIO_Set_Pin_Direction(LCD_D5_PORT, LCD_D5_PIN, DIO_PIN_OUTPUT);
    DIO_Set_Pin_Direction(LCD_D6_PORT, LCD_D6_PIN, DIO_PIN_OUTPUT);
    DIO_Set_Pin_Direction(LCD_D7_PORT, LCD_D7_PIN, DIO_PIN_OUTPUT);

    _delay_ms(40);

    /* ŒÿÊ«   ›⁄Ì· «·‹ 4-bit Mode „‰ «·œ« « ‘Ì  */
    LCD_send_command(0x33);
    LCD_send_command(0x32);
    LCD_send_command(LCD_4BIT_MODE_2_LINES_5X8);

    LCD_send_command(LCD_DISPLAY_ON_CURSOR_OFF);
    LCD_send_command(LCD_CLEAR_COMMAND);
}

void LCD_send_string(const char *Copy_pcString)
{
    u8 Local_u8Counter = 0;
    while (Copy_pcString[Local_u8Counter] != '\0')
    {
    	LCD_send_data(Copy_pcString[Local_u8Counter]);
        Local_u8Counter++;
    }
}

void LCD_go_to_XY(u8 Copy_u8X, u8 Copy_u8Y)
{
    u8 Local_u8Address;
    if (Copy_u8Y == 0)
    {
        Local_u8Address = Copy_u8X;
    }
    else if (Copy_u8Y == 1)
    {
        Local_u8Address = Copy_u8X + 0x40;
    }
    LCD_send_command(Local_u8Address + 128);
}

void LCD_send_number(u32 Copy_u32Number)
{
    char Local_chNumber[10];
    u8 Local_u8Index = 0;
    s8 Local_s8Counter;

    if (Copy_u32Number == 0)
    {
    	LCD_send_data('0');
        return;
    }

    /*  ›ﬂÌﬂ «·—ﬁ„ Ê Œ“Ì‰Â ›Ì «·„’›Ê›… »«·⁄ﬂ” */
    while (Copy_u32Number != 0)
    {
        Local_chNumber[Local_u8Index] = (Copy_u32Number % 10) + '0';
        Copy_u32Number /= 10;
        Local_u8Index++;
    }

    /* ÿ»«⁄… «·—ﬁ„ »«· — Ì» «·’ÕÌÕ */
    for (Local_s8Counter = Local_u8Index - 1; Local_s8Counter >= 0; Local_s8Counter--)
    {
    	LCD_send_data(Local_chNumber[Local_s8Counter]);
    }
}
