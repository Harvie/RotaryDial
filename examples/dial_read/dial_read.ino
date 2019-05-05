#include <RotaryDial.h>

#define ROTARY_DIAL_PULSE_PIN 2 //PIN 2 supports interrupts on Arduino Nano
#define ROTARY_DIAL_TIMEOUT 3000 //If no numbers are dialed for this period, newline is sent

void setup() {
  Serial.begin(9600);
  RotaryDial::setup(ROTARY_DIAL_PULSE_PIN);
}

unsigned long lastdigit = 0;
int newline = true;

void loop() {
  if(RotaryDial::available()) {
    Serial.print(RotaryDial::read());
    lastdigit = millis();
    newline = false;
  } else {
    if(!newline && millis() - lastdigit > ROTARY_DIAL_TIMEOUT) {
      Serial.println(" OK");
      newline = true;
    }
  }
}
