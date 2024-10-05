#line 1 "D:/Schedule_Device/Schedule_Device_Levani_Rusishvili_rev_002/IT.c"
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
#line 1 "d:/schedule_device/schedule_device_levani_rusishvili_rev_002/scheduledevice.h"
void Check_Simstatus();
