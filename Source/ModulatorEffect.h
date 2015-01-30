/*
  ==============================================================================

    ModulatorEffect.h
    Created: 11 Jan 2015 2:47:31pm
    Author:  Alex

  ==============================================================================
*/

#ifndef MODULATOREFFECT_H_INCLUDED
#define MODULATOREFFECT_H_INCLUDED
#include"Effect.h"
#include "../JuceLibraryCode/JuceHeader.h"
#include "VariableDelayLine.h"
#include "EffectLFO.h"


class ModulatorEffect : public Effect
{
protected:
	float* mix;
	float* feedback;

	float depth;
	float center;
	float samplesPerMillisecond;
	VariableDelayLine* vdlLeft;
	VariableDelayLine* vdlRight;
	EffectLFO* lfo;
	int delayOffset;
	int delayRange;
	int delayCenter;

public:	
	//void setMix(float newMix){ Mix = newMix; };
	void setDepth(float newDepth){ depth = newDepth; };
	void updateRange(){ delayRange =(int) (depth * samplesPerMillisecond) / 2; };

	void process(float* left, float *right);

};




#endif  // MODULATOREFFECT_H_INCLUDED
