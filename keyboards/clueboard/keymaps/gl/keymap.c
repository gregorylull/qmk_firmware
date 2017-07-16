// GLULL

#include "clueboard.h"

// Helpful defines
#define GRAVE_MODS  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT)|MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI)|MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))
#define _______ KC_TRNS

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DEFAULT_MAC 0
#define _GL 1
#define _FL 2
#define _CL 3
#define _ML 4

// Quantum key shorcuts
#define Q_GS_ESC SCMD_T(KC_ESC)

// SPECIAL KEYS
#define MT_C_ES LCTL_T(KC_ESC)
#define MT_C_SP LCTL_T(KC_SPC)
#define MT_G_ES RGUI_T(KC_ESC)

//Tap Dance Declarations
enum {
  CT_ESC_GRAVE_TILDE = 0
};

// TAP DANCE KEYS
#define CT_EGT TD(CT_ESC_GRAVE_TILDE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _DEFAULT_MAC
   * make this togglable
   * BLUE LED TO ON
   * RGB CLEAR/WHITE
   */
[_DEFAULT_MAC] = KEYMAP(
  F(0),    KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_GRV,  KC_BSPC,          KC_PGUP, \
  KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,                   KC_PGDN, \
  KC_CAPS, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,                             \
  KC_LSFT, KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,   KC_SLSH,  KC_RO,    KC_RSFT,          KC_UP,            \
  KC_LCTL, KC_LCTL, KC_LALT, KC_LGUI,          KC_SPC,KC_SPC,                        KC_RGUI,  KC_RALT,  KC_RCTL,  MO(_FL), KC_LEFT, KC_DOWN, KC_RGHT),

  /* Keymap _GL:
   * TODO: make this persistent
   * BLUE LED ALWAYS OFF
   * RGB BLUE
   */
[_GL] = KEYMAP(
  F(0),    KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,     KC_MINS,  KC_EQL,  _______,  KC_BSPC,         KC_PGUP, \
  KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS,                   KC_PGDN, \
  MT_C_ES, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN,  KC_QUOT,  KC_NUHS, KC_ENT,                             \
  Q_GS_ESC,KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT, KC_RSPC,          KC_UP,            \
  MO(_ML), KC_LCTL, KC_LALT,KC_LGUI,        MT_C_SP,KC_SPC,                          MT_G_ES,  KC_RALT,  KC_RCTL, MO(_FL), KC_LEFT, KC_DOWN, KC_RGHT),

  /* Keymap _FL: Function Layer
   * RGB RED
   */
[_FL] = KEYMAP(
  KC_GRV,  KC_F1,   KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______, KC_DEL,           BL_STEP, \
  _______, _______, _______,_______,_______,_______,_______,_______,KC_PSCR,KC_SLCK, KC_PAUS,  _______,  _______,  _______,                   _______, \
  _______, _______, MO(_CL),_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  _______,                           \
  _______, _______, _______,_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  _______,          KC_PGUP,         \
  MO(_CL), _______, _______,_______,        _______,_______,                         _______,  _______,  _______,  MO(_FL), _______, KC_PGDN, _______),

  /* Keymap _CL: Control layer
   * RGB GREEN
   */
[_CL] = KEYMAP(
  _______, TO(_DEFAULT_MAC),TO(_GL),_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  _______, RGB_TOG,             RGB_VAI, \
  _______, _______, _______,_______,RESET,  _______,_______,_______,_______,_______, _______,  _______,  _______,  _______,                   RGB_VAD, \
  _______, _______, MO(_CL),_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  _______,                         \
  MO(_FL), _______, _______,_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  MO(_FL),          RGB_SAI,          \
  _______, _______, _______,_______,        RGB_MOD,   RGB_MOD,                            _______,  _______,  _______,  _______, RGB_HUD,    RGB_SAD,    RGB_HUI),

/* Future layers
 * RGB YELLOW
 * mac brightness
 */
/* Keymap _ML: Mouse layer (from magic_monty) */
[_ML] = KEYMAP(
  _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______, _______, _______, _______,  _______, _______,  _______, _______, _______,         KC_VOLU, \
  _______, _______, _______, _______, _______, _______, _______, KC_WH_U, KC_MS_U, KC_WH_D,  _______, _______,  _______, _______,                  KC_VOLD, \
  _______, _______, KC_BTN2, KC_BTN3, KC_BTN1, _______, KC_WH_R, KC_MS_L, KC_MS_D, KC_MS_R,  KC_WH_L, _______,  _______, _______,                            \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,  _______, _______,          KC_MUTE,          \
  _______, _______, _______, _______,                   KC_BTN1, KC_BTN2,                    _______, KC_BTN1,  KC_BTN2,  KC_BTN3, KC_MRWD,KC_MPLY,KC_MFFD),

}; // THIS IS KEYMAP CLOSING

/* This is a list of user defined functions. F(N) corresponds to item N
   of this list.
 */
const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_FUNCTION(0),  // Calls action_function()
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t mods_pressed;
  static bool mod_flag;

  switch (id) {
    case 0:
      /* Handle the combined Grave/Esc key
       */
      mods_pressed = get_mods()&GRAVE_MODS; // Check to see what mods are pressed

      if (record->event.pressed) {
        /* The key is being pressed.
         */
        if (mods_pressed) {
          mod_flag = true;
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        /* The key is being released.
         */
        if (mod_flag) {
          mod_flag = false;
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}

// const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
//     if (record->event.pressed) {
//         switch(id) {
//             case 0:
//                 // LEFT browser tab navigation cmd-shift-left bracket
//                 return MACRO(D(LSFT), D((LGUI), T(LBRC), U(LSFT), U(LGUI), END);
//             case 1:
//                 // RIGHT browser tab navigation cmd-shift-right bracket
//                 return MACRO(D(LSFT), D((LGUI), T(RBRC), U(LSFT), U(LGUI), END);
//         }
//     }
//     return MACRO_NONE;
// };

void ct_esc_grave_tilde (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    register_code(KC_ESC);
    unregister_code(KC_ESC);
    break;
  case 2:
    register_code(KC_GRV);
    unregister_code(KC_GRV);
    break;
  case 3:
    register_code(KC_LSFT);
    register_code(KC_GRV);

    unregister_code(KC_GRV);
    unregister_code(KC_LSFT);
    break;
  case 4:
    reset_tap_dance(state);
  }
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for grave(backtick), thrice for tilde
  [CT_ESC_GRAVE_TILDE]  = ACTION_TAP_DANCE_FN(ct_esc_grave_tilde)
// Other declarations would go here, separated by commas, if you have them
};
