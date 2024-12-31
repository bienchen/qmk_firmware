#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

void set_non_passthrough_colour(uint8_t, uint8_t, uint8_t, uint8_t, const uint16_t[][MATRIX_ROWS][MATRIX_COLS]);

#endif
