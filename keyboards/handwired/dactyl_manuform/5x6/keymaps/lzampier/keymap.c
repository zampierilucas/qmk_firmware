#include QMK_KEYBOARD_H
#include <stdio.h>

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
// RALT(KC_QUOTE)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x6(
        KC_ESC , KC_1, KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC       ,
        KC_TAB , KC_Q, KC_W   , KC_E   , KC_R   , KC_T   ,                   KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS       ,
        KC_LSFT, KC_A, KC_S   , KC_D   , KC_F   , KC_G   ,                   KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, RALT(KC_QUOTE),
        KC_LCTL, KC_Z, KC_X   , KC_C   , KC_V   , KC_B   ,                   KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_BACKSLASH  ,
                       KC_LBRC, KC_RBRC,                                                                KC_PLUS, KC_EQL ,
                                         RAISE  , KC_SPC ,                   KC_ENT , LOWER  ,
                                         KC_LGUI, KC_DEL ,                   KC_PGUP, KC_PGDN,
                                         KC_LALT, KC_APP ,                   KC_HOME, KC_END
    ),

    [_LOWER] = LAYOUT_5x6(
        KC_GRV , KC_F11 , KC_F12 , KC_F13 , KC_F14          , KC_F15       ,            LALT(KC_1)   , LALT(KC_2)      , LALT(KC_3) , LALT(KC_4) , LALT(KC_5),  KC_DEL ,
        _______, RGB_HUI, RGB_SAI, _______, _______         , KC_LBRC      ,            KC_RBRC      , _______         , KC_UP      , _______    , KC_GAMING   , KC_PLUS ,
        _______, RGB_HUD, RGB_SAD, _______, _______         , KC_LPRN      ,            KC_RPRN      , KC_LEFT         , KC_DOWN    , KC_RGHT    , KC_QWERTY   , KC_QUOTE,
        _______, _______, _______, _______, RGB_MODE_FORWARD, QK_BOOTLOADER,            QK_BOOTLOADER, RGB_MODE_FORWARD, KC_P2      , KC_P3      , KC_EQL    , KC_UNDS ,
                         _______, KC_PSCR,                                                                              _______     , KC_P0      ,
                                  _______, _______         ,                                          _______         , _______     ,
                                           _______         , _______      ,            _______      , _______,
                                           _______         , _______      ,            _______      , _______

    ),

    [_RAISE] = LAYOUT_5x6(
          KC_GRV , KC_F1  , KC_F2  , KC_F3        , KC_F4           , KC_F5        ,               KC_F6        , KC_F7       , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
          _______, KC_F11 , KC_F12 ,  _______     , _______         , KC_LBRC      ,               RGB_VAI      , _______     , KC_NUM , KC_INS , KC_SCRL, KC_VOLU,
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
                          KC_LBRC, KC_RBRC,                                                   KC_PLUS, KC_QWERTY,
                                            RAISE    , KC_SPC ,           KC_ENT   , LOWER  ,
                                            KC_LGUI  , KC_LALT,           KC_QWERTY, KC_LGUI,
                                            KC_QWERTY, KC_GRV ,           KC_HOME  , KC_END
    )
};

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_90; }

void render_rgb_status(void) {
    oled_write("RGB: ", false);
    static char temp[20] = {0};
    #ifdef RGB_MATRIX_ENABLE
        uint16_t brightness = ((uint16_t)rgblight_get_val() * UINT8_MAX) / RGB_MATRIX_MAXIMUM_BRIGHTNESS;
        snprintf(temp, sizeof(temp) + 1, "M:%3dB:%3dH:%3dS:%3d", rgblight_get_mode(), brightness, rgblight_get_hue(), rgblight_get_sat());
    #endif
    oled_write(temp, false);
}

void render_wpm(void) {
    static char temp[20] = {0};
    snprintf(temp, sizeof(temp) + 1, "\nW:%3d", get_current_wpm());
    oled_write(temp, false);
}

/* KEYBOARD PET START */

/* settings */
#define MIN_WALK_SPEED      10
#define MIN_RUN_SPEED       40

/* advanced settings */
#define ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
#define ANIM_SIZE           96   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

/* timers */
uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;

/* current frame */
uint8_t current_frame = 0;

/* status variables */
int   current_wpm = 0;
led_t led_usb_state;

bool isSneaking = false;
bool isJumping  = false;
bool showedJump = true;

/* logic */
static void render_luna(int LUNA_X, int LUNA_Y) {
    /* Sit */
    static const char PROGMEM sit[2][ANIM_SIZE] = {/* 'sit1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'sit2', 32x22px */
                                                   {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};

    /* Walk */
    static const char PROGMEM walk[2][ANIM_SIZE] = {/* 'walk1', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80, 0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03, 0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'walk2', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Run */
    static const char PROGMEM run[2][ANIM_SIZE] = {/* 'run1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'run2', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   }};

    /* Bark */
    static const char PROGMEM bark[2][ANIM_SIZE] = {/* 'bark1', 32x22px */
                                                    {
                                                        0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'bark2', 32x22px */
                                                    {
                                                        0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Sneak */
    static const char PROGMEM sneak[2][ANIM_SIZE] = {/* 'sneak1', 32x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04, 0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06, 0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
                                                     },

                                                     /* 'sneak2', 32x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04, 0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                     }};

    /* animation */
    void animate_luna(void) {
        /* jump */
        if (isJumping || !showedJump) {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y + 2);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y - 1);

            showedJump = true;
        } else {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y - 1);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y);
        }

        /* switch frame */
        current_frame = (current_frame + 1) % 2;

        /* current status */
        if (led_usb_state.caps_lock) {
            oled_write_raw_P(bark[abs(1 - current_frame)], ANIM_SIZE);

        } else if (isSneaking) {
            oled_write_raw_P(sneak[abs(1 - current_frame)], ANIM_SIZE);

        } else if (current_wpm <= MIN_WALK_SPEED) {
            oled_write_raw_P(sit[abs(1 - current_frame)], ANIM_SIZE);

        } else if (current_wpm <= MIN_RUN_SPEED) {
            oled_write_raw_P(walk[abs(1 - current_frame)], ANIM_SIZE);

        } else {
            oled_write_raw_P(run[abs(1 - current_frame)], ANIM_SIZE);
        }
    }

    /* animation timer */
    if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
        anim_timer = timer_read32();
        animate_luna();
    }

}

/* KEYBOARD PET END */
static void print_status_narrow(void) {
    /* Print current mode */
    oled_set_cursor(0, 0);

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write("QWRTY", false);
            break;
        case _GAMING:
            oled_write("GAMES", false);
            break;
        default:
            oled_write("UNDEF", false);
    }

    oled_set_cursor(0, 2);

    /* Print current layer */
    oled_write("LAYER", false);

    oled_set_cursor(0, 3);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write("Base ", false);
            break;

        case _RAISE:
            oled_write("Raise", false);
            break;

        case _LOWER:
            oled_write("Lower", false);
            break;

        default:
            oled_write("Undef", false);
    }

    /* caps lock */
    oled_set_cursor(0, 5);

    #ifdef RGB_MATRIX_ENABLE
        render_rgb_status();
    #endif

    render_wpm();
    /* KEYBOARD PET RENDER START */

    render_luna(0, 13);

    /* KEYBOARD PET RENDER END */
}

bool oled_task_user(void) {
    // Host Keyboard Layer Status
    current_wpm   = get_current_wpm();

    if (is_keyboard_master()) {
        print_status_narrow();
    }
    return false;
}
#endif

static uint16_t idle_timer = 0;
static uint8_t halfmin_counter = 0;

void matrix_scan_user(void) {
    if (timer_elapsed(idle_timer) > 30000) {
        halfmin_counter++;
        idle_timer = timer_read();
    }

    // if (halfmin_counter / 2 >= RGBLIGHT_TIMEOUT)
        // #ifdef RGB_MATRIX_ENABLE
        //     rgblight_disable_noeeprom();
        // #endif

    if (halfmin_counter / 2 >= OLEDDISPLAY_TIMEOUT)
        oled_off();
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        // #ifdef RGB_MATRIX_ENABLE
        //     rgblight_enable_noeeprom();
        // #endif
        oled_on();
        idle_timer = timer_read();
        halfmin_counter = 0;
    }

    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;

        case KC_GAMING:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAMING);
            }
            return false;

        /* KEYBOARD PET STATUS START */
        case KC_LCTL:
        case KC_RCTL:
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
            break;
        case KC_SPC:
            if (record->event.pressed) {
                isJumping  = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            break;
    }
    return true;
}




#ifdef RGB_MATRIX_ENABLE
// LED layout
// 00  01  02  03  04  05     37  36  35  34  33  32
// 06  07  08  09  10  11     43  42  41  40  39  38
// 12  13  14  15  16  17     49  48  47  46  45  44
// 18  19  20  21  22  23     55  54  53  52  51  50
//         24  25		              57  56
//             26  27 	          59  58
//                 28  29     61  60
//                 31  30     62  63

    led_config_t g_led_config = { {
    // Key matrix to LED index
    // Left 1-31
    {0,      1,      2,      3,      4,      5},
    {6,      7,      8,      9,      10,     11},
    {12,     13,     14,     15,     16,     17},
    {18,     19,     20,     21,     22,     23},
    {NO_LED, NO_LED, 24,     25,     NO_LED, NO_LED},
    {27,     31,     30,     29,     31,     28},
    // Right 32-63
    {37,     36,     35,     34,     33,     32},
    {43,     42,     41,     40,     39,     38},
    {49,     48,     47,     46,     45,     44},
    {55,     54,     53,     52,     51,     50},
    {NO_LED, NO_LED, 57,     56,     NO_LED, NO_LED},
    {60,     63,     61,     62,     58,     59},  }, {
    // LED index to physical position
    // Left 1-18
    // 0   20  41  61  81  102
    {0, 0},{20, 0},{41, 0},{61, 0},{81, 0},{102, 0},   // 0
    {0,13},{20,13},{41,13},{61,13},{81,13},{102,13},   // 13
    {0,26},{20,26},{41,26},{61,26},{81,26},{102,26},   // 26
    {0,38},{20,38},{41,38},{61,38},{81,38},{102,38},   // 38
                   {41,51},{61,51},                    // 51
                                   {81,64},{102,70},
                                           {110,77},{125,113},
                                           {110,126},{102,78},    // 64

    // Right 1-18
    // 122 143 163 183 204 224
    {224, 0},{204, 0},{183, 0},{163, 0},{143, 0},{122, 0},   // 0
    {224,13},{204,13},{183,13},{163,13},{143,13},{122,13},   // 13
    {224,26},{204,26},{183,26},{163,26},{143,26},{122,26},   // 26
    {224,38},{204,38},{183,38},{163,38},{143,38},{122,38},   // 38
                      {183,51},{163,51},                     // 51
             {143,64},{122,70},
    {123,77},{115,113},
    {100,126},{115,77},   // 64
    }, {
        // LED index to flag
        // Left 1-18
        4,4,4,4,4,4,
        4,4,4,4,4,4,
        4,4,4,4,4,4,
        4,4,4,4,4,4,
        4,4,
        4,4,4,4,4,4,
        // Right 1-18
        4,4,4,4,4,4,
        4,4,4,4,4,4,
        4,4,4,4,4,4,
        4,4,4,4,4,4,
        4,4,
        4,4,4,4,4,4,
    } };

    void suspend_power_down_kb(void) {
        oled_off();
        rgb_matrix_disable();
        suspend_power_down_user();
    }

    void suspend_wakeup_init_kb(void) {
        oled_on();
        rgb_matrix_enable();
        suspend_wakeup_init_user();
    }
#endif
