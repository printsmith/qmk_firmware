// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "super_alt_tab.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* ┌───┬───┬───┬───┐		┌───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┐  ┌───┐ 
	 * │Kn1│F13│F14│F15│		│Esc│ │ F1│ F2│ F3│ F4│ │ F5│ F6│ F7│ F8│ │ F9│F10│F11│F12│ │Del│  │Kn2│ 
	 * └───┴───┴───┴───┘		└───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┘  └───┘ 
     * ┌───┬───┬───┬───┐		┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────────┐  ┌───┐
     * │ - │ * │ / │NmL│		│ ~ │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backspace │  │Pup│
     * ├───┼───┼───┼───┤		├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────────┤  ├───┤
     * │   │ 9 │ 8 │ 7 │		│Tab  │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │   \     │  │Pdn│
     * │ + ├───┼───┼───┤ ┌───┐	├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────────┤  ├───┤
     * │   │ 6 │ 5 │ 4 │ │Mod│	│Caps  │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ Return     │  │Hom│
     * ├───┼───┼───┼───┤ └───┘  ├──────┴──┬┴──┬┴──┬┴──┬┴──┬┴──┬┴──┬┴──┬┴──┬┴──┬┴──┬┴──────┬─────┘  ├───┤
     * │   │ 3 │ 2 │ 1 │ ┌───┐	│Shift    │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │Shift  │  ┌───┐ │End│
     * │ENT├───┼───┼───┘ │Up │  └───┬─────┼───┴─┬─┴───┴───┴┬──┴─┬─┴───┴──┬┴──┬┴──┬┴──┬────┘  │Up │ └───┘
     * │   │ . │ 0 │ ┌───┼───┼───┐  │Ctrl │Alt  │ Space    │Win │        │Alt│Fn │Ctl│   ┌───┼───┼───┐
	 * └───┴───┴───┘ │Lft│Dn │Rht│  └─────┴─────┴──────────┴────┴────────┴───┴───┴───┘   │Lft│Dn │Rht│
	 *				 └───┴───┴───┘                                                       └───┴───┴───┘
	 */    
    [0] = LAYOUT(
    KC_MUTE, MO(2)  , KC_F13 , KC_F14 ,          KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_DEL , RGB_MOD,
																																											   
    KC_PMNS, KC_PAST, KC_PSLS, KC_NUM ,          KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC, KC_PGUP,
    KC_PPLS, KC_P9  , KC_P8  , KC_P7  ,          KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS, KC_PGDN,
             KC_P6  , KC_P5  , KC_P4  , ALT_TAB, KC_CAPS, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT , 		   KC_HOME, 
    KC_PENT, KC_P3  , KC_P2  , KC_P1  , KC_UP  , KC_LSFT, 		   KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, KC_UP  , KC_END ,
             KC_PDOT, KC_P0  , KC_LEFT, KC_DOWN, KC_RGHT, KC_LCTL, KC_LALT, KC_SPC ,          KC_LWIN,          KC_RSFT,          KC_RALT, MO(1)  , KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {,
    [0] 	= { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif