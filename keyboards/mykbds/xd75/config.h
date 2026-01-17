#pragma once

#define DEBUG_MATRIX_SCAN_RATE

// 0b1110100 AD <-> GND
// 0b1110111 AD <-> VCC
// 0b1110101 AD <-> SCL
// 0b1110110 AD <-> SDA

#ifdef RGB_MATRIX_ENABLE
#define RGB_DI_PIN GP26
// The number of LEDs connected
#define DRIVER_LED_TOTAL 10
#endif
#define LEADER_TIMEOUT 300
#define LEADER_PER_KEY_TIMING
#define COMBO_COUNT 4
/*
#ifdef RGB_MATRIX_ENABLE
    #define I2C_DRIVER          I2CD1
    #define I2C1_SDA_PIN        GP4
    #define I2C1_SCL_PIN        GP5
    #define DRIVER_ADDR_1       0b1110100
    #define DRIVER_COUNT        1
    #define DRIVER_1_LED_TOTAL  1
    #define DRIVER_LED_TOTAL    (DRIVER_1_LED_TOTAL) 
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
#endif
*/
