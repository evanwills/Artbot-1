public interface IArtbotDriver {
	public:
		void terminate( bool end )
		void setWheelAction(
			byte wheelSide, // wheelSide = LEFT (0) or RIGHT (1)
			int distance,
			int speed,
			unsigned int acceleration,
			unsigned int deceleration
		)
		void setPenDepth(float depth);
		void setPenLocation(float position);
		bool getTravelComplete( byte wheelSide ) // wheelSide = LEFT (0) or RIGHT (1)
		bool getEdgeReached()


}

public class ArtbotDriver : IArtbotDriver {
	public:
		ArtbotDriver( int maxSpeed , int maxAccelleration , int stepsPerRevolution , float wheelDiameter );

		void forwardStepLeft();
		void backwardStepLeft();
		// wrappers for the second motor!
		void forwardStepRight();
		void backwardStepRight();

	protected:
		float stepFactor;
		AF_Stepper leftAccelMotor;
		AF_Stepper rightAccelMotor;
		AccelStepper leftAccelMotor;
		AccelStepper rightAccelMotor;

}