/*
  ==============================================================================

    EffectLFO.cpp
    Created: 10 Dec 2014 5:25:56pm
    Author:  Felix Rolshausen

  ==============================================================================
*/

#include "EffectLFO.h"

void EffectLFO::calculateIncrement(int samplerate)
{
	increment = double_Pi / (samplerate / frequency);
}

float EffectLFO::getNextSample()
{
	if (index >= double_Pi)
		index = 0;
	float out = sin(index);
	index += increment;
	return out;
}


