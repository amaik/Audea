/*
  ==============================================================================

    Flanger.cpp
    Created: 10 Dec 2014 3:20:41pm
    Author:  Felix Rolshausen

  ==============================================================================
*/

#include "Flanger.h"
Flanger::Flanger(float samplesPerSecond){
	center = 8.0f;
	Mix = 0.5f;
	Feedback = 0.0f;
	depth = 10.0f;
	samplesPerMillisecond = samplesPerSecond / 1000;
	lfo->calculateIncrement(samplesPerSecond);

	float maxDelay = center + (10.0f / 2);

	vdlLeft = new VariableDelayLine(maxDelay * samplesPerMillisecond);
	vdlRight = new VariableDelayLine(maxDelay * samplesPerMillisecond);
	delayCenter = (center * samplesPerMillisecond);
	delayRange = (depth / 2) * samplesPerMillisecond;
}


Flanger::~Flanger(){
	delete vdlLeft;
	delete vdlRight;
}

void Flanger::process(float* left, float* right){
	float in = *left;
	float inFB = *left;

	bool isFeedback = false;

	float nextSample = lfo->getNextSample();

	if (Feedback != 0){
		inFB = *left - vdlLeft->getValueAtOffset(center * samplesPerMillisecond) * Feedback;
		isFeedback = true;
	}
	vdlLeft->Set((center + ((depth / 2)  * nextSample))* samplesPerMillisecond);

	if (isFeedback)
		*left = (in * (1 - Mix)) + (vdlLeft->readWrite(inFB) * Mix);
	else
		*left = (in * (1 - Mix)) + (vdlLeft->readWrite(in) * Mix);

	in = *right;
	inFB = *right;
	if (Feedback != 0){
		in = *right - vdlRight->getValueAtOffset(center * samplesPerMillisecond) * Feedback;
		isFeedback = true;
	}

	vdlRight->Set((center + ((depth/2)  * nextSample))* samplesPerMillisecond);
	if (isFeedback)
		*right = (in * (1 - Mix)) + (vdlRight->readWrite(inFB) * Mix);
	else 
		*right = (in * (1 - Mix)) + (vdlRight->readWrite(in) * Mix);

}