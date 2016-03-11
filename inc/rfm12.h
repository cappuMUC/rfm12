/*
 * Copyright (c)2015 by Bernhard Rohloff <rohloff.bernhard@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License (either version 2 or
 * version 3) as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * For more information on the GPL, please go to:
 * http://www.gnu.org/copyleft/gpl.html
 */

/**
 * \file rfm12.h
 *
 * \brief functions to access rfm12b module
 *
 * \details
 *
 * \author Bernhard Rohloff <rohloff.bernhard@gmail.com>
 */

<<<<<<< HEAD
/**
 * \brief Pointer to the low level SPI interface driver function.
 *
 *
 */
typedef uint16_t (*spiInterface_t)(uint16_t word);
 
/**
 * \brief Pointer to the low level SPI interface driver function.
 *
 *
 */
void rfm12_setSpiInterface( spiInterface_t iface);
 
/**
 * \brief Writes the configuration registers for initial setup.
 *
 * 
 */
void rfm12_initModule(uint16_t *config);

/**
 * \brief 
 *
 *
 */
void rfm12_updateStatus(void);

/**
 * \brief 
 *
 *
 */
bool rfm12_isTxModuleReady(void)

/**
 * \brief 
 *
 *
 */
void rfm12_txByte(char c);

/**
 * \brief 
 *
 *
 */
=======

void rfm12_init(uint16_t *config);
void rfm12_updateStatus(void);
void rfm12_txByte(char c);
>>>>>>> 7f90bed8c88aeb3213b729b5edf3006d203ea51a
char rfm12_rxByte(void);
