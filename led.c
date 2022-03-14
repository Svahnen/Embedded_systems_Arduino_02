#include "led.h"

#include <avr/io.h>

void LED_init() {
    DDRB &= ~(1 << BLUE);  // Set PB1 (Pin9, blue LED on the shield) in DDRB (Port B Data Direction Register) to 0, this makes PB1 an input so we can jump to a interupt instead
    DDRB &= ~(1 << GREEN);
    DDRB &= ~(1 << RED);
    // OC0A_PIN
    DDRB |= (1 << PD6);  // Set OC0A to output
}

void LED_toggle(int LED) {
    PORTB ^= (1 << LED);
}
