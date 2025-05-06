#include "pico/stdlib.h"
#include "buttons.h"
#include "config.h"
#include <cstdio>

int main() {
    // Initialize the standard library
    stdio_init_all();

    // Initialize buttons
    init_buttons();

    while (true) {
        // Check if buttons are pressed
        if (is_button_pressed(BUTTON1_PIN)) {
            printf("Button 1 pressed\n");
            sleep_ms(200); // debounce delay
        }

        if (is_button_pressed(BUTTON2_PIN)) {
            printf("Button 2 pressed\n");
            sleep_ms(200); // debounce delay
        }

        if (is_button_pressed(BUTTON3_PIN)) {
            printf("Button 3 pressed\n");
            sleep_ms(200); // debounce delay
        }
        
        sleep_ms(10); // Small delay to avoid busy-waiting
    }
}