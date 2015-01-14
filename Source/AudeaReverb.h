/*
  ==============================================================================

    Reverb.h
    Created: 9 Jan 2015 3:10:31pm
    Author:  Alex

  ==============================================================================
*/

#ifndef AUDEAREVERB_H_INCLUDED
#define AUDEAREVERB_H_INCLUDED

#include "Effect.h"
#include "../JuceLibraryCode/JuceHeader.h"


class AudeaReverb : public Effect
{

	juce::Reverb reverb;
	Reverb::Parameters params;

public:
	AudeaReverb(float sampleRate,float mix, float size, float width);
	~AudeaReverb();

	void setMix(float mix);
	void setWidth(float width);
	void setSize(float size);
	void process(float* left, float *right);
};




#endif  // AUDEAREVERB_H_INCLUDED
