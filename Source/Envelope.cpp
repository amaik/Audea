/*
  ==============================================================================

    Envelope.cpp
    Created: 12 Nov 2014 4:08:07pm
    Author:  Alex

  ==============================================================================
*/

#include "Envelope.h"

void Envelope::initSegments()
{
	envState = Attack;

	attackNumSamples	=	(* attackTime / 1000) * sampleRate;
	decayNumSamples		=	(* decayTime	 / 1000) * sampleRate;
	releaseNumSamples	= (* releaseTime / 1000) * sampleRate;

	attackMultiplier	= 0.0f;
	decayMultiplier		= 1.0f;
	releaseMultiplier	= *sustainLevel;

	attackIncr		= attackNumSamples  != 0 ? (1.0f / attackNumSamples) : 0;
	decayIncr		= decayNumSamples   != 0 ? ((1.0f - *sustainLevel) / decayNumSamples) : 0;
	releaseIncr		= releaseNumSamples != 0 ? ((*sustainLevel) / releaseNumSamples) : 0;
}

float Envelope::getNextMultiplier()
{
	double ret;
	switch (envState)
	{
	case Attack: ret = attackMultiplier;
		attackMultiplier += attackIncr;
		if (--attackNumSamples <= 0)
			envState = Decay;
		break;
	case Decay: ret = decayMultiplier;
		decayMultiplier -= decayIncr;
		if (--decayNumSamples <= 0)
			envState = Sustain;
		break;
	case Sustain: ret = *sustainLevel;
		if (isRelease)
			envState = Release;
		break;
	case Release: ret = releaseMultiplier;
		releaseMultiplier -= releaseIncr;
		if (--releaseNumSamples <= 0)
			isRelease = false;
		break;
	}
	return ret;
}

bool Envelope::isStartRelease()
{
	return isRelease;
}

void Envelope::StartRelease()
{
	isRelease = true;
}

void Envelope::StopRelease()
{
	isRelease = false;
}

void Envelope::setEnvState(int id)
{
	envState = id;
}
int Envelope::getEnvState()
{
	return envState;
}