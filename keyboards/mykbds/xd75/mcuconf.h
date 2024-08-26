#pragma once

#include_next <mcuconf.h>

#define NOP_FUDGE 0.4

#ifdef RGB_MATRIX_ENABLE
#undef WS2812_PIO_USE_PIO1
#define WS2812_PIO_USE_PIO1 TRUE
#endif
/*
#undef RP_I2C_USE_I2C0
#define RP_I2C_USE_I2C0 TRUE
*/

