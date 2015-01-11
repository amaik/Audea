/*
  ==============================================================================

    Flanger.cpp
    Created: 10 Dec 2014 3:20:41pm
    Author:  Felix Rolshausen

  ==============================================================================
*/

#include "Flanger.h"
Flanger::Flanger(float samplesPerSecond,float *mx,float *fb){
	center = 8.0f;
	mix = mx;
	feedback = fb;
	depth = 10.0f;
	samplesPerMillisecond = samplesPerSecond / 1000;
	lfo = new EffectLFO(0.15f,samplesPerSecond);
	lfo->calculateIncrement();

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

