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
#pragma once

#include "quantum.h"


enum custom_keycodes {
	KC_SECRET_1 = SAFE_RANGE,
	KC_SECRET_2,
	KC_SECRET_3,
	KC_SECRET_4,
	KC_SECRET_5,
	KC_SECRET_6,
	KC_SECRET_7,
	KC_SECRET_8,
	KC_SECRET_9,
	KC_SECRET_10,
	KC_SECRET_11,
	KC_SECRET_12,
	KC_SECRET_13,
	KC_SECRET_14,
	KC_SECRET_15,
	KC_SECRET_16,
	KC_SECRET_17,
	KC_SECRET_18,
	KC_SECRET_19,
	KC_SECRET_20,
	KC_SECRET_21,
	KC_SECRET_22,
	KC_SECRET_23,
	KC_SECRET_24,
	KC_SECRET_25,
	KC_SECRET_26,
	KC_SECRET_27,
	KC_SECRET_28,
	KC_SECRET_29,
	KC_SECRET_30,
	KC_QORB,
	KC_QSEL,
	KC_QWH1,
	KC_QWH2,
	KC_QWH3,
	KC_QJN1,
	KC_QJN2,
	KC_QJN3,
	};

#define LAYOUT( \
		 L00, L01, L02, L03, L04 \
    ) \
    { \
        { L00, L01, L02, L03, L04 } \
    }
