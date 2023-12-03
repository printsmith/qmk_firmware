// Copyright 2023 Tyler (@Tyler)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* Bootloeader defs for RP2040 */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

//// SPI Configuration
#define SPI_DRIVER SPID1
#define SPI_SCK_PIN GP13
#define SPI_MOSI_PIN GP12
// We don't actually use MISO, so set it to a pin we don't use.
// Otherwise it likely get's tripped up as we use GP16 for D/C
#define SPI_MISO_PIN GP25

//// LCD Configuration
#define LCD_RST_PIN GP14
#define LCD_CS_PIN 	GP22
#define LCD_DC_PIN 	GP18
#ifndef DISPLAY_ACTIVITY_TIMEOUT
#    define DISPLAY_ACTIVITY_TIMEOUT 30000
#endif // DISPLAY_ACTIVITY_TIMEOUT

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
//#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

// RGB configuration
#define RGB_ENABLE_PIN GP28

// RGB definitions
#define RGBLED_NUM 			108		// Number of LEDs on board  
#define RGBLIGHT_HUE_STEP 	8		// Number of steps to cycle through the hue by
#define RGBLIGHT_SAT_STEP 	8 		// Number of steps to increment the saturation by
#define RGBLIGHT_VAL_STEP 	8		// Number of steps to increment the brightness by
#define RGBLIGHT_LIMIT_VAL  50		// Maximum brightness. Using SK6803 mini-e each draw around 3mA at idle.
#define RGBLIGHT_SLEEP 				// RGB will turn off when PC is put to sleep

/* turn off effects when suspended */
#define RGB_DISABLE_WHEN_USB_SUSPENDED

/* Define lighting layers for using leds to display layers, caps lock, and other useful things */
//#define RGBLIGHT_LAYERS

#define QUANTUM_PAINTER_SUPPORTS_256_PALETTE TRUE
#define QUANTUM_PAINTER_LOAD_FONTS_TO_RAM TRUE
#define QUANTUM_PAINTER_PIXDATA_BUFFER_SIZE 128
// #define QUANTUM_PAINTER_DEBUG

