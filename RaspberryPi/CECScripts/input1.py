import cec

cec.init()

avr = cec.Device(5)
avr.set_av_input(1)
avr.set_audio_input(1)