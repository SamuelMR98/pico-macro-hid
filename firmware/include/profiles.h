#ifndef PROFILES_H
#define PROFILES_H

#include "buttons.h"
#include "actions.h"

void profiles_init(void);
button_action_t profiles_get_action(button_id_t button_id);
const char *profiles_get_current_page_name(void);
unsigned int profiles_get_current_page_index(void);
unsigned int profiles_get_page_count(void);
void profiles_next_page(void);
void profiles_previous_page(void);

#endif // PROFILES_H