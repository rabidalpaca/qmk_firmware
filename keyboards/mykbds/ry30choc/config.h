#pragma once

// 0b1110100 AD <-> GND
// 0b1110111 AD <-> VCC
// 0b1110101 AD <-> SCL
// 0b1110110 AD <-> SDA
#include "config_common.h"

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 6
#define MATRIX_COLS 5

// wiring of each half
#define MATRIX_ROW_PINS { GP2, GP9, GP19 } //GP10
#define MATRIX_COL_PINS { GP20, GP7, GP26, GP4, GP28 }

//#define MASTER_LEFT

#define DIODE_DIRECTION COL2ROW

//#define DIODE_DIRECTION ROW2COL

#define DEBOUNCE 5

/* serial.c configuration for split keyboard */
#define SOFT_SERIAL_PIN GP0
//#define SERIAL_PIO_USE_PIO1

//#define SPLIT_MAX_CONNECTION_ERRORS 0
//#define SERIAL_USART_DRIVER SIOD0 // USART driver of TX and RX pin. default: SD1
//#define SERIAL_USART_TIMEOUT 20    // USART driver timeout. default 20
//#define SPLIT_USB_DETECT


#ifdef RGB_MATRIX_ENABLE
#define RGB_DI_PIN GP29
#define DRIVER_LED_TOTAL 6
#define RGB_MATRIX_LED_COUNT 6
#define RGBLED_NUM 6
#define WS2812_PIO_USE_PIO1
#define RGBLED_SPLIT { 3, 3 }
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100



     /* Enable Framebuffer and keypress effects */
#    define ENABLE_RGB_MATRIX_BREATHING
#endif

#define TAPPING_TERM 250
#define COMBO_TERM 65

#define COMBO_COUNT 8

#define MEDIA_KEY_DELAY 2

#define USB_POLLING_INTERVAL_MS 1
#define FORCE_NKRO

