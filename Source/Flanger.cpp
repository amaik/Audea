/*
  ==============================================================================

    Flanger.cpp
    Created: 10 Dec 2014 3:20:41pm
    Author:  Felix Rolshausen

  ==============================================================================
*/

#include "Flanger.h"


void Flanger::process(float* left, float* right){
	float in = 0;

	if (Feedback != 0)
		in = *left - vdlLeft->getValueAtOffset(center* samplesPerMillisecond) * Feedback;
	vdlLeft->Set((center + (depth  * lfo->getNextSample()))* samplesPerMillisecond);
	*left = (in * (1 - Mix)) + (vdlLeft->readWrite(in) * Mix);


	if (Feedback != 0)
		in = *right - vdlRight->getValueAtOffset(center * samplesPerMillisecond) * Feedback;
	vdlRight->Set((center + (depth  * lfo->getNextSample()))* samplesPerMillisecond);
	*right = (in * (1 - Mix)) + (vdlRight->readWrite(in) * Mix);

}