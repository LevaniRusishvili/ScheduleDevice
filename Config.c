#include        "built_in.h"
#include        "Config.h"
#include        "LCD_DT.h"
#include        "CMD.h"
//-----------------------Configuraciebi-----------------------------------------
//------------------------------------------------------------------------------
//TCCR1C=0; TCCR1A=0; TCCR1B=0x0C;  OCR1AH=0x18; OCR1AL=0x69; OCIE1A_bit=1;     //100ms timer inicializacia
//------------------------------------------------------------------------------
extern volatile char         UART2_Buffer[];                                       // Mimgebi buferi
extern volatile unsigned int UART2_Buffer_Counter;                                 // Mimgebi buferis baitebis caunteri
extern volatile char         FL_UART2_Data,FL_First;                               // Paketis migeba dasrulebulia  ,FL_Sec
extern char                  Temp_txt[256];
//extern char                  GSM_cnt;
extern char   FL_10ms,  FL_100ms, FL_500ms, FL_1sec, FL_1min, FL_5sec, FL_10sec;

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

void Clr_UART2_Buffer(void)
{
memset(UART2_Buffer,0,255);UART2_Buffer_Counter=0;
} // GSM-is buferis washla

void Uart2Send (char *Buf, unsigned int Len)
{
unsigned int i=0; 
  for (i=0; i<Len; i++)
  {
      GSM_char(Buf[i]);                                                         // Baitebis Gayra UART2-ze
  }
}   //

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

 void UART1_RX_INT(void) iv IVT_ADDR_USART1__RX
{

 if (FL_First==0)                                                                // Tu Pirveli Baiti Shemovida Chavrtot T0 Gadavsebaze !!!
   {
   FL_First=1; TCCR0A=0; TCCR0B=4; TOIE0_bit=1; UART2_Buffer_Counter=0;         // Uartze Semosuli Pirveli Baiti Chartavs T0-is INTERRUPTS !! -> 5.925 Miliwamian Gadavsebaze
   }

    UART2_Buffer [UART2_Buffer_Counter++] = UART2_Read();                       // Vcert Migebul Baitebs UART1_Buffer-Shi Miyolebit

    TCNT0 = 0;                                                                  // Yoveli Semosuli Baiti Chamoyris T0-is Mtvlels (Ar Vacdit Datvla-Gadavsebas)


}

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

void T0_OVF_INT (void) iv IVT_ADDR_TIMER0_OVF                                   // Baitiebis Semosvla Roca Sewydeba Gadaivseba, Moxdeba ES Int-i
{
TCCR0A=0;   TCCR0B=0;  TOIE0_bit=0;                                            // Tu Gadaivso (moxda INT-i) Gamoirtavs Tavis Tavs
FL_First=0; UART2_Buffer_Counter=0;  FL_UART2_Data=1;                           // Taimauti Gavida >> Monacemebi Migebulia  UART1_Buffer-Shi
}

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void InitPeriferial()
{
TWI_Init(100000);
UART2_Init(115200);  RXCIE1_bit=1;                                              // UART 19200 Interrupt Enable
TCCR0A=0; TCCR0B=0;  TOIE0_bit=0;                                               // T0 for UART - SwitchOff (first time)
TCCR1A=0; TCCR1B=0x0B;  OCR1AH=0x09; OCR1AL=0xC4; OCIE1A_bit=1;                 // T1-10ms Interrupt Enable Mode CTC Clock-16000000 OCR1A
SREG_I_bit=1;
DDR_RS=1;
DDR_E=1;
DDR_D4=1;
DDR_D5=1;
DDR_D6=1;
DDR_D7=1;
LCD_LED_DDR=1;

PORT_RS=0;
PORT_E=0;
PORT_D4=0;
PORT_D5=0;
PORT_D6=0;
PORT_D7=0;
LCD_LED_PORT=1;
------------------------------------------------------------------------------//INT0_500ms
EICRA=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (1<<ISC00);
EIMSK=(0<<INT1) | (1<<INT0);
EIFR=(0<<INTF1) | (1<<INTF0);
PCICR=(0<<PCIE2) | (0<<PCIE1) | (0<<PCIE0);
//------------------------------------------------------------------------------
}
//------------------------------------------------------------------------------

 void INT_0 (void) iv IVT_ADDR_INT0                                              //INT0_500ms
{
static char FL_500ms_cnt=0;
static char FL_1sec_cnt=0;

//FL_500ms=1;
//
//if(FL_500ms_cnt++>=1)
//{
// FL_500ms_cnt=0;
// FL_1sec=1;
// if(FL_1sec_cnt++>=59)
//  {
//   FL_1sec_cnt=0;
//   FL_1min=1;
//
//   }
// }
//
}


       void Timer_1 (void) iv IVT_ADDR_TIMER1_COMPA                                    // T1-10ms Interrupt Enable Mode CTC Clock-16000000 OCR1A
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





//------------------------------------------------------------------------------