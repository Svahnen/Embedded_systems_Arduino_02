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
    int time2 = 0;

    while (1) {
        // OCF0B | (1<< TIFR0))
        // Instead of bit_is_set it should be possible to shift the bit all the way to the right and see if its == 1
        if (bit_is_set(TIFR0, OCF0B)) {  // Look at overflow bit, 16 000 000 / 1024
            time1++;
            time2++;
            TIFR0 |= (1 << OCF0B);
        }
        if (time1 == 15625) {  // Count seconds
            // LED_toggle(RED);
            time1 = 0;
        }
        if (time2 == 625) {  // Count 250ms
            LED_toggle(RED);
            time2 = 0;
        }
    }
}
