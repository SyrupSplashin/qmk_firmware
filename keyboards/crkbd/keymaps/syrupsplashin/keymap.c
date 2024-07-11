/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2024 SyrupSplashin

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// NOTE: Keyboard Layout/Layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//        ┌──────┬─────────────────┬───┬───────┬────────────┬───────────────────┐   ┌────────────────────┬────────────┬────┬───┬─────────────────┬──────┐
//        │  `   │        '        │ , │   .   │     p      │         y         │   │         f          │     g      │ c  │ r │        l        │  /   │
//        ├──────┼─────────────────┼───┼───────┼────────────┼───────────────────┤   ├────────────────────┼────────────┼────┼───┼─────────────────┼──────┤
//        │ lsft │        a        │ o │   e   │     u      │         i         │   │         d          │     h      │ t  │ n │        s        │  -   │
//        ├──────┼─────────────────┼───┼───────┼────────────┼───────────────────┤   ├────────────────────┼────────────┼────┼───┼─────────────────┼──────┤
//        │ lgui │ MT(MOD_LALT, ;) │ q │   j   │     k      │         x         │   │         b          │     m      │ w  │ v │ MT(MOD_RALT, z) │ rctl │
//        └──────┴─────────────────┴───┼───────┼────────────┼───────────────────┤   ├────────────────────┼────────────┼────┼───┴─────────────────┴──────┘
//                                     │ MO(3) │ LT(1, ent) │ MT(MOD_LCTL, tab) │   │ MT(MOD_LSFT, bspc) │ LT(2, spc) │ no │
//                                     └───────┴────────────┴───────────────────┘   └────────────────────┴────────────┴────┘
[0] = LAYOUT_split_3x6_3(
      KC_GRV  , KC_QUOTE              , KC_COMM , KC_DOT , KC_P            , KC_Y                 ,     KC_F                  , KC_G            , KC_C    , KC_R , KC_L               , KC_SLASH    ,
      KC_LSFT , KC_A                  , KC_O    , KC_E   , KC_U            , KC_I                 ,     KC_D                  , KC_H            , KC_T    , KC_N , KC_S               , KC_MINUS    ,
      KC_LGUI , MT(MOD_LALT, KC_SCLN) , KC_Q    , KC_J   , KC_K            , KC_X                 ,     KC_B                  , KC_M            , KC_W    , KC_V , MT(MOD_RALT, KC_Z) , KC_RCTL     ,
                                                  MO(3)  , LT(1, KC_ENTER) , MT(MOD_LCTL, KC_TAB) ,     MT(MOD_LSFT, KC_BSPC) , LT(2, KC_SPACE) , XXXXXXX
),

//        ┌─────┬─────┬───┬─────┬─────┬─────┐   ┌─────┬───┬─────┬───┬───┬──────┐
//        │ esc │  !  │ @ │  #  │  $  │  %  │   │  +  │ 7 │  8  │ 9 │ / │  \   │
//        ├─────┼─────┼───┼─────┼─────┼─────┤   ├─────┼───┼─────┼───┼───┼──────┤
//        │  ?  │  ^  │ & │  *  │  (  │  )  │   │  -  │ 4 │  5  │ 6 │ * │ bspc │
//        ├─────┼─────┼───┼─────┼─────┼─────┤   ├─────┼───┼─────┼───┼───┼──────┤
//        │     │     │ [ │  ]  │  {  │  }  │   │  .  │ 1 │  2  │ 3 │ = │      │
//        └─────┴─────┴───┼─────┼─────┼─────┤   ├─────┼───┼─────┼───┴───┴──────┘
//                        │     │     │     │   │     │ 0 │     │
//                        └─────┴─────┴─────┘   └─────┴───┴─────┘
[1] = LAYOUT_split_3x6_3(
      KC_ESC  , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC ,     KC_PLUS  , KC_7 , KC_8    , KC_9 , KC_SLASH , KC_BSLS    ,
      KC_QUES , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN ,     KC_MINUS , KC_4 , KC_5    , KC_6 , KC_ASTR  , KC_BSPC    ,
      KC_TRNS , KC_TRNS , KC_LBRC , KC_RBRC , KC_LCBR , KC_RCBR ,     KC_DOT   , KC_1 , KC_2    , KC_3 , KC_EQUAL , KC_TRNS    ,
                                    KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS  , KC_0 , KC_TRNS
),

//        ┌─────┬────┬──────┬──────┬──────┬─────┐   ┌──────┬──────┬──────┬──────┬─────┬─────┐
//        │ no  │ no │  no  │ volu │  no  │ no  │   │ pgup │ home │  up  │ end  │ no  │ no  │
//        ├─────┼────┼──────┼──────┼──────┼─────┤   ├──────┼──────┼──────┼──────┼─────┼─────┤
//        │     │ no │ mprv │ vold │ mnxt │ no  │   │ pgdn │ left │ down │ rght │ no  │ no  │
//        ├─────┼────┼──────┼──────┼──────┼─────┤   ├──────┼──────┼──────┼──────┼─────┼─────┤
//        │ no  │ no │  no  │ mute │  no  │ no  │   │ pscr │  no  │  no  │ del  │     │     │
//        └─────┴────┴──────┼──────┼──────┼─────┤   ├──────┼──────┼──────┼──────┴─────┴─────┘
//                          │      │      │     │   │      │      │      │
//                          └──────┴──────┴─────┘   └──────┴──────┴──────┘
[2] = LAYOUT_split_3x6_3(
      XXXXXXX , XXXXXXX , XXXXXXX , KC_VOLU , XXXXXXX , XXXXXXX ,     KC_PGUP , KC_HOME , KC_UP   , KC_END   , XXXXXXX , XXXXXXX    ,
      KC_TRNS , XXXXXXX , KC_MPRV , KC_VOLD , KC_MNXT , XXXXXXX ,     KC_PGDN , KC_LEFT , KC_DOWN , KC_RIGHT , XXXXXXX , XXXXXXX    ,
      XXXXXXX , XXXXXXX , XXXXXXX , KC_MUTE , XXXXXXX , XXXXXXX ,     KC_PSCR , XXXXXXX , XXXXXXX , KC_DEL   , KC_TRNS , KC_TRNS    ,
                                    _______ , _______ , _______ ,     _______ , _______ , _______
),

//        ┌────┬────┬────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬────┬─────┬───────┐
//        │ no │ no │ no │ no  │ no  │ no  │   │ no  │ no  │ no  │ no │ no  │ DF(4) │
//        ├────┼────┼────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼────┼─────┼───────┤
//        │ f1 │ f2 │ f3 │ f4  │ f5  │ f6  │   │ no  │ no  │ no  │ no │ no  │  no   │
//        ├────┼────┼────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼────┼─────┼───────┤
//        │ f7 │ f8 │ f9 │ f10 │ f11 │ f12 │   │ no  │ no  │ no  │ no │     │       │
//        └────┴────┴────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼────┴─────┴───────┘
//                       │     │     │     │   │     │     │     │
//                       └─────┴─────┴─────┘   └─────┴─────┴─────┘
[3] = LAYOUT_split_3x6_3(
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , DF(4)      ,
      KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX    ,
      KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_TRNS , KC_TRNS    ,
                                    _______ , _______ , _______ ,     _______ , _______ , _______
),

//        ┌─────┬──────┬───┬─────┬───────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬───────┐
//        │ esc │  no  │ q │  w  │   e   │  r  │   │     │     │     │     │     │ DF(0) │
//        ├─────┼──────┼───┼─────┼───────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼───────┤
//        │ tab │ lsft │ a │  s  │   d   │  f  │   │     │     │     │     │     │       │
//        ├─────┼──────┼───┼─────┼───────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼───────┤
//        │ no  │ lctl │ z │  x  │   c   │  v  │   │     │     │     │     │     │       │
//        └─────┴──────┴───┼─────┼───────┼─────┤   ├─────┼─────┼─────┼─────┴─────┴───────┘
//                         │     │ MO(5) │ spc │   │     │     │     │
//                         └─────┴───────┴─────┘   └─────┴─────┴─────┘
[4] = LAYOUT_split_3x6_3(
      KC_ESC  , XXXXXXX , KC_Q , KC_W    , KC_E  , KC_R   ,     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , DF(0)      ,
      KC_TAB  , KC_LSFT , KC_A , KC_S    , KC_D  , KC_F   ,     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS    ,
      XXXXXXX , KC_LCTL , KC_Z , KC_X    , KC_C  , KC_V   ,     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS    ,
                                 _______ , MO(5) , KC_SPC ,     _______ , _______ , _______
),

//        ┌────┬────┬────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬────┬────┬────┐
//        │ no │ no │ no │ no  │ no  │ no  │   │ no  │ no  │ no  │ no │ no │ no │
//        ├────┼────┼────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼────┼────┼────┤
//        │ no │ 1  │ 2  │  3  │  4  │  5  │   │ no  │ no  │ no  │ no │ no │ no │
//        ├────┼────┼────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼────┼────┼────┤
//        │ no │ 6  │ 7  │  8  │  9  │  0  │   │ no  │ no  │ no  │ no │ no │ no │
//        └────┴────┴────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼────┴────┴────┘
//                       │     │     │     │   │     │     │     │
//                       └─────┴─────┴─────┘   └─────┴─────┴─────┘
[5] = LAYOUT_split_3x6_3(
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX    ,
      XXXXXXX , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX    ,
      XXXXXXX , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX    ,
                                    _______ , _______ , _______ ,     _______ , _______ , _______
)
};

// NOTE: Tapping Term Config
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LSFT, KC_BSPC):
            return TAPPING_TERM -25;
        case MT(MOD_LCTL, KC_TAB):
            return TAPPING_TERM -25;
        case LT(2,KC_SPACE):
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}

// NOTE: Permissive Hold Config
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LSFT, KC_BSPC):
            // Immediately select the hold action when another key is tapped.
            return true;
        case MT(MOD_LCTL, KC_TAB):
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}
// NOTE: OLED Configuration
// WIP!
