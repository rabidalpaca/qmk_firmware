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

#define NOP_FUDGE 0.4


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
    KC_SECRET_31,
    KC_SECRET_32,
    KC_SECRET_33,
    KC_SECRET_34,
    KC_SECRET_35,
    KC_SECRET_36,
    MY_SEL,
    MY_WHR,
    MY_WHRC,
    MY_IN,
    MY_INC,
	MY_LK,
    MY_SQ,
    MY_DQ,
    MY_EQ,
    MY_JN1,
    MY_JN2,
    MY_ISN,
    MY_PAR,
    KC_EQEQ,
    KC_MYESC,
    MY_UP,
    MY_DECL,
    MY_OB,
    MY_GB,
    MY_AG1,
    MY_AG2,
    BSP_DEL,
    MY_WQ,
    MY_SYS,
    POINTER_DEFAULT_DPI_FORWARD,
    POINTER_DEFAULT_DPI_REVERSE,
    POINTER_SNIPING_DPI_FORWARD,
    POINTER_SNIPING_DPI_REVERSE,
    SNIPING_MODE,
    SNIPING_MODE_TOGGLE,
    DRAGSCROLL_MODE,
    DRAGSCROLL_MODE_TOGGLE,
    MY_SLMCR,
    MY_JNMCR,
    MY_WHMCR,
    MY_QTMCR,
    MY_AGMCR,
    MY_GBMCR,
    MY_SCHMCR,
    MY_SYSMCR,
    MY_DCMCR,
    MY_OPMCR,
    MY_EQMCR,
    MY_EXMCR,
    LLOCK,
    MS_SFTLC,
    MS_CTLLC
    };

#        define DPI_MOD POINTER_DEFAULT_DPI_FORWARD
#        define DPI_RMOD POINTER_DEFAULT_DPI_REVERSE
#        define S_D_MOD POINTER_SNIPING_DPI_FORWARD
#        define S_D_RMOD POINTER_SNIPING_DPI_REVERSE
#        define SNIPING SNIPING_MODE
#        define SNP_TOG SNIPING_MODE_TOGGLE
#        define DRGSCRL DRAGSCROLL_MODE
#        define DRG_TOG DRAGSCROLL_MODE_TOGGLE

/** \brief Return the current DPI value for the pointer's default mode. */
uint16_t piantor42_get_pointer_default_dpi(void);

/**
 * \brief Update the pointer's default DPI to the next or previous step.
 *
 * Increases the DPI value if `forward` is `true`, decreases it otherwise.
 * The increment/decrement steps are equal to piantor42_DEFAULT_DPI_CONFIG_STEP.
 *
 * The new value is persisted in EEPROM.
 */
void piantor42_cycle_pointer_default_dpi(bool forward);

/**
 * \brief Same as `piantor42_cycle_pointer_default_dpi`, but do not write to
 * EEPROM.
 *
 * This means that reseting the board will revert the value to the last
 * persisted one.
 */
void piantor42_cycle_pointer_default_dpi_noeeprom(bool forward);

/** \brief Return the current DPI value for the pointer's sniper-mode. */
uint16_t piantor42_get_pointer_sniping_dpi(void);

/**
 * \brief Update the pointer's sniper-mode DPI to the next or previous step.
 *
 * Increases the DPI value if `forward` is `true`, decreases it otherwise.
 * The increment/decrement steps are equal to piantor42_SNIPING_DPI_CONFIG_STEP.
 *
 * The new value is persisted in EEPROM.
 */
void piantor42_cycle_pointer_sniping_dpi(bool forward);

/**
 * \brief Same as `piantor42_cycle_pointer_sniping_dpi`, but do not write to
 * EEPROM.
 *
 * This means that reseting the board will revert the value to the last
 * persisted one.
 */
void piantor42_cycle_pointer_sniping_dpi_noeeprom(bool forward);

/** \brief Whether sniper-mode is enabled. */
bool piantor42_get_pointer_sniping_enabled(void);

/**
 * \brief Enable/disable sniper mode.
 *
 * When sniper mode is enabled the dpi is reduced to slow down the pointer for
 * more accurate movements.
 */
void piantor42_set_pointer_sniping_enabled(bool enable);

/** \brief Whether drag-scroll is enabled. */
bool piantor42_get_pointer_dragscroll_enabled(void);

/**
 * \brief Enable/disable drag-scroll mode.
 *
 * When drag-scroll mode is enabled, horizontal and vertical pointer movements
 * are translated into horizontal and vertical scroll movements.
 */
void piantor42_set_pointer_dragscroll_enabled(bool enable);
