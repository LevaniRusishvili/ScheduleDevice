#line 1 "D:/Schedule_Device/Schedule_Device_Levani_Rusishvili_rev_002/Config.c"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for avr/include/built_in.h"
#line 1 "d:/schedule_device/schedule_device_levani_rusishvili_rev_002/config.h"
#line 25 "d:/schedule_device/schedule_device_levani_rusishvili_rev_002/config.h"
void InitPeriferial();
void Clr_UART2_Buffer(void);
void Check_SimStatus();
void TimerInterruptHandler();
int dayOfWeek(int year, int month, int day);
int isLeapYear(int year);
void CheckScheduleMatch();
void UpdateCurrentTimeComponents();
void CheckRelayStatus();
void ParseUART2Data();
void ShowRealTimeOnLCD();
#line 1 "d:/schedule_device/schedule_device_levani_rusishvili_rev_002/lcd_dt.h"
#line 84 "d:/schedule_device/schedule_device_levani_rusishvili_rev_002/lcd_dt.h"
void LCD_WriteData(char dt);
void LCD_ini(void);
void LCD_Clear(void);
void LCD_SendChar(char ch, char ax, char ay);
void LCD_String(char* st, char ax, char ay);
void LCD_SetPos(char ax, char ay);
void LCD_Command(char dt);
void LCD_Data(char dt);
void LCD_PutCustom(char ax, char ay, char location, const char *adata);
void Charcho_Marcxniv (void);
void Charcho_Marjvniv (void);

void TWI_TimeoutCallback(char errorCode);
void I2C_LCD_Init(void);
void I2C_LCD_Cmd(char out_char);
void I2C_LCD_Chr(char row, char column, char out_char);
void I2C_LCD_Chr_Cp(char out_char);
void I2C_LCD_Out(char row,char col,char *text);
void I2C_LCD_Out_Cp(char *text);
void I2C_LCD_cursor(char row, char col);
void I2C_LCD_PutCustom(char row_pos, char col_pos, char location, const char *cosChar);

char SWTWI_Error_Handler (void);

void Big_Custom_Clock (char ax, char ay);
void Big_Number_1(char ax, char ay);
void Big_Number_2(char ax, char ay);
void Big_Number_3(char ax, char ay);
void Big_Number_4(char ax, char ay);
void Big_Number_5(char ax, char ay);
void Big_Number_6(char ax, char ay);
void Big_Number_7(char ax, char ay);
void Big_Number_8(char ax, char ay);
void Big_Number_9(char ax, char ay);
void Big_Number_0(char ax, char ay);
void Big_Number_Write(char ax, char ay, char number);

void Test_Word (void);
#line 1 "d:/schedule_device/schedule_device_levani_rusishvili_rev_002/cmd.h"





 void GSM_Speed(char *buf);
#line 9 "D:/Schedule_Device/Schedule_Device_Levani_Rusishvili_rev_002/Config.c"
extern volatile char UART2_Buffer[];
extern volatile unsigned int UART2_Buffer_Counter;
extern volatile char FL_UART2_Data,FL_First;
extern char Temp_txt[256];

extern char FL_10ms, FL_100ms, FL_500ms, FL_1sec, FL_1min, FL_5sec, FL_10sec;





void Clr_UART2_Buffer(void)
{
memset(UART2_Buffer,0,255);UART2_Buffer_Counter=0;
}

void Uart2Send (char *Buf, unsigned int Len)
{
unsigned int i=0;
 for (i=0; i<Len; i++)
 {
  UART2_Write (Buf[i]);
 }
}





 void UART1_RX_INT(void) iv IVT_ADDR_USART1__RX
{

 if (FL_First==0)
 {
 FL_First=1; TCCR0A=0; TCCR0B=4; TOIE0_bit=1; UART2_Buffer_Counter=0;
 }

 UART2_Buffer [UART2_Buffer_Counter++] = UART2_Read();

 TCNT0 = 0;


}





void T0_OVF_INT (void) iv IVT_ADDR_TIMER0_OVF
{
TCCR0A=0; TCCR0B=0; TOIE0_bit=0;
FL_First=0; UART2_Buffer_Counter=0; FL_UART2_Data=1;
}




void InitPeriferial()
{
TWI_Init(100000);
UART2_Init(115200); RXCIE1_bit=1;
TCCR0A=0; TCCR0B=0; TOIE0_bit=0;
TCCR1A=0; TCCR1B=0x0B; OCR1AH=0x09; OCR1AL=0xC4; OCIE1A_bit=1;
SREG_I_bit=1;
 DDA2_bit =1;
 DDA1_bit =1;
 DDA3_bit =1;
 DDA4_bit =1;
 DDA5_bit =1;
 DDA6_bit =1;
 DDA7_bit =1;

 PORTA2_bit =0;
 PORTA1_bit =0;
 PORTA3_bit =0;
 PORTA4_bit =0;
 PORTA5_bit =0;
 PORTA6_bit =0;
 PORTA7_bit =1;
------------------------------------------------------------------------------
EICRA=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (1<<ISC00);
EIMSK=(0<<INT1) | (1<<INT0);
EIFR=(0<<INTF1) | (1<<INTF0);
PCICR=(0<<PCIE2) | (0<<PCIE1) | (0<<PCIE0);

}


 void INT_0 (void) iv IVT_ADDR_INT0
{
static char FL_500ms_cnt=0;
static char FL_1sec_cnt=0;
#line 116 "D:/Schedule_Device/Schedule_Device_Levani_Rusishvili_rev_002/Config.c"
}


 void Timer_1 (void) iv IVT_ADDR_TIMER1_COMPA
{
static char FL_10ms_cnt=0;
static char FL_100ms_cnt=0;
static char FL_500ms_cnt=0;
static char FL_1sec_cnt=0;
static char FL_2sec_cnt=0;
static char FL_5sec_cnt=0;


FL_10ms=1;

if(FL_10ms_cnt++>=9)
 {
 FL_10ms_cnt=0;
 FL_100ms=1;
 if(FL_100ms_cnt++>=4)
 {
 FL_100ms_cnt=0;
 FL_500ms=1;
 if(FL_500ms_cnt++>=1)
 {
 FL_500ms_cnt=0;
 FL_1sec=1;
 if(FL_1sec_cnt++>=9)
 {
 FL_1sec_cnt=0;
 FL_10sec=1;


 }
 }

 }

 }

}
