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


//this file is for static configurations

#ifndef RFM12_CONFIG_H
#define RFM12_CONFIG_H



/* Choose your modules baseband frequency between 315, 433, 868, 915 */

//General Settings 
#define RFM12_FREQUENCY_BAND_MHZ 433 //315, 433, 868 915
#define RFM12_INIT_FREQUENCY_HZ  433900000UL
#define RFM12_INIT_BANDWIDTH_KHZ 240
#define RFM12_INIT_TX_GAIN       3
#define RFM12_XTAL_LOAD_CAPACITANCE_PF 8.5

#define RFM12_BAUDRATE 9600

#define RFM12_DATA_QUALITY_THRESHOLD 5 // Value must be between 0 and 7

//Power Settings
#define RFM12_USE_WAKEUP_TIMER 0
#define RFM12_USE_BATTERY_MON  0
#define RFM12_CLOCK_OUTPUT     0


<<<<<<< HEAD
=======

#define RFM12_SPI_TRANSFER_16BIT app_rfm12Transfer16Bit
extern uint16_t RFM12_SPI_TRANSFER_16BIT(uint16_t w);
>>>>>>> 7f90bed8c88aeb3213b729b5edf3006d203ea51a
#endif
