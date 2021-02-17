#include QMK_KEYBOARD_H

#if defined PS2_MOUSE_ENABLE
#include "ps2_mouse.h"
#endif

#if defined MOUSEKEY_ENABLE
#include "mousekey.h"
#endif

#if defined MH_AUTO_BUTTONS
#include MH_USER_NAME_H // for MH_AUTO_BUTTONS_LAYER
#endif


#if defined MH_AUTO_BUTTONS && defined PS2_MOUSE_ENABLE && defined MOUSEKEY_ENABLE

static uint16_t mh_auto_buttons_timer;
extern int tp_buttons; // mousekey button state set in action.c and used in ps2_mouse.c

void ps2_mouse_moved_user(report_mouse_t *mouse_report) {
  if (mh_auto_buttons_timer) {
    mh_auto_buttons_timer = timer_read();
  } else {
    if (!tp_buttons) {
      layer_on(MH_AUTO_BUTTONS_LAYER);
      mh_auto_buttons_timer = timer_read();
    }
  }
}

void matrix_scan_user(void) {
  if (mh_auto_buttons_timer && (timer_elapsed(mh_auto_buttons_timer) > MH_AUTO_BUTTONS_TIMEOUT)) {
    if (!tp_buttons) {
      layer_off(MH_AUTO_BUTTONS_LAYER);
      mh_auto_buttons_timer = 0;
    }
  }
}

#endif // defined MH_AUTO_BUTTONS && defined PS2_MOUSE_ENABLE && #defined MOUSEKEY_ENABLE
