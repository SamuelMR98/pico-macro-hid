#ifndef BUTTONS_H
#define BUTTONS_H

#include <stdbool.h>
#include <stdint.h>

typedef enum {
    BUTTON_ID_1 = 0,
    BUTTON_ID_2,
    BUTTON_ID_3,
    BUTTON_ID_4,
    BUTTON_ID_COUNT
} button_id_t;

void buttons_init(void);
void buttons_update(void);
bool button_is_pressed(button_id_t button_id);
bool button_was_pressed(button_id_t button_id);

#endif // BUTTONS_H