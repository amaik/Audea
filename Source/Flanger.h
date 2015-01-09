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

public:
	Flanger(){}
	Flanger(float samplesPerSecond){
		center = 8.0f;
		Mix = 0.5f;
		Feedback = 0.0f;
		depth = 10.0f;
		samplesPerMillisecond = samplesPerSecond/1000;
		lfo->calculateIncrement(samplesPerSecond);

		float maxDelay = center + (10.0f / 2);
		vdlLeft = new VariableDelayLine(maxDelay * samplesPerMillisecond);
		vdlRight = new VariableDelayLine(maxDelay * samplesPerMillisecond);
		delayCenter = (center * samplesPerMillisecond);
		delayRange = (depth / 2) * samplesPerMillisecond;
	}

	~Flanger(){
		delete vdlLeft;
		delete vdlRight;
	}

	void setMix(float newMix){ Mix = newMix; };
	void setFeedback(float newFeedback){ Feedback = newFeedback; };
	void setDepth(float newDepth){ depth = newDepth; };
	void updateRange(){ delayRange = (depth * samplesPerMillisecond) / 2; };

	void process(float* left, float *right);


private:
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
};



#endif  // FLANGER_H_INCLUDED
