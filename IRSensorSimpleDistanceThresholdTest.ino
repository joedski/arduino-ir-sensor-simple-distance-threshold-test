// Useful links
// Vishay App Note on Fast Proximity Sensing:
//   http://www.vishay.com/docs/82741/tssp4056sensor.pdf
// Vishay App Note on Slow Proximity Sensing with Directionality:
//   https://www.vishay.com/docs/82729/tsspagcpsensor.pdf
// Code mentioned in the Slow Proximity Sensing note:
//   http://www.vishay.com/doc?82728
// Next best thing to the ATMega32 data sheet regarding FWM:
//   https://www.arduino.cc/en/Tutorial/SecretsOfArduinoPWM

// These start and stop Arduino Pin 3 pulsing.
#define stopPulsing() TCCR2A &= ~(1<<COM2B1)
#define startPulsing() TCCR2A |= (1<<COM2B1)
#define setPulseDuty(duty) OCR2B = duty

// Timing Settings
// With the timer settins, this gives us a freq of 38kHz.
// See the App Note on Slow Proximity Sensing for details on the math,
// but in short:
//   HALF_PERIOD = 16MHz / (2 * 38kHz)
// For 56kHz, we'd need
//   16e6 / (2 * 56e3) = 142.86...
//   or 143, with a negligible 0.1% error.
#define HALF_PERIOD 210
// Duty is actually as you'd expect:
//   DUTY = 30% * HALF_PERIOD
// As it goes higher, Pin 3 is switched off for less and less time,
// thus increasing the cycle duty.
#define DUTY_LOW 63
// 50%
#define DUTY_MID 105
// 67%
#define DUTY_HIGH 126

void setup() {
  // This is basically copied verbatim from the Slow Proximity note.
  // Granted, it does exactly what I want, and there's
  // only so many ways to twiddle bits.

  // Mode5: PWM phase correct with TOP=OCR2A
  // OC2A pin not used, OC2B disconnected for now
  TCCR2A = (1<<WGM20) | (0<<COM2B1);
  // FOC not used, no prescaler, final bit of Mode5 setting
  TCCR2B = (1<<WGM22) | (1<<CS20);

  // set timer2 TOP value
  OCR2A = HALF_PERIOD;
  // set switching value for the output pin
  OCR2B = DUTY_LOW;

  // set arduino D3, AVR PD3 as output pin
  DDRD |= (1<<DDD3);
}

void loop() {
  // TODO: ... stuff!
  // - Turn pulse train on for so many pulses
  // - Turn pules train off for so many pulses
  // - See ef sensor activated (sufficiently?) during that time
}
