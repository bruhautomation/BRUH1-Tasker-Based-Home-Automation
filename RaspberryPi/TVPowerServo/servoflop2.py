import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD)

GPIO.setup(22, GPIO.OUT)

p = GPIO.PWM(22,50)
p.start(7.5)


p.ChangeDutyCycle(5.5)
time.sleep(1)
p.ChangeDutyCycle(9.4)
time.sleep(0.5)


print "1"

p.stop()
GPIO.cleanup()

