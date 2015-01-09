/*
  ==============================================================================

    Reverb.cpp
    Created: 9 Jan 2015 3:10:31pm
    Author:  Alex

  ==============================================================================
*/

#include "Reverb.h"

Reverb::Reverb(float sampleRate, float *mix, float *decay, float *size) :
	mix(mix),
	decay(decay),
	size(size)
{
	//Compute maxLength
	int maxLengthDelay = 0.5 * sampleRate;
	delay = new float[maxLengthDelay];
	delayLen = maxLengthDelay;
}
void Reverb::setDelayLenght(float newSize)
{

}

void Reverb::process(float* left, float *right)
{
	float inLeft = *left;

	float inRight = *right;
}