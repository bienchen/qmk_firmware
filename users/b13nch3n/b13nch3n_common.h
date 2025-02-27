// Copyright 2024 Stefan Bienert (@bienchen)
// SPDX-License-Identifier: GPL-2.0-or-later
#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

enum custom_keycodes {
  _B13NCH3N_DUMMY = SAFE_RANGE - 1, /* Do not use, handle macro based enum */
#ifdef EMACS_COMMENTING_ENABLE
    ES_CORU,               /* Emacs: comment-or-uncomment-region */
#endif
#ifdef EMACS_BUFFER_SWITCHER_ENABLE
    ES_NEXT,              /* Emacs: switch-to-next-buffer*/
    ES_PREV,              /* Emacs: switch-to-prev-buffer */
#endif
};

void rgb_matrix_set_non_passthrough_color(const uint16_t[][MATRIX_ROWS][MATRIX_COLS], bool (*)(uint8_t, uint8_t), uint8_t, ...);

void rgb_matrix_set_color_hsv(uint8_t, uint8_t, uint8_t, uint8_t);

bool process_record_b13nch3n(uint16_t, keyrecord_t *);

#endif
