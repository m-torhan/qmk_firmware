/* Copyright 2021 OpenAnnePro community
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

enum anne_pro_layers {
    BASE,
    FN1,
    FN2,
    FN3,
};

/* shortcuts */
#define _FN1_BS LT(FN1, KC_BSPC)
#define _FN2_TB LT(FN2, KC_TAB)
#define _FN3_BH LT(FN3, KC_BSLS)

#define _FN1_LF LT(FN1, KC_LEFT)
#define _FN2_DW LT(FN2, KC_DOWN)
#define _CTL_RG RCTL_T(KC_RIGHT)
#define _SFT_UP RSFT_T(KC_UP)

#define _BT_1   KC_AP2_BT1
#define _BT_2   KC_AP2_BT2
#define _BT_3   KC_AP2_BT3
#define _BT_4   KC_AP2_BT4
#define _BT_UNP KC_AP2_BT_UNPAIR
#define _USB    KC_AP2_USB

#define _LED_ON KC_AP_LED_ON
#define _LED_OF KC_AP_LED_OFF
#define _LED_PR KC_AP_LED_PREV_PROFILE
#define _LED_NE KC_AP_LED_NEXT_PROFILE
#define _LED_IN KC_AP_LED_NEXT_INTENSITY
#define _LED_SP KC_AP_LED_SPEED

#define _RGB_MO KC_AP_RGB_MOD
#define _RGB_TG KC_AP_RGB_TOG
#define _RGB_VI KC_AP_RGB_VAI
#define _RGB_VD KC_AP_RGB_VAD

// clang-format off
// Key symbols are based on QMK. Use them to remap your keyboard
/*
* Layer BASE
* ,-----------------------------------------------------------------------------------------.
* | esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | FN2    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |  FN3   |
* |-----------------------------------------------------------------------------------------+
* | FN1     |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
* \-----------------------------------------------------------------------------------------/
* Layer TAP in BASE
* ,-----------------------------------------------------------------------------------------.
* |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
* |-----------------------------------------------------------------------------------------+
* | TAB    |     |     |     |     |     |     |     |     |     |     |     |     |   \    |
* |-----------------------------------------------------------------------------------------+
* | Bksp    |     |     |     |     |     |     |     |     |     |     |     |             |
* |-----------------------------------------------------------------------------------------+
* |            |     |     |     |     |     |     |     |     |     |     |       UP       |
* |-----------------------------------------------------------------------------------------+
* |       |       |       |                                 |       |  LEFT | DOWN  | RIGHT |
* \-----------------------------------------------------------------------------------------/
*/
 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [BASE] = LAYOUT_60_ansi( /* Base */
     KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSPC,
    _FN2_TB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, _FN3_BH,
    _FN1_BS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,           KC_ENT,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,                   _SFT_UP,
    KC_LCTL, KC_LGUI, KC_LALT,                             KC_SPC,                            KC_RALT, _FN1_LF, _FN2_DW, _CTL_RG
),
  /*
  * Layer FN1
  * ,-----------------------------------------------------------------------------------------.
  * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  DELETE   |
  * |-----------------------------------------------------------------------------------------+
  * | FN2    |     | UP  |     |     |     |     |     |     |     | PS  | HOME| END |  FN3   |
  * |-----------------------------------------------------------------------------------------+
  * |         |LEFT |DOWN |RIGHT|     |     |     |     |     |     | PGUP| PGDN|             |
  * |-----------------------------------------------------------------------------------------+
  * |            |     |     |     |     |     |     |     |     |INSRT| DEL |                |
  * |-----------------------------------------------------------------------------------------+
  * |       |       |       |                                 |       |       |  FN2  |       |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [FN1] = LAYOUT_60_ansi( /* FN1 */
     KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    MO(FN2), _______,   KC_UP, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_HOME,  KC_END, MO(FN3),
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN,          _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_INS,  KC_DEL,                   _______,
    _______, _______, _______,                            _______,                            _______, _______, MO(FN2), _______
),
  /*
  * Layer FN2
  * ,-----------------------------------------------------------------------------------------.
  * |  ~  |     |     |     |     |     |     |     |     |     | MUTE| VOL-| VOL+|           |
  * |-----------------------------------------------------------------------------------------+
  * | FN2    |     |     |     |     |     |     |     |     |     |     |     |     |  FN3   |
  * |-----------------------------------------------------------------------------------------+
  * | FN1     | MPRV| MPLY| MNXT|     |     |     |     |     |     |     |     |             |
  * |-----------------------------------------------------------------------------------------+
  * |            |     |     |     |     |     |     |     |     |     |     |                |
  * |-----------------------------------------------------------------------------------------+
  * |       |       |       |                                 |       |  FN1  |  FN2  |       |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [FN2] = LAYOUT_60_ansi( /* FN2 */
    KC_TILD, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______,
    MO(FN2), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, MO(FN3),
    MO(FN1), KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
    _______, _______, _______,                            _______,                            _______, MO(FN1), MO(FN2), _______
 ),
  /*
  * Layer FN3
  * ,-----------------------------------------------------------------------------------------.
  * |     | BT1 | BT2 | BT3 | BT4 | USB | UNP |     |     | LEDM| LEDT| LED-| LED+|           |
  * |-----------------------------------------------------------------------------------------+
  * | FN2    |     |     |     |     |     |     |     |     |     |     |     |     |  FN3   |
  * |-----------------------------------------------------------------------------------------+
  * | FN1     |LEDON|LEDOF|     |     |     |     |     |     |     |     |     |             |
  * |-----------------------------------------------------------------------------------------+
  * |            |LEDPP|LEDPN|LEDIN|LEDSP|     |     |     |     |     |     |                |
  * |-----------------------------------------------------------------------------------------+
  * |       |       |       |                                 |       |  FN1  |  FN2  |       |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [FN3] = LAYOUT_60_ansi( /* FN3 */
    _______,   _BT_1,   _BT_2,   _BT_3,   _BT_4,    _USB, _BT_UNP, _______, _______, _RGB_MO, _RGB_TG, _RGB_VI, _RGB_VD, _______,
    MO(FN2), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, MO(FN3),
    MO(FN1), _LED_ON, _LED_OF, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _LED_PR, _LED_NE, _LED_IN, _LED_SP, _______, _______, _______, _______, _______, _______,                   _______,
    _______, _______, _______,                            _______,                            _______, MO(FN1), MO(FN2), _______
 ),
};
// clang-format on

void keyboard_post_init_user(void) {
    ap2_led_enable();
    ap2_led_set_profile(0);
}

        const ap2_led_t color_white = {.p.red = 0xff, .p.green = 0xff, .p.blue = 0xff, .p.alpha = 0xff};

layer_state_t layer_state_set_user(layer_state_t state) {

    uint8_t layer = get_highest_layer(state);

    if (FN1 == layer) {
        ap2_led_sticky_set_key(2, 0, color_white);
        ap2_led_sticky_set_key(4, 10, color_white);
    }
    else
    {
        ap2_led_unset_sticky_key(2, 0);
        ap2_led_unset_sticky_key(4, 10);
    }
    if (FN2 == layer) {
        ap2_led_sticky_set_key(1, 0, color_white);
        ap2_led_sticky_set_key(4, 11, color_white);
    }
    else
    {
        ap2_led_unset_sticky_key(1, 0);
        ap2_led_unset_sticky_key(4, 11);
    }
    if (FN3 == layer) {
        ap2_led_sticky_set_key(1, 13, color_white);
    }
    else
    {
        ap2_led_unset_sticky_key(1, 13);
    }
    return state;
}

