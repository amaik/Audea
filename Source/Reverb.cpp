/*
  ==============================================================================

    Reverb.cpp
    Created: 9 Jan 2015 3:10:31pm
    Author:  Alex

  ==============================================================================
*/

#include "Reverb.h"

Reverb::Reverb(float sampleRate)
{
	//Compute maxLength
	int maxLengthDelay = 0.5 * sampleRate;
	delay = new float[maxLengthDelay];
	delayLen = maxLengthDelay;
}

void Reverb::setSize(float newSize)
{
	size = newSize;
	delayLen =
}

void Reverb::process(float* left, float *right)
{
	float inLeft = *left;

	float inRight = *right;
}