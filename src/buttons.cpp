#include "buttons.h"
#include "config.h"
#include "pico/stdlib.h"

void init_buttons() {
    // Initialize GPIO pins for buttons
    gpio_init(BUTTON1_PIN);
    gpio_set_dir(BUTTON1_PIN, GPIO_IN);
    gpio_pull_up(BUTTON1_PIN);

    gpio_init(BUTTON2_PIN);
    gpio_set_dir(BUTTON2_PIN, GPIO_IN);
    gpio_pull_up(BUTTON2_PIN);

    gpio_init(BUTTON3_PIN);
    gpio_set_dir(BUTTON3_PIN, GPIO_IN);
    gpio_pull_up(BUTTON3_PIN);
}

bool is_button_pressed(int gpio) {
    // Check if the button is pressed (active low)
    return !gpio_get(gpio);
}