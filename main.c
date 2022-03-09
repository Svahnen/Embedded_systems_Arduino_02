#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <util/delay.h>

#include "led.h"
#include "serial.h"
#include "timer.h"

int main(void) {
    uart_init();

    while (1) {
        /* remove this once you've verified it works */
        printf_P(PSTR("Hello there\n"));
        _delay_ms(1000);
    }
}
