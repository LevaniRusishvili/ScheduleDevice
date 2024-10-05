#line 1 "D:/Schedule_Device/Schedule_Device_Levani_Rusishvili_rev_002/CMD.c"
#line 1 "d:/schedule_device/schedule_device_levani_rusishvili_rev_002/cmd.h"





 void GSM_Speed(char *buf);
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
#line 1 "d:/schedule_device/schedule_device_levani_rusishvili_rev_002/scheduledevice.h"
void Check_Simstatus();
#line 16 "D:/Schedule_Device/Schedule_Device_Levani_Rusishvili_rev_002/CMD.c"
extern char FL_Power_Ok;
char FL_Speed_GSM_Ok;
