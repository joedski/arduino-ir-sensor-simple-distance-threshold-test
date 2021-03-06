IR Sensor - Simple Distance Threshold Test
==========================================

A simple distance threshold test using an IR sensor such as Vishay's TSOP38238 (that's what I used, anyway) and a bunch of IR LEDs.

This project does a _little_ jiggery pokery with Timer 2.  You may also notice a distinct lack of `analogWrite()`.

Pins used:
- Output:
  - Pin 3: Controls power to the emission LEDs, creating the pulse train.
  - Pins 4, 5, 6, 7: Used to switch out the emission LEDs, allowing me to change the power of emission for test reasons.
- Input:
  - Pin 13: Rising edge tells this code to cycle through how many of 4, 5, 6, and 7 to push High.
  - Pin 12: Rising edge toggles the duty cycle, which thus also changes the effective power of the LEDs.
  - Pin 10: IR Sensor.  Low means it's receiving a signal!

Useful links:
- [Vishay App Note on Fast Proximity Sensing](http://www.vishay.com/docs/82741/tssp4056sensor.pdf)
- [Vishay App Note on Slow Proximity Sensing with Directionality](https://www.vishay.com/docs/82729/tsspagcpsensor.pdf)
  - [Code mentioned in the Slow Proximity Sensing note](http://www.vishay.com/doc?82728)
- [Next best thing to the ATMega32 data sheet regarding FWM](https://www.arduino.cc/en/Tutorial/SecretsOfArduinoPWM)
