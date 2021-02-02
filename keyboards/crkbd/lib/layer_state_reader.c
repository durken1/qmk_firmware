
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "crkbd.h"

// in the future, should use (1U<<_LAYER_NAME) instead, but needs to be moved to keymap,c
#define L_COLEMAK 0
#define L_MBO 2
#define L_GAME 4
#define L_LOWER 8
#define L_RAISE 16
#define L_GRAISE 20

char layer_state_str[24];

const char *read_layer_state(void) {
  switch (layer_state)
  {
  case L_COLEMAK:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Colemak");
    break;
  case L_MBO:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: MBO");
    break;
  case L_GAME:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Game");
    break;
  case L_LOWER:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Lower");
    break;
  case L_RAISE:
  case L_GRAISE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Raise");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
  }

  return layer_state_str;
}
