#include QMK_KEYBOARD_H

#if defined PS2_MOUSE_ENABLE
#include "ps2_mouse.h"
#endif

#if defined MOUSEKEY_ENABLE
#include "mousekey.h"
#endif

#if defined AUTO_BUTTONS
#include USER_NAME_H // for AUTO_BUTTONS_LAYER
#endif


#if defined AUTO_BUTTONS && defined PS2_MOUSE_ENABLE && defined MOUSEKEY_ENABLE

static uint16_t auto_buttons_timer;
extern int tp_buttons; // mousekey button state set in action.c and used in ps2_mouse.c

void ps2_mouse_moved_user(report_mouse_t *mouse_report) {
  if (auto_buttons_timer) {
    auto_buttons_timer = timer_read();
  } else {
    if (!tp_buttons) {
      layer_on(AUTO_BUTTONS_LAYER);
      auto_buttons_timer = timer_read();
    }
  }
}

void matrix_scan_user(void) {
  if (auto_buttons_timer && (timer_elapsed(auto_buttons_timer) > AUTO_BUTTONS_TIMEOUT)) {
    if (!tp_buttons) {
      layer_off(AUTO_BUTTONS_LAYER);
      auto_buttons_timer = 0;
    }
  }
}

#endif // defined AUTO_BUTTONS && defined PS2_MOUSE_ENABLE && #defined MOUSEKEY_ENABLE
