// Copyright 2024 Stefan Bienert (@bienchen)
// SPDX-License-Identifier: GPL-2.0-or-later
#include <stdarg.h>

#include "rgb_layer.h"

void _turn_off_led(uint8_t pos) {
    rgb_matrix_set_color(pos, RGB_OFF);
}
void _turn_off_led_dummy(uint8_t pos) {}

void _set_non_passthrough_color(uint8_t h, uint8_t s, const uint16_t keymap[][MATRIX_COLS]) {
    /* adjust brightness */
    HSV hsv = {h, s, rgb_matrix_get_val()};
    RGB rgb = hsv_to_rgb(hsv);

    /* turn lights off based on effect */
    uint8_t mode = rgb_matrix_get_mode();
    void (*tol_ptr)(uint8_t);
    switch (mode) {
        case RGB_MATRIX_TYPING_HEATMAP:
            tol_ptr = &_turn_off_led_dummy;
            break;
        default:
            tol_ptr = &_turn_off_led;
            break;
    }

    /* iterate keymaps */
    uint16_t k = 0;
    for (uint16_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint16_t col = 0; col < MATRIX_COLS; col++) {
            /* column 14 skips the rotary encoder and around the enter key */
            if (col == 14) {
                switch (row) {
                    case 0:
                    case 3:
                        continue;
                        break;
                    default:
                        break;
                }
            } else {
                switch (row) {
                    case 4: /* row 4 skips around the shift keys */
                        switch (col) {
                            case 1:
                            case 12:
                                continue;
                                break;
                            default:
                                break;
                        }
                        break;
                    case 5: /* row 5 has some holes in the matrix because of the space bar */
                        switch (col) {
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
            if (keymap[row][col] != _______) {
                rgb_matrix_set_color(k, rgb.r, rgb.g, rgb.b);
            } else {
                (*tol_ptr)(k);
            }
            k++;
        }
    }
}

void rgb_matrix_set_non_passthrough_color(const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS], uint8_t n_layers, ...) {
    /* Get the current layer */
    uint8_t current_layer = get_highest_layer(layer_state);
    /* Search the list of variable arguments for current layer */
    uint8_t layer;
    uint8_t h;
    uint8_t s;
    va_list layer_hsv_list;
    va_start(layer_hsv_list, n_layers);
    for (uint8_t i = 0; i < n_layers; i++) {
        /* pop 4 values of the variable argument list */
        layer = (uint8_t)va_arg(layer_hsv_list, int);
        h     = (uint8_t)va_arg(layer_hsv_list, int);
        s     = (uint8_t)va_arg(layer_hsv_list, int);
        va_arg(layer_hsv_list, int);
        /* On hitting the right layer, colour keys not set to pass-through */
        if (layer == current_layer) {
            _set_non_passthrough_color(h, s, keymaps[layer]);
        }
    }
}

void rgb_matrix_set_color_hsv(uint8_t index, uint8_t h, uint8_t s, uint8_t v) {
    /* Set colour of a single LED respecting the current brightness. That means,
       the v paramete ris ignored and only exists to enable use of QMKs HSV
       C macros. */
    HSV hsv = {h, s, rgb_matrix_get_val()};
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
}
