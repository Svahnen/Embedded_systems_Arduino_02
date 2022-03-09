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

    LED_toggle(RED);
    while (1) {
        if (TCNT0 >= 255) {
            LED_toggle(RED);
            TCNT0 = 0;  // reset counter
        }
    }
}
