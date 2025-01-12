// Copyright 2024 Stefan Bienert (@bienchen)
// SPDX-License-Identifier: GPL-2.0-or-later
#include <stdarg.h>

#include "b13nch3n_common.h"

void _turn_off_led(uint8_t pos) {
    rgb_matrix_set_color(pos, RGB_OFF);
}
void _turn_off_led_dummy(uint8_t pos) {}

void _set_non_passthrough_color(uint8_t h, uint8_t s, const uint16_t keymap[][MATRIX_COLS], bool (*idx_has_led_ptr)(uint8_t, uint8_t)) {
    /* Set LEDs of non-pass-through keys to given colour. Colour is described
       by H & S of HSV, V is used form the current brightness level. For most
       RGB matrix effects, LEDs of pass-through keys are turned off.
     */
    /* adjust brightness */
    HSV hsv = {h, s, rgb_matrix_get_val()};
    RGB rgb = hsv_to_rgb(hsv);
    /* turn lights off based on effect
       to skip turning off, use a pointer to a "do nothing" function
    */
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
    /* iterate keymap */
    uint16_t k = 0;
    for (uint16_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint16_t col = 0; col < MATRIX_COLS; col++) {
            /* Some matrices have "holes" mappng row/ column coordinates to LED
               positions. Determine to skip them...
            */
            if ((*idx_has_led_ptr)(row, col) == false) {
                continue;
            }
            /* do the actual colouring */
            if (keymap[row][col] != _______) {
                rgb_matrix_set_color(k, rgb.r, rgb.g, rgb.b);
            } else {
                (*tol_ptr)(k);
            }
            k++;
        }
    }
}

void rgb_matrix_set_non_passthrough_color(const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS], bool (*idx_has_led_ptr)(uint8_t, uint8_t), uint8_t n_layers, ...) {
    /* Set the RGB matrix for the keymap of the current layer.
       Takes the `keymaps` 3-dimensional array, an indicator function for
       coordinates with/ wihtout LEDs, and the number of layers, which are
       described in the variable list of arguments.
       The variable list of arguments is a multiple of 4 of the `n_layers`.
       Each layer is described by the ID of the layer and 3 HSV values. Since
       the current brightness level is preserved, the V component of HSV is
       ignored. By using all 3 HSV values, you can use QMKs' colour macros.

       In the current layer, all keys that are not set to pass-through, are
       turned on with the given colour. All pass-through keys are turned of.
       There are some exceptions from turning off LEDs for some RGB matrix
       effects.
    */
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
            _set_non_passthrough_color(h, s, keymaps[layer], idx_has_led_ptr);
        }
    }
}

void rgb_matrix_set_color_hsv(uint8_t index, uint8_t h, uint8_t s, uint8_t v) {
    /* Set colour of a single LED respecting the current brightness. That means,
       the v paramete ris ignored and only exists to enable use of QMKs' HSV
       C macros. */
    HSV hsv = {h, s, rgb_matrix_get_val()};
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
}
