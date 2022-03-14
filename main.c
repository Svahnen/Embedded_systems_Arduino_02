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
    int time3 = 0;

    while (1) {
        // OCF0B | (1<< TIFR0))
        // Instead of bit_is_set it should be possible to shift the bit all the way to the right and see if its == 1
        if (bit_is_set(TIFR0, OCF0B)) {  // Look at overflow bit, 16 000 000 / 1024
            time1++;
            time2++;
            TIFR0 |= (1 << OCF0B);  // Reset bit
        }
        if (time1 == 15625) {  // Count seconds, 16 000 000 Hz / 1024 = 15625 Hz
            // LED_toggle(RED);
            time1 = 0;
        }
        if (time2 == 156) {  // Count ~10ms, 1 % of 15625 Hz ~156 Hz (1000ms for one second, 10ms = 1% of 1000).
            time3++;
            time2 = 0;
        }
        if (time3 == 10) {  // Count ~100ms, ~10ms * 10 = ~100ms
            LED_toggle(RED);
            time3 = 0;
        }
    }
}
