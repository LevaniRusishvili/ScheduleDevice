#define    LCD_Parallel
////#define    LCD_I2C_Hardware
////#define    LCD_I2C_Software
//==============================================================================
#define  DDR_RS               DDA2_bit
#define  DDR_E                DDA1_bit
#define  DDR_D4               DDA3_bit
#define  DDR_D5               DDA4_bit
#define  DDR_D6               DDA5_bit
#define  DDR_D7               DDA6_bit

#define  PORT_RS              PORTA2_bit
#define  PORT_E               PORTA1_bit
#define  PORT_D4              PORTA3_bit
#define  PORT_D5              PORTA4_bit
#define  PORT_D6              PORTA5_bit
#define  PORT_D7              PORTA6_bit

#define  LCD_LED_DDR          DDA7_bit
#define  LCD_LED_PORT         PORTA7_bit
//=================================================================Paralel_LCD==
/* Commands*/
#define HD44780_CLEARDISPLAY        0x01
#define HD44780_RETURNHOME          0x02
#define HD44780_ENTRYMODESET        0x04
#define HD44780_DISPLAYCONTROL      0x08
#define HD44780_CURSORSHIFT         0x10
#define HD44780_FUNCTIONSET         0x20
#define HD44780_SETCGRAMADDR        0x40
#define HD44780_SETDDRAMADDR        0x80
/* Flags for display entry mode */
#define HD44780_ENTRYRIGHT          0x00
#define HD44780_ENTRYLEFT           0x02
#define HD44780_ENTRYSHIFTINCREMENT 0x01
#define HD44780_ENTRYSHIFTDECREMENT 0x00
/* Flags for display on/off control */
#define HD44780_DISPLAYON           0x04
#define HD44780_CURSORON            0x02
#define HD44780_BLINKON             0x01
/* Flags for display/cursor shift */
#define HD44780_DISPLAYMOVE         0x08
#define HD44780_CURSORMOVE          0x00
#define HD44780_MOVERIGHT           0x04
#define HD44780_MOVELEFT            0x00
/* Flags for function set */
#define HD44780_8BITMODE            0x10
#define HD44780_4BITMODE            0x00
#define HD44780_2LINE               0x08
#define HD44780_1LINE               0x00
#define HD44780_5x10DOTS            0x04
#define HD44780_5x8DOTS             0x00
////////////////////////////////////////////////////////////////////////////////
//===================================================================TWI_LCD====
#define _LCD_CLEAR              0x01     //Clear display
#define _LCD_RETURN_HOME        0x02     //Return cursor to home position, returns a shifted display to
#define _LCD_FIRST_ROW          0x80     //Move cursor to the 1st row
#define _LCD_SECOND_ROW         0xC0     //Move cursor to the 2nd row
#define _LCD_THIRD_ROW          0x94     //Move cursor to the 3rd row
#define _LCD_FOURTH_ROW         0xD4     //Move cursor to the 4th row
#define _LCD_SETCGRAMADDR       0x40
#define _LCD_SETDDRAMADDR       0x80
                                         //its original position. Display data RAM is unaffected.
#define _LCD_CURSOR_OFF         0x0C     //Turn off cursor
#define _LCD_UNDERLINE_ON       0x0E     //Underline cursor on
#define _LCD_BLINK_CURSOR_ON    0x0F     //Blink cursor on
#define _LCD_MOVE_CURSOR_LEFT   0x10     //Move cursor left without changing display data RAM
#define _LCD_MOVE_CURSOR_RIGHT  0x14     //Move cursor right without changing display data RAM
#define _LCD_TURN_ON            0x0C     //Turn Lcd display Ðg
#define _LCD_TURN_OFF           0x08     //Turn Lcd display off
#define _LCD_SHIFT_LEFT         0x18     //Shift display left without changing display data RAM
#define _LCD_SHIFT_RIGHT        0x1E     //Shift display right without changing display data RAM
// LCD Definitions
#define LCD_ADDR 0x4E                    // 0x4C  0x4A  0x48  0x46  0x44 0x42 0x40
//==============================================================================
#define  SWTWI_SCL_PORT             PORTD0_bit
#define  SWTWI_SDA_PORT             PORTD1_bit
#define  SWTWI_SCL_PIN              PIND0_bit
#define  SWTWI_SDA_PIN              PIND1_bit
#define  SWTWI_SCL_DDR              DDD0_bit
#define  SWTWI_SDA_DDR              DDD1_bit

//==============================================================================
//------------------------------------------------------------PARALELURI--------
void LCD_WriteData(char dt);
void LCD_ini(void);
void LCD_Clear(void);
void LCD_SendChar(char ch, char ax, char ay);  // <<<
void LCD_String(char* st, char ax, char ay);   // <<<
void LCD_SetPos(char ax, char ay);
void LCD_Command(char dt);
void LCD_Data(char dt);
void LCD_PutCustom(char ax, char ay, char location,  const char *adata);
void Charcho_Marcxniv (void);
void Charcho_Marjvniv (void);
//==============================================================I2C_Hardware====
void TWI_TimeoutCallback(char errorCode);
void I2C_LCD_Init(void);
void I2C_LCD_Cmd(char out_char);
void I2C_LCD_Chr(char row, char column, char out_char);
void I2C_LCD_Chr_Cp(char out_char);
void I2C_LCD_Out(char row,char col,char *text);
void I2C_LCD_Out_Cp(char *text);
void I2C_LCD_cursor(char row, char col);
void I2C_LCD_PutCustom(char row_pos, char col_pos, char location, const char *cosChar);
//==============================================================I2C_Software====
char SWTWI_Error_Handler (void);
//==============================================================================
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
//------------------------------------------------------------------------------
void Test_Word (void);
//------------------------------------------------