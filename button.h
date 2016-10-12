/**
 * TimedButton is useful for when you want to do time
 * based things with a button
 * e.g. a short click of the button (say, less than 1 second) is used
 *		for modifying settings but a long click is used for resetting
 *		to defaults
 */
public class TimedButton {

	public:
		ArtbotButton(byte pin);
		/**
		 * If button is pressed, starts counting the number of
		 * milliseconds since start and returns true. If not,
		 * resets the timer and returns false.
		 */
		bool readButton();

		/**
		 * reads the button's state then returns the number of
		 * milliseconds the buttons was pressed for.
		 */
		int buttonPresedFor( bool doRead = true );

	private:
		/*
		 * btnPin the Arduino Mega pin number used by the button
		 */
		byte btnPin = 0;

		/**
		 * inUse whether or not the button is being pressed.
		 */
		bool inUse = false;

		int pressDuration = 0;

		/**
		 * start the time in milliseconds (from when the Arduino was
		 * turned on) the button was pressed.
		 */
		unsigned long start = 0;
}