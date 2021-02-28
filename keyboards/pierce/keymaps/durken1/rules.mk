MH_TRACKPOINT=yes
MH_AUTO_BUTTONS=yes
MH_LOW_MOUSE=yes
LTO_ENABLE=no

USER_NAME := durken1

this_dir=keyboards/pierce/keymaps/durken1

OPT_DEFS += -DMH_USER_NAME_H=\"$(USER_NAME).h\"

ifeq ($(strip $(MH_TRACKPOINT)), yes)
  PS2_MOUSE_ENABLE = yes
  PS2_USE_INT = yes
  OPT_DEFS += -DMH_MODULE_TRACKPOINT
endif

ifeq ($(strip $(MH_AUTO_BUTTONS)), yes)
  MOUSEKEY_ENABLE = yes
  OPT_DEFS += -DMH_AUTO_BUTTONS
endif

ifeq ($(strip $(MH_LOW_MOUSE)), yes)
  OPT_DEFS += -DMH_LOW_MOUSE
endif
