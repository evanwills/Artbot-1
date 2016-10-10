#include button.h


button::button(byte pin) {
	btnPin = pin;
	pinMode(btnPin, INPUT);
}

void button::readButtion() {
	if (digitalRead(incrementBtn) == HIGH) {
		if (pressedForLoops < 65,535 ) {
			pressedForLoops += 1;
		}
	} else {
		pressedForLoops = 0;
	}
}

unsigned int button::buttonPressedFor() {
	readButtion();
	return pressedForLoops;
}
