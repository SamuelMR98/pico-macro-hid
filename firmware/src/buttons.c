#include "buttons.h"
#include "pins.h"
#include "pico/stdlib.h"

static const unit button_pins[BUTTON_ID_COUNT] = {
    BUTTON_1_PIN,
    BUTTON_2_PIN,
    BUTTON_3_PIN,
    BUTTON_4_PIN,
};

static bool stable_state[BUTTON_ID_COUNT];
static bool last_reading[BUTTON_ID_COUNT];
static bool pressed_event[BUTTON_ID_COUNT];
static absolute_time_t last_change_time[BUTTON_ID_COUNT];

static bool read_raw_pressed(button_id_t button_id) {
    return !gpio_get(button_pins[button_id]); // pull-up: LOW means pressed
}

void buttons_init(void) {
    for (int i = 0; i < BUTTON_ID_COUNT; i++) {
        gpio_init(button_pins[i]);
        gpio_set_dir(button_pins[i], GPIO_IN);
        gpio_pull_up(button_pins[i]);
        
        bool initial = read_raw_pressed((button_id_t)i);
        stable_state[i] = initial;
        last_reading[i] = initial;
        pressed_event[i] = false;
        last_change_time[i] = get_absolute_time();
    }        
}

void buttons_update(void) {
    for (int i = 0; i < BUTTON_ID_COUNT; i++) {
        bool current = read_raw_pressed((button_id_t)i);

        if (current != last_reading[i]) {
            last_reading[i] = current;
            last_change_time[i] = get_absolute_time();
        }

        int64_t elapsed_ms = absolute_time_diff_us(last_change_time[i], get_absolute_time()) / 1000;

        if (elapsed_ms >= DEBOUNCE_MS && stable_state[i] != current) {
            stable_state[i] = current;
            if (stable_state[i]) {
                pressed_event[i] = true;
            }
        } 
    }
}

bool buttons_was_pressed(button_id_t button_id) {
    if (pressed_event[button_id]) {
        pressed_event[button_id] = false; // clear event after reading
        return true;
    }
    return false;
}

bool buttons_is_pressed(button_id_t button_id) {
    return stable_state[button_id];
}