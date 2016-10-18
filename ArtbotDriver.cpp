ArtbotDriver::ArtbotDriver( int maxSpeed , int maxAccelleration , int stepsPerRevolution , float wheelDiameter ) {

	// Declare the motors (for AFMotor lib)
	leftMotor(stepsPerRevolution, 1);
	rightMotor(stepsPerRevolution, 2);

	// Declare the AccelStepper motors (which 'wrap' the AFMotor lib motors)
	leftAccelMotor(forwardStepLeft, backwardStepLeft);
	rightAccelMotor(forwardStepRight, backwardStepRight);

	stepFactor = stepsPerRevolution / (wheelDiameter * 3.1416) / 2
}



// These methods are used as 'wrappers' so that we can use 2 motor libraries together
// Note that each step can be SINGLE, DOUBLE, INTERLEAVE or MICROSTEP
void ArtbotDriver::forwardStepLeft() {
	leftMotor.onestep(FORWARD, SINGLE);
}
void ArtbotDriver::backwardStepLeft() {
	leftMotor.onestep(BACKWARD, SINGLE);
}
// wrappers for the second motor!
void ArtbotDriver::forwardStepRight() {
	rightMotor.onestep(BACKWARD, SINGLE);
}
void ArtbotDriver::backwardStepRight() {
	rightMotor.onestep(FORWARD, SINGLE);
}