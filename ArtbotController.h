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
		virtual void calculate();
}

public class ArtbotControllerDefault : ArtbotController {
	public:
		void setValues( ArtbotSettingsDefault settings );
		void calculate();
}


ArtBotUI::addSubClass('Default');