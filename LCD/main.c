#include <avr/io.h>
#include <lcd.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#define F_CPU 16000000


int main(void)
{
    /*initialisiert das Display
    *   4 Möglichkeiten:
    *       LCD_DISP_OFF            display off
    *       LCD_DISP_ON             display on, cursor off
    *       LCD_DISP_ON_CURSOR      display on, cursor on
    *       LCD_DISP_CURSOR_BLINK   display on, cursor on flashingn
    */
    lcd_init(LCD_DISP_ON);
    //Gibt Text auf dem LCD aus
    lcd_puts("Hello World!\n");
    _delay_ms(1000);

    while(1)
    {
        for(int i = 0; i<20;i++){
            //cleared den Screen
            lcd_clrscr();
            //verändert die X und X Position des Cursors
            lcd_gotoxy(i,0);
            lcd_puts("Hello World!\n");
            _delay_ms(10000);
        }
    }
}