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
#define SPI_MISO_PIN NO_PIN // We don't actually use MISO, so we set it to NO_PIN

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
#define RGB_MATRIX_LED_COUNT    108		// Number of LEDs on board  

/* Define lighting layers for using leds to display layers, caps lock, and other useful things */
//#define RGBLIGHT_LAYERS

#define QUANTUM_PAINTER_SUPPORTS_256_PALETTE TRUE
#define QUANTUM_PAINTER_LOAD_FONTS_TO_RAM TRUE
#define QUANTUM_PAINTER_PIXDATA_BUFFER_SIZE 128
// #define QUANTUM_PAINTER_DEBUG

