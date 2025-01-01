/* Copyright 2023 @ Keychron (https://www.keychron.com)
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
#ifdef CONSOLE_ENABLE
#include "print.h"
#endif
#include "rgb_layer.h"

enum layers {
    MAC_BASE,
    WIN_BASE,
    MAC_FN1,
    WIN_FN1,
    FN2
};
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_73(
        KC_MUTE,     KC_ESC,   KC_1,    KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_DEL,
        MC_2,        KC_TAB,   KC_Q,    KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_HOME,
        MC_3,        KC_CAPS,  KC_A,    KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,           KC_PGUP,
        MC_4,        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT, KC_UP,   KC_PGDN,
        MC_5,        KC_LCTL,  KC_LOPTN,KC_LCMMD,                            KC_SPC,                             KC_RCMMD, MO(MAC_FN1),MO(FN2),KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_BASE] = LAYOUT_ansi_73(
        KC_MUTE,     KC_ESC,   KC_1,    KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_DEL,
        MC_2,        KC_TAB,   KC_Q,    KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_HOME,
        MC_3,        KC_CAPS,  KC_A,    KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,           KC_PGUP,
        MC_4,        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT, KC_UP,   KC_PGDN,
        MC_5,        KC_LCTL,  KC_LGUI, KC_LALT,                             KC_SPC,                             KC_RALT,  MO(WIN_FN1),MO(FN2),KC_LEFT, KC_DOWN, KC_RGHT),

    [MAC_FN1] = LAYOUT_ansi_73(
        RGB_TOG,     KC_GRV,  KC_BRID,  KC_BRIU,  KC_MCTRL,KC_LNPAD,RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          _______,
        _______,     _______, BT_HST1,  BT_HST2,  BT_HST3, P2P4G,  _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______,     RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______,  _______,            _______,          _______,
        _______,     _______,           RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, NK_TOGG, _______, _______, _______,  _______,            _______, _______, _______,
        _______,     _______, _______,  _______,                             _______,                            _______,  _______,  _______,  _______, _______, _______),

    [WIN_FN1] = LAYOUT_ansi_73(
        RGB_TOG,     KC_GRV,  KC_BRID,  KC_BRIU,  KC_TASK, KC_FILE, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          _______,
        _______,     _______, BT_HST1,  BT_HST2,  BT_HST3, P2P4G,  _______, _______, _______, _______, _______, _______,  _______,  _______,   _______,          _______,
        _______,     RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______,  _______,            _______,          _______,
        _______,     _______,           RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, NK_TOGG, _______, _______, _______,  _______,            _______, _______, _______,
        _______,     _______, _______,  _______,                             _______,                            _______,  _______,  _______,  _______, _______, _______),

    [FN2] = LAYOUT_ansi_73(
        _______,    KC_TILD, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,    _______,          _______,
        _______,    _______, _______,  _______,   _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______,    _______, _______,  _______,   _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______,          _______,
        _______,    _______,           _______,   _______, _______, _______, BAT_LVL, _______, _______, _______, _______,  _______,            _______, _______, _______,
        _______,    _______, _______,  _______,                              _______,                            _______,  _______,  _______,  _______, _______, _______)
};

// clang-format on
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN1]  = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_FN1]  = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [FN2]      = {ENCODER_CCW_CW(_______, _______)},
};
#endif // ENCODER_MAP_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

#ifdef CONSOLE_ENABLE
  uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif 

    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    return true;
}

/* b13nch3ns' mods beyond the keymap (above) */
/* layer colouring */
bool rgb_matrix_indicators_user(void) {
  /* LED positions
      0:  `| 1:  1| 2:  2| 3:  3| 4: 4| 5:  5| 6: 6| 7: 7| 8:  8| 9: 9|10:  0
     11:  -|12:  =|13: BS|14:DEL|15:M2|16:TAB|17: Q|18: W|19:  E|20: R|21:  T
     22:  Y|23:  U|24:  I|25:  O|26: P|27:  [|28: ]|29: \|30:PGU|31:M3|32:CLK
     33:  A|34:  S|35:  D|36:  F|37: G|38:  H|39: J|40: K|41:  L|42: ;|43:  '
     44:ENT|45:PGD|46: M4|47:SHL|48: Z|49:  X|50: C|51: V|52:  B|53: N|54:  M
     55:  ,|56:  .|57:  /|58:SHR|59:AU|60:END|61:M5|62:CL|63:ALT|64:SU|65:SPC
     66:SYS|67:FN1|68:FN2|69: AL|70:AD|71:AR

     Rows/ Cols with LEDs
       00|01|02|03|04|05|06|07|08|09|10|11|12|13|14|15
     -------------------------------------------------
     0|  | 0| 1| 2| 3| 4| 5| 6| 7| 8| 9|10|11|12|13|14
     1|15|16|17|18|19|20|21|22|23|24|25|26|27|28|29|30
     2|31|32|33|34|35|36|37|38|39|40|41|42|43|44|45|
     3|46|47|  |48|49|50|51|52|53|54|55|56|57|58|59|60
     4|61|62|63|64|  |  |  |65|  |  |66|67|68|69|70|71
  */

  /* Some extra highlights on macro keys */
  rgb_matrix_set_color_hsv(15, HSV_PURPLE);// RED AZURE CHARTREUSE CORAL GOLD
  rgb_matrix_set_color_hsv(31, HSV_PURPLE);// GOLDENROD
  rgb_matrix_set_color_hsv(46, HSV_PURPLE);
  rgb_matrix_set_color_hsv(61, HSV_PURPLE);

  /* layer based RGB matrix settings */
  //rgb_matrix_set_non_passthrough_color(keymaps, 2,
  //                                     MAC_FN, HSV_ORANGE,
  //                                     WIN_BASE, HSV_MAGENTA);

  return true;
}
