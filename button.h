public class button {

	public:
		void button(byte pin);
		void readButton();
		unsigned int buttonPresedFor();

	private:
		byte btnPin = 0;
		byte pressedForLoops = 0;
}