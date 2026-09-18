/*
 * STP_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed__Samir
 */


#include "util/delay.h"

#define F_CPU 8000000UL


#include "STP_Interface.h"
#include "STP_Config.h"
#include "../../MCAL/DIO/DIO_Interface.h"

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function initialize the pins which connected to stepper motor as output pins
* Parameters : Nothing
* return : Nothing
*/
void STEPPER_voidInit( void )
{

	DIO_Set_Pin_Direction( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_PORT_OUTPUT );
	DIO_Set_Pin_Direction( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_PORT_OUTPUT );
	DIO_Set_Pin_Direction( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_PORT_OUTPUT );
	DIO_Set_Pin_Direction( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_PORT_OUTPUT );

	DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_PIN_LOW );
	DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_PIN_LOW );
	DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_PIN_LOW );
	DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_PIN_LOW );

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function used to  stepper motor on
* Parameters :
            => Type : (STEPPER_FULL_STEP or STEPPER_HALF_STEP)
			=> Direction (STEPPER_CLOCK_WISE or STEPPER_ANTI_CLOCK_WISE)
			=> Speed
			=> Degree
* return : void
*/
void STEPPER_voidOn  ( u8 Copy_u8StepType , u8 Copy_u8Direction , u8 Copy_u8Speed , u16 Copy_u16Degree ){

	u32 LOC_u16Iterator = 0 ;

	if( Copy_u8StepType == STEPPER_FULL_STEP )
	{

		if( Copy_u8Direction == STEPPER_CLOCK_WISE )
		{

			for( LOC_u16Iterator = 0 ; LOC_u16Iterator < ( ( (u32)Copy_u16Degree * 256 ) / 45 ) /  4; LOC_u16Iterator++  ){

				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_PIN_HIGH );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_PIN_LOW  );
				_delay_ms( Copy_u8Speed );

				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_PIN_HIGH );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_PIN_LOW  );
				_delay_ms( Copy_u8Speed );

				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_PIN_HIGH );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_PIN_LOW  );
				_delay_ms( Copy_u8Speed );

				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_PIN_HIGH );
				_delay_ms( Copy_u8Speed );


			}

		}else if( Copy_u8Direction == STEPPER_ANTI_CLOCK_WISE )
		{

			for( LOC_u16Iterator = 0 ; LOC_u16Iterator < ( ( (u32)Copy_u16Degree * 256 ) / 45 ) / 4 ; LOC_u16Iterator++  ){

				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_PIN_HIGH );
				_delay_ms( Copy_u8Speed );

				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_PIN_HIGH );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_PIN_LOW  );
				_delay_ms( Copy_u8Speed );

				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_PIN_HIGH );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_PIN_LOW  );
				_delay_ms( Copy_u8Speed );

				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_PIN_HIGH );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_PIN_LOW  );
				_delay_ms( Copy_u8Speed );


			}

		}

	}
	else if( Copy_u8StepType == STEPPER_HALF_STEP ){

		if( Copy_u8Direction == STEPPER_CLOCK_WISE )
		{

			for( LOC_u16Iterator = 0 ; LOC_u16Iterator < ( ( (u32)Copy_u16Degree * 512 ) / 45 ) / 8 ; LOC_u16Iterator++  ){

				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_PIN_HIGH );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_PIN_LOW  );
				_delay_ms( Copy_u8Speed );

				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_PIN_HIGH );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_PIN_HIGH );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_PIN_LOW  );
				_delay_ms( Copy_u8Speed );

				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_PIN_HIGH );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_PIN_LOW  );
				_delay_ms( Copy_u8Speed );

				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_PIN_HIGH );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_PIN_HIGH );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_PIN_LOW  );
				_delay_ms( Copy_u8Speed );

				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_PIN_HIGH );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_PIN_LOW  );
				_delay_ms( Copy_u8Speed );

				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_PIN_HIGH );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_PIN_HIGH );
				_delay_ms( Copy_u8Speed );

				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_PIN_HIGH );
				_delay_ms( Copy_u8Speed );

				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_PIN_HIGH );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_PIN_HIGH );
				_delay_ms( Copy_u8Speed );



			}

		}
		else if( Copy_u8Direction == STEPPER_ANTI_CLOCK_WISE ){


			for( LOC_u16Iterator = 0 ; LOC_u16Iterator < ( ( (u32)Copy_u16Degree * 512 ) / 45 ) / 8 ; LOC_u16Iterator++  ){
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_PIN_HIGH );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_PIN_HIGH );
				_delay_ms( Copy_u8Speed );

				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_PIN_HIGH );
				_delay_ms( Copy_u8Speed );

				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_PIN_HIGH );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_PIN_HIGH );
				_delay_ms( Copy_u8Speed );

				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_PIN_HIGH );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_PIN_LOW  );
				_delay_ms( Copy_u8Speed );

				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_PIN_HIGH );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_PIN_HIGH );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_PIN_LOW  );
				_delay_ms( Copy_u8Speed );

				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_PIN_HIGH );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_PIN_LOW  );
				_delay_ms( Copy_u8Speed );

				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_PIN_HIGH );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_PIN_HIGH );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_PIN_LOW  );
				_delay_ms( Copy_u8Speed );

				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_PIN_HIGH );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_PIN_LOW  );
				DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_PIN_LOW  );
				_delay_ms( Copy_u8Speed );

			}

		}

	}

}

/*
* Breif : This Function This Function used to  stepper motor off
* Parameters : Nothing
* return : Nothing
*/
void STEPPER_voidOff ( void )
{

	DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_PIN_LOW );
	DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_PINK_PIN   , DIO_PIN_LOW );
	DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_PIN_LOW );
	DIO_Set_Pin_Value( STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_PIN_LOW );

}
//================================================================================//

/*
 * Stepper proteus with ULN2003A
 */

void Stepper_Protues_Init(void)
{
	DIO_Set_Pin_Direction( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Top_PIN , DIO_PIN_OUTPUT );
	DIO_Set_Pin_Direction( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Bot_PIN , DIO_PIN_OUTPUT );
	DIO_Set_Pin_Direction( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Bot_PIN, DIO_PIN_OUTPUT );
	DIO_Set_Pin_Direction( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Top_PIN, DIO_PIN_OUTPUT );

	DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Top_PIN   , DIO_PIN_LOW );
	DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Bot_PIN   , DIO_PIN_LOW );
	DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Bot_PIN , DIO_PIN_LOW );
	DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Top_PIN , DIO_PIN_LOW );
}

/*
 * Stepper proteus with ULN2003A
 */

void Stepper_Protues_ON(u8 type ,u8 direction ,u16 angle)
{
	if( type == STEPPER_HALF_STEP ){
		if( direction == STEPPER_CLOCK_WISE ){
			if((angle >= ANGLE_45)&&(angle<= ANGLE_360))
			{
				if(angle == ANGLE_45)
				{
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Top_PIN   , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Bot_PIN   , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Bot_PIN ,  DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Top_PIN ,  DIO_PIN_HIGH );
				}
				else if(angle == ANGLE_90)
				{
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Top_PIN   , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Bot_PIN   ,  DIO_PIN_LOW);
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Bot_PIN ,  DIO_PIN_HIGH );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Top_PIN ,  DIO_PIN_HIGH );
				}
				else if(angle == ANGLE_135)
				{
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Top_PIN   , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Bot_PIN   , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Bot_PIN , DIO_PIN_HIGH );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Top_PIN , DIO_PIN_LOW );
				}
				else if(angle == ANGLE_180)
				{
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Top_PIN   , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Bot_PIN   , DIO_PIN_HIGH );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Bot_PIN , DIO_PIN_HIGH );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Top_PIN , DIO_PIN_LOW );
				}
				else if(angle == ANGLE_225)
				{
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Top_PIN   , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Bot_PIN   , DIO_PIN_HIGH );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Bot_PIN , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Top_PIN , DIO_PIN_LOW );
				}
				else if(angle == ANGLE_270)
				{
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Top_PIN   , DIO_PIN_HIGH );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Bot_PIN   , DIO_PIN_HIGH );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Bot_PIN , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Top_PIN , DIO_PIN_LOW );
				}
				else if(angle == ANGLE_315)
				{
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Top_PIN   , DIO_PIN_HIGH );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Bot_PIN   , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Bot_PIN , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Top_PIN , DIO_PIN_LOW );
				}
				else if(angle == ANGLE_360)
				{
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Top_PIN   , DIO_PIN_HIGH );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Bot_PIN   , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Bot_PIN , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Top_PIN , DIO_PIN_HIGH );
				}
			}
		}
		else if( direction == STEPPER_ANTI_CLOCK_WISE ){
			if((angle >= ANGLE_45)&&(angle<= ANGLE_360))
			{
				if(angle == ANGLE_45)
				{
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Top_PIN   , DIO_PIN_HIGH );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Bot_PIN   , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Bot_PIN ,  DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Top_PIN ,  DIO_PIN_LOW );
				}
				else if(angle == ANGLE_90)
				{
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Top_PIN  , DIO_PIN_HIGH );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Bot_PIN  , DIO_PIN_HIGH);
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Bot_PIN , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Top_PIN , DIO_PIN_LOW );
				}
				else if(angle == ANGLE_135)
				{
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Top_PIN  , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Bot_PIN  , DIO_PIN_HIGH );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Bot_PIN , DIO_PIN_LOW);
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Top_PIN , DIO_PIN_LOW );
				}
				else if(angle == ANGLE_180)
				{
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Top_PIN   , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Bot_PIN   , DIO_PIN_HIGH );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Bot_PIN , DIO_PIN_HIGH );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Top_PIN , DIO_PIN_LOW );
				}
				else if(angle == ANGLE_225)
				{
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Top_PIN   , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Bot_PIN   , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Bot_PIN , DIO_PIN_HIGH );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Top_PIN , DIO_PIN_LOW );
				}
				else if(angle == ANGLE_270)
				{
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Top_PIN   , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Bot_PIN   , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Bot_PIN , DIO_PIN_HIGH );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Top_PIN , DIO_PIN_HIGH );
				}
				else if(angle == ANGLE_315)
				{
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Top_PIN   , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Bot_PIN   , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Bot_PIN , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Top_PIN , DIO_PIN_HIGH );
				}
				else if(angle == ANGLE_360)
				{
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Top_PIN   , DIO_PIN_HIGH );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Bot_PIN   , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Bot_PIN , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Top_PIN , DIO_PIN_HIGH );
				}
			}
		}
	}
	else if( type == STEPPER_FULL_STEP ){
		if( direction == STEPPER_CLOCK_WISE ){
			if((angle >= ANGLE_45)&&(angle<= ANGLE_360))
			{
				if(angle == ANGLE_90)
				{
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Top_PIN   , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Bot_PIN   ,  DIO_PIN_LOW);
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Bot_PIN ,  DIO_PIN_HIGH );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Top_PIN ,  DIO_PIN_HIGH );
				}
				else if(angle == ANGLE_180)
				{
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Top_PIN   , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Bot_PIN   , DIO_PIN_HIGH );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Bot_PIN , DIO_PIN_HIGH );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Top_PIN , DIO_PIN_LOW );
				}
				else if(angle == ANGLE_270)
				{
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Top_PIN   , DIO_PIN_HIGH );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Bot_PIN   , DIO_PIN_HIGH );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Bot_PIN , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Top_PIN , DIO_PIN_LOW );
				}
				else if(angle == ANGLE_360)
				{
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Top_PIN   , DIO_PIN_HIGH );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Bot_PIN   , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Bot_PIN , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Top_PIN , DIO_PIN_HIGH );
				}
			}
		}
		else if( direction == STEPPER_ANTI_CLOCK_WISE ){
			if((angle >= ANGLE_45)&&(angle<= ANGLE_360))
			{
				if(angle == ANGLE_90)
				{
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Top_PIN  , DIO_PIN_HIGH );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Bot_PIN  , DIO_PIN_HIGH);
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Bot_PIN , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Top_PIN , DIO_PIN_LOW );
				}
				else if(angle == ANGLE_180)
				{
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Top_PIN   , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Bot_PIN   , DIO_PIN_HIGH );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Bot_PIN , DIO_PIN_HIGH );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Top_PIN , DIO_PIN_LOW );
				}
				else if(angle == ANGLE_270)
				{
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Top_PIN   , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Bot_PIN   , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Bot_PIN , DIO_PIN_HIGH );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Top_PIN , DIO_PIN_HIGH );
				}
				else if(angle == ANGLE_360)
				{
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Top_PIN   , DIO_PIN_HIGH );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Bot_PIN   , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Bot_PIN , DIO_PIN_LOW );
					DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Top_PIN , DIO_PIN_HIGH );
				}
			}
		}
	}
}

void Stepper_Protues_OFF(void)
{
	DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Top_PIN   , DIO_PIN_LOW );
	DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Left_Bot_PIN   , DIO_PIN_LOW );
	DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Bot_PIN , DIO_PIN_LOW );
	DIO_Set_Pin_Value( STEPPER_Proteus_PORT , STEPPER_Proteus_Right_Top_PIN , DIO_PIN_LOW );
}
