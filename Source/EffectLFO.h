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
	float frequency = 0.15;
	float samplerate = 0;

public:
	EffectLFO(float frq,int smplrate )
	{
		frequency = frq;
		samplerate = smplrate;
	}
	void setFrequency(float frq);
	float getNextSample();
	void calculateIncrement();
};



#endif  // EFFECTLFO_H_INCLUDED
