import cec

cec.init()

avr = cec.Device(5)
avr.set_av_input(3)
avr.set_audio_input(3)
