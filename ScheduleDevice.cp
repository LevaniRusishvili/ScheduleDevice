#line 1 "D:/Schedule_Device/Schedule_Device_Levani_Rusishvili_rev_002/ScheduleDevice.c"
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
#line 1 "d:/schedule_device/schedule_device_levani_rusishvili_rev_002/scheduledevice.h"
void Check_Simstatus();
#line 1 "d:/schedule_device/schedule_device_levani_rusishvili_rev_002/cmd.h"





 void GSM_Speed(char *buf);
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for avr/include/stdio.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for avr/include/stdlib.h"







 typedef struct divstruct {
 int quot;
 int rem;
 } div_t;

 typedef struct ldivstruct {
 long quot;
 long rem;
 } ldiv_t;

 typedef struct uldivstruct {
 unsigned long quot;
 unsigned long rem;
 } uldiv_t;

int abs(int a);
float atof(char * s);
int atoi(char * s);
long atol(char * s);
div_t div(int number, int denom);
ldiv_t ldiv(long number, long denom);
uldiv_t uldiv(unsigned long number, unsigned long denom);
long labs(long x);
int max(int a, int b);
int min(int a, int b);
void srand(unsigned x);
int rand();
int xtoi(char * s);
#line 11 "D:/Schedule_Device/Schedule_Device_Levani_Rusishvili_rev_002/ScheduleDevice.c"
char FL_Power_Ok = 0;
volatile char UART2_Buffer[256];
volatile unsigned int UART2_Buffer_Counter = 0;
volatile char FL_UART2_Data = 0, FL_First = 0;
char Temp_txt[256];
char FL_10ms = 0, FL_100ms = 0, FL_500ms = 0, FL_1sec = 0, FL_1min = 0, FL_10sec = 0;
char FlStatusAT = 0, FlSimStatus = 0;

int row = 3;
int col = 0;

unsigned int current_month;
unsigned int current_day;
unsigned int current_hour;
unsigned int current_minute;
char *result = 0;
int onHour;
int onMinute;
int offHour;
int offMinute;
char onTimeStr[6];
char offTimeStr[6];
int total_minutes_current;
int total_minutes_on;
int total_minutes_off;
int RealTime=0;
int OnTime=0;
int OffTime=0;




char Relay_Status=0;



char tempBufyy[4];
char tempBufmo[4];
char tempBufmd[4];
char tempBufhh[4];
char tempBufmn[4];
char tempBufss[4];

char tempBuf10[12];
char tempBuf11[12];





char OnTimehh0[12];
char OnTimehh1[12];
char OnTimemn0[12];
char OnTimemn1[12];
char OffTimehh0[12];
char OffTimehh1[12];
char OffTimemn0[12];
char OffTimemn1[12];



int daysInMonth=0;
int current_column_index=0;



unsigned int i = 0;
unsigned int j = 0;
unsigned int k = 0;
unsigned int p = 0;



unsigned int current_command_index = 0;
char messages_sent = 0;
char *response;



unsigned char hour_on ;
unsigned char minute_on;
unsigned char hour_off;
unsigned char minute_off;

 unsigned int column_index = 0;


char ATOK = 0;
char ATE1OK = 0;
char ATIOK = 0;
char ATCREGOK = 0;
char ATCSQOK = 0;
char ATCOPSOK = 0;
char ATCMGFOK=0;
char ATCPINOK=0;
char ATCCLKOK=0;
char ATCLTSOK=0;
char ATWOK=0;
char ATCCLK2OK=0;





 const unsigned char Grafiki[12][6][12] =
 {
 {"17:49,08:09", "17:54,08:09", "17:58,08:08", "18:06,08:06", "18:11,08:03", "18:17,07:58"},
 {"18:26,07:52", "18:36,07:47", "18:39,07:41", "18:45,07:35", "18:51,07:27", "18:56,07:21"},
 {"19:02,07:14", "19:06,07:07", "19:13,06:57", "19:19,06:49", "19:25,06:39", "19:30,06:29"},
 {"19:37,06:20", "19:41,06:14", "19:48,06:04", "19:53,05:57", "19:59,05:49", "20:02,05:41"},
 {"20:10,05:35", "20:15,05:29", "20:20,05:23", "14:28,14:29", "10:10,14:45", "11:34,14:00"},
 {"20:39,05:08", "20:43,05:05", "20:46,05:05", "20:48,05:05", "20:48,05:06", "20:40,05:07"},
 {"20:48,05:10", "20:47,05:13", "20:45,05:16", "20:41,05:21", "20:37,05:25", "20:31,05:31"},
 {"20:25,05:36", "20:19,05:41", "20:12,05:46", "20:05,05:52", "19:57,05:57", "19:49,06:02"},
 {"19:45,06:08", "19:31,06:13", "19:22,06:19", "19:14,06:24", "19:05,06:29", "18:56,06:34"},
 {"18:47,06:40", "18:39,06:46", "18:31,06:52", "18:23,06:57", "18:16,07:02", "18:07,07:10"},
 {"18:01,07:16", "17:55,07:22", "17:50,07:29", "17:46,07:35", "17:42,07:40", "17:40,07:46"},
 {"17:38,07:50", "17:38,07:56", "17:38,08:00", "17:39,08:03", "17:41,08:06", "17:44,08:09"}
 };






typedef struct
{
 unsigned char ss;
 unsigned char mn;
 unsigned char hh;
 unsigned char md;
 unsigned char wd;
 unsigned char mo;
 unsigned int yy;
} TimeStruct;


TimeStruct ts1, ts2, ts3;



void main()
{

 InitPeriferial();
 LCD_ini();
 LCD_Clear();
 Delay_ms(2000);



while (1)
 {

if (FL_1sec == 1)
 {
FL_1sec = 0;
LCD_Clear();
#line 186 "D:/Schedule_Device/Schedule_Device_Levani_Rusishvili_rev_002/ScheduleDevice.c"
if(ATOK==1)
{
asm jmp A
}
else
 {
 asm startA:
 UART_Write_Text("AT\r\n"); Delay_ms(10);
 if(strstr(UART2_Buffer,"OK")!=0)
 {
 LCD_String("AT OK Found",0,1);
 ATOK=1;
 Delay_ms(800);
 LCD_Clear();
 }
 else
 {
 LCD_String("AT OK not Found",0,1);
 ATOK=0;
 Delay_ms(800);
 LCD_Clear();
 asm jmp startA
 }
 }
asm A:
memset(UART2_Buffer, 0, sizeof(UART2_Buffer));
if(ATE1OK==1)
{
 asm jmp B
}
else
{
asm startB:
UART_Write_Text("ATE1\r\n"); Delay_ms(10);
 if(strstr(UART2_Buffer,"OK")!=0)
 {
 LCD_String("ATE1 OK Found",0,1);
 ATE1OK=1;
 Delay_ms(800);
 LCD_Clear();
 }
 else
 {
 LCD_String("ATE1 OK not Found",0,1);
 ATE1OK=0;
 Delay_ms(800);
 LCD_Clear();
 asm jmp startB
 }
}
asm B:
 memset(UART2_Buffer, 0, sizeof(UART2_Buffer));
if(ATIOK==1)
{
 asm jmp C
}
else
{
asm startC:
UART_Write_Text("ATI\r\n"); Delay_ms(10);
 if(strstr(UART2_Buffer,"OK")!=0)
 {
 LCD_String("ATI OK Found",0,1);
 ATIOK=1;
 Delay_ms(800);
 LCD_Clear();

 }
 else
 {
 LCD_String("ATI OK not Found",0,1);
 ATIOK=0;
 Delay_ms(800);
 LCD_Clear();
 asm jmp startC
 }
}
asm C:
 memset(UART2_Buffer, 0, sizeof(UART2_Buffer));

if(ATCREGOK==1)
{
 asm jmp D
}
else
{
asm startD:
UART_Write_Text("AT+CREG=1\r\n"); Delay_ms(10);
if(strstr(UART2_Buffer,"OK")!=0)
 {
 LCD_String("AT+CREG OK found",0,1);
 ATCREGOK=1;
 Delay_ms(800);
 LCD_Clear();

 }
 else
 {
 LCD_String("AT+CREG OK not found",0,1);
 ATCREGOK=0;
 Delay_ms(800);
 LCD_Clear();
 asm jmp startD
 }
}
asm D:
 memset(UART2_Buffer, 0, sizeof(UART2_Buffer));


if(ATCSQOK==1)
{
 asm jmp E
}
else
{
 asm startE:
UART_Write_Text("AT+CSQ\r\n"); Delay_ms(10);
if(strstr(UART2_Buffer,"+CSQ: 0,0")!=0)
 {
 LCD_String("AT+CSQ 0,0 found",0,1);
 ATCSQOK=0;
 Delay_ms(800);
 LCD_Clear();
 asm jmp startE


 }
 else
 {
 LCD_String("AT+CSQ 0,0 not found",0,1);
 ATCSQOK=1;
 Delay_ms(800);
 LCD_Clear();

 }
}
asm E:
 memset(UART2_Buffer, 0, sizeof(UART2_Buffer));


if(ATCOPSOK==1)
{
 asm jmp F
}
else
{
asm startF:
UART_Write_Text("AT+COPS?\r\n"); Delay_ms(10);
if(strstr(UART2_Buffer,"OK")!=0)
 {
 LCD_String("AT+COPS? OK found",0,1);
 ATCOPSOK=1;
 Delay_ms(800);
 LCD_Clear();

 }
 else
 {
 LCD_String("AT+COPS? OK not found",0,1);
 ATCOPSOK=0;
 Delay_ms(800);
 LCD_Clear();
 asm jmp startF
 }
}
asm F:
 memset(UART2_Buffer, 0, sizeof(UART2_Buffer));



if(ATCMGFOK==1)
{
 asm jmp G
}
else
{
asm startG:
UART_Write_Text("AT+CMGF=1\r\n"); Delay_ms(10);
if(strstr(UART2_Buffer,"OK")!=0)
 {
 LCD_String("AT+CMGF OK found",0,1);
 ATCMGFOK=1;
 Delay_ms(800);
 LCD_Clear();

 }
 else
 {
 LCD_String("AT+CMGF OK not found",0,1);
 ATCMGFOK=0;
 Delay_ms(800);
 LCD_Clear();
 asm jmp startG
 }
}
asm G:
 memset(UART2_Buffer, 0, sizeof(UART2_Buffer));


if(ATCPINOK==1)
{
 asm jmp H
}
else
{
asm startH:
UART_Write_Text("AT+CPIN?\r\n"); Delay_ms(10);
if(strstr(UART2_Buffer,"READY")!=0)
 {
 LCD_String("AT+CPIN? READY",0,1);
 ATCPINOK=1;
 Delay_ms(800);
 LCD_Clear();

 }
 else
 {
 LCD_String("AT+CPIN? ERROR",0,1);
 ATCPINOK=0;
 Delay_ms(800);
 LCD_Clear();
 asm jmp startH
 }
}
asm H:
 memset(UART2_Buffer, 0, sizeof(UART2_Buffer));



if(ATCCLKOK==1)
{
 asm jmp I
}
else
{
asm startI:
UART_Write_Text("AT+CCLK?\r\n"); Delay_ms(10);
if(strstr(UART2_Buffer,"+CCLK:")!=0)
 {

 LCD_String("AT+CCLK? OK",0,1);
 ATCCLKOK=1;
 Delay_ms(800);
 LCD_Clear();

 }
 else
 {
 LCD_String("AT+CCLK? not OK",0,1);
 ATCCLKOK=0;
 Delay_ms(800);
 LCD_Clear();
 asm jmp startI
 }
}
asm I:





if(ATCLTSOK==1)
{
 asm jmp J
}
else
{
asm startJ:
UART_Write_Text("AT+CLTS=1\r\n"); Delay_ms(10);
if(strstr(UART2_Buffer,"OK")!=0)
 {

 LCD_String("AT+CLTS=1 OK",0,1);
 ATCLTSOK=1;
 Delay_ms(800);
 LCD_Clear();

 }
 else
 {
 LCD_String("AT+CLTS=1 not OK",0,1);
 ATCLTSOK=0;
 Delay_ms(800);
 LCD_Clear();
 asm jmp startJ
 }
}
asm J:



if(ATWOK==1)
{
 asm jmp K
}
else
{
asm startK:
UART_Write_Text("AT&W\r\n"); Delay_ms(10);
if(strstr(UART2_Buffer,"OK")!=0)
 {

 LCD_String("AT&W OK",0,1);
 ATWOK=1;
 Delay_ms(800);
 LCD_Clear();

 }
 else
 {
 LCD_String("AT&W not OK",0,1);
 ATWOK=0;
 Delay_ms(800);
 LCD_Clear();
 asm jmp startK
 }
}
asm K:



if(ATCCLK2OK==1)
{
 asm jmp L
}
else
{
asm startL:
UART_Write_Text("AT+CCLK?\r\n"); Delay_ms(10);
if(strstr(UART2_Buffer,"+CCLK:")!=0)
 {
ParseUART2Data();
 LCD_String("AT+CCLK? OK",0,1);
 ATCCLK2OK=1;
 Delay_ms(800);
 LCD_Clear();

 }
 else
 {
 LCD_String("AT+CCLK? not OK",0,1);
 ATCCLK2OK=0;
 Delay_ms(800);
 LCD_Clear();
 asm jmp startL
 }
}
asm L:


memset(UART2_Buffer, 0, sizeof(UART2_Buffer));
TimerInterruptHandler();
CheckRelayStatus();
CheckScheduleMatch();


 }
 }
}







int isLeapYear(int year)
{
 return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}



int dayOfWeek(int year, int month, int day)
{
 static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
 year -= month < 3;
 return (year + year/4 - year/100 + year/400 + t[month-1] + day) % 7;
}






void TimerInterruptHandler()
{

 ts3.ss++;
 if (ts3.ss >= 60)
 {
 ts3.ss = 0;

 ts3.mn++;
 if (ts3.mn >= 60)
 {
 ts3.mn = 0;

 ts3.hh++;
 if (ts3.hh >= 24)
 {
 ts3.hh = 0;

 ts3.md++;

 daysInMonth = 31;
 if (ts3.mo == 2)
 {
 daysInMonth = isLeapYear(ts3.yy) ? 29 : 28;
 } else if (ts3.mo == 4 || ts3.mo == 6 || ts3.mo == 9 || ts3.mo == 11)
 {
 daysInMonth = 30;
 }
 if (ts3.md > daysInMonth)
 {
 ts3.md = 1;
 ts3.mo++;
 if (ts3.mo > 12)
 {
 ts3.mo = 1;
 ts3.yy++;
 }
 }

 ts3.wd = dayOfWeek(ts3.yy, ts3.mo, ts3.md);
 }
 }
 }
sprintf(tempBufyy, "%02u/",(unsigned int)ts3.yy);
LCD_String(tempBufyy, 0, 1);
sprintf(tempBufmo, "%02u/",(unsigned int)ts3.mo);
LCD_String(tempBufmo, 3, 1);
sprintf(tempBufmd, "%02u",(unsigned int)ts3.md);
LCD_String(tempBufmd, 6, 1);
sprintf(tempBufhh, "%02u:",(unsigned int)ts3.hh);
LCD_String(tempBufhh, 9, 1);
sprintf(tempBufmn, "%02u:",(unsigned int)ts3.mn);
LCD_String(tempBufmn, 12, 1);
sprintf(tempBufss, "%02u",(unsigned int)ts3.ss);
LCD_String(tempBufss, 15, 1);

}






void CheckScheduleMatch()
{

 current_month = ts3.mo;
 current_day = ts3.md;
 current_hour = ts3.hh;
 current_minute = ts3.mn;

 for(k=0; k<12; k++)
 {
 if(k==current_month)
 {
 for(p=0; p<31; p++)
 {
 if(p==current_day)
 {
 if(p>=1 && p<=5) {column_index=0;}
 if(p>=6 && p<=10) {column_index=1;}
 if(p>=11 && p<=15) {column_index=2;}
 if(p>=16 && p<=20) {column_index=3;}
 if(p>=21 && p<=25) {column_index=4;}
 if(p>=26 && p<=31) {column_index=5;}
 }
 }
 sprintf(OnTimehh0,"%c",Grafiki[k-1][column_index][0]);
 sprintf(OnTimehh1,"%c",Grafiki[k-1][column_index][1]);
 sprintf(OnTimemn0,"%c",Grafiki[k-1][column_index][3]);
 sprintf(OnTimemn1,"%c",Grafiki[k-1][column_index][4]);
 strcat(OnTimehh0,OnTimehh1);
 strcat(OnTimemn0, OnTimemn1);

 sprintf(OffTimehh0,"%c",Grafiki[k-1][column_index][6]);
 sprintf(OffTimehh1,"%c",Grafiki[k-1][column_index][7]);
 sprintf(OffTimemn0,"%c",Grafiki[k-1][column_index][9]);
 sprintf(OffTimemn1,"%c",Grafiki[k-1][column_index][10]);
 strcat(OffTimehh0,OffTimehh1);
 strcat(OffTimemn0, OffTimemn1);

 LCD_String("On",0,2);
 LCD_String(OnTimehh0,3,2);
 LCD_String(":",5,2);
 LCD_String(OnTimemn0,6,2);

 LCD_String("Off",10,2);
 LCD_String(OffTimehh0,14,2);
 LCD_String(":",16,2);
 LCD_String(OffTimemn0,17,2);

 strcat(OnTimehh0,OnTimemn0);
 OnTime=atoi(OnTimehh0);
 strcat(OffTimehh0,OffTimemn0);
 OffTime=atoi(OffTimehh0);
 strcat(tempBufhh,tempBufmn);
 RealTime=current_hour*100+current_minute;


 if(RealTime>=OnTime && RealTime<OffTime)
 {
 Relay_Status=1;
 }
 else
 {
 Relay_Status=0;
 }
 }
 }
}




void CheckRelayStatus()
{
 if(Relay_Status==1)
 {  PORTC5_bit =1;
 LCD_String("Relay On",0,3);
 }
 else
 {  PORTC5_bit =0;
 LCD_String("Relay Off",0,3);
 }
}



void ParseUART2Data()
{
ts3.yy = (UART2_Buffer[19] - 48) * 10 + (UART2_Buffer[20] - 48);
ts3.mo = (UART2_Buffer[22] - 48) * 10 + (UART2_Buffer[23] - 48);
ts3.md = (UART2_Buffer[25] - 48) * 10 + (UART2_Buffer[26] - 48);
ts3.hh = (UART2_Buffer[28] - 48) * 10 + (UART2_Buffer[29] - 48);
ts3.mn = (UART2_Buffer[31] - 48) * 10 + (UART2_Buffer[32] - 48);
ts3.ss = (UART2_Buffer[34] - 48) * 10 + (UART2_Buffer[35] - 48);
}
