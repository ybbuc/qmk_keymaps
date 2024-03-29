/* Copyright 2023 Jakob Wells <jakob@duck.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum layers {
    _COLEMAK_DH = 0,
    _NAV,
    _SYM,
    _NUM,
};


// Aliases for readability
#define QWERTY   DF(_QWERTY)
#define COLEMAK  DF(_COLEMAK_DH)
#define DVORAK   DF(_DVORAK)

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)

#define ESC_HYPR  MT(KC_HYPR, KC_ESC)
#define QUOT_HYPR MT(KC_HYPR, KC_QUOTE)
#define SYM_TAB MT(SYM, KC_TAB)
#define BKSP_DEL MT(NAV, KC_BSPC)

// Bottom row mods
#define Z_CTL MT(KC_LCTL, KC_Z)
#define X_ALT MT(KC_LALT, KC_X)
#define C_SFT MT(KC_LSFT, KC_C)
#define D_GUI MT(KC_LGUI, KC_D)
#define H_GUI MT(KC_RGUI, KC_H)
#define COMM_SFT MT(KC_RSFT, KC_COMM)
#define DOT_ALT MT(KC_RALT, KC_DOT)
#define SLSH_CTL MT(KC_RCTL, KC_SLSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Colemak-DH
 *
 * ╭────────┬────────┬────────┬────────┬────────┬────────╮                                    ╭────────┬────────┬────────┬────────┬────────┬────────╮
 * │CapsWrd │   Q    │   W    │   F    │   P    │   B    │                                    │   J    │   L    │   U    │   Y    │   ;    │   \    │
 * ├────────┼────────┼────────┼────────┼────────┼────────┤                                    ├────────┼────────┼────────┼────────┼────────┼────────┤
 * │Esc/Hyp │   A    │   R    │   S    │   T    │   G    │                                    │   M    │   N    │   E    │   I    │   O    │ '/Hyp  │
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────╮╭────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 * │        │ Z Ctl  │ X Alt  │ C Sft  │ D GUI  │   V    │        │        ││        │        │   K    │ H GUI  │  , Sft │ . Alt  │ / Ctl  │Ctl Ctl │
 * ╰────────┴────────┴────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┴────────┴────────╯
 *                            │        │        │        │ Enter  │Tab/Sym ││BkSp/Nav│ Space  │        │        │        │
 *                            ╰────────┴────────┴────────┴────────┴────────╯╰────────┴────────┴────────┴────────┴────────╯
 */
    [_COLEMAK_DH] = LAYOUT(
      CW_TOGG,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_BSLS,
     ESC_HYPR,   KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,QUOT_HYPR,
      _______,  Z_CTL,   X_ALT,   C_SFT,   D_GUI,    KC_V, _______, _______,  _______, _______,    KC_K,   H_GUI, COMM_SFT,DOT_ALT,SLSH_CTL,  _______,
                                _______, _______, _______,  KC_ENT, SYM_TAB, BKSP_DEL,  KC_SPC, _______, _______, _______
    ),

/*
 * Nav Layer: Media, navigation
 * 
 * ╭────────┬────────┬────────┬────────┬────────┬────────╮                                    ╭────────┬────────┬────────┬────────┬────────┬────────╮
 * │        │        │ VolDow │ VolUp  │ VolMut │        │                                    │        │        │        │        │        │        │
 * ├────────┼────────┼────────┼────────┼────────┼────────┤                                    ├────────┼────────┼────────┼────────┼────────┼────────┤
 * │        │        │  Prev  │  Next  │  Play  │        │                                    │    ←   │    ↓   │    ↑   │    →   │        │        │
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────╮╭────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 * │        │        │        │        │        │        │        │        ││        │        │        │        │        │        │        │        │
 * ╰────────┴────────┴────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┴────────┴────────╯
 *                            │        │        │        │        │        ││        │        │        │        │        │
 *                            ╰────────┴────────┴────────┴────────┴────────╯╰────────┴────────┴────────┴────────┴────────╯
 */
    [_NAV] = LAYOUT(
      _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, KC_MPRV, KC_MNXT, KC_MPLY, _______,                                     KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Sym Layer: Symbols
 *
 * ╭────────┬────────┬────────┬────────┬────────┬────────╮                                    ╭────────┬────────┬────────┬────────┬────────┬────────╮
 * │        │        │        │        │        │        │                                    │        │        │        │        │        │        │
 * ├────────┼────────┼────────┼────────┼────────┼────────┤                                    ├────────┼────────┼────────┼────────┼────────┼────────┤
 * │   `    │   !    │   @    │   #    │   $    │   %    │                                    │   ^    │   &    │   *    │   -    │        │        │
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────╮╭────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 * │   ~    │        │   [    │   ]    │   (    │   )    │        │        ││        │        │        │   =    │   _    │   +    │        │        │
 * ╰────────┴────────┴────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┴────────┴────────╯
 *                            │        │   {    │   }    │        │        ││        │        │        │        │        │
 *                            ╰────────┴────────┴────────┴────────┴────────╯╰────────┴────────┴────────┴────────┴────────╯
 */
    [_SYM] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
       KC_GRV, KC_EXLM,   KC_AT, _______, _______, _______,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, _______, _______,
      KC_TILD, _______, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, _______, _______, _______, _______, _______,  KC_EQL, KC_UNDS, KC_PLUS, _______, _______,
                                 _______, KC_LCBR, KC_RCBR, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Function Layer: Function keys
 *
 * ╭────────┬────────┬────────┬────────┬────────┬────────╮                                    ╭────────┬────────┬────────┬────────┬────────┬────────╮
 * │        │        │   F9   │   F8   │   F7   │  F12   │                                    │        │   7    │   8    │   0    │        │        │
 * ├────────┼────────┼────────┼────────┼────────┼────────┤                                    ├────────┼────────┼────────┼────────┼────────┼────────┤
 * │        │        │   F6   │   F5   │   F4   │  F11   │                                    │        │   4    │   5    │   6    │        │        │
 * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────╮╭────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 * │        │        │   F3   │   F2   │   F1   │  F10   │        │        ││        │        │        │   1    │   2    │   3    │        │        │
 * ╰────────┴────────┴────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┴────────┴────────╯
 *                            │        │        │        │        │        ││        │    0   │        │        │        │
 *                            ╰────────┴────────┴────────┴────────┴────────╯╰────────┴────────┴────────┴────────┴────────╯
 */
    [_NUM] = LAYOUT(
      _______, _______ ,  KC_F9 ,  KC_F8 ,  KC_F7 , KC_F12 ,                                     _______,    KC_7,    KC_8,    KC_9, _______, _______,
      _______, _______ ,  KC_F6 ,  KC_F5 ,  KC_F4 , KC_F11 ,                                     _______,    KC_4,    KC_5,    KC_6, _______, _______,
      _______, _______ ,  KC_F3 ,  KC_F2 ,  KC_F1 , KC_F10 , _______, _______, _______, _______, _______,    KC_1,    KC_2,    KC_3, _______, _______,
                                  _______, _______, _______, _______, _______, _______,    KC_0, _______, _______, _______
    ),

// /*
//  * Layer template
//  *
//  * ╭────────┬────────┬────────┬────────┬────────┬────────╮                                    ╭────────┬────────┬────────┬────────┬────────┬────────╮
//  * │        │        │        │        │        │        │                                    │        │        │        │        │        │        │
//  * ├────────┼────────┼────────┼────────┼────────┼────────┤                                    ├────────┼────────┼────────┼────────┼────────┼────────┤
//  * │        │        │        │        │        │        │                                    │        │        │        │        │        │        │
//  * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────╮╭────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//  * │        │        │        │        │        │        │        │        ││        │        │        │        │        │        │        │        │
//  * ╰────────┴────────┴────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┴────────┴────────╯
//  *                            │        │        │        │        │        ││        │        │        │        │        │
//  *                            ╰────────┴────────┴────────┴────────┴────────╯╰────────┴────────┴────────┴────────┴────────╯
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

void keyboard_pre_init_user(void) {
  setPinOutput(24);  // Set LED pin as output
  writePinHigh(24);  // Turn the LED off
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _COLEMAK_DH:
        rgblight_setrgb (0x00,  0x00, 0x00);
        break;
    case _NAV:
        rgblight_setrgb (0xFF,  0x00, 0x00);
        break;
    case _SYM:
        rgblight_setrgb (0x00,  0xFF, 0x00);
        break;
    case _NUM:
        rgblight_setrgb (0x7A,  0x00, 0xFF);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0x00,  0x00 , 0x00);
        break;
    }
  return state;
}
