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

enum layers {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [MAC_BASE] = LAYOUT_ansi_82(
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTRL, KC_LNPAD, RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_DEL,             KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_HOME,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGUP,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_PGDN,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD,MO(MAC_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_ansi_82(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,            _______,
        _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            KC_END,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
        _______,  _______,  _______,                                _______,                                MO(WIN_BASE),  _______,  _______,  MC_0,  _______,  MC_1),

    [WIN_BASE] = LAYOUT_ansi_82(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,            RGB_TOG,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            KC_END,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______),

    [WIN_FN] = LAYOUT_ansi_82(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,            RGB_TOG,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            KC_END,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______)
};

// clang-format on
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
};
#endif // ENCODER_MAP_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    return true;
}

// b13nch3ns' mods beyond the keymap (above)
// layer colouring

void turn_off_led(uint8_t pos) {
  rgb_matrix_set_color(pos, RGB_OFF);
}
void turn_off_led_dummy(uint8_t pos) {}

void set_non_passthrough_colour(uint8_t current_layer, uint8_t h, uint8_t s, uint8_t v) {
  // adjust brightness
  HSV hsv = {h, s, v};
  hsv.v = rgb_matrix_get_val();
  RGB rgb = hsv_to_rgb(hsv);

  // turn lights off based on effect
  uint8_t mode = rgb_matrix_get_mode();
  void (*tol_ptr)(uint8_t);
  switch(mode) {
  case RGB_MATRIX_TYPING_HEATMAP:
    tol_ptr = &turn_off_led_dummy;
    break;
  default:
    tol_ptr = &turn_off_led;
    break;
  }

  // iterate keymaps
  uint16_t k = 0;
  for (uint16_t row = 0; row < MATRIX_ROWS; row++) {
    for (uint16_t col = 0; col < MATRIX_COLS; col++) {
      // column 14 skips the rotary encoder and around the enter key
      if (col == 14) {
        switch(row) {
        case 0:
        case 3:
          continue;
          break;
        default:
          break;
        }
      }
      else {
        switch(row) {
        case 4: // row 4 skips around the shift keys
          switch(col) {
          case 1:
          case 12:
            continue;
            break;
          default:
            break;
          }
          break;
        case 5: // row 5 has some holes in the matrix because of the space bar
          switch(col) {
          case 3:
          case 4:
          case 5:
          case 7:
          case 8:
            continue;
            break;
          default:
            break;
          }
          break;
        default:
          break;
        }
      }
      if (keymaps[current_layer][row][col] != _______) {
        rgb_matrix_set_color(k, rgb.r, rgb.g, rgb.b);
      }
      else {
        (*tol_ptr)(k);
      }
      k++;
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  /* LED positions
     0: Esc|1 : F1|2:  F2|3: F3|4: F4|5:  F5|6: F6|7:  F7|8: F8|9:  F9|10:F10
     11:F11|12:F12|13:Del|14: `|15: 1|16: 2|17:  3|18:  4|19: 5|20:  6|21:  7
     22:  8|23:  9|24:  0|25: -|26: =|27:BS|28: HM|29:TAB|30: Q|31:  W|32:  E
     33:  R|34:  T|35:  Y|36: U|37: I|38: O|39:  P|40:  [|41: ]|42:  ||43:PGU
     44:CLK|45:  A|46:  S|47: D|48: F|49: G|50:  H|51:  j|52: K|53:  L|54:  ;
     55:  '|56:ENT|57:PGD|58:SH|59: Z|60: X|61:  C|62:  V|63: B|64:  N|65:  M
     66:  <|67:  >|68:  ?|69:SH|70:AU|71:CR|72:SYS|73:ALT|74:SP|75:ALT|76: FN
     77: CR|78: AL|79: AD|80:AR

     Rows/ Cols with LEDs
       00|01|02|03|04|05|06|07|08|09|10|11|12|13|14
     -----------------------------------------------
     0| 0| 1| 2| 3| 4| 5| 6| 7| 8| 9|10|11|12|13|  |
     1|14|15|16|17|18|19|20|21|22|23|24|25|26|27|28|
     2|29|30|31|32|33|34|35|36|37|38|39|40|41|42|43|
     3|44|45|46|47|48|49|50|51|52|53|54|55|56|57|  |
     4|58|  |59|60|61|62|63|64|65|66|67|68|  |69|70|
     5|71|72|73|  |  |  |74|  |  |75|76|77|78|79|80|
  */

  // Some extra highlights 
  // paint Esc red
  rgb_matrix_set_color(0, RGB_RED);

  // layer based RGB matrix settings
  uint8_t current_layer = get_highest_layer(layer_state);
  switch (current_layer) {
  case MAC_FN:
    set_non_passthrough_colour(current_layer, HSV_GREEN);// CYAN SPRINGGREEN PURPLE
    break;
  case WIN_BASE:
    set_non_passthrough_colour(current_layer, HSV_PINK);
    break;
  // case WIN_FN:
    // set_non_passthrough_colour(current_layer, RGB_WHITE);
    // break;
  default: // for any other layers, or the default layer MAC_BASE do nothing, so
           // RGB can still be configured.
    break;
  }

  return true;
}
