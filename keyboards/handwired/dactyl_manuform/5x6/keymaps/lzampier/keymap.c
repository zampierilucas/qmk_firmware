#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _GAMING 3

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_GAMING,
};

#include "oled.c"

// RALT(KC_QUOTE)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x6(
        KC_ESC , KC_1, KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC       ,
        KC_TAB , KC_Q, KC_W   , KC_E   , KC_R   , KC_T   ,                   KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS       ,
        KC_LSFT, KC_A, KC_S   , KC_D   , KC_F   , KC_G   ,                   KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, RALT(KC_QUOTE),
        KC_LCTL, KC_Z, KC_X   , KC_C   , KC_V   , KC_B   ,                   KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_BACKSLASH  ,
                       KC_LBRC, KC_RBRC,                                                                KC_PLUS, KC_EQL ,
                                         RAISE  , KC_SPC ,                   KC_ENT , LOWER  ,
                                         KC_LGUI, KC_LALT,                   KC_DEL , KC_LGUI,
                                         KC_APP , KC_GRV ,                   KC_HOME, KC_END
    ),

    [_LOWER] = LAYOUT_5x6(
        KC_GRV , KC_QWERTY, KC_GAMING , KC_HASH, KC_DLR          , KC_PERC      ,            KC_F20       , KC_F21          , KC_F13 , KC_F14 , KC_RPRN, KC_DEL ,
        _______, RGB_HUI  , RGB_SAI   , _______, _______         , KC_LBRC      ,            KC_RBRC      , _______         , KC_UP  , _______, _______, KC_PLUS,
        _______, RGB_HUD  , RGB_SAD   , _______, _______         , KC_LPRN      ,            KC_RPRN      , KC_LEFT         , KC_DOWN, KC_RGHT, KC_MINS, KC_QUOTE,
        _______, _______  , _______   , _______, RGB_MODE_FORWARD, QK_BOOTLOADER,            QK_BOOTLOADER, RGB_MODE_FORWARD, KC_P2  , KC_P3  , KC_EQL , KC_UNDS,
                            _______   , KC_PSCR,                                                                              _______, KC_P0  ,
                                                 _______         , _______      ,            _______      , _______,
                                                 _______         , _______      ,            _______      , _______,
                                                 _______         , _______      ,            _______      , _______

    ),

    [_RAISE] = LAYOUT_5x6(
          KC_GRV , KC_F1  , KC_F2  , KC_F3        , KC_F4           , KC_F5        ,               KC_F6        , KC_F7       , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
          _______, _______, _______,  _______     , _______         , KC_LBRC      ,               RGB_VAI      , _______     , KC_NUM , KC_INS , KC_SCRL, KC_VOLU,
          _______, _______, _______,  _______     , _______         , KC_LPRN      ,               RGB_VAD      , KC_MPRV     , KC_MPLY, KC_MNXT, _______, KC_VOLD,
          _______, _______, _______, RALT(KC_COMM), RGB_MODE_FORWARD, QK_BOOTLOADER,               QK_BOOTLOADER, _______     , _______, _______, _______, _______,
                            _______, KC_PSCR      ,                                                                             _______, _______,
                                                    _______         , _______      ,               _______      , _______     ,
                                                    _______         , _______      ,               _______      , _______     ,
                                                    _______         , _______      ,               KC_PAGE_UP   , KC_PAGE_DOWN
    ),
    [_GAMING] = LAYOUT_5x6(
        KC_GRV , KC_ESC , KC_1   , KC_2   , KC_3     , KC_4   ,           KC_6     , KC_7   , KC_8   , KC_9  , KC_0   , KC_BSPC,
        KC_TAB , KC_TAB , KC_Q   , KC_W   , KC_E     , KC_R   ,           KC_Y     , KC_U   , KC_I   , KC_O  , KC_P   , KC_MINS,
        KC_LSFT, KC_LSFT, KC_A   , KC_S   , KC_D     , KC_F   ,           KC_H     , KC_J   , KC_K   , KC_L  , KC_SCLN, KC_QUOTE,
        KC_LCTL, KC_LCTL, KC_Z   , KC_X   , KC_C     , KC_V   ,           KC_N     , KC_M   , KC_COMM, KC_DOT, KC_SLSH, KC_BACKSLASH,
                          KC_LBRC, KC_RBRC,                                                   KC_PLUS, KC_EQL,
                                            RAISE    , KC_SPC ,           KC_ENT   , LOWER  ,
                                            KC_LGUI  , KC_LALT,           KC_QWERTY, KC_LGUI,
                                            KC_QWERTY, KC_GRV ,           KC_HOME  , KC_END
    )
};
