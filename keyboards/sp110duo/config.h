// Copyright 2023 Tyler (@Tyler)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* Bootloeader defs for RP2040 */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

/* SPI Configuration for display */
#define SPI_DRIVER SPID1
#define SPI_SCK_PIN GP14
#define SPI_MOSI_PIN GP11
#define SPI_MISO_PIN NO_PIN // We don't actually use MISO, so we set it to NO_PIN

/* LCD Configuration */
#ifdef QUANTUM_PAINTER_ENABLE

    #define LCD_RST_PIN GP13
    #define LCD_CS_PIN GP17
    #define LCD_DC_PIN GP18
    #define LCD_WIDTH 240
    #define LCD_HEIGHT 320
    #define LCD_SPI_DIVISOR 16 // tested with 8 as well
    #define SPI_MODE 3

    #define QUANTUM_PAINTER_SUPPORTS_256_PALETTE TRUE
    #define QUANTUM_PAINTER_SUPPORTS_NATIVE_COLORS TRUE
    #define QUANTUM_PAINTER_LVGL_USE_CUSTOM_CONF
    #define QUANTUM_PAINTER_DISPLAY_TIMEOUT 0

#endif // QUANTUM_PAINTER_ENABLE

#ifndef LCD_ACTIVITY_TIMEOUT
#    define LCD_ACTIVITY_TIMEOUT 10000
#endif // LCD_ACTIVITY_TIMEOUT

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
//#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* RGB configuration */
#ifdef RGB_MATRIX_ENABLE

    #define RGB_MATRIX_LED_COUNT 108                // Number of LEDs on board  
    #define RGB_ENABLE_PIN GP28                     // This pin also controls the LCD power
    #define RGB_MATRIX_HUE_STEP 8
    #define RGB_MATRIX_SAT_STEP 8
    #define RGB_MATRIX_VAL_STEP 8
    #define RGB_MATRIX_SPD_STEP 10

    // RGB animations
    #define ENABLE_RGB_MATRIX_ALPHAS_MODS            // Static dual hue, speed is hue for secondary hue
    #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN       // Static gradient top to bottom, speed controls how much gradient changes
    #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT    // Static gradient left to right, speed controls how much gradient changes
    #define ENABLE_RGB_MATRIX_BREATHING              // Single hue brightness cycling animation
    #define ENABLE_RGB_MATRIX_BAND_SAT               // Single hue band fading saturation scrolling left to right
    #define ENABLE_RGB_MATRIX_BAND_VAL               // Single hue band fading brightness scrolling left to right
    #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT      // Single hue 3 blade spinning pinwheel fades saturation
    #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL      // Single hue 3 blade spinning pinwheel fades brightness
    #define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT        // Single hue spinning spiral fades saturation
    #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL        // Single hue spinning spiral fades brightness
    #define ENABLE_RGB_MATRIX_CYCLE_ALL              // Full keyboard solid hue cycling through full gradient
    #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT       // Full gradient scrolling left to right
    #define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN          // Full gradient scrolling top to bottom
    #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN           // Full gradient scrolling out to in
    #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL      // Full dual gradients scrolling out to in
    #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON // Full gradient Chevron shaped scrolling left to right
    #define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL         // Full gradient spinning pinwheel around center of keyboard
    #define ENABLE_RGB_MATRIX_CYCLE_SPIRAL           // Full gradient spinning spiral around center of keyboard
    #define ENABLE_RGB_MATRIX_DUAL_BEACON            // Full gradient spinning around center of keyboard
    #define ENABLE_RGB_MATRIX_RAINBOW_BEACON         // Full tighter gradient spinning around center of keyboard
    #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS      // Full dual gradients spinning two halfs of keyboard
    #define ENABLE_RGB_MATRIX_RAINDROPS              // Randomly changes a single key's hue
    #define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS    // Randomly changes a single key's hue and saturation
    #define ENABLE_RGB_MATRIX_HUE_BREATHING          // Hue shifts up a slight amount at the same time, then shifts back
    #define ENABLE_RGB_MATRIX_HUE_PENDULUM           // Hue shifts up a slight amount in a wave to the right, then back to the left
    #define ENABLE_RGB_MATRIX_HUE_WAVE               // Hue shifts up a slight amount and then back down in a wave to the right
    #define ENABLE_RGB_MATRIX_PIXEL_FRACTAL          // Single hue fractal filled keys pulsing horizontally out to edges
    #define ENABLE_RGB_MATRIX_PIXEL_FLOW             // Pulsing RGB flow along LED wiring with random hues
    #define ENABLE_RGB_MATRIX_PIXEL_RAIN             // Randomly light keys with random hues
    
    #if defined (RGB_MATRIX_FRAMEBUFFER_EFFECTS)
        #define ENABLE_RGB_MATRIX_TYPING_HEATMAP // How hot is your WPM!
        #define ENABLE_RGB_MATRIX_DIGITAL_RAIN   // That famous computer simulation
    #endif

    #if defined(RGB_MATRIX_KEYPRESSES) || defined(RGB_MATRIX_KEYRELEASES)
        #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE     // Pulses keys hit to hue & value then fades value out
        #define ENABLE_RGB_MATRIX_SOLID_REACTIVE            // Static single hue, pulses keys hit to shifted hue then fades to current hue
        #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE       // Hue & value pulse near a single key hit then fades value out
        #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE  // Hue & value pulse near multiple key hits then fades value out
        #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS      // Hue & value pulse the same column and row of a single key hit then fades value out
        #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS // Hue & value pulse the same column and row of multiple key hits then fades value out
        #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS      // Hue & value pulse away on the same column and row of a single key hit then fades value out
        #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS // Hue & value pulse away on the same column and row of multiple key hits then fades value out
        #define ENABLE_RGB_MATRIX_SPLASH                    // Full gradient & value pulse away from a single key hit then fades value out
        #define ENABLE_RGB_MATRIX_MULTISPLASH               // Full gradient & value pulse away from multiple key hits then fades value out
        #define ENABLE_RGB_MATRIX_SOLID_SPLASH              // Hue & value pulse away from a single key hit then fades value out
        #define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH         // Hue & value pulse away from multiple key hits then fades value out
    #endif
#endif // RGB_MATRIX_ENABLE

/* Define lighting layers for using leds to display layers, caps lock, and other useful things */
//#define RGBLIGHT_LAYERS