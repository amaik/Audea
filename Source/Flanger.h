/*
  ==============================================================================

    Flanger.h
    Created: 10 Dec 2014 3:20:41pm
    Author:  Felix Rolshausen

  ==============================================================================
*/

#ifndef FLANGER_H_INCLUDED
#define FLANGER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "VariableDelayLine.h"
#include "EffectLFO.h"

class Flanger{
	float Mix;
	float Feedback;
	float depth;
	float center;
	float samplesPerMillisecond;
	VariableDelayLine* vdlLeft;
	VariableDelayLine* vdlRight;
	EffectLFO* lfo = new EffectLFO(0.15f);
	int delayOffset;
	int delayRange;
	int delayCenter;

public:
	Flanger(float samplesPerSecond);
	~Flanger();

	void setMix(float newMix){ Mix = newMix; };
	void setFeedback(float newFeedback){ Feedback = newFeedback; };
	void setDepth(float newDepth){ depth = newDepth; };
	void updateRange(){ delayRange = (depth * samplesPerMillisecond) / 2; };

	void process(float* left, float *right);

};



#endif  // FLANGER_H_INCLUDED
