import machine

spi = machine.SPI(1, baudrate=1000000)

import quokka_radio
nrf_slave_select = machine.Pin(0, machine.Pin.OUT)
nrf_slave_select.value(1)
r = quokka_radio.QuokkaRadio(nrf_slave_select, spi)
