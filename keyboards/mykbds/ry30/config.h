#pragma once

// 0b1110101 AD <-> SCL
// 0b1110100 AD <-> GND
#include "config_common.h"
// 0b1110111 AD <-> VCC
// 0b1110110 AD <-> SDA

#ifdef RGB_MATRIX_ENABLE
#define RGB_DI_PIN GP17
#define DRIVER_LED_TOTAL 1
#define RGB_MATRIX_LED_COUNT 1
#define RGBLED_NUM 1
#define WS2812_PIO_USE_PIO1
#define RGB_MATRIX_DEFAULT_SAT 255

     /* Enable Framebuffer and keypress effects */
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES

#define ENABLE_RGB_MATRIX_BREATHING
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 80

#endif

#define TAPPING_TERM 250
#define COMBO_TERM 65

#define COMBO_COUNT 8

#define MEDIA_KEY_DELAY 2

#define USB_POLLING_INTERVAL_MS 1
#define FORCE_NKRO
