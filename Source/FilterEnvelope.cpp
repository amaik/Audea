/*
  ==============================================================================

    FilterEnvelope.cpp
    Created: 18 Nov 2014 9:04:53pm
    Author:  Alex

  ==============================================================================
*/

#include "FilterEnvelope.h"

void FilterEnvelope::initSegments()
{
	cutoffFrequencyBuffer = 0.0f;

	envState = Attack;

	attackNumSamples = (*attackTime / 1000) * sampleRate;
	decayNumSamples = (*decayTime / 1000) * sampleRate;
	releaseNumSamples = (*releaseTime / 1000) * sampleRate;

	attackIncr = attackNumSamples != 0 ? (*envAmt / attackNumSamples) : 0;
	decayIncr = decayNumSamples != 0 ?	 ((*envAmt * (1.0f - *sustainLevel))  / decayNumSamples) : 0;
	releaseIncr = releaseNumSamples != 0 ? ((*envAmt * *sustainLevel) / releaseNumSamples) : 0;
}

float FilterEnvelope::getNextCutoffFrequency()
{
	double ret = *cutoffFrequency + cutoffFrequencyBuffer;
	switch (envState)
	{
	case Attack: 
		cutoffFrequencyBuffer += attackIncr;
		if (--attackNumSamples <= 0)
			envState = Decay;
		break;
	case Decay: 
		cutoffFrequencyBuffer -= decayIncr;
		if (--decayNumSamples <= 0)
			envState = Sustain;
		break;
	case Sustain: 
		if (isRelease)
			envState = Release;
		break;
	case Release: 
		if (isRelease)
		 cutoffFrequencyBuffer -= releaseIncr;
		if (--releaseNumSamples <= 0)
			isRelease = false;
		break;
	}
	return ret;
}

bool FilterEnvelope::isStartRelease()
{
	return isRelease;
}

void FilterEnvelope::StartRelease()
{
	isRelease = true;
}

void FilterEnvelope::StopRelease()
{
	isRelease = false;
}

void FilterEnvelope::setEnvState(int id)
{
	envState = id;
}
int FilterEnvelope::getEnvState()
{
	return envState;
}