public class IRotaryEncoder {

	public:
		virtual long getPosition( bool doRead = true );
}


public class RotaryEncoder : IRotaryEncoder {

	public:
		// void RotaryEncoder(int clockPin, int dataPin, int buttonPin );
		RotaryEncoder( int clockPin , int dataPin , int defaultPos );

		long getPosition( bool read = true );


	protected:
		int clkPin;
		int dtPin;
		int clk_value;
		int dt_value;
		long position;
		int previous_clk_value;
		int increment = 1;
}


public class BtnRotaryEncoder : RotaryEncoder ITimedButton {

	public:
		BtnRotaryEncoder( int clockPin , int dataPin , int defaultPos , ITimedButton button );
		bool readButton();
		int pressed();

	protected:
		ITimedButton btn;

}
