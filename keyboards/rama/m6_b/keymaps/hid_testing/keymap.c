#include QMK_KEYBOARD_H

#define BASE 0
#define FIRST 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT(
        KC_1, KC_2, KC_3, KC_4, KC_5, TG(1)),

    [FIRST] = LAYOUT(
        KC_6,  KC_7, KC_8, KC_9, KC_O, TG(1)),

    LAYOUT(
        KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),

    LAYOUT(
        KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO) };

