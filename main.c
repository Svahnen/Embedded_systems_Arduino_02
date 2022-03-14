#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <util/delay.h>

#include "led.h"
#include "serial.h"
#include "timer.h"

int main(void) {
    timer_init();
    uart_init();
    LED_init();

    while (1) {
        OCR0A = 255;
        _delay_ms(1000);
        OCR0A = 100;
        _delay_ms(1000);
        OCR0A = 0;
        _delay_ms(1000);
    }
}
