#define F_CPU 16000000

#include <stdio.h>
#include <util/delay.h>
#include <avr/io.h>

int main(void){
    DDRB = 0xFF;
    while (1)
    {
        PORTB = 0xFF;
        _delay_ms(50);
        PORTB = 0x00;
        _delay_ms(50);
    }
    return 0;
}