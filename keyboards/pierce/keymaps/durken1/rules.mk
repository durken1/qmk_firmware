#TRACKPOINT = interrupt
#TRACKPOINT = usart
AUTO_BUTTONS = yes
MOUSEKEY_ENABLE = yes

USER_NAME := durken1

this_dir = keyboards/pierce/keymaps/durken1

OPT_DEFS += -DUSER_NAME_H=\"$(USER_NAME).h\"

ifeq ($(strip $(TRACKPOINT)), interrupt)
  PS2_MOUSE_ENABLE = yes
  PS2_USE_INT = yes
  OPT_DEFS += -DINTERRUPT
else ifeq ($(strip $(TRACKPOINT)), usart)
  PS2_MOUSE_ENABLE = yes
  PS2_USE_USART = yes
  OPT_DEFS += -DUSART
endif

ifeq ($(strip $(AUTO_BUTTONS)), yes)
  MOUSEKEY_ENABLE = yes
  OPT_DEFS += -DAUTO_BUTTONS
endif

