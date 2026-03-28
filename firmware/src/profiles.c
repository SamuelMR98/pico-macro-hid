#include "profiles.h"
#include "pins.h"

static unsigned int current_page = 0;

static const button_action_t pages[2][BUTTON_COUNT] = {
    {
        {ACTION_MACRO, MACRO_COPY, "Copy"},
        {ACTION_MACRO, MACRO_PASTE, "Paste"},
        {ACTION_MACRO, MACRO_UNDO, "Undo"},
        {ACTION_NEXT_PAGE, MACRO_NONE, "Next"}
    },
    {
        {ACTION_MACRO, MACRO_CUT, "Cut"},
        {ACTION_MACRO, MACRO_SAVE, "Save"},
        {ACTION_MACRO, MACRO_REDO, "Redo"},
        {ACTION_PREV_PAGE, MACRO_NONE, "Prev"}
    }
};

static const char *page_names[2] = {
    "EDITING",
    "TOOLS"
};

void profiles_init(void) {
    current_page = 0;
}

button_action_t profiles_get_action(button_id_t button_id) {
    return pages[current_page][button_id];
}

const char *profiles_get_current_page_name(void) {
    return page_names[current_page];
}

unsigned int profiles_get_current_page_index(void) {
    return current_page;
}

unsigned int profiles_get_page_count(void) {
    return sizeof(pages) / sizeof(pages[0]);
}

void profiles_next_page(void) {
    current_page = (current_page + 1) % profiles_get_page_count();
}

void profiles_prev_page(void) {
    if (current_page == 0) {
        current_page = profiles_get_page_count() - 1;
    } else {
        current_page--;
    }
}