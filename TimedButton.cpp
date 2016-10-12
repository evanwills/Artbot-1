#include TimedButton.h


TimedButton::TimedButton(byte pin) {
	btnPin = pin;
	pinMode(btnPin, INPUT);
}


bool TimedButton::readButton() {
	if (digitalRead(incrementBtn) == HIGH) {
		if (start == 0 ) {
			start = millis();
		}
		// update how long the button has been pressed for
		pressDuration = millis() - start;
		inUse = true;
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
	}
	return inUse;
}

/**
 * How many seconds has the button been pressed for
 * If it's currently being pressed then it returns -1 to let caller
 * know that it can't give a final answer yet.
 * If it's not being pressed, then it returns zero.
 * If the button has just been released, it returns the number of
 * milliseconds the button was pressed for.
 *
 * NOTE: if you are using both readButton() & buttonPressedFor(),
 *		 you the doRead parameter needs to be false otherwise, you'll
 *		 never get a value greater than zero
 *
 *		 e.g. (BEST)
 *			TimedButton btn = new TimedButtion(1);
 *			int val;
 *			val = buttonPressedFor();
 *
 *		 e.g. (GOOD)
 *			TimedButton btn = new TimedButtion(1);
 *			int val;
 *			btn->readButton();
 *			val = buttonPressedFor(false); // val: 0 or -1
 *
 *		 e.g. (BAD)
 *			TimedButton btn = new TimedButtion(1);
 *			int val;
 *			btn->readButton();
 *			val = buttonPressedFor(); // val: 0 or -1
 *			// val will always be either -1 or 0 because pressDuration
 *			// is set when readButton() is called for a second time
 *			// with the before buttonPressedFor() can use the
 *			// pressDuration value
 */
int TimedButton::buttonPressedFor( bool doRead ) {
	if( doRead == true ) {
		readButtion();
	}

	if( inUse == true ) {
		// let the caller know that the button is being pressed
		// but that we don't know for how long yet.
		return -1;
	} else {
		return (int) pressDuration;
	}
}
