/*
  ==============================================================================

    Chorus.h
    Created: 10 Dec 2014 5:34:45pm
    Author:  Felix Rolshausen

  ==============================================================================
*/

#ifndef CHORUS_H_INCLUDED
#define CHORUS_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "ModulatorEffect.h"
#include "VariableDelayLine.h"
#include "EffectLFO.h"

class Chorus : public ModulatorEffect{
	float *fb;
public:
	Chorus(float samplesPerSecond,float *mx);
	~Chorus();

	void setLFOfrequency(float frequency);
};


#endif  // CHORUS_H_INCLUDED
