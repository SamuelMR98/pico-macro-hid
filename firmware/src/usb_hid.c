#include "usb_hid.h"
#include <stdio.h>

void usb_hid_init(void) {
    // Initialize USB HID here if needed
    printf("[usb_hid] init stub\r\n");
}

const char *usb_hid_macro_name(macro_id_t macro_id) {
    switch (macro_id){
        case MACRO_COPY: return "COPY";
        case MACRO_PASTE: return "PASTE";
        case MACRO_CUT: return "CUT";
        case MACRO_UNDO: return "UNDO";
        case MACRO_REDO: return "REDO";
        case MACRO_SAVE: return "SAVE";
        case MACRO_TERMINAL: return "TERMINAL";
        case MACRO_NONE:
        default: return "NONE";
    }
}

void usb_hid_send_macro(macro_id_t macro_id) {
    // Stub: just print the macro name for now
    // Later, this becomes TinyUSB keyboard/media-key implementation
    printf("[usb_hid] send macro: %s\r\n", usb_hid_macro_name(macro_id));
}