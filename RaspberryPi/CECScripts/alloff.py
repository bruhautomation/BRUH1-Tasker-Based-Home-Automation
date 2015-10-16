import cec

cec.init()


tv = cec.Device(0)
tv.standby()
avr = cec.Device(5)
avr.standby()