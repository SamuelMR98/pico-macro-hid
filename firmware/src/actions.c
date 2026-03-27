#include "actions.h"
#include "profiles.h"
#include <stdio.h>

void actions_execute(button_action_t action, char *status_buf, size_t status_buf_len) {
    switch (action.type) {
        case ACTION_MACRO:
            usb_hid_send_macro(action.macro_id);
            snprintf(status_buf, status_buf_len, "Executed: %s", action.label);
            break;
        case ACTION_NEXT_PAGE:
            profiles_next_page();
            snprintf(status_buf, status_buf_len, "Switched to page: %s", profiles_get_current_page_name());
            break;
        case ACTION_PREV_PAGE:
            profiles_prev_page();
            snprintf(status_buf, status_buf_len, "Switched to page: %s", profiles_get_current_page_name());
            break;
        case ACTION_NONE:
        default:
            snprintf(status_buf, status_buf_len, "No action assigned");
            break;
    }
}