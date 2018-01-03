/*
The MIT License (MIT)

Copyright (c) 2017 Sebastian Pauka

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#ifndef SPI_RADIO_CMDS_H
#define SPI_RADIO_CMDS_H

// States
static const uint8_t SPI_STATE_ON = 0x01;
static const uint8_t SPI_STATE_OFF = 0x00;
static const uint8_t SPI_QUERY = 0x02;

// Peripherals
static const uint8_t SPI_RADIO_STATE = 0x01 << 2;
static const uint8_t SPI_RADIO_FREQ = 0x02 << 2;
static const uint8_t SPI_RADIO_POWER = 0x03 << 2;
static const uint8_t SPI_MSG_AVAIL = 0x04 << 2;

// Cmds from master
typedef enum {
    SPI_NOOP = 0x00,
    // Radio State
    SPI_RADIO_STATE_DISABLE = SPI_RADIO_STATE | SPI_STATE_OFF,
    SPI_RADIO_STATE_ENABLE = SPI_RADIO_STATE | SPI_STATE_ON,
    SPI_RADIO_STATE_QUERY = SPI_RADIO_STATE | SPI_QUERY,
    // Radio Frequency
    SPI_RADIO_FREQ_SET = SPI_RADIO_FREQ,
    SPI_RADIO_FREQ_QUERY = SPI_RADIO_FREQ | SPI_QUERY,
    // Radio Transmit Power
    SPI_RADIO_POWER_SET = SPI_RADIO_POWER,
    SPI_RADIO_POWER_QUERY = SPI_RADIO_POWER | SPI_QUERY,
    // Message Available Query
    SPI_MSG_QUERY = SPI_MSG_AVAIL | SPI_QUERY
} spi_radio_cmds_t;

// Responses
typedef enum {
    SPI_NOCMD = 0x00,
    SPI_SUCCESS = 0x01,
    SPI_OUT_OF_RANGE = 0x02,
    SPI_FAIL = 0xFF
} spi_radio_responses_t;

#endif
