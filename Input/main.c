#define F_CPU 16000000

#include <stdio.h>
#include <util/delay.h>
#include <avr/io.h>

int main(void){
    DDRB = 0x02;
    while(1){
        if(PINB & (1<<PINB0))
        {
           PORTB ^= 1 << PORTB1;
        }
        _delay_ms(100);
    }
    _delay_ms(100);
    return 0;
}