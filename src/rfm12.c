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


#include "rfm12.h"
#include "rfm12_config.h"
#include "rfm12_cmd.h"

#include <stdint.h>
#include <stdbool.h>

#ifdef RFM12_DEBUG
    #include <stdio.h>
#endif

<<<<<<< HEAD
=======

static union {
    uint16_t value;
    struct {
    uint16_t bit_FFIT_RGIT : 1;
    uint16_t bit_POR       : 1;
    uint16_t bit_FFOV_RGUR : 1;
    uint16_t bit_WKUP      : 1;
    uint16_t bit_EXT       : 1;
    uint16_t bit_LBD       : 1;
    uint16_t bit_FFEM      : 1;
    uint16_t bit_ATS_RSSI  : 1;
    uint16_t bit_DQD       : 1;
    uint16_t bit_CRL       : 1;
    uint16_t bit_ATGL      : 1;
    uint16_t bit_OFFSET6   : 1;
    uint16_t bit_OFFSET3   : 1;
    uint16_t bit_OFFSET2   : 1;
    uint16_t bit_OFFSET1   : 1;
    uint16_t bit_OFFSET0   : 1;
    } bits;
} mStatus;


>>>>>>> 7f90bed8c88aeb3213b729b5edf3006d203ea51a

static union {
    uint16_t value;
    struct {
    uint16_t bit_FFIT_RGIT : 1;
    uint16_t bit_POR       : 1;
    uint16_t bit_FFOV_RGUR : 1;
    uint16_t bit_WKUP      : 1;
    uint16_t bit_EXT       : 1;
    uint16_t bit_LBD       : 1;
    uint16_t bit_FFEM      : 1;
    uint16_t bit_ATS_RSSI  : 1;
    uint16_t bit_DQD       : 1;
    uint16_t bit_CRL       : 1;
    uint16_t bit_ATGL      : 1;
    uint16_t bit_OFFSET6   : 1;
    uint16_t bit_OFFSET3   : 1;
    uint16_t bit_OFFSET2   : 1;
    uint16_t bit_OFFSET1   : 1;
    uint16_t bit_OFFSET0   : 1;
    } bits;
} mStatus;


void rfm12_defaultInit(void)
{
        RFM12_SPI_TRANSFER_16BIT(CMD_CONFIG_SETTING_DEFAULT);
        RFM12_SPI_TRANSFER_16BIT(CMD_POWER_MANAGEMENT_DEFAULT);
        RFM12_SPI_TRANSFER_16BIT(CMD_FREQUENCY_SETTING_DEFAULT);
        RFM12_SPI_TRANSFER_16BIT(CMD_DATA_RATE_DEFAULT);
        RFM12_SPI_TRANSFER_16BIT(CMD_POWER_SETTING_DEFAULT);
        RFM12_SPI_TRANSFER_16BIT(CMD_DATA_FILTER_DEFAULT);
        RFM12_SPI_TRANSFER_16BIT(CMD_FIFO_RESET_DEFAULT);
        
        rfm12_updateStatus();
}     

void rfm12_defaultInit(void)
{
        RFM12_SPI_TRANSFER_16BIT(CMD_CONFIG_SETTING_DEFAULT);
        RFM12_SPI_TRANSFER_16BIT(CMD_POWER_MANAGEMENT_DEFAULT);
        RFM12_SPI_TRANSFER_16BIT(CMD_FREQUENCY_SETTING_DEFAULT);
        RFM12_SPI_TRANSFER_16BIT(CMD_DATA_RATE_DEFAULT);
        RFM12_SPI_TRANSFER_16BIT(CMD_POWER_SETTING_DEFAULT);
        RFM12_SPI_TRANSFER_16BIT(CMD_DATA_FILTER_DEFAULT);
        RFM12_SPI_TRANSFER_16BIT(CMD_FIFO_RESET_DEFAULT);
        
        rfm12_updateStatus();
}     
        

void rfm12_init(uint16_t *config, uint8_t size)
{
    //initialize status register
    mStatus.value = 0;
    
    //send configuration commands to module
    for (uint8_t i = 0; i < size; i++) {
        RFM12_SPI_TRANSFER_16BIT(*(config+i));
    }
}

void rfm12_updateStatus(void)
{
    //read status register from module and set flag bits
    mStatus.value = RFM12_SPI_TRANSFER_16BIT(RFM12_CMD_READ_STATUS);
    
}

void rfm12_txByte(char c)
{   
    RFM12_SPI_TRANSFER_16BIT(RFM12_CMD_TX_DATA_WRITE | (uint16_t)c);
}

char rfm12_rxByte(void)
{
    //read data from rx fifo
    return (char)(RFM12_SPI_TRANSFER_16BIT(RFM12_CMD_RX_FIFO_READ) & 0x00FF);
}


bool rfm12_isTxModuleReady(void)
{
    return (rfm12_status.bit_FFIT_RGIT) ? true : false;
}
