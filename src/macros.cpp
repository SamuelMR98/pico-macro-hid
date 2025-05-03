#include "macros.h"
#include "tusb.h"

void handle_keypress() {
    if (tud_hid_ready()) {
        uint8_t report[6] = {0x04} // HID code for 'a' key
        tud_hid_keyboard_report(0, 0, report);
    }
}