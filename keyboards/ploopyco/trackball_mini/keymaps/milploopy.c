#include QMK_KEYBOARD_H
bool is_drag_scroll = false;

enum custom_keycodes {
    DRAG_SCROLL = PLOOPY_SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DRAG_SCROLL:
            if (record->event.pressed) {
                is_drag_scroll ^= 1;
            }
            break;
    }
    return true;
}

void process_mouse_user(report_mouse_t* mouse_report, int16_t x, int16_t y) {
    if (is_drag_scroll) {
        mouse_report->h = x;
        mouse_report->v = y;
    } else {
        mouse_report->x = x;
        mouse_report->y = y;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( /* Base */
        KC_BTN1, KC_BTN3, KC_BTN2,
          KC_BTN4, LT(1, KC_BTN5)
    ),
    [1] = LAYOUT(
        DRAG_SCROLL, _______, _______,
          _______, _______
    )
};