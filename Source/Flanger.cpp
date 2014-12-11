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


	if (Feedback != 0)
		in = *left - vdlLeft->getValueAtOffset(center*(Samples / 1000)) * Feedback;
	vdlLeft->Set((center + (depth  /**Oszillator*/))*(Samples / 1000));
	*left = (in * (1 - Mix)) + (vdlLeft->readWrite(in) * Mix);


	if (Feedback != 0)
		in = *right - vdlRight->getValueAtOffset(center*(Samples / 1000)) * Feedback;
	vdlRight->Set((center + (depth  /**Oszillator*/))*(Samples/1000));
	*right = (in * (1 - Mix)) + (vdlRight->readWrite(in) * Mix);

}