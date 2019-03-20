#include QMK_KEYBOARD_H

#define BASE 0
#define FIRST 1

enum custom_keycodes {
  LATEXMK = SAFE_RANGE,
  LATEX_TIDY,
  LATEX_CLEAN,
  LATEX_DEBUG,
  LATEX_CONT,
  CTRL_C
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case LATEXMK:
      if(record->event.pressed) {
        SEND_STRING("latex_make_and_clean\n");
      } else {
        // when key released
      }
      break;
    case LATEX_TIDY:
      if(record->event.pressed) {
        SEND_STRING("latexmk -c &> /dev/null\n");
      } else {
        // when key released
      }
      break;
    case LATEX_CLEAN:
      if(record->event.pressed) {
        SEND_STRING("latexmk -C &> /dev/null\n");
      } else {
        // when key released
      }
      break;
    case LATEX_DEBUG:
      if(record->event.pressed) {
        SEND_STRING("latexmk -pdf\n");
      } else {
        // when key released
      }
      break;
    case CTRL_C:
      if(record->event.pressed) {
        SEND_STRING(SS_LCTRL("c"));
      } else {
        // when key released
      }
      break;
    case LATEX_CONT:
      if(record->event.pressed) {
        SEND_STRING("latexmk -pvc\n");
      } else {
        // when key released
      }
      break;
  }
  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT(
        LATEXMK, LATEX_TIDY, LATEX_CLEAN, LATEX_DEBUG, CTRL_C , OSL(1)),

    [FIRST] = LAYOUT(
        RESET, LATEX_CONT, KC_B, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),

    LAYOUT(
        KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),

    LAYOUT(
        KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO) };

