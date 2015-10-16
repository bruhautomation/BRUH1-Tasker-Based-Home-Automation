import cec

cec.init()

tv = cec.Device(0)
tv.power_on()
avr = cec.Device(5)
avr.power_on()