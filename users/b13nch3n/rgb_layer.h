// Copyright 2024 Stefan Bienert (@bienchen)
// SPDX-License-Identifier: GPL-2.0-or-later
#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

void set_non_passthrough_colour(uint8_t, uint8_t, uint8_t, uint8_t, const uint16_t[][MATRIX_ROWS][MATRIX_COLS]);

void rgb_matrix_set_color_hsv(uint8_t, uint8_t, uint8_t, uint8_t);

#endif
