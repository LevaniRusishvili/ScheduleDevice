#include "Config.h"
#include "ScheduleDevice.h"
//==============================================================================
//extern volatile char       UART2_Buffer[];                                      // Mimgebi buferi
//extern volatile char       UART2_Buffer_Counter;                                // Mimgebi buferis baitebis caunteri
//extern volatile char       FL_UART2_Data,FL_First;                              // Paketis migeba dasrulebulia  ,FL_Sec
//extern volatile char       FL_10_ms,FL_100_ms=0,FL_200_ms,FL_300_ms, FL_1_sec, FL_1min, FL_Cmd_sec;              // Drois Amtvleli Registrebi

//------------------------------------------------------------------------------
//==============================================================================
//============================= INTERRUPTS =====================================
//==============================================================================
/*
void UART1_RX_INT (void) iv IVT_ADDR_USART1__RX
{
if (FL_First==0)                                                                // Tu Pirveli Baiti Shemovida Chavrtot T0 Gadavsebaze !!!
   {FL_First=1; TCCR0A=0; TCCR0B=4; TOIE0_bit=1; UART2_Buffer_Counter=0;}       // Uartze Semosuli Pirveli Baiti Chartavs T0-is INTERRUPTS !! -> 5.925 Miliwamian Gadavsebaze
    UART2_Buffer [UART2_Buffer_Counter++] = UART2_Read();                       // Vcert Migebul Baitebs UART1_Buffer-Shi Miyolebit
    TCNT0 = 0;                                                                  // Yoveli Semosuli Baiti Chamoyris T0-is Mtvlels (Ar Vacdit Datvla-Gadavsebas)
}
*/

/*
void T0_OVF_INT (void) iv IVT_ADDR_TIMER0_OVF                                   // Baitiebis Semosvla Roca Sewydeba Gadaivseba, Moxdeba ES Int-i
{
 TCCR0A=0;   TCCR0B=0;  TOIE0_bit=0;                                            // Tu Gadaivso (moxda INT-i) Gamoirtavs Tavis Tavs
 FL_First=0; UART2_Buffer_Counter=0;  FL_UART2_Data=1;                          // Taimauti Gavida >> Monacemebi Migebulia  UART1_Buffer-Shi
}
*/
////////////////////////////////////////////////////////////////////////////////
 /*
void Timer_1 (void) iv IVT_ADDR_TIMER1_COMPA                                    // T1-10ms Interrupt Enable Mode CTC Clock-16000000 OCR1A
{
static char FL_10ms_cnt=0;
static char FL_100ms_cnt=0;
static char FL_500ms_cnt=0;
static char FL_1sec_cnt=0;


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
             if(FL_1sec_cnt++>=59)
                {
                 FL_1sec_cnt=0;
                 FL_1min=1;

                 }
             }

        }

    }

}
*/

//==============================================================================
/*
void INT_0 (void) iv IVT_ADDR_INT0                                              //500_ms INT
{
 static char  cnt_local=0;
//  FL_500_ms=1;
  if (cnt_local++>=1) 
  {
  cnt_local=0;
  FL_1_sec=1;
                       
  }
}
 */
//------------------------------------------------------------------------------