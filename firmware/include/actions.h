#ifndef ACTIONS_H
#define ACTIONS_H

#include <stddef.h>
#include "usb_hid.h"

typedef enum {
    ACTION_NONE = 0,
    ACTION_MACRO,
    ACTION_NEXT_PAGE,
    ACTION_PREV_PAGE,
} action_type_t;

typedef struct {
    action_type_t type;
    macro_id_t macro_id; // Valid if type == ACTION_MACRO
    const char *label; // Label for the action (e.g., for display purposes)
} button_action_t;

void actions_execute(button_action_t action, char *status_buf, size_t status_buf_len);

#endif // ACTIONS_H