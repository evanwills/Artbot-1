public interface IArtbotController {
	public:
		virtual void setValues( IArtbotSettings settings );
		virtual int getSpeed( byte wheelSide); // wheelSide = LEFT (0) or RIGHT (1)
		virtual unsigned int getDistance( byte wheelSide); // wheelSide = LEFT (0) or RIGHT (1)
		virtual unsigned int getAccel( byte wheelSide ); // wheelSide = LEFT (0) or RIGHT (1)
		virtual unsigned int getDecel( byte wheelSide ); // wheelSide = LEFT (0) or RIGHT (1)
		virtual float getPenDepth();
		virtual void setEdgeReached( bool hitEdge );
		virtual void init();
		virtual void calculate();
		virtual string getRequiredUI();

}

public class ArtbotController : IArtbotController {

	public:
		void setValues( IArtbotSettings settings );
		int getSpeed( byte wheelSide); // wheelSide = LEFT (0) or RIGHT (1)
		unsigned int getDistance( byte wheelSide); // wheelSide = LEFT (0) or RIGHT (1)
		unsigned int getAccel( byte wheelSide ); // wheelSide = LEFT (0) or RIGHT (1)
		unsigned int getDecel( byte wheelSide ); // wheelSide = LEFT (0) or RIGHT (1)
		float getPenDepth();
		void setEdgeReached( bool hitEdge );
		void init();
		string getUI();
		virtual void calculate();
	protected:
		bool edgeHit = false;
	private:
		/**
		 * used for identifying which UI to instantiate for use with this controller.
		 */
		string uiName[16] = ''
}

public class ArtbotControllerDefault : ArtbotController {
	public:
		void setValues( ArtbotSettingsDefault settings );
		void calculate();

	private:
		/**
		 * used for identifying which UI to instantiate for use with this controller.
		 */
		string uiName[16] = 'Default'
}
