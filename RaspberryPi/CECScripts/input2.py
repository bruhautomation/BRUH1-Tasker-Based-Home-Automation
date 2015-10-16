import cec

cec.init()

avr = cec.Device(5)
avr.set_av_input(2)
avr.set_audio_input(2)