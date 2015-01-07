/*
  ==============================================================================

    EffectLFO.h
    Created: 10 Dec 2014 5:25:56pm
    Author:  Felix Rolshausen

  ==============================================================================
*/

#ifndef EFFECTLFO_H_INCLUDED
#define EFFECTLFO_H_INCLUDED

#include "math.h"
#include "JuceHeader.h"

class EffectLFO
{
private:
	float index = 0;
	float increment = 0;
	float frequency;

public:
	float getNextSample();
	void setFrequency(float frequency);
	void calculateIncrement(int samplerate);
};



#endif  // EFFECTLFO_H_INCLUDED
