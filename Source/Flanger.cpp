/*
  ==============================================================================

    Flanger.cpp
    Created: 10 Dec 2014 3:20:41pm
    Author:  Felix Rolshausen

  ==============================================================================
*/

#include "Flanger.h"


void Flanger::process(float* left, float* right){
	float in = *left;
	float inFB = *left;

	bool isFeedback = false;

	float nextSample = lfo->getNextSample();

	if (Feedback != 0){
		inFB = *left - vdlLeft->getValueAtOffset(center * samplesPerMillisecond) * Feedback;
		isFeedback = true;
	}
	vdlLeft->Set((center + (depth  * nextSample))* samplesPerMillisecond);

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

	vdlRight->Set((center + (depth  * nextSample))* samplesPerMillisecond);
	if (isFeedback)
		*right = (in * (1 - Mix)) + (vdlRight->readWrite(inFB) * Mix);
	else 
		*right = (in * (1 - Mix)) + (vdlRight->readWrite(in) * Mix);

}