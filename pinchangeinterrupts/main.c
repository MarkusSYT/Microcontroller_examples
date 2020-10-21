#define F_CPU 16000000

#include <stdio.h>
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

void init_PinChangeInterrupts(void);
 
int t1_pressed = 0;
int t2_pressed = 0;
int t3_pressed = 0;
int t4_pressed = 0;
 
 
int main(void)
{
DDRD = 0b00100000;                                        //PIND5 = Ausgang für LED, PIND6 und PIND7 sind 2 Taster-Eingänge
DDRB = 0b00000000;                                        //PINB0 und PINB1 sind zwei weitere Taster-Eingänge
 
PORTB = (1<<PINB0) | (1<<PINB1);                          //Hier werden die PULLUPS aktiviert
PORTD = (1<<PIND6) | (1<<PIND7);                          //Hier werden die PULLUPS aktiviert

init_PinChangeInterrupts();                               //Hier werden die Interrupts initialisiert          
sei();                                                    //Aktivieren der Interrupts
                                                       
while (1){};
}
 
 
ISR(PCINT0_vect)
{  
    if (!(PIND & (1<<PIND7)))                //Taster von PIND7 wurde gedrückt
    {
        if (t1_pressed == 0)            //Wenn die LED zuvor ausgeschalten war
            {  
                PORTD |= (1<<PIND5);
                t1_pressed >= 1;
                _delay_ms(100);
            }
        else if (t1_pressed >= 1)        //Wenn die LED zuvor eingeschalten war
            {
                PORTD &= ~(1<<PIND5);
                t1_pressed = 0;
                _delay_ms(100);
            }
    }
 
    if (!(PIND & (1<<PIND6)))                //Taster von PIND6 wurde gedrückt
    {
        if (t2_pressed == 0)            //Wenn die LED zuvor ausgeschalten war
            {
                PORTD |= (1<<PIND5);
                t2_pressed = 1;
                _delay_ms(100);
            }
        else if (t2_pressed >= 1)        //Wenn die LED zuvor eingeschalten war
            {
                PORTD &= ~(1<<PIND5);
                t2_pressed = 0;
                _delay_ms(100);
            }
    }
 
    if (!(PINB & (1<<PINB0)))                //Taster von PIND6 wurde gedrückt
    {
        if (t3_pressed == 0)            //Wenn die LED zuvor ausgeschalten war
            {
                PORTD |= (1<<PIND5);
                t3_pressed = 1;
                _delay_ms(100);
            }
        else if (t3_pressed >= 1)        //Wenn die LED zuvor eingeschalten war
            {
                PORTD &= ~(1<<PIND5);
                t3_pressed = 0;
                _delay_ms(100);
            }
    }
 
    if (!(PINB & (1<<PINB1)))                //Taster von PINDB1 wurde gedrückt
    {
        if (t4_pressed == 0)            //Wenn die LED zuvor ausgeschalten war
            {  
                PORTD |= (1<<PIND5);
                t4_pressed = 1;
                _delay_ms(100);
            }
        else if (t4_pressed >= 1)        //Wenn die LED zuvor eingeschalten war
            {
                PORTD &= ~(1<<PIND5);
                t4_pressed = 0;
                _delay_ms(100);
            }
    }
}
 
void init_PinChangeInterrupts(void)
{
    PCICR  |= (1<<PCIE2) | (1<<PCIE0);            //Die Pins 23 bis 16 werden als Interrupts hergenommen, als auch die pins 0 bis 7
    PCMSK2 |= (1<<PCINT23) | (1<<PCINT22);        //Hier werden die Interrupts für die jeweiligen Pins enabled
    PCMSK0 |= (1<<PCINT0) | (1<<PCINT1);        //Hier das gleiche wie obige Zeile
}