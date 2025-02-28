SRC += b13nch3n_common.c
# To enable debugging console, disable some features
#CONSOLE_ENABLE = yes
#MOUSEKEY_ENABLE = no
#WIRELESS_NKRO_ENABLE = no
#BLUETOOTH_NKRO_ENABLE = no
#NKRO_ENABLE = no
#EXTRAKEY_ENABLE = no
# to print debug output, do #include "print.h" and use
# - print("string")
# - uprintf("%s string", var)
# and don't forget to wrap the print calls in
# #ifdef CONSOLE_ENABLE
# print(...);
# #endif






ifeq ($(strip $(EMACS_COMMENTING_ENABLE)), yes)
    OPT_DEFS += -DEMACS_COMMENTING_ENABLE
endif

ifeq ($(strip $(EMACS_BUFFERSWITCHER_ENABLE)), yes)
    OPT_DEFS += -DEMACS_BUFFERSWITCHER_ENABLE
endif

ifeq ($(strip $(VIRTUAL_SCREENSWITCHER_ENABLE)), yes)
    OPTS_DEFS += -DVIRTUAL_SCREENSWITCHER_ENABLE
    # OPT_DEFS += -DVIRTUAL_SCREENSWITCHER_HOLD=\"FOO\"
endif
