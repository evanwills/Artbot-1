
void ArtbotController::setValues( IArtbotSettings settings );

int ArtbotController::getSpeed( byte wheelSide); // wheelSide = LEFT (0) or RIGHT (1)

unsigned int ArtbotController::getDistance( byte wheelSide); // wheelSide = LEFT (0) or RIGHT (1)

unsigned int ArtbotController::getAccel( byte wheelSide ); // wheelSide = LEFT (0) or RIGHT (1)

unsigned int ArtbotController::getDecel( byte wheelSide ); // wheelSide = LEFT (0) or RIGHT (1)

float ArtbotController::getPenDepth();

void ArtbotController::setEdgeReached( bool hitEdge ) {

}

void ArtbotController::init();

string ArtbotController::getRequiredUI() {
	return uiName;
}