//==============================================================================
#include "CMD.h"
#include "Config.h"
#include "LCD_DT.h"
#include "ScheduleDevice.h"
//#include "I2Cdew.h"
//#include "timelib.h"
//==============================================================================
//extern volatile char     UART1_Buffer[];                                       // Mimgebi buferi
//extern char              Time_Buffer[];                                        // GSM-is Drois buferi

//extern char              GSM_ERROR_st;
//extern char              Fl_Config_write;

//--------------------- levanis externebi---------------------------------------
extern char              FL_Power_Ok;
char                     FL_Speed_GSM_Ok;
//------------------------------------------------------------------------------

/*
//==============================================================================

char Check_GSM_CMD(char *buf)
{
char st=0;
char FL_Clr=0;   
long temp_lok=0;
FL_Clr=1;                                                                       // FL_Clr=1;  Zog Kamandaze Tu Gvinda Rom Ar Washalos Buferi

if(strstr(buf,"kata")!=0)  {  UART_Write_Text("ok kata\r\n"); FL_Clr=1;}   //SIM900_SMS_Check_Send ();  GSM_txt("AT+CMGL=\"ALL\"\r\n");

if(strstr(buf,"cmd_clear")!=0)  {  Fl_Config_write=1; FL_Clr=1;}

//if(strstr(buf,"kote")!=0){DS1307_Set_Time (buf,  0 );}
if(strstr(buf,"CCLK:")!=0){DS1307_Set_Time (buf,  temp_lok );}

if(strstr(buf,"OK")!=0) { FL_Clr=0;}
if(strstr(UART1_Buffer,"+CREG: 1,1")!=0){ FL_Clr=0; }

if (FL_Clr==1) {  FL_Clr=0; Clr_UART1_Buffer();  }
return 0;
}
//==============================================================================
*/


/*

void GSM_Speed(char *buf)
{     
   // if(strstr(buf,"OK"==0)
  //  {
  //    UART2_Write_Text("AT\r\n");
 //     Delay_ms(10);
  //    FL_Speed_GSM_Ok=0;
      LCD_String("GSM speed not OK",3,0);
      
//    }
  //  else if(strstr(buf,"OK"!=0)                                                 //anu OK waikitxa da misamarti daabruna
 //   {
 //    Delay_ms(10);
  //   FL_Speed_GSM_Ok=1;
     LCD_String("GSM Speed OK",2,0);
    }

}
*/