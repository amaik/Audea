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
	//Oszillator
	float maxDelay = center + (depth / 2);

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



	if (Feedback != 0)
		in = *right - variableDelayLine[(int)center] * Feedback;
	delayOffset = delayCenter + (delayRange /**Oszillator*/);
	delayRead = delayWrite - delayOffset;
	if (delayRead < 0)
		delayRead += maxDelay * (Samples / 1000);
	readInt = (int)(delayCenter + (delayRange/**Oszillator*/));
	readFract = (delayCenter + (delayRange/**Oszillator*/)) - readInt;
	if (delayOffset < 1)
		variableDelayLine[delayWrite] = *right;
	out = variableDelayLine[readInt] * (1 - readFract);
	if (--readInt < 0)
		readInt += maxDelay * (Samples / 1000);
	out += variableDelayLine[readInt] * readFract;
	if (delayOffset >= 1)
		variableDelayLine[delayWrite] = *right;
	if (++delayWrite >= maxDelay * (Samples / 1000))
		delayWrite -= maxDelay * (Samples / 1000);
	out *= Mix;

	*right = (in * (1-Mix)) + out;

}