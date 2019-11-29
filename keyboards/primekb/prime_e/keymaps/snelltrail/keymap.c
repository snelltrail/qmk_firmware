/* Copyright 2018 Holten Campbell
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
		KC_TAB,   KC_Q,     KC_W,     KC_E,   KC_R,    KC_T,          KC_Y,   KC_U,     KC_I, KC_O,    KC_P,    KC_LBRC, KC_RBRC,
		KC_LCTL,   KC_A,     KC_S,     KC_D,   KC_F,    KC_G,          KC_H,   KC_J,     KC_K, KC_L,    KC_SCLN, LT(2, KC_ENT),
		KC_LSFT,  KC_Z,     KC_X,     KC_C,   KC_V,    KC_B,          LT(3, KC_B),  KC_N,     KC_M, KC_COMM, KC_DOT,  KC_SLSH, MO(3),
		KC_LCTL,  KC_LGUI,                    KC_LALT, LT(1, KC_SPC),	          KC_BSPC, LM(1, MOD_LALT),    LM(1, MOD_LALT | MOD_LSFT), MO(2)
    ),

    LAYOUT(
		KC_ESC,  LALT(KC_1),      LALT(KC_2),      LALT(KC_3),      LALT(KC_4),       LALT(KC_5),             KC_7,      KC_8,     KC_9,    KC_MINS,    KC_EQL,      KC_BSLS,  KC_GRV,
		KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,          KC_4,   KC_5,    KC_6,   KC_TRNS,   KC_TRNS,   KC_QUOT,
		KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,          KC_0,   KC_1,    KC_2,   KC_3,   KC_TRNS,   KC_TRNS,  KC_TRNS,
		KC_TRNS,  KC_TRNS,                         KC_TRNS,    KC_TRNS,	         KC_NO,   KC_PDOT,                               KC_TRNS,  KC_TRNS
    ),

    LAYOUT(
		KC_CAPS,    KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,          KC_F6,   KC_F7,    KC_F8,     KC_F9,   KC_F10,   KC_F11,   KC_F12,
		KC_TRNS,   KC_VOLU,   KC_VOLD,   KC_MUTE,   KC_TRNS,    KC_TRNS,          KC_TRNS,   KC_LEFT,    KC_DOWN,   KC_LEFT,  KC_RIGHT,   KC_BSLS,
		KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,          KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_DOWN,   KC_TRNS,   KC_TRNS,
		BL_TOGG,   BL_STEP,                         KC_TRNS,    KC_TRNS,	        KC_TRNS,   KC_TRNS,                                     KC_TRNS,   KC_TRNS
    ),

    LAYOUT(
		RESET,  LSFT(KC_Q),     LSFT(KC_W),     LSFT(KC_E),     LSFT(KC_R),      LSFT(KC_T),            KC_F6,     KC_F7,    KC_F8,   KC_F9,   KC_UP,    KC_F11,   KC_F12,
		KC_TRNS,  LSFT(KC_A),   LSFT(KC_S),   LSFT(KC_D),   LSFT(KC_F),    LSFT(KC_G),          KC_TRNS,   KC_TRNS,  KC_TRNS, KC_LEFT, KC_RIGHT,   KC_TRNS,
		KC_TRNS,  LSFT(KC_Z),   LSFT(KC_X),   LSFT(KC_C),   LSFT(KC_V),    LSFT(KC_B),          KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS, KC_DOWN,   KC_TRNS,  KC_TRNS,
		KC_TRNS,  KC_TRNS,                         KC_TRNS,    KC_TRNS,	         KC_TRNS,   KC_TRNS,                               KC_TRNS,  KC_TRNS
    )
};

void matrix_init_user(void) {
  // set CapsLock LED to output and low
  setPinOutput(B1);
  writePinLow(B1);
  // set NumLock LED to output and low
  setPinOutput(B2);
  writePinLow(B2);
  // set ScrollLock LED to output and low
  setPinOutput(B3);
  writePinLow(B3);
}

void matrix_scan_user(void) {

}


void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
    writePinHigh(B2);
  } else {
    writePinLow(B2);
  }
  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    writePinHigh(B1);
  } else {
    writePinLow(B1);
  }
/*
  if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {
    writePinHigh(B3);
  } else {
    writePinLow(B3);
  }*/

}

//function for layer indicator LED
uint32_t layer_state_set_user(uint32_t state)
{
    if (biton32(state) == 1) {
    writePinHigh(B3);
	} else {
		writePinLow(B3);
    }
    return state;
}
