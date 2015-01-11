/*
  ==============================================================================

    ModulatorEffect.cpp
    Created: 11 Jan 2015 2:47:31pm
    Author:  Alex

  ==============================================================================
*/

#include "ModulatorEffect.h"


void ModulatorEffect::process(float* left, float* right){
	float in = *left;
	float inFB = *left;

	bool isFeedback = false;

	float nextSample = lfo->getNextSample();

	if (*feedback != 0){
		inFB = *left - vdlLeft->getValueAtOffset(center * samplesPerMillisecond) * *feedback;
		isFeedback = true;
	}
	vdlLeft->Set((center + ((depth / 2)  * nextSample))* samplesPerMillisecond);

	if (isFeedback)
		*left = (in * (1 - *mix)) + (vdlLeft->readWrite(inFB) * *mix);
	else
		*left = (in * (1 - *mix)) + (vdlLeft->readWrite(in) * *mix);

	in = *right;
	inFB = *right;
	if (*feedback != 0){
		in = *right - vdlRight->getValueAtOffset(center * samplesPerMillisecond) * *feedback;
		isFeedback = true;
	}

	vdlRight->Set((center + ((depth / 2)  * nextSample))* samplesPerMillisecond);
	if (isFeedback)
		*right = (in * (1 - *mix)) + (vdlRight->readWrite(inFB) * *mix);
	else
		*right = (in * (1 - *mix)) + (vdlRight->readWrite(in) * *mix);

}