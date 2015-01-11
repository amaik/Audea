/*
  ==============================================================================

    Chorus.cpp
    Created: 10 Dec 2014 5:34:45pm
    Author:  Felix Rolshausen

  ==============================================================================
*/

#include "Chorus.h"

Chorus::Chorus(float samplesPerSecond, float *mx){
	center = 30.0f;
	mix = mx;
	feedback = new float(0.0f);
	depth = 1.25f;
	samplesPerMillisecond = samplesPerSecond / 1000;
	lfo = new EffectLFO(5.0f,samplesPerSecond);
	lfo->calculateIncrement();

	float maxDelay = center + (10.0f / 2);

	vdlLeft = new VariableDelayLine(maxDelay * samplesPerMillisecond);
	vdlRight = new VariableDelayLine(maxDelay * samplesPerMillisecond);
	delayCenter = (center * samplesPerMillisecond);
	delayRange = (depth / 2) * samplesPerMillisecond;
}


Chorus::~Chorus(){
	delete vdlLeft;
	delete vdlRight;
	delete feedback;
}

void Chorus::setLFOfrequency(float frq)
{
	lfo->setFrequency(frq);
}