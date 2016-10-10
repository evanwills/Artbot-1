public interface IArtbotUI {
	public:
		// init is called by setup() or when mode is changed
		virtual void init();

		// called once very loop()
		virtual bool configHasChanged();

		// called if necessary once a loop();
		virtual IArtbotSettings getConfig(); // returns object appropriate for specific controller

		// whether or not to terminate the current drawing
		virtual bool terminate();

		// whether or not change artbot modes
		virtual bool newMode(); // do we need to change mode?

		// called if new artbot mode is requested
		virtual IArtbotController getNewController();

		// called if new artbot mode is requested
		virtual IArtbotUI getNewUI();

		static void addSubClass( char shortName[32] );


	protected:
		bool terminateDraw = false;
		bool startNewMode = false;
		char * subClasses[10];

		virtual void _setArtbotMode();


}

public class ArtbotUI : IArtbotUI {
	public:
		bool terminate();

		bool newMode();

		void _setArtbotMode();

		// init is called by setup() or when mode is changed
		virtual void init();

		// called once very loop()
		virtual bool configHasChanged();

		// called if necessary once a loop();
		virtual IArtbotSettings getConfig(); // returns object appropriate for specific controller

		// called if new artbot mode is requested
		virtual IArtbotController getNewController();

		// called if new artbot mode is requested
		virtual IArtbotUI getNewUI();

		static void addSubClass( char shortName[32] );


	protected:
		virtual void _setArtbotMode();
}

public class ArtbotUIDefault : ArtbotUI {
	public:
		ArtbotUIDefault( displayType , displayColour , IRotaryEncoder rotaryEncoder , button startStopBtn , button modeBtn );

		bool configHasChanged();

		ArtbotSettings getConfig();

		IArtbotController getNewController();

		IArtbotUI getNewUI();

		void init();

	private:
		button startStop;
		button mode;
		IRotaryEncoder encoder

}