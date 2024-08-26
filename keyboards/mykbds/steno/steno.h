#pragma once

#include "quantum.h"

#define LAYOUT_steno( \
    K00, \
    K10,   K11, K12, K13, K14, K15, K16, K17, K18, K19,\
    K20,   K21, K22, K23, K24, K25, K26, K27, K28, K29,\
    K30,   K31, K32, K33, K34, K35, K36, K37, K38, K39 \
    ) \
    { \
        { K00 }, \
        { K10,   K11, K12, K13, K14, K15, K16, K17, K18, K19 }, \
        { K20,   K21, K22, K23, K24, K25, K26, K27, K28, K29 }, \
        { K30,   K31, K32, K33, K34, K35, K36, K37, K38, K39 } \
    }
