/* Copyright 2024 @ b13nch3n
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
#include "keychron_common.h"

enum layers {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_90(
        KC_MUTE,    KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTRL, KC_LNPAD, RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_INS,             KC_DEL,
        MC_1,       KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        MC_2,       KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        MC_3,       KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        MC_4,       KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        MC_5,       MO(WIN_BASE),  KC_LCTL,           KC_LOPTN, KC_SPC,  KC_LCMMD,                     KC_SPC,             MO(MAC_FN), KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_ansi_90(
        RGB_TOG,    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,            _______,
        _______,    _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,    RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,    _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,  _______,  _______,  _______,  _______,  _______,            _______,            KC_END,
        _______,    _______,            _______,  _______,  _______,  _______,   BAT_LVL,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,    _______,  _______,            _______,  _______,  _______,                       _______,            _______,  _______,            _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_ansi_90(
        KC_MUTE,    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_DEL,
        MC_1,       KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        MC_2,       KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        MC_3,       KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        MC_4,       KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        MC_5,       KC_LCTL,  KC_LWIN,            KC_LALT,  KC_SPC,  MO(WIN_FN),                     KC_SPC,             KC_RALT,  KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_ansi_90(
        RGB_TOG,    _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,   KC_VOLU,  _______,            _______,
        _______,    _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,    RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,    _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,  _______,  _______,  _______,  _______,  _______,             _______,            KC_END,
        _______,    _______,            _______,  _______,  _______,  _______,   BAT_LVL,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,   _______,  _______,  _______,
        _______,    _______,  _______,            _______,  _______,  _______,                       _______,            _______,  _______,             _______,  _______,  _______),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN] = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN] = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)}
};
#endif // ENCODER_MAP_ENABLE

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    return true;
}

// b13nch3ns' mods beyond the keymap (above)
// LED positions
//  0: esc
//  1: F1
//  2: F2
//  3: F3
//  4: F4
//  5: F5
//  6: F6
//  7: F7
//  8: F8
//  9: F9
// 10: F10
// 11: F11 
// 12: F12
// 13: ins
// 14: del
// 15: M1
// 16: `~
// 17: 1
// 18: 2
// 19: 3
// 20: 4
// 21: 5
// 22: 6
// 23: 7
// 24: 8
// 25: 9
// 26: 0
// 27: -_
// 28: =+
// 29: backspace
// 30: pgup
// 31: M2
// 32: Tab
// 33: Q
// 34: W
// 35: E
// 36: R
// 37: T
// 38: Y
// 39: U
// 40: I
// 41: O
// 42: P
// 43: [{
// 44: ]}
// 45: \|
// 46: pgdn
// 47: M3
// 48: CapsLock
// 49: A
// 50: S
// 51: D
// 52: F
// 53: G
// 54: H
// 55: J
// 56: K
// 57: L
// 58: ;:
// 59: '"
// 60: RETURN
// 61: home
// 62: M4
// 63: LSHIFT
// 64: Z
// 65: X
// 66: C
// 67: V
// 68: LB
// 69: RB
// 70: N
// 71: M
// 72: ,<
// 73: .>
// 74: /?
// 75: RSHIFT
// 76: UPARROW
// 77: M5
// 78: fn1
// 79: LCTRL
// 80: LOPT
// 81: LSPACE
// 82: LCMD
// 83: RSPACE
// 84: fn
// 85: RCTRL
// 86: LEFTARROW
// 87: DOWNARROW
// 88: RIGHTARROW
// Black: RGB_GOLD, RGB_CORAL, RGB_YELLOW, RGB_GOLDENROD, AZURE, MAGENTA,
//        ORANGE, RED
// Grey: RGB_GOLD
// Red: RGB_AZURE, 
// White keys: RGB_MAGENTA, RGB_GOLDENROD, RGB_GREEN (chars), RGB_AZURE,
//             RGB_ORANGE
// Layer indicator: GOLD seems to work with black, white, grey (not so much
//                  with red)
// Ideas:
// - capslock only on tap dance
bool rgb_matrix_indicators_user(void) {
  int i = 77;
  // Find indeces
  rgb_matrix_set_color(i,   RGB_GOLD);
  rgb_matrix_set_color(i+1, RGB_BLUE);
  rgb_matrix_set_color(i+2, RGB_RED);
  rgb_matrix_set_color(i+3, RGB_YELLOW);
  rgb_matrix_set_color(i+4, RGB_GREEN);
  rgb_matrix_set_color(i+5, RGB_AZURE);
  rgb_matrix_set_color(i+6, RGB_CORAL);
  rgb_matrix_set_color(i+7, RGB_GOLDENROD);
  rgb_matrix_set_color(i+8, RGB_MAGENTA);
  rgb_matrix_set_color(i+9, RGB_ORANGE);
  rgb_matrix_set_color(i+10, RGB_SPRINGGREEN);
  rgb_matrix_set_color(i+11, RGB_PURPLE);
  // Find nice colour for specific key
  rgb_matrix_set_color(0, RGB_GOLDENROD); // esc GOLD

  return true;
}
