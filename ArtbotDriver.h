public interface IArtbotDriver {
	public:
		void terminate( bool end )
		void setWheelAction(
			byte wheelSide, // wheelSide = LEFT (0) or RIGHT (1)
			uint distance,
			int speed,
			uint acceleration,
			uint deceleration
		)
		void setPenDepth(float depth)
		bool getTravelComplete( byte wheelSide ) // wheelSide = LEFT (0) or RIGHT (1)
		bool getEdgeReached()


}