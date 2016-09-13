#include rotaryEncoder.h

//		int clkPin;
//		int dtPin;
//		int btnPin;
//		int clk_value;
//		int dt_value;
//		long position;
//		int previous_clk_value;
//		int increment = 1;

//void rotaryEncoder::RotaryEncoder(int clockPin, int dataPin, int buttonPin ) {
//}
void rotaryEncoder::RotaryEncoder(int clockPin, int dataPin, int buttonPin, int defaultPos ) {
	clkPin = clockPin;
	dtPin = dataPin;
	btnPin = buttonPin;
	position = defaultPos;
	increment = rotaryEncoder::defaultIncrement;
}

long rotaryEncoder::getPosition() {
	_readEncoder();
	return position;
}

long rotaryEncoder::getPosition( bool doRead ) {
	if (doRead != false) {
		_readEncoder();
	}
	return position;
}


static void rotaryEncoder::setStartIncrement( int inc ) {
	rotaryEncoder::defaultIncrement = inc;
}

void rotaryEncoder::_readEncoder() {
	clk_value = digitalRead(clkPin);
	dt_value  = digitalRead(dtPin);

	if ((clk_value != previous_clk_value) && (clk_value != LOW)) {
		if (dt_value == LOW) {
			position += increment;
		} else {
			position -= increment;
		}
	}
	previous_clk_value = clk_value;
}
