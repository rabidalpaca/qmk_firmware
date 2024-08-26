#pragma once

#include_next <mcuconf.h>

//#define NOP_FUDGE 0.4


#undef WS2812_PIO_USE_PIO1
#define WS2812_PIO_USE_PIO1 TRUE

/*
#undef RP_I2C_USE_I2C0
#define RP_I2C_USE_I2C0 TRUE
*/
// Used for EEPROM
//#undef RP_SPI_USE_SPI0
//#define RP_SPI_USE_SPI0 TRUE

//#undef RP_USB_USE_ERROR_DATA_SEQ_INTR
//#define RP_USB_USE_ERROR_DATA_SEQ_INTR TRUE


//#undef RP_I2C_USE_I2C1
//#define RP_I2C_USE_I2C1 TRUE
