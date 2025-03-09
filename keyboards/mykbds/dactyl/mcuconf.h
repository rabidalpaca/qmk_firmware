#pragma once

#include_next <mcuconf.h>

// Used for EEPROM
#undef RP_SPI_USE_SPI0
#define RP_SPI_USE_SPI0 TRUE
