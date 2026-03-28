#include <stdio.h>
#include "pico/stdlib.h"

#include "actions.h"
#include "buttons.h"
#include "display.h"
#include "profiles.h"
#include "usb_hid.h"


int main(void) {
    stdio_init_all();
    printf("Starting Macro Pad Firmware\r\n");

    // Give USB serial a moment to enumerate
    sleep_ms(1500); // Adjust as needed for your host system

    printf("macro-hud booting...\r\n");

    buttons_init();
    profiles_init();
    display_init();
    usb_hid_init();

    char status[64] = "Ready";
    display_show(profiles_get_current_page_name(), status);

    while (true) {
        buttons_update();

        for (button_id_t button_id = 0; button_id < BUTTON_ID_COUNT; button_id++) {
            if (button_was_pressed(button_id)) {
                button_action_t action = profiles_get_action(button_id);
                actions_execute(action, status, sizeof(status));
                display_show(profiles_get_current_page_name(), status);
            }
        }

        sleep_ms(10); // Small delay to reduce CPU usage
    }

    return 0;
}