#include "Arduino.h"

#pragma once

class RotaryDial {
	public:
		static void setup(int PulsePin);
		static int available();
		static int readPulses();
		static int read();
	private:
		static unsigned long lastHigh;
		static int pulseCount;
		static int interruptPin;
		static void change();
		static int last;
};
