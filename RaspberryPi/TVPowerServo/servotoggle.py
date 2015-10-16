#signalpin is pin 7
#power is pin 2
#ground is pin 6


import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD)

GPIO.setup(7, GPIO.OUT)

p = GPIO.PWM(7,50)
p.start(7.5)

p.ChangeDutyCycle(11.0)
time.sleep(1)
p.ChangeDutyCycle(5)
time.sleep(0.5)


print "1"

p.stop()
GPIO.cleanup()

