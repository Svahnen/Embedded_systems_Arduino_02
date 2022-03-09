#include "led.h"

#include <avr/io.h>

void LED_init() {
    DDRB |= (1 << BLUE);  // Set PB1 (Pin9, blue LED on the shield) in DDRB (Port B Data Direction Register) to 1, this makes PB1 an output
    DDRB |= (1 << GREEN);
    DDRB |= (1 << RED);

    PORTB |= (1 << BLUE);  // Set PB1 in PORTB to initial 1 (high) so it is off
    PORTB |= (1 << GREEN);
    PORTB |= (1 << RED);
}

void LED_toggle(int LED) {
    PORTB ^= (1 << LED);
}
