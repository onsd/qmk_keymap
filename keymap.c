#include "ergo42.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "config.h"

extern keymap_config_t keymap_config;

#define BASE 0
#define META 1
#define SYMB 2
#define GAME 3

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

//Tap Dance Declarations
enum tap_dance_keycodes{
  TD_TAB_ESC = 0
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE
 * ,------------------------------------------------.   ,------------------------------------------------.
 * | Tab/ESC|   Q  |   W  |   E  |   R  |   T  |  [   |   |  ]   |   Y  |   U  |   I  |   O  |   P  |BS    |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * | ctrl |   A  |   S  |   D  |   F  |   G  |  (   |   |  )   |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * | Sft  |   Z  |   X  |   C  |   V  |   B  |     |   |  }   |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * |MO      | MO   | TG   | TG   |GUI   | ESC |Space|   |Space | Click|Click |      |      | MO   |MO   |
 * |  meta  | symb |  meta|  SYMB|      |      |    |   |      |  left| right| -    |      | symb |meta |
 * `------------------------------------------------'   `------------------------------------------------'
 */

[BASE] = KEYMAP( \
  TD(TD_TAB_ESC),   KC_Q,    KC_W,   KC_E,    KC_R,             KC_T,          KC_LBRC,       KC_RBRC,    KC_Y,             KC_U,    KC_I,     KC_O,     KC_P,     KC_BSPC, \
  KC_LCTRL,  KC_A,    KC_S,   KC_D,    KC_F,             KC_G,          S(KC_9),       S(KC_0),    KC_H,             KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_ENT, \
  KC_LSFT,  KC_Z,    KC_X,   KC_C,    KC_V,             KC_B,          S(KC_LBRC),    S(KC_RBRC), KC_N,             KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, \
 MO(META), MO(SYMB),TG(META), TG(SYMB) , KC_LGUI,        KC_ESC,        KC_SPC,        KC_SPC,    KC_MS_BTN1,     KC_MS_BTN2, KC_MINS, KC_MS_D,  MO(SYMB), MO(META) \
),

/* META
 * ,------------------------------------------------.   ,------------------------------------------------.
 * |  ~ |   1  |   2  |   3  |   4  |   5  |   6  |   |   7  |   8  |   9  |   0  |   -  |  =    |  |   |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+-----+------|
 * |      |  F1  |      |Muhen | Henk |      |  (   |   |  )   | Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * |      |  F2  |  F3  |  F4  |  F5  |  F6  |  {   |   |  }   |  F7  |  F8  |  F9  | F10  | F11  |\/Sft |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * |      |      | M0   | M0   |GUI   | ESC |Space |    |Space | Click|Click |      |      |      |TG    |
 * |      |      |  meta|  SYMB|      |      |      |   |      |  left| right|      |      |      | meta |
 * `------------------------------------------------'   `------------------------------------------------'
 */

[META] = KEYMAP( \
  KC_GRAVE, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,  KC_0,    KC_MINS, KC_EQL, S(KC_BSLS),   \
  _______, KC_F1,   XXXXXXX, KC_MHEN, KC_HENK, XXXXXXX, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_QUOTE, XXXXXXX, \
  _______, KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, KC_F7,   KC_F8,  KC_F9, KC_F10,  KC_F11,  SFT_T(KC_RO), \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET, _______, _______, _______ \
),

/* SYMB &*()_+-=
 * ,------------------------------------------------.   ,------------------------------------------------.
 * |      |   !  |   "  |   #  |   $  |   %  |   ^  |   |   &  |   *  |   ( |   )  |   _   |  +   |      |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * | Alt  |      |      |      |      |      |  (   |   |  )   |M LEFT|M DOWN|M UP|M right|   +  |  *   |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * | Sft  |      |      |      |      |      |  {   |   |  }   |      |      |   <  |   >  |   ?  |  \   |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * | Ctrl | GUI  |  App |PrtSc |ESC/  |Space/|Tab/  |   |Back  |Enter/| Del  |PrtSc |=>GAME|=>SYMB|  \   |
 * |      |      |      |      |~SYMB |RCtrl |Shift |   |Space |~META |      |      |      |      |      |
 * `------------------------------------------------'   `------------------------------------------------'
 */

[SYMB] = KEYMAP( \
   _______,S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6), S(KC_7), S(KC_8), S(KC_9),    S(KC_0),   S(KC_MINS), S(KC_EQL),KC_QUOT, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_MS_L,KC_MS_D,   KC_MS_U,KC_MS_R,   S(KC_SCLN), S(KC_QUOT), \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, S(KC_COMM), S(KC_DOT), S(KC_SLSH), S(KC_RO), \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,   _______,    _______ \
),

/* GAME
 * ,------------------------------------------------.   ,------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |  [   |   |  ]   |   Y  |   U  |   I  |   O  |   P  |  @   |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * | Alt  |   A  |   S  |   D  |   F  |   G  |  (   |   |  )   |   H  |   J  |   K  |   L  |   ;  |  :   |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * | Sft  |   Z  |   X  |   C  |   V  |   B  |  {   |   |  }   |   N  |   M  |   ,  |   .  |   /  |\/Sft |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * | Ctrl | GUI  |  App |PrtSc | ESC  |Space |Tab   |   |Back  |Enter | Del  |PrtSc |=>GAME|=>SYMB|  \   |
 * |      |      |      |      |      |      |      |   |Space |      |      |      |      |      |      |
 * `------------------------------------------------'   `------------------------------------------------'
 */
[GAME] = KEYMAP( \
  KC_TAB,   KC_Q,    KC_W,   KC_E,    KC_R,   KC_T,   KC_RBRC,    KC_BSLS,    KC_Y,   KC_U,    KC_I,     KC_O,    KC_P,    KC_LBRC, \
  KC_LALT,  KC_A,    KC_S,   KC_D,    KC_F,   KC_G,   S(KC_8),    S(KC_9),    KC_H,   KC_J,    KC_K,     KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,    KC_X,   KC_C,    KC_V,   KC_B,   S(KC_RBRC), S(KC_BSLS), KC_N,   KC_M,    KC_COMM,  KC_DOT,  KC_SLSH, SFT_T(KC_RO), \
  KC_LCTRL, KC_LGUI, KC_APP, KC_PSCR, KC_ESC, KC_SPC, KC_TAB,     KC_BSPC,    KC_ENT, KC_DELT, KC_PSCR,  _______, _______, KC_JYEN \
)

};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_TAB_ESC]  = ACTION_TAP_DANCE_DOUBLE(KC_TAB,KC_ESC)
// Other declarations would go here, separated by commas, if you have them
};
