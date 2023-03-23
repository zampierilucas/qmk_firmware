# Build Options
EXTRAKEY_ENABLE = yes       # Audio control and System control
WPM_ENABLE = yes
SPLIT_WPM_ENABLE = yes
TAP_DANCE_ENABLE = no
# RGB
RGB_MATRIX_ENABLE = no
# RGB_MATRIX_DRIVER = WS2812

RGBLIGHT_ENABLE = yes
RGBLIGHT_DRIVER = WS2812

# OLED
OLED_ENABLE = yes
OLED_DRIVER = SSD1306

# Debounce
# https://github.com/qmk/qmk_firmware/blob/master/docs/feature_debounce_type.md
#DEBOUNCE_TYPE = sym_defer_pk
DEBOUNCE_TYPE = sym_eager_pk

# OPTIMIZATIONS
LTO_ENABLE = yes
AUDIO_ENABLE = no           # Audio output
MOUSEKEY_ENABLE = no        # Mouse keys
DEBUG_ENABLE = no
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
