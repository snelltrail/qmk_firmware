/* Copyright 2019 Ryota Goto
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
/*
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, \
    K300, K301, K302,     K304,       K306,       K308,   K309, K310, K311  \
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_all( /* Base */
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, 
    KC_LGUI,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, 
    KC_LSFT, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  LT(3, KC_SLASH), 
    MO(2), KC_LGUI, KC_LALT,          LT(1, KC_SPC),           KC_SPC,       LT(2,KC_BSPC),      MO(1),  KC_RGUI, MO(2) 
  ),
  [1] = LAYOUT_all( /* Numbers,       */
    KC_ESC, LALT(KC_1),      LALT(KC_2),      LALT(KC_3),      LALT(KC_4), KC_LBRC, KC_7, KC_8, KC_9,   KC_LBRC, KC_RBRC, _______, 
    _______, LALT(KC_A), LALT(KC_S), LALT(KC_D),  LALT(KC_F), LALT(KC_G), KC_4, KC_5, KC_6, _______, _______, KC_QUOT, 
    _______, _______, _______, _______, _______, KC_PSCR, KC_0,  KC_1, KC_2, KC_3,  _______, _______, 
    _______, _______, _______,          _______,          _______,     _______,      _______, _______, _______
  ),
  [2] = LAYOUT_all( 
    RESET, KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_MINS,    KC_EQL, KC_BSLS,    KC_GRV, 
    _______, KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN,   KC_AUDIO_MUTE,   _______,   _______,   _______,   _______,   _______, _______, _______, _______, 
    _______, _______, _______,   _______,   _______,   _______,  _______,  _______,  _______, _______, _______, _______, 
    _______, _______, _______,          _______,          _______,     _______,      _______, _______,  _______
  ),
  [3] = LAYOUT_all( /* could probably use RSHIFT as a full modifier; use LSHIFT exclusively for SHIFT */
    KC_CAPS, LSFT(KC_Q),   LSFT(KC_W),    LSFT(KC_E),    LSFT(KC_R),    LSFT(KC_T),    _______,    _______,    _______,    KC_UP, _______,    _______, 
    _______, LSFT(KC_A),   LSFT(KC_S),   LSFT(KC_D),   LSFT(KC_F),   LSFT(KC_G),   _______,   _______, KC_LEFT, KC_RIGHT, _______, _______, 
    _______, _______, LSFT(KC_Z),   LSFT(KC_X),   LSFT(KC_C),   LSFT(KC_V),  LSFT(KC_B),  _______,  _______, KC_DOWN, _______, _______, 
    _______, _______, _______,          _______,          _______,     _______,      _______, _______,  _______
  )

};
