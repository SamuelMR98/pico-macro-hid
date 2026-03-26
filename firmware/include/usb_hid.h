#ifndef USB_HID_H
#define USB_HID_H

typedef enum {
    MACRO_NONE = 0,
    MACRO_COPY,
    MACRO_PASTE,
    MACRO_CUT,
    MACRO_UNDO,
    MACRO_REDO,
    MACRO_SAVE,
    MACRO_TERMINAL,
} macro_id_t;

void usb_hid_init(void);
void usb_hid_send_macro(macro_id_t macro_id);
const char *usb_hid_macro_name(macro_id_t macro_id);

#endif // USB_HID_H