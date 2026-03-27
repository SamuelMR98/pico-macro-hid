#include "display.h"
#include <stdio.h>
#include <string.h>

static char last_page[32];
static char last_status[64];

void display_init(void) {
    // Initialize display hardware here if needed
    memset(last_page, 0, sizeof(last_page));
    memset(last_status, 0, sizeof(last_status));
    printf("[display] init stub\r\n");
}

void display_show(const char *page_name, const char *status_line) {
    if (strncmp(last_page, page_name, sizeof(last_page) - 1) == 0 &&
        strncmp(last_status, status_line, sizeof(last_status) - 1) == 0) {
        // No change, skip update
        return;
    }
    // Update display with new page and status
    snprintf(last_page, sizeof(last_page), "%s", page_name);
    snprintf(last_status, sizeof(last_status), "%s", status_line);

    // Stub output. Later replace with SSD1306/ST7789 actual drawing code
    printf("\r\n=== DISPLAY ===\r\n");
    printf("Page: %s\r\n", last_page);
    printf("Status: %s\r\n", last_status);
    printf("===============\r\n");
}