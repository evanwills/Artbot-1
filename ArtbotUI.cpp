#include ArtbotUI.h


bool ArtbotUI::terminate(); {
	return terminateDraw;
}


bool ArtbotUI::newMode() {
	return startNewMode;
}

/*
 * When a sub class of ArtbotUI is added, so the system can know about
 * it, add the class name to the list of available sub-classes.
 *
 * @param char[32] name of class e.g. 'Default' or 'Decay'
 */
void ArtBotUI::addSubClass( char className[32] ) {
	int i = 0;
	bool addSubClass = true;
	int j = ELEMENTS(subClasses);
	for ( i = 0 ; i < j ; i += 1 ) {
		if (subClasses[i] == className ) {
			addSubClass = false;
		}
	}
	if (assSubClass == true ) {
		subClasses[j] = className;
	}
}

void ArtbotUI::_setArtbotMode() {
	if( startStop->getPressedLoopse() > 10000 && modeBtn->getPressedLoopse() > 10000 )
	{
		terminateDraw = true;
		startNewMode = true;
	}
}

ArtbotUIDefault::ArtbotUIDefault( displayType , displayColour , IRotaryEncoder Encoder , button startStopBtn , button modeBtn ) {
	encoder = Encoder;
	startStop = startStopBtn;
	mode = modeBtn;
}

ArtBotUI::addSubClass('Default');