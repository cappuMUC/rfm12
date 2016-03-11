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
 * \file   rfm12_command.h
 *
 * \author Bernhard Rohloff <rohloff.bernhard@gmail.com>
 *
 * \brief  definition of commands and bit flags
 *
 */
 

#ifndef RFM12_COMMAND_H
#define RFM12_COMMAND_H


#include "rfm12_config.h"

/* Register Defines */
/********************/
#define RFM12_CMD_CONFIG_SETTING       0x8000

#define INTERNAL_DATA_REG_ENABLED      0x0080

#define FIFO_MODE_ENABLED              0x0040

#define FREQUENCY_BAND_315_MHZ         0x0000
#define FREQUENCY_BAND_433_MHZ         0x0010
#define FREQUENCY_BAND_868_MHZ         0x0020
#define FREQUENCY_BAND_915_MHZ         0x0030

#define XTAL_LOAD_CAPACITANCE_8_5_PF   0x0000
#define XTAL_LOAD_CAPACITANCE_9_PF     0x0001
#define XTAL_LOAD_CAPACITANCE_9_5_PF   0x0002
#define XTAL_LOAD_CAPACITANCE_10_PF    0x0003
#define XTAL_LOAD_CAPACITANCE_10_5_PF  0x0004
#define XTAL_LOAD_CAPACITANCE_11_PF    0x0005
#define XTAL_LOAD_CAPACITANCE_11_5_PF  0x0006
#define XTAL_LOAD_CAPACITANCE_12_PF    0x0007
#define XTAL_LOAD_CAPACITANCE_12_5_PF  0x0008
#define XTAL_LOAD_CAPACITANCE_13_PF    0x0009
#define XTAL_LOAD_CAPACITANCE_13_5_PF  0x000A
#define XTAL_LOAD_CAPACITANCE_14_PF    0x000B
#define XTAL_LOAD_CAPACITANCE_14_5_PF  0x000C
#define XTAL_LOAD_CAPACITANCE_15_PF    0x000D
#define XTAL_LOAD_CAPACITANCE_15_5_PF  0x000E
#define XTAL_LOAD_CAPACITANCE_16_PF    0x000F



/********************/
#define RFM12_CMD_POWER_MANAGEMENT    0x8200

#define RECEIVER_CHAIN_ENABLE         0x0080
#define RECEIVER_BASEBAND_ENABLE      0x0040
#define TRANSMITTER_ENABLE            0x0020
#define SYNTHESIZER_ENABLE            0x0010
#define CRYSTAL_OSZILLATOR_ENABLE     0x0008
#define LOW_BATTERY_DETECTOR_ENABLE   0x0004
#define WAKE_UP_TIMER_ENABLE          0x0002
#define CLOCK_OUTPUT_DISABLE          0x0001



/********************/
#define RFM12_CMD_FREQUENCY_SETTING   0xA000

#if (RFM12_FREQUENCY_BAND_MHZ) == 315
    #define FREQUENCY_SETTING_VALUE(f) (((f)-310000000UL)/2500UL)
#elif (RFM12_FREQUENCY_BAND_MHZ) == 433
    #define FREQUENCY_SETTING_VALUE(f) (((f)-430000000UL)/2500UL)
#elif (RFM12_FREQUENCY_BAND_MHZ) == 868
    #define FREQUENCY_SETTING_VALUE(f) (((f)-860000000UL)/5000UL)
#elif (RFM12_FREQUENCY_BAND_MHZ) == 915
    #define FREQUENCY_SETTING_VALUE(f) (((f)-900000000UL)/7500UL)
#else
    #error "RFM12: Incorrect frequency band configured!"
#endif



/********************/
#define RFM12_CMD_DATA_RATE           0xC600

#if RFM12_BAUDRATE < 2700
    #define DATA_RATE_CS_BIT              0x0080
    #define DATA_RATE_VALUE() (uint8_t)((10000000 / 29 / 1 / RFM12_BAUDRATE) - 1)
    
#elif RFM12_BAUDRATE < 115200
    #define DATA_RATE_CS_BIT              0x0000
    #define DATA_RATE_VALUE() (uint8_t)((10000000 / 29 / 8 / RFM12_BAUDRATE) - 1)
    
#else
    #error "RFM12: Baudrate is too high!"
#endif



/********************/
#define RFM12_CMD_POWER_SETTING       0x9000

#define PIN16_INTERRUPT_INPUT         0x0000
#define PIN16_VDI_OUTPUT              0x0400

#define VDI_RESPONSE_FAST             0x0000
#define VDI_RESPONSE_MEDIUM           0x0100
#define VDI_RESPONSE_SLOW             0x0200
#define VDI_RESPONSE_ALWAYS_ON        0x0300

#define BASEBAND_BANDWIDTH_400KHZ     0x0020
#define BASEBAND_BANDWIDTH_340KHZ     0x0040
#define BASEBAND_BANDWIDTH_270KHZ     0x0060
#define BASEBAND_BANDWIDTH_200KHZ     0x0080
#define BASEBAND_BANDWIDTH_134KHZ     0x00A0
#define BASEBAND_BANDWIDTH_067KHZ     0x00C0

#define LNA_GAIN_MINUS_0DB            0x0000
#define LNA_GAIN_MINUS_6DB            0x0008
#define LNA_GAIN_MINUS_14DB           0x0010
#define LNA_GAIN_MINUS_20DB           0x0018

#define RSSI_THRESHOLD_MINUS_103DB    0x0000
#define RSSI_THRESHOLD_MINUS_097DB    0x0001
#define RSSI_THRESHOLD_MINUS_091DB    0x0002
#define RSSI_THRESHOLD_MINUS_085DB    0x0003
#define RSSI_THRESHOLD_MINUS_079DB    0x0004
#define RSSI_THRESHOLD_MINUS_073DB    0x0005



/********************/
#define RFM12_CMD_DATA_FILTER         0xC200

#define CLK_RECOVERY_AUTO_LOCK        0x0080
#define CLK_RECOVERY_LOCK_FAST        0x0040
#define CLK_RECOVERY_AUTO_SLOW        0x0000

#define FILTER_TYPE_DIGITAL           0x0000
#define FILTER_TYPE_ANALOG            0x0010

#define DATA_QUALITY_THRESHOLD(x)     (x & 0x0007)



/********************/
#define RFM12_CMD_FIFO_RESET_MODE     0xCA00

#define FILL_AFTER_SYNC_PATTERN       0x0000
#define FILL_ALWAYS_WITHOUT_SYNC      0x0004

#define FIFO_FILL_ENABLED             0x0002
#define HIGH_SENSE_RST_MODE           0x0001

#define FIFO_IRQ_AT_BITS(x)           ((x & 0x000F) << 4)



/********************/
#define RFM12_CMD_RX_FIFO_READ        0xB000
// no bitflags 



/********************/
#define RFM12_CMD_AFC_OPERATION       0xC400

#define AUTO_MODE_OFF                 0x0000
#define AUTO_MODE_AFTER_STARTUP       0x0040
#define AUTO_MODE_AT_RECEIVING        0x0080
#define AUTO_MODE_ALWAYS_ON           0x00C0

#define OFFSET_RANGE_LIMIT_OFF        0x0000
#define OFFSET_RANGE_LIMIT_15X        0x0010
#define OFFSET_RANGE_LIMIT_07X        0x0020
#define OFFSET_RANGE_LIMIT_03X        0x0030

#define STROBE_EDGE_HIGH              0x0008
#define HIGH_ACCURACY_MODE            0x0004
#define ENABLE_FREQ_OFFSET_REGISTER   0x0002
#define ENABLE_OFFSET_CALCULATION     0x0001


       
/********************/
#define RFM12_CMD_TX_CONFIG_CONTROL   0x9800

#define FSK_FREQ_SHIFT_INVERSE        0x0100

#define FSK_BANDWIDTH_15KHZ           0x0000
#define FSK_BANDWIDTH_30KHZ           0x0010
#define FSK_BANDWIDTH_45KHZ           0x0020
#define FSK_BANDWIDTH_60KHZ           0x0030
#define FSK_BANDWIDTH_75KHZ           0x0040
#define FSK_BANDWIDTH_90KHZ           0x0050
#define FSK_BANDWIDTH_105KHZ          0x0060
#define FSK_BANDWIDTH_120KHZ          0x0070
#define FSK_BANDWIDTH_135KHZ          0x0080
#define FSK_BANDWIDTH_150KHZ          0x0090
#define FSK_BANDWIDTH_165KHZ          0x00A0
#define FSK_BANDWIDTH_180KHZ          0x00B0
#define FSK_BANDWIDTH_195KHZ          0x00C0
#define FSK_BANDWIDTH_210KHZ          0x00D0
#define FSK_BANDWIDTH_225KHZ          0x00E0
#define FSK_BANDWIDTH_240KHZ          0x00F0

#define FSK_BANDWIDTH_VAULE(x) (((x - 15) / 15) << 8)

#define OUTPUT_POWER_MINUS_0DB        0x0000
#define OUTPUT_POWER_MINUS_3DB        0x0001
#define OUTPUT_POWER_MINUS_6DB        0x0002
#define OUTPUT_POWER_MINUS_9DB        0x0003
#define OUTPUT_POWER_MINUS_12DB       0x0004
#define OUTPUT_POWER_MINUS_15DB       0x0005
#define OUTPUT_POWER_MINUS_18DB       0x0006
#define OUTPUT_POWER_MINUS_21DB       0x0007

#define OUTPUT_POWER_GAIN_VALUE(x) (x / 3)

/********************/
#define RFM12_CMD_TX_DATA_WRITE       0xB800
// no bitflags
 

 
/********************/
#define RFM12_CMD_WAKE_UP_TIMER       0xE000

// wake up timer calculation
// T(ms) = M*2^R
#define WAKE_UP_TIMER_M(x)            ((x & 0x001F) << 8)
#define WAKE_UP_TIMER_R(x)            (x & 0x00FF)


/********************/
#define RFM12_CMD_LOW_DUTY_CYCLE      0xC800

#define LOW_DUTY_CYCLE_ENABLE         0x0001

#define LOW_DUTY_CYCLE_VALUE(x)       ((x & 0x00FF) << 1)


/********************/
#define RFM12_CMD_LOW_BAT_CLK_DIV     0xC000

#define VOLTAGE_MULTIPLICATOR(x)      (x & 0x001F)

#define CLK_OUTPUT_FREQ_1_MHZ         0x0000
#define CLK_OUTPUT_FREQ_1_25_MHZ      0x0200
#define CLK_OUTPUT_FREQ_1_66_MHZ      0x0400
#define CLK_OUTPUT_FREQ_2_MHZ         0x0600
#define CLK_OUTPUT_FREQ_1_5_MHZ       0x0800
#define CLK_OUTPUT_FREQ_3_33_MHZ      0x0A00
#define CLK_OUTPUT_FREQ_5_MHZ         0x0C00
#define CLK_OUTPUT_FREQ_10_MHZ        0x0E00



/********************/
#define RFM12_CMD_SOFT_RESET          0xFFFF



/********************/
#define RFM12_CMD_READ_STATUS         0x0000

/* Interrupt Bits */
#define RFM12_STATUS_IRQ_RGIT         0x8000 ///< TX register is ready
#define RFM12_STATUS_IRQ_FFIT         0x8000 ///< defined number of bits in RX fifo
#define RFM12_STATUS_IRQ_POR          0x4000 ///< power on reset detected
#define RFM12_STATUS_IRQ_RGUR         0x2000 ///< TX register under run
#define RFM12_STATUS_IRQ_FFOV         0x2000 ///< RX FIFO overflow
#define RFM12_STATUS_IRQ_WKUP         0x1000 ///< wake up timer overflow
#define RFM12_STATUS_IRQ_EXT          0x0800 ///< detected falling edge on pin 16
#define RFM12_STATUS_IRQ_LBD          0x0400 ///< low battery detect

/* Status Bits */
#define RFM12_STATUS_FFEM             0x0200 ///< FIFO is emtpy
#define RFM12_STATUS_ATS              0x0100 ///< strong enough RF signal detected
#define RFM12_STATUS_RSSI             0x0100 ///< incoming signal is over programmed limit
#define RFM12_STATUS_DQD              0x0080 ///< data quality output
#define RFM12_STATUS_CRL              0x0040 ///< clock recovery locked
#define RFM12_STATUS_ATGL             0x0020 ///< toggling each AFC cycle

/* Frequency Offset Value */
#define RFM12_OFFSET_MSB              0x0010 ///< MSB (sign) of measured freq offset
#define RFM12_OFFSET_VALUE            0x000F ///< four LSB of measured freq offset


#endif /* RFM12_COMMAND_H */
