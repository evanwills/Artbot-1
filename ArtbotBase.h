/*
# ArtbotBase

ArtbotBase is the super controller for the artbot.

ArtbotBase manages:
*	objects for the physical components of the Artbot.
	*	buttons
	*	rotary encoders
	*	physical switches
	*	motors
*	generates the objects that manage actually doing the drawing
	*	driver
	*	controller
	*	user interface
*	passing data from the UI to the controller to the driver
*	passing data from the driver back to the controller
*	has its own UI to handle switching between drawing modes

*/

public class ArtbotBase {
	public:
		char[16] getMode();
	private:
		ArtbotButton modeButton;
		ArtbotButton button1;
		ArtbotButton button2;
		ArtbotButton button3;
		ArtbotButton button4;
		ArtbotButton button5;
		ArtbotButton button6;
		ArtbotRotaryEncoder encoder;
		char mode[16] = 'default';
}