// Copyright 2024 Stefan Bienert (@bienchen)
// SPDX-License-Identifier: GPL-2.0-or-later
#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

enum custom_keycodes {
    ES_CORU = SAFE_RANGE, /* Emacs: comment-or-uncomment-region */
#ifdef EMACS_BUFFER_SWITCHER_ENABLE
    ES_NEXT,              /* Emacs: switch-to-next-buffer*/
    ES_PREV,              /* Emacs: switch-to-prev-buffer */
#endif
};

void rgb_matrix_set_non_passthrough_color(const uint16_t[][MATRIX_ROWS][MATRIX_COLS], bool (*)(uint8_t, uint8_t), uint8_t, ...);

void rgb_matrix_set_color_hsv(uint8_t, uint8_t, uint8_t, uint8_t);

bool process_record_b13nch3n(uint16_t, keyrecord_t *);

#endif
