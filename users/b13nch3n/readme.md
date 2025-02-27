# B13nch3n's own QMK extensions/ stuff for keymaps...


To use these extras, add the whole directory to `users/` in your qmk checkout.
Include `b13nch3n_common.h` in your `keymap.c`:

```
#include "b13nch3n_common.h"
```

## Adding features

Still in `keymap.c`, depending on the functionality you want...

### Adding macros

Add `process_record_b13nch3n()` to `keymap.c`:

```
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    /* b13nch3ns' macros - begin */
    if (!process_record_b13nch3n(keycode, record)) {
      return false;
    }
    /* b13nch3ns' macros - end */

    return true;
}
```

There is a good chance that `process_record_user()` is already in the `keymap.c` you copied, just add our function to it.

The following table lists what needs to be enabled in your `rules.mk` and which keycodes are used to trigger the macro:

| `rules.mk`                     | Keycode              | What? |
| :---                           | :---                 | :---  |
| `EMACS_BUFFER_SWITCHER_ENABLE` | `ES_PREV`, `ES_NEXT` | Switch to next or previous buffer in Emacs (`switch-to-prev-buffer`, `switch-to-next-buffer`) |


Copyright 2024, 2025 Stefan Bienert @bienchen

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
