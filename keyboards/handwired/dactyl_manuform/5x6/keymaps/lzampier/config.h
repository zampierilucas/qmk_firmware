#pragma once

#define MASTER_LEFT
//#define MASTER_RIGHT

//#define EE_HANDS

#ifdef RGB_MATRIX_ENABLE
    #define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
    #define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
    #define RGB_MATRIX_LED_FLUSH_LIMIT 32 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 210 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
    #define RGB_MATRIX_HUE_STEP 8
    #define RGB_MATRIX_SAT_STEP 8
    #define RGB_MATRIX_VAL_STEP 42
    #define RGB_MATRIX_SPD_STEP 10

    // Enable animations
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS // Required for the following two effects

    #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON      // Full gradent Chevron shapped scrolling left to right
    // #define ENABLE_RGB_MATRIX_TYPING_HEATMAP               // How hot is your WPM!
    // #define ENABLE_RGB_MATRIX_BAND_SAT                    // Single hue baned ading saturation scrolling left to right
    // #define ENABLE_RGB_MATRIX_CYCLE_ALL                   // Full keyboard solid hue cycling through full gradient
    // #define RGB_MATRIX_BAND_PINWHEEL_SAT
    // #define RGB_MATRIX_BAND_PINWHEEL_VAL
    // #define RGB_MATRIX_PIXEL_FRACTAL
    // #define RGB_MATRIX_PIXEL_FLOW
    // #define RGB_MATRIX_PIXEL_RAIN
    // #define RGB_MATRIX_SOLID_REACTIVE_WIDE
    // #define RGB_MATRIX_SOLID_REACTIVE_NEXUS
    // #define RGB_MATRIX_SPLASH
#endif
