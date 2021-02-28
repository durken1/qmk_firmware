#pragma once

#if defined MH_MODULE_TRACKPOINT && defined PS2_MOUSE_ENABLE
  // clock on pin 3 (d0, int0)
  #define PS2_CLOCK_PORT PORTD
  #define PS2_CLOCK_PIN PIND
  #define PS2_CLOCK_DDR DDRD
  #define PS2_CLOCK_BIT 0
  #define PS2_INT_INIT() do { EICRA |= ((1<<ISC01) | (0<<ISC00)); } while (0)
  #define PS2_INT_ON() do { EIMSK |= (1<<INT0); } while (0)
  #define PS2_INT_OFF() do { EIMSK &= ~(1<<INT0); } while (0)
  #define PS2_INT_VECT INT0_vect
  // data on pin 2 (d1)
  #define PS2_DATA_PORT PORTD
  #define PS2_DATA_PIN PIND
  #define PS2_DATA_DDR DDRD
  #define PS2_DATA_BIT 1
  #define PS2_MOUSE_ROTATE 270 // compensate for east-facing device orientation
  #define PS2_MOUSE_SCROLL_BTN_MASK (1 << PS2_MOUSE_BTN_MIDDLE)
  #define PS2_MOUSE_SCROLL_BTN_SEND TAPPING_TERM
  #define PS2_MOUSE_SCROLL_DIVISOR_V 3
  #define PS2_MOUSE_SCROLL_DIVISOR_H PS2_MOUSE_SCROLL_DIVISOR_V
#endif

#if defined MH_AUTO_BUTTONS
  #define MH_AUTO_BUTTONS_LAYER MBO
  #define MH_AUTO_BUTTONS_TIMEOUT 750
#endif

#if !defined MH_LOW_MOUSE && defined PS2_MOUSE_ENABLE
  #define PS2_MOUSE_X_MULTIPLIER 3
  #define PS2_MOUSE_Y_MULTIPLIER PS2_MOUSE_X_MULTIPLIER
  #define PS2_MOUSE_USE_2_1_SCALING
#endif

#if defined MH_LOW_MOUSE && defined MOUSEKEY_ENABLE
  #undef MOUSEKEY_TIME_TO_MAX
  #define MOUSEKEY_TIME_TO_MAX 128
#endif

#if defined MH_LOW_MOUSE
  #undef PRODUCT
  #define PRODUCT Pierce Keyboard with low rate mouse
#endif
