/*
  ==============================================================================

    Reverb.cpp
    Created: 9 Jan 2015 3:10:31pm
    Author:  Alex

  ==============================================================================
*/

#include "AudeaReverb.h"
#include <cmath>
AudeaReverb::AudeaReverb(float sampleRate, float mix, float size, float width) 
{
	params.damping = 0.5;
	params.freezeMode = 0.4;
	params.roomSize = size;
	params.width = width;
	params.wetLevel = mix;
	params.dryLevel = (1 - mix);
	reverb.setSampleRate(sampleRate);
	reverb.setParameters(params);
}

AudeaReverb::~AudeaReverb()
{
}


void AudeaReverb::process(float* left, float *right)
{
	reverb.processStereo(left, right, 1);
}

void AudeaReverb::setMix(float mix)
{
	params.wetLevel = mix;
	params.dryLevel = 1 - mix;
	reverb.setParameters(params);
}

void AudeaReverb::setSize(float size)
{
	params.roomSize = size;
	reverb.setParameters(params);
}

void AudeaReverb::setWidth(float width)
{
	params.width = width;
	reverb.setParameters(params);
}