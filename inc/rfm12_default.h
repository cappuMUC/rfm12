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
 * \file   rfm12_default.h
 *
 * \author Bernhard Rohloff <rohloff.bernhard@gmail.com>
 *
 * \brief  default command settings for configuration
 *
 */

#ifndef RFM12_DEFAULT_H
#define RFM12_DEFAULT_H

#include "rfm12_command.h"

#define CMD_CONFIG_SETTING_DEFAULT (    \
        RFM12_CMD_CONFIG_SETTING     |  \
        INTERNAL_DATA_REG_ENABLED    |  \
        FIFO_MODE_ENABLED            |  \
        FREQUENCY_BAND_433_MHZ       |  \
        XTAL_LOAD_CAPACITANCE_10_PF     \
        )

#define CMD_POWER_MANAGEMENT_DEFAULT (  \
        RFM12_CMD_POWER_MANAGEMENT   |  \
        CLOCK_OUTPUT_DISABLE            \
        )

#define CMD_FREQUENCY_SETTING_DEFAULT ( \
        RFM12_CMD_FREQUENCY_SETTING  |  \
        FREQUENCY_SETTING_VALUE(RFM12_INIT_FREQUENCY_HZ) \
        )

#define CMD_DATA_RATE_DEFAULT ( \
        RFM12_CMD_DATA_RATE |   \
        DATA_RATE_CS_BIT    |   \
        DATA_RATE_VALUE(RFM12_BAUDRATE) \
        )

#define CMD_POWER_SETTING_DEFAULT ( \
        RFM12_CMD_POWER_SETTING   | \
        PIN16_INTERRUPT_INPUT     | \
        VDI_RESPONSE_FAST         | \
        BASEBAND_BANDWIDTH_400KHZ | \
        LNA_GAIN_MINUS_0DB        | \
        RSSI_THRESHOLD_MINUS_97DB   \
        )

<<<<<<< HEAD:inc/rfm12_default.h
#define CMD_DATA_FILTER_DEFAULT ( \
=======
#define CMD_DATA_FILTER_DEFAULD ( \
>>>>>>> 7f90bed8c88aeb3213b729b5edf3006d203ea51a:inc/rfm12_default.h
        RFM12_CMD_DATA_FILTER   | \
        CLK_RECOVERY_AUTO_LOCK  | \
        FILTER_TYPE_DIGITAL     | \
        DATA_QUALITY_THRESHOLD(RFM12_DATA_QUALITY_THRESHOLD) \
        )

#define CMD_TX_CONFIG_DEFAULT (       \
        RFM12_CMD_TX_CONFIG_CONTROL | \
        FSK_BANDWIDTH_VAULE(RFM12_INIT_BANDWIDTH_KHZ) | \
        OUTPUT_POWER_GAIN_VALUE(RFM12_INIT_TX_GAIN)     \
        )


#endif
