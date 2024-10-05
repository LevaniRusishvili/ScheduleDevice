#line 1 "D:/Schedule_Device/Schedule_Device_Levani_Rusishvili_rev_002/LCD_DT.c"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for avr/include/built_in.h"
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
#line 7 "D:/Schedule_Device/Schedule_Device_Levani_Rusishvili_rev_002/LCD_DT.c"
const char characterAA[] = {8,8,4,2,1,17,14,0};
const char characterBB[] = {8,12,4,14,17,17,14,0};
const char characterGG[] = {12,18,4,10,17,17,14,0};
const char characterDD[] = {14,17,17,30,16,14,1,0};
const char characterEE[] = {14,17,1,1,17,17,14,0};
const char characterVV[] = {14,17,1,2,17,17,14,0};
const char characterZZ[] = {12,18,12,6,9,9,6,0};
const char characterTT[] = {10,21,21,21,21,21,9,0};
const char characterII[] = {14,17,17,17,17,17,10,0};
const char characterKK[] = {1,1,2,1,9,9,6,0};
const char characterLL[] = {14,17,17,16,8,20,2,0};
const char characterMM[] = {14,17,1,15,17,17,14,0};
const char characterNN[] = {15,16,16,30,17,17,14,0};
const char characterOO[] = {10,21,21,17,17,17,10,0};
const char characterPP[] = {4,2,1,2,1,9,6,0};
const char characterDJ[] = {6,5,13,1,1,9,6,0};
const char characterRR[] = {2,4,8,16,30,17,17,0};
const char characterSS[] = {16,16,16,18,17,17,14,0};
const char characterTTT[]= {4,4,14,21,17,17,14,0};
const char characterUU[] = {10,21,5,1,1,17,14,0};
const char characterFF[] = {10,21,9,2,1,9,6,0};
const char characterQQ[] = {1,1,7,9,1,9,6,0};
const char characterGH[] = {10,21,17,16,8,22,1,0};
const char characterYY[] = {9,9,9,7,1,9,6,0};
const char characterSH[] = {10,21,1,15,17,17,14,0};
const char characterCH[] = {14,17,17,30,17,17,18,0};
const char characterCC[] = {17,17,18,17,17,17,14,0};
const char characterDZ[] = {1,1,1,15,17,17,14,0};
const char characterTS[] = {27,20,16,30,17,17,14,0};
const char characterTCH[]= {5,10,5,12,2,17,14,0};
const char characterXX[] = {16,16,16,30,17,17,14,0};
const char characterJJ[] = {4,12,6,4,2,17,14,0};
const char characterHH[] = {2,1,2,1,2,9,6,0};

const char characterSMAILIK[] = {4,2,25,1,1,25,2,4};


const char characterUpLeft [] = {7,15,31,31,31,31,31,31};
const char characterUpRight [] = {28,30,31,31,31,31,31,31};
const char characterDownRight[] = {31,31,31,31,31,31,30,28};
const char characterDownLeft [] = {31,31,31,31,31,31,15,7};
const char characterUp3 [] = {31,31,31,0,0,0,0,0};
const char characterDown3 [] = {0,0,0,0,0,31,31,31};
const char characterUp3Down2 [] = {31,31,31,0,0,0,31,31};
const char characterUp1Down3 [] = {31,0,0,0,0,31,31,31};



void LCD_WriteData(char dt)
{
 if(((dt>>3)&0x01)==1) { PORTA6_bit =1;} else { PORTA6_bit =0; }
 if(((dt>>2)&0x01)==1) { PORTA5_bit =1;} else { PORTA5_bit =0; }
 if(((dt>>1)&0x01)==1) { PORTA4_bit =1;} else { PORTA4_bit =0; }
 if(( dt&0x01) ==1) { PORTA3_bit =1;} else { PORTA3_bit =0; }
}

void LCD_ini(void)
{
 Delay_ms(10);
  PORTA2_bit =0;
 LCD_WriteData(3);
  PORTA1_bit =1;
 Delay_us(50);
  PORTA1_bit =0;
 Delay_ms(5);
 LCD_WriteData(3);
  PORTA1_bit =1;
 Delay_us(50);
  PORTA1_bit =0;
 Delay_ms(1);
 LCD_WriteData(3);
  PORTA1_bit =1;
 Delay_us(50);
  PORTA1_bit =0;
 Delay_us(200);
 LCD_WriteData(2);
  PORTA1_bit =1;
 Delay_us(50);
  PORTA1_bit =0;
 Delay_us(200);

 LCD_Command(0x28);
 Delay_ms(1);
 LCD_Command(0x28);
 Delay_ms(1);
 LCD_Command(0x0C);
 Delay_ms(1);
 LCD_Command(0x06);
 Delay_ms(1);
 LCD_Command(0x02);
 Delay_ms(1);
 LCD_Command(0x80);
 Delay_ms(1);
 LCD_Command(0x01);
 Delay_ms(2);

}


void LCD_Command(char dt)
{
  PORTA2_bit =0;
 LCD_WriteData(dt>>4);
  PORTA1_bit =1;
 Delay_us(35);
  PORTA1_bit =0;
 LCD_WriteData(dt);
  PORTA1_bit =1;
 Delay_us(35);
  PORTA1_bit =0;
}

void LCD_Data(char dt)
{
  PORTA2_bit =1;
 LCD_WriteData(dt>>4);
  PORTA1_bit =1;
 Delay_us(35);
  PORTA1_bit =0;
 LCD_WriteData(dt);
  PORTA1_bit =1;
 Delay_us(35);
  PORTA1_bit =0;
}

void LCD_Clear(void)
{
 LCD_Command(0x01);
 Delay_ms(2);
}

void LCD_SetPos(char ax, char ay)
{
 switch(ay)
 {
 case 0:
 LCD_Command(ax|0x80);
 Delay_ms(1);
 break;
 case 1:
 LCD_Command((0x40+ax)|0x80);
 Delay_ms(1);
 break;
 case 2:
 LCD_Command((0x14+ax)|0x80);
 Delay_ms(1);
 break;
 case 3:
 LCD_Command((0x54+ax)|0x80);
 Delay_ms(1);
 break;
 }
}

void LCD_SendChar(char ch, char ax, char ay)
{
 LCD_SetPos(ax, ay);
 LCD_Data(ch);
 Delay_us(50);
}

void LCD_String(char* st, char ax, char ay)
{
 char i=0;
 LCD_SetPos( ax, ay);
 while(st[i]!=0)
 {
 LCD_Data(st[i]);
 Delay_us(50);
 i++;
 }
}

void LCD_PutCustom(char ax, char ay, char location, const char *adata){
 char i;
 location &= 0x07;
 LCD_Command( 0x40  | (location << 3));
 for (i = 0; i<=7; i++){ LCD_Data((char)adata[i]); }
 LCD_SendChar(location,ax,ay);
}

void Charcho_Marcxniv (void){LCD_Command(0x1C);}
void Charcho_Marjvniv (void){LCD_Command(0x18);}
#line 365 "D:/Schedule_Device/Schedule_Device_Levani_Rusishvili_rev_002/LCD_DT.c"
void Test_Word (void)
{
LCD_PutCustom(0, 0, 0, characterMM );
LCD_PutCustom(1, 0, 1, characterAA );
LCD_PutCustom(2, 0, 2, characterRR );
LCD_PutCustom(3, 0, 3, characterTT );
LCD_PutCustom(4, 0, 1, characterAA );

LCD_PutCustom(7, 1, 4, characterCH );
LCD_PutCustom(8, 1, 5, characterXX );
LCD_PutCustom(9, 1, 6, characterLL );
LCD_PutCustom(10, 1, 1, characterAA );
LCD_PutCustom(11, 1, 2, characterRR );
LCD_PutCustom(12, 1, 3, characterTT );
LCD_PutCustom(13, 1, 1, characterAA );

LCD_PutCustom(15, 0, 7, characterSMAILIK );
}


void Big_Custom_Clock (char ax, char ay)
{
static unsigned char cntSec=40, cntMin=5, cntHrs=6;
static char stTemp=0;

 LCD_String(" ", (ax+7), ay);
 LCD_String(" ", (ax+7), (ay+1));

 if(cntSec++>=59){ cntSec=0;
 if(cntMin++>=59){ cntMin=0;
 if(cntHrs++>=23){ cntHrs=0; }
 }
 LCD_String("                    ", ax, ay);
 LCD_String("                    ", ax, (ay+1));
 }

 LCD_String("  ", (ax+15), (ay+1));
 LCD_String("  ", (ax+16), (ay+1));

 Big_Number_Write(ax, ay, cntHrs / 10);
 Big_Number_Write((ax+4), ay, cntHrs % 10);

 Big_Number_Write((ax+8), ay, cntMin / 10);
 Big_Number_Write((ax+12), ay, cntMin % 10);
 LCD_SendChar(48+(cntSec / 10), (ax+15), (ay+1));
 LCD_SendChar(48+(cntSec % 10), (ax+16), (ay+1));

 LCD_SendChar(0x2E, (ax+7), ay);
 LCD_SendChar(0x2E, (ax+7), (ay+1));

}

void Big_Number_1(char ax, char ay)
{
LCD_SendChar (0x20, ax, ay);
LCD_SendChar (0x20, ax, (ay+1));
LCD_PutCustom((ax+1), ay, 4, characterUp3);
LCD_SendChar (0x20, (ax+1), (ay+1));
LCD_PutCustom((ax+2), ay, 1, characterUpRight);
LCD_PutCustom((ax+2), (ay+1), 2, characterDownRight);
}

void Big_Number_2(char ax, char ay)
{
LCD_PutCustom(ax, ay, 6, characterUp3Down2);
LCD_PutCustom(ax, (ay+1), 3, characterDownLeft);
LCD_PutCustom((ax+1), ay, 6, characterUp3Down2);
LCD_PutCustom((ax+1), (ay+1), 7, characterUp1Down3);
LCD_PutCustom((ax+2), ay, 1, characterUpRight);
LCD_PutCustom((ax+2), (ay+1), 7, characterUp1Down3);
}

void Big_Number_3(char ax, char ay)
{
LCD_PutCustom(ax, ay, 4, characterUp3);
LCD_PutCustom(ax, (ay+1), 5, characterDown3);
LCD_PutCustom((ax+1), ay, 6, characterUp3Down2);
LCD_PutCustom((ax+1), (ay+1), 7, characterUp1Down3);
LCD_PutCustom((ax+2), ay, 1, characterUpRight);
LCD_PutCustom((ax+2), (ay+1), 2, characterDownRight);
}

void Big_Number_4(char ax, char ay)
{
LCD_PutCustom(ax, ay, 3, characterDownLeft);
LCD_SendChar (0x20, ax, (ay+1));
LCD_PutCustom((ax+1), ay, 5, characterDown3);
LCD_SendChar (0x20, (ax+1), (ay+1));
LCD_PutCustom((ax+2), ay, 1, characterUpRight);
LCD_PutCustom((ax+2), (ay+1), 2, characterDownRight);
}

void Big_Number_5(char ax, char ay)
{
LCD_PutCustom(ax, ay, 0, characterUpLeft);
LCD_PutCustom(ax, (ay+1), 7, characterUp1Down3);
LCD_PutCustom((ax+1), ay, 6, characterUp3Down2);
LCD_PutCustom((ax+1), (ay+1), 7, characterUp1Down3);
LCD_PutCustom((ax+2), ay, 6, characterUp3Down2);
LCD_PutCustom((ax+2), (ay+1), 2, characterDownRight);
}

void Big_Number_6(char ax, char ay)
{
LCD_PutCustom(ax, ay, 0, characterUpLeft);
LCD_PutCustom(ax, (ay+1), 3, characterDownLeft);
LCD_PutCustom((ax+1), ay, 6, characterUp3Down2);
LCD_PutCustom((ax+1), (ay+1), 7, characterUp1Down3);
LCD_PutCustom((ax+2), ay, 6, characterUp3Down2);
LCD_PutCustom((ax+2), (ay+1), 2, characterDownRight);
}

void Big_Number_7(char ax, char ay)
{
LCD_PutCustom(ax, ay, 4, characterUp3);
LCD_SendChar (0x20, ax, (ay+1));
LCD_PutCustom((ax+1), ay, 4, characterUp3);
LCD_SendChar (0x20, (ax+1), (ay+1));
LCD_PutCustom((ax+2), ay, 1, characterUpRight);
LCD_PutCustom((ax+2), (ay+1), 2, characterDownRight);
}

void Big_Number_8(char ax, char ay)
{
LCD_PutCustom(ax, ay, 0, characterUpLeft);
LCD_PutCustom(ax, (ay+1), 3, characterDownLeft);
LCD_PutCustom((ax+1), ay, 6, characterUp3Down2);
LCD_PutCustom((ax+1), (ay+1), 7, characterUp1Down3);
LCD_PutCustom((ax+2), ay, 1, characterUpRight);
LCD_PutCustom((ax+2), (ay+1), 2, characterDownRight);
}

void Big_Number_9(char ax, char ay)
{
LCD_PutCustom(ax, ay, 0, characterUpLeft);
LCD_PutCustom(ax, (ay+1), 7, characterUp1Down3);
LCD_PutCustom((ax+1), ay, 6, characterUp3Down2);
LCD_PutCustom((ax+1), (ay+1), 7, characterUp1Down3);
LCD_PutCustom((ax+2), ay, 1, characterUpRight);
LCD_PutCustom((ax+2), (ay+1), 2, characterDownRight);
}

void Big_Number_0(char ax, char ay)
{
LCD_PutCustom(ax, ay, 0, characterUpLeft);
LCD_PutCustom(ax, (ay+1), 3, characterDownLeft);
LCD_PutCustom((ax+1), ay, 4, characterUp3);
LCD_PutCustom((ax+1), (ay+1), 5, characterDown3);
LCD_PutCustom((ax+2), ay, 1, characterUpRight);
LCD_PutCustom((ax+2), (ay+1), 2, characterDownRight);
}

void Big_Number_Write(char ax, char ay, char number)
{
 switch(number)
 {
 case 0:{
 Big_Number_0(ax,ay); }
 break;
 case 1: {
 Big_Number_1(ax,ay); }
 break;;
 case 2: {
 Big_Number_2(ax,ay); }
 break;
 case 3: {
 Big_Number_3(ax,ay); }
 break;
 case 4: {
 Big_Number_4(ax,ay); }
 break;
 case 5: {
 Big_Number_5(ax,ay); }
 break;
 case 6: {
 Big_Number_6(ax,ay); }
 break;
 case 7: {
 Big_Number_7(ax,ay); }
 break;
 case 8: {
 Big_Number_8(ax,ay); }
 break;
 case 9: {
 Big_Number_9(ax,ay); }
 break;
 };
}
