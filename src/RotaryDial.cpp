#include "Arduino.h"
#include "RotaryDial.h"

#define MS_DEBOUNCE 15
#define MS_DIGITEND 600

int RotaryDial::interruptPin = 2;
int RotaryDial::last = 0;
unsigned long RotaryDial::lastHigh = 0;
int RotaryDial::pulseCount = 0;

void RotaryDial::setup(int pulsePin) {
  interruptPin = pulsePin;
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), RotaryDial::change, CHANGE);
}

void RotaryDial::change() {
  //Ignore interrupts that do not change state
  int state = digitalRead(interruptPin);
  if(state == last) return;
  last = state;

  /*If there is an unread digit when a new pulse arrives, we have a choice:
    (1) ignore the new pulses until the last digit is read ("first in wins"), or
    (2) discard the unread digit and start accumulating a new one ("last in wins").
    Note that the first-in-wins semantics can result in partial pulse-trains
    being counted (and corrupt digits returned) on subsequent read()s.
    Hence the default semantics is last-in-wins, but it can be changed e.g.
    with "-DRD_FIRST_IN_WINS" compile flag or by uncommenting the following line:
  */
//#define RD_FIRST_IN_WINS
#ifdef RD_FIRST_IN_WINS
  if(available()) return;
#else
  if(available()) { pulseCount = 0; }
#endif

  //Process signal edges
  if(state) { //RISING

    lastHigh = millis();
    return;

  } else { //FALLING

    unsigned long highLen = millis() - lastHigh;
    if(highLen > MS_DEBOUNCE) {
      //Serial.println(highLen);
      pulseCount++;
    }

  }

  return;
}

int RotaryDial::available() {
  return (pulseCount > 0 && millis() - lastHigh > MS_DIGITEND);
}

int RotaryDial::readPulses() {
  if(available()) {
    int ret = pulseCount;
    pulseCount=0;
    return ret;
  }
  return -1;
}

int RotaryDial::read() {
  int ret = readPulses();
  if(ret == 10) return 0;
  return ret;
}
