/* Copyright 2020 zvecr <git@zvecr.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "dactyl.h"

// clang-format off
/*
led_config_t g_led_config = { {
    { 1, 2, 3, 4, 5, 6 },
    { NO_LED, NO_LED, NO_LED,  NO_LED, NO_LED, NO_LED },
    { NO_LED, NO_LED, NO_LED,  NO_LED, NO_LED, NO_LED },
    { 7, 8, 9, 10, 11, 12 },
    { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
    { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
    { NO_LED, NO_LED, NO_LED  },
    { NO_LED, NO_LED, NO_LED  }
}, {
    { 6, 1 }, { 6, 2 }, { 6, 3 }, { 6, 4 }, { 6, 5 }, { 6, 6 }, { 6, 16 },  { 6, 17 } , { 6, 18 } , { 6, 19} , { 6, 20 } ,  { 6, 21 }// right thumb cluster
}, {
    4,4,4,4,4,4,4,4,4,4,4,4
} };
*/
// clang-format on

#ifdef CONSOLE_ENABLE
#    include "print.h"
#endif // CONSOLE_ENABLE


