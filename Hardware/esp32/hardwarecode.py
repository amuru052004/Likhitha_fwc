from machine import Pin
from time import sleep

# Define pushbuttons
button_a = Pin(14, Pin.IN, Pin.PULL_DOWN)
button_b = Pin(15, Pin.IN, Pin.PULL_DOWN)

# Define LED
led = Pin(13, Pin.OUT)

while True:
    a = button_a.value()
    b = button_b.value()

    # NAND logic: output is off only if both inputs are high
    if a == 1 and b == 1:
        led.value(0)  # LED off
    else:
        led.value(1)  # LED on

    sleep(0.1)
