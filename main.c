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
    int time1 = 0;

    while (1) {
        // Instead of bit_is_set it should be possible to shift the bit all the way to the right and see if its == 1
        if (bit_is_set(TIFR0, OCF0A)) {  // Look at compare flag, 16 000 000 / 1024
            time1++;
            TIFR0 = (1 << OCF0A);  // Reset bit, we use = here since we clear the bit by setting 1 even tho its already 1, and if other flags in this register where 1 they would also be reset if we used |=
        }
        if (time1 == 10) {
            LED_toggle(RED);
            time1 = 0;
        }
    }
}
