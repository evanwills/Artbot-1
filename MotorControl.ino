/*
 *  This file hides all the complexity involved in
 *  using the Accell Stepper library with the
 *  Adafruit AFMotor library
 *
 */

/*
 * Utility to stop steppers, and set them back to a 0 position
 */
void stopAndResetSteppers() {
  // stop everything
  leftAccelMotor.stop(); // Stop as fast as possible: sets new target
  rightAccelMotor.stop(); // Stop as fast as possible: sets new target

  // move both steppers to the same default position.
  leftAccelMotor.runToPosition();
  rightAccelMotor.runToPosition();

  // reset the steppers to position 0
  leftAccelMotor.setCurrentPosition(0);
  rightAccelMotor.setCurrentPosition(0);

  // tell the system that we are no longer drawing
  isDrawing = false;
}
