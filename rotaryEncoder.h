public interface IRotaryEncoder {

	public:
		int clkPin;
		int dtPin;
		int btnPin;
		int clk_value;
		int dt_value;
		long position;
		int previous_clk_value;
		int increment;

		virtual long getPosition();
		virtual long getPosition( bool doRead );

	private:
		static int defaultIncrement = 1;
		virtual void _readEncoder();


}

public class RotaryEncoder : IRotaryEncoder {

	public:
		// void RotaryEncoder(int clockPin, int dataPin, int buttonPin );
		void RotaryEncoder( int clockPin, int dataPin, int buttonPin, int defaultPos );

		long getPosition();
		long getPosition( bool read );

		static void setStartIncrement( int inc );
}