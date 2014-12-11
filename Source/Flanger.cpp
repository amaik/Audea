/*
  ==============================================================================

    Flanger.cpp
    Created: 10 Dec 2014 3:20:41pm
    Author:  Felix Rolshausen

  ==============================================================================
*/

#include "Flanger.h"


void Flanger::process(float* left, float* right){
	float in;
	oscil.Init(sweep);

<<<<<<< HEAD
=======
	if (Feedback != 0)
	//	in = *left - DelayTap(center) * Feedback;
	delayOffset = delayCenter + (delayRange /**Oszillator*/);
	delayRead = delayWrite - delayOffset;
	if (delayRead < 0)
		delayRead += maxDelay * (Samples / 1000);
	readInt = (int)(delayCenter + (delayRange/**Oszillator*/));
	readFract = (delayCenter + (delayRange/**Oszillator*/)) - readInt;
	if (delayOffset < 1)
		variableDelayLine[delayWrite] = *left;
	float out = variableDelayLine[readInt] * (1 - readFract);
	if (--readInt < 0)
		readInt += maxDelay * (Samples / 1000);
	out += variableDelayLine[readInt] * readFract;
	if (delayOffset >= 1)
		variableDelayLine[delayWrite] = *left;
	if (++delayWrite >= maxDelay * (Samples / 1000))
		delayWrite -= maxDelay * (Samples / 1000);
	out *= Mix;

	*left = (in * (1-Mix)) + out;
>>>>>>> 978000947854ebeef65e3e7b5320915a450af676

	if (Feedback != 0)
		in = *left - vdlLeft->getValueAtOffset(center*(Samples / 1000)) * Feedback;
	vdlLeft->Set((center + (depth  /**Oszillator*/))*(Samples / 1000));
	*left = (in * (1 - Mix)) + (vdlLeft->readWrite(in) * Mix);


	if (Feedback != 0)
		in = *right - vdlRight->getValueAtOffset(center*(Samples / 1000)) * Feedback;
	vdlRight->Set((center + (depth  /**Oszillator*/))*(Samples/1000));
	*right = (in * (1 - Mix)) + (vdlRight->readWrite(in) * Mix);

}