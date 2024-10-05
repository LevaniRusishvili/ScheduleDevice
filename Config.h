#define      GSM_UART1_RX_DDR             DDD2_bit
#define      GSM_UART1_RX_PORT            PORTD2_bit
#define      GSM_UART1_TX_DDR             DDD3_bit
#define      GSM_UART1_TX_PORT1           PORTD3_bit
#define      GSM_SIMSTATUS_DDR            DDD4_bit
#define      GSM_SIMSTATUS_PORT           PORTD4_bit
#define      GSM_SIMSTATUS_PIN            PIND4_bit

#define      DC_K1_DDR                    DDC5_bit
#define      DC_K1_PORT                   PORTC5_bit
#define      DC_K2_DDR                    DDC6_bit
#define      DC_K2_PORT                   PORTC6_bit

#define      MISO_DDR                     DDB3_bit
#define      MISO_PORT                    PORTB3_bit
#define      MOSI_DDR                     DDB2_bit
#define      MOSI_PORT                    PORTB2_bit
#define      SCK_DDR                      DDB1_bit
#define      SCK_PORT                     PORTB1_bit
#define      RESET_DDR                    DDB4_bit
#define      RESET_PORT                   PORTB4_bit
#define      SS_DDR                       DDB0_bit
#define      SS_PORT                      PORTB0_bit

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
