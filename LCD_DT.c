//==============================================================================
//#include       "M8_328.h"   // Mtavar Failshi Maqvs Mtavari Definiciebi Da Magitom Vabav Amas
#include         "built_in.h"
#include         "LCD_DT.h"
//==============================================================================
//------------------------------------------------
const char characterAA[] = {8,8,4,2,1,17,14,0};                                 // 1 A // A,B,L,N,S,I,M,D,E,R,T,SH,T,F
const char characterBB[] = {8,12,4,14,17,17,14,0};                              // 0 B // 0-64 1-72 2-80 3-88 4-96 5-104 6-112 7-120
const char characterGG[] = {12,18,4,10,17,17,14,0};                             // 0 G //
const char characterDD[] = {14,17,17,30,16,14,1,0};                             // 3 D //
const char characterEE[] = {14,17,1,1,17,17,14,0};                              // 4 E // 6,9,1,1,9,9,6,0
const char characterVV[] = {14,17,1,2,17,17,14,0};                              //   V  // 6,9,1,2,9,9,6,0
const char characterZZ[] = {12,18,12,6,9,9,6,0};                                //   Z
const char characterTT[] = {10,21,21,21,21,21,9,0};                             // 7 T //
const char characterII[] = {14,17,17,17,17,17,10,0};                            // 5 I // 3) MIADE BARATI
const char characterKK[] = {1,1,2,1,9,9,6,0};                                   // 4 K //
const char characterLL[] = {14,17,17,16,8,20,2,0};                              // 2 L //
const char characterMM[] = {14,17,1,15,17,17,14,0};                             // 2 M // 4) NASHTI BARATZE
const char characterNN[] = {15,16,16,30,17,17,14,0};                            // 2 N // 1) TARIFI  LARI
const char characterOO[] = {10,21,21,17,17,17,10,0};                            //   O
const char characterPP[] = {4,2,1,2,1,9,6,0};                                   //   P
const char characterDJ[] = {6,5,13,1,1,9,6,0};                                  //   DJ
const char characterRR[] = {2,4,8,16,30,17,17,0};                               // 6 R // 2,4,8,16,30,17,17,0  4,8,16,16,30,18,18,0
const char characterSS[] = {16,16,16,18,17,17,14,0};                            // 4 S // 2) KETILI MGZAVROBA ???
const char characterTTT[]= {4,4,14,21,17,17,14,0};                              // 4 TT//
const char characterUU[] = {10,21,5,1,1,17,14,0};                               //   U
const char characterFF[] = {10,21,9,2,1,9,6,0};                                 // 0 F //
const char characterQQ[] = {1,1,7,9,1,9,6,0};                                   //   QQ
const char characterGH[] = {10,21,17,16,8,22,1,0};                              //   GH
const char characterYY[] = {9,9,9,7,1,9,6,0};                                   //   YY
const char characterSH[] = {10,21,1,15,17,17,14,0};                             // 4 SH//
const char characterCH[] = {14,17,17,30,17,17,18,0};                            //   CH
const char characterCC[] = {17,17,18,17,17,17,14,0};                            //   CC
const char characterDZ[] = {1,1,1,15,17,17,14,0};                               //   DZ
const char characterTS[] = {27,20,16,30,17,17,14,0};                            //   TS
const char characterTCH[]= {5,10,5,12,2,17,14,0}; //{5,10,4,14,1,17,14,0};  //{5,10,5,4,10,17,14,0};                               //   TCH
const char characterXX[] = {16,16,16,30,17,17,14,0};                            //   XX
const char characterJJ[] = {4,12,6,4,2,17,14,0};                                //   DJ
const char characterHH[] = {2,1,2,1,2,9,6,0};                                   //   HH
//------------------------------------------------
const char characterSMAILIK[] = {4,2,25,1,1,25,2,4};
//------------------------------------------------
//================================================ big number cheracters
const char characterUpLeft   [] = {7,15,31,31,31,31,31,31};                     // 0
const char characterUpRight  [] = {28,30,31,31,31,31,31,31};                    // 1
const char characterDownRight[] = {31,31,31,31,31,31,30,28};                    // 2
const char characterDownLeft [] = {31,31,31,31,31,31,15,7};                     // 3
const char characterUp3      [] = {31,31,31,0,0,0,0,0};                         // 4
const char characterDown3    [] = {0,0,0,0,0,31,31,31};                         // 5
const char characterUp3Down2 [] = {31,31,31,0,0,0,31,31};                       // 6
const char characterUp1Down3 [] = {31,0,0,0,0,31,31,31};                        // 7
//==============================================================================
//==============================================================================
#ifdef LCD_Parallel
void LCD_WriteData(char dt)
{
        if(((dt>>3)&0x01)==1)  {PORT_D7=1;} else {PORT_D7=0; }
        if(((dt>>2)&0x01)==1)  {PORT_D6=1;} else {PORT_D6=0; }
        if(((dt>>1)&0x01)==1)  {PORT_D5=1;} else {PORT_D5=0; }
        if(( dt&0x01)    ==1)  {PORT_D4=1;} else {PORT_D4=0; }
}
//------------------------------------------------
void LCD_ini(void)
{
        Delay_ms(10);
        PORT_RS=0;
        LCD_WriteData(3);  //1  //<<<<<<<
        PORT_E=1;
        Delay_us(50);
        PORT_E=0;
        Delay_ms(5);
        LCD_WriteData(3);  //2
        PORT_E=1;
        Delay_us(50);
        PORT_E=0;
        Delay_ms(1);
        LCD_WriteData(3);  //3
        PORT_E=1;
        Delay_us(50);
        PORT_E=0;
        Delay_us(200);
        LCD_WriteData(2);  //4
        PORT_E=1;
        Delay_us(50);
        PORT_E=0;
        Delay_us(200);   //<<<<<<<
//<<<<<kamandebi
        LCD_Command(0x28);  //4 bit 2 xazi 5x8-ze  // 0x28 0b00101000
        Delay_ms(1);
        LCD_Command(0x28);  //4 bit 2 xazi 5x8-ze  // 0x28  // kidev erTxel garantirebulad (araa aucilebeli)
        Delay_ms(1);
        LCD_Command(0x0C);  //Display On Cursos off Blink off
        Delay_ms(1);
        LCD_Command(0x06);  //Marcxnidan Marjvniv
        Delay_ms(1);
        LCD_Command(0x02);  //kursori nulze
        Delay_ms(1);
        LCD_Command(0x80);  // DDRAM-ze adresacia 0x40 CGRAM-ze
        Delay_ms(1);
        LCD_Command(0x01);   //Display-s washla
        Delay_ms(2);

}

//------------------------------------------------
void LCD_Command(char dt)
{
        PORT_RS=0;                   //delay();
        LCD_WriteData(dt>>4);        //delay();
        PORT_E=1;
        Delay_us(35);                //HAL_Delay(1000);
        PORT_E=0;                    //delay();
        LCD_WriteData(dt);           //delay();
        PORT_E=1;
        Delay_us(35);                //HAL_Delay(1000);
        PORT_E=0;
}
//------------------------------------------------------------------------------
void LCD_Data(char dt)
{
        PORT_RS=1;                   //delay();
        LCD_WriteData(dt>>4);        //delay();
        PORT_E=1;
        Delay_us(35);                //HAL_Delay(1000);
        PORT_E=0;                    //delay();
        LCD_WriteData(dt);           //delay();
        PORT_E=1;
        Delay_us(35);                //HAL_Delay(1000);
        PORT_E=0;
}
//------------------------------------------------
void LCD_Clear(void)
{
        LCD_Command(0x01);
        Delay_ms(2);
}
//------------------------------------------------
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
//------------------------------------------------
void LCD_SendChar(char ch, char ax, char ay) // <<<<<
{
        LCD_SetPos(ax, ay);                        // <<<<<
        LCD_Data(ch);
        Delay_us(50);
}
//------------------------------------------------
void LCD_String(char* st, char ax, char ay)  //  <<<<<<<
{
        char i=0;
        LCD_SetPos( ax, ay);                       // <<<<<
        while(st[i]!=0)
        {
                LCD_Data(st[i]);
                Delay_us(50);
                i++;
        }
}
//------------------------------------------------------------------------------
void LCD_PutCustom(char ax, char ay, char location, const char *adata){
        char i;
        location &= 0x07;                                  // DAZGVEVA-RATA 7-Ze Meti Ar Moxvdes
        LCD_Command(_LCD_SETCGRAMADDR | (location << 3));  // Rata 8-8 Baitit Gadaaxtes Adresebs    6 Tu Semova avtomaturad dajdeba 112-e addressze >> I2C_LCD_Cmd(112);
        for (i = 0; i<=7; i++){ LCD_Data((char)adata[i]); }
        LCD_SendChar(location,ax,ay);
}
//------------------------------------------------------------------------------
void Charcho_Marcxniv (void){LCD_Command(0x1C);}  // ekrani marcxniv midis, gamosaxuleba marjvniv imaleba
void Charcho_Marjvniv (void){LCD_Command(0x18);}  // ekrani marjvniv midis, gamosaxuleba marcxniv imaleba
#endif
//------------------------------------------------------------------------------
//==============================================================================
//==============================================================================
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//==============================================================================
//==============================================================================
//------------------------------------------------------------------------------
#ifdef  LCD_I2C_Hardware
void TWI_TimeoutCallback(char errorCode) {
   if (errorCode == _TWI_TIMEOUT_RD) {
     // do something if timeout is caused during read
   }
   if (errorCode == _TWI_TIMEOUT_WR) {
     // do something if timeout is caused during write
   }
   if (errorCode == _TWI_TIMEOUT_START) {
     // do something if timeout is caused during start
   }
}
//------------------------------------------------------------------------------
void I2C_LCD_Init(void)
{
    char rs = 0x00;                                                             // TWI_Init(100000);
                                                                                TWI_SetTimeoutCallback(1000, TWI_TimeoutCallback);
    TWI_Start();
    TWI_Write(LCD_ADDR);
    Delay_ms(30);

    TWI_Write(0x30 | rs | 0x04 | 0x08);
    Delay_us(50);
    TWI_Write(0x30 | rs | 0x00 | 0x08);
    Delay_ms(10);

    TWI_Write(0x30 | rs | 0x04 | 0x08);
    Delay_us(50);
    TWI_Write(0x30 | rs | 0x00 | 0x08);
    Delay_ms(10);

    TWI_Write(0x30 | rs | 0x04 | 0x08);
    Delay_us(50);
    TWI_Write(0x30 | rs | 0x00 | 0x08);
    Delay_ms(10);

    TWI_Write(0x20 | rs | 0x04 | 0x08);
    Delay_us(50);
    TWI_Write(0x20 | rs | 0x00 | 0x08);
    TWI_Stop();

    Delay_ms(10);

    I2C_LCD_Cmd(0x28);
    I2C_LCD_Cmd(0x06);
    I2C_LCD_Cmd(_LCD_TURN_ON);
    I2C_LCD_Cmd(_LCD_CLEAR);
}
//------------------------------------------------------------------------------
void I2C_LCD_Cmd(char out_char) {
    char hi_n, lo_n;
    char rs = 0x00;

    hi_n = out_char & 0xF0;
    lo_n = (out_char << 4) & 0xF0;
                                                                                TWI_SetTimeoutCallback(1000, TWI_TimeoutCallback);
    TWI_Start();
    TWI_Write(LCD_ADDR);
    TWI_Write(hi_n | rs | 0x04 | 0x08);
    Delay_us(50);
    TWI_Write(hi_n | rs | 0x00 | 0x08);
    Delay_us(100);
    TWI_Write(lo_n | rs | 0x04 | 0x08);
    Delay_us(50);
    TWI_Write(lo_n | rs | 0x00 | 0x08);
    TWI_Stop();
    if(out_char == 0x01)Delay_ms(2);
}
//------------------------------------------------------------------------------
void I2C_LCD_Chr(char row, char column, char out_char)
{
    char hi_n, lo_n;
    char rs = 0x01;

    switch(row){

        case 1:
        I2C_LCD_Cmd(0x80 + (column - 1));
        break;
        case 2:
        I2C_LCD_Cmd(0xC0 + (column - 1));
        break;
        case 3:
        I2C_LCD_Cmd(0x94 + (column - 1));
        break;
        case 4:
        I2C_LCD_Cmd(0xD4 + (column - 1));
        break;
    };
    hi_n = out_char & 0xF0;
    lo_n = (out_char << 4) & 0xF0;
                                                                                TWI_SetTimeoutCallback(1000, TWI_TimeoutCallback);
    TWI_Start();
    TWI_Write(LCD_ADDR);
    TWI_Write(hi_n | rs | 0x04 | 0x08);
    Delay_us(50);
    TWI_Write(hi_n | rs | 0x00 | 0x08);
    Delay_us(100);
    TWI_Write(lo_n | rs | 0x04 | 0x08);
    Delay_us(50);
    TWI_Write(lo_n | rs | 0x00 | 0x08);
    TWI_Stop();
}
//------------------------------------------------------------------------------
void I2C_LCD_Chr_Cp(char out_char)                                              // DATAS GADAVCEMT AQ !!!!!
{
    char hi_n, lo_n;
    char rs = 0x01;

    hi_n = out_char & 0xF0;
    lo_n = (out_char << 4) & 0xF0;
                                                                                TWI_SetTimeoutCallback(1000, TWI_TimeoutCallback);
    TWI_Start();
    TWI_Write(LCD_ADDR);
    TWI_Write(hi_n | rs | 0x04 | 0x08);
    Delay_us(50);
    TWI_Write(hi_n | rs | 0x00 | 0x08);
    Delay_us(100);
    TWI_Write(lo_n | rs | 0x04 | 0x08);
    Delay_us(50);
    TWI_Write(lo_n | rs | 0x00 | 0x08);
    TWI_Stop();
}
//------------------------------------------------------------------------------
void I2C_LCD_Out(char row,char col,char *text) {while(*text) {I2C_LCD_Chr(row,col++,*text++);} }
//------------------------------------------------------------------------------
void I2C_LCD_Out_Cp(char *text) { while(*text) { I2C_LCD_Chr_Cp(*text++); }  }
//------------------------------------------------------------------------------
void I2C_LCD_cursor(char row, char col) {
    char position = 0x80;  // Start address of the LCD DDRAM
    if (row == 1) {
        position += 0x40;     // Address of the second row
    }
    position += col;         // Add the column offset
    I2C_LCD_Cmd(position | 0x80); // Send the command to set cursor position
}
//------------------------------------------------------------------------------
void I2C_LCD_PutCustom(char row_pos, char col_pos, char location, const char *cosChar){
        char i;
        location &= 0x07;                                  // DAZGVEVA-RATA 7-Ze Meti Ar Moxvdes
        I2C_LCD_Cmd(_LCD_SETCGRAMADDR | (location << 3));  // Rata 8-8 Baitit Gadaaxtes Adresebs    6 Tu Semova avtomaturad dajdeba 112-e addressze >> I2C_LCD_Cmd(112);
        for (i = 0; i<=7; i++){ I2C_LCD_Chr_Cp(cosChar[i]); }
        I2C_LCD_Chr(row_pos, col_pos, location);
}
//------------------------------------------------------------------------------
//==============================================================================
#endif
//==============================================================================
//==============================================================================// Tu Software I2C-s Gamoviyenebt  Saltis Shesamowmeblad Gamoviyenot Es
#ifdef  LCD_I2C_Software
char SWTWI_Error_Handler (void)                                                 // 0- OK    1- Error
{char st=0;
st=0;
SWTWI_SCL_DDR=1;      SWTWI_SCL_PORT=0;
SWTWI_SDA_DDR=0;
Delay_us(25);
if ( SWTWI_SCL_PIN!=0 || SWTWI_SDA_PIN !=1  )  {st=1;   return 1; }    // TWI BUS Error
SWTWI_SCL_DDR=0;
SWTWI_SDA_DDR=1;      SWTWI_SDA_PORT=0;
Delay_us(25);
if ( SWTWI_SCL_PIN!=1 || SWTWI_SDA_PIN !=0  )  {st=1;   return 1; }    // TWI BUS Error
st=0;
return st;
}
#endif
//==============================================================================
//==============================================================================
void Test_Word (void)
{
LCD_PutCustom(0, 0, 0, characterMM );
LCD_PutCustom(1, 0, 1, characterAA );
LCD_PutCustom(2, 0, 2, characterRR );
LCD_PutCustom(3, 0, 3, characterTT );
LCD_PutCustom(4, 0, 1, characterAA );

LCD_PutCustom(7,  1, 4, characterCH );
LCD_PutCustom(8,  1, 5, characterXX );
LCD_PutCustom(9,  1, 6, characterLL );
LCD_PutCustom(10, 1, 1, characterAA );
LCD_PutCustom(11, 1, 2, characterRR );
LCD_PutCustom(12, 1, 3, characterTT );
LCD_PutCustom(13, 1, 1, characterAA );
//
LCD_PutCustom(15, 0, 7, characterSMAILIK );
}
//==============================================================================
//==============================================================================
void Big_Custom_Clock (char ax, char ay)
{
static unsigned char            cntSec=40, cntMin=5, cntHrs=6;
static char                     stTemp=0;
//============================================================================== Time
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
//==============================================================================
}
//==============================================================================
void Big_Number_1(char ax, char ay)
{
LCD_SendChar  (0x20, ax, ay);
LCD_SendChar  (0x20, ax, (ay+1));
LCD_PutCustom((ax+1), ay, 4, characterUp3);
LCD_SendChar  (0x20, (ax+1), (ay+1));
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
LCD_SendChar  (0x20, ax, (ay+1));
LCD_PutCustom((ax+1), ay, 5, characterDown3);
LCD_SendChar  (0x20, (ax+1), (ay+1));
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
LCD_SendChar  (0x20, ax, (ay+1));
LCD_PutCustom((ax+1), ay, 4, characterUp3);
LCD_SendChar  (0x20, (ax+1), (ay+1));
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
//==============================================================================
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
//==============================================================================
//==============================================================================