#include TimedButton.h


DumbButton::DumbButton(byte pin) {
	btnPin = pin;
	pinMode(btnPin, INPUT);
}


bool DumbButton::readButton() {
	if (digitalRead(incrementBtn) == HIGH) {
		return true;
	} else {
		return false;
	}
}

int DumbButton::pressed() {
	if ( readButton() == true ) {
		return 1;
	} else {
		return 0;
	}
}
void DumbButton::makePinModePullup() {
	pinMode(btnPin, INPUT_PULLUP);
}


/**
 * How many seconds has the button been pressed for
 * If it's currently being pressed then it returns -1 to let caller
 * know that it can't give a final answer yet.
 * If it's not being pressed, then it returns zero.
 * If the button has just been released, it returns the number of
 * milliseconds the button was pressed for.
 */
int TimedButton::pressed() {
//	bool pressed = readButtion();

	if( readButtion() == true ) {
//	if( pressed == true ) {
		if (start == 0 ) {
			start = millis();
		}
		// update how long the button has been pressed for
		pressDuration = millis() - start;
		inUse = true;

		// let the caller know that the button is being pressed
		// but that we don't know for how long yet.
		return -1;
	} else {
		// button is no longer being pressed.
		// we keep the press duration for one call so
		// that buttonPressedFor() can be used effectively
		if( inUse == false ) {
			// button was being pressed two calls ago
			// reset for next press
			start = 0;
			pressDuration = 0;
		}
		// button is no longer being pressed
		inUse = false;
		return (int) pressDuration;
	}
}




MultiPressButton::MultiPressButton( byte pin , int maxNoPress ) {
	btnPin = pin;
	pinMode(btnPin, INPUT);
	resetTime = maxNoPress * 2;
	noPress = maxNoPress;
}

int multiPressCount::pressed() {

	if( readButtion() == true ) {
		if ( inUse == false ) {
			if ( counting == false ) {
				counting = true;
			}
			presses = presses + 1;
			inUse = true;
		}

		// let the caller know that the button is being pressed
		// but that we don't know for how long yet.
		return -1;
	} else {
		int output = 0;
		if ( counting == true ) {
			if ( inUse == true ) {
				notPressed = millis();
			}

			int duration = millis() - notPressed;
			if( duration > maxNoPress ) {
				// send the number of presses to the caller
				output = presses;
				// reset count
				counting = false;
				// reset presses
				presses = 0;
			} else {
				// let the caller know we're still counting presses
				output = -1;
			}
		}
		// button is no longer being pressed
		inUse = false;
		return output;
	}
}
