#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <util/delay.h>

#include "led.h"
#include "serial.h"
#include "timer.h"

int main(void) {
    timer0_init();
    timer2_init();
    uart_init();
    LED_init();

    while (1) {
        if (bit_is_set(TIFR2, OCF2A)) {
            OCR0A = simple_ramp();
            TIFR2 = (1 << OCF2A);
        }
    }
}
