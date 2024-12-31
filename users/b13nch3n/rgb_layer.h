// Copyright 2024 Stefan Bienert (@bienchen)
// SPDX-License-Identifier: GPL-2.0-or-later
#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

void rgb_matrix_set_non_passthrough_color(const uint16_t[][MATRIX_ROWS][MATRIX_COLS], uint8_t, ...);

void rgb_matrix_set_color_hsv(uint8_t, uint8_t, uint8_t, uint8_t);

#endif
