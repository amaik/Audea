/*
  ==============================================================================

    LFO.cpp
    Created: 14 Jan 2015 4:21:02pm
    Author:  Alex

  ==============================================================================
*/

#include "LFO.h"

LFO::LFO(float frq, int smplrate, float* amt)
{
	frequency = frq;
	samplerate = smplrate;
	amount = amt;
}


LFO::~LFO()
{

}

void LFO::reset()
{
	index = 0;
	calculateIncrement();
}

void LFO::setFrequency(float frq)
{
	frequency = frq;
	calculateIncrement();
}

void LFO::setDestination(int dest)
{
	destination = dest;
	index = 0.0f;
}

void LFO::calculateIncrement()
{
	increment = double_Pi / (samplerate / frequency);
}

float LFO::getNextVolumeOffset()
{
	if (index >= 2 * double_Pi)
		index = 0;
	float out = sin(index);

	//Mapping to value range
	out *= 0.75f;

	//Apply amount
	out *= *amount;

	index += increment;
	
	if (destination == Volume)
		return out;
	else
		return 0.0f;
}

float LFO::getNextPanOffset()
{
	if (index >= 2 * double_Pi)
		index = 0;
	float out = sin(index);
	//Map to range
	out *= 0.5f;
	//Apply Amount
	out *= *amount;

	index += increment;

	if (destination == Pan)
		return out;
	else
		return 0.0f;
}

int LFO::getNextCutoffFrqOffset()
{
	if (index >= 2 * double_Pi)
		index = 0;
	float out = sin(index);
	//Mapping to value range
	out *= 9980;

	//Apply amount
	out *= *amount;

	index += increment;
	
	if (destination == FilterCutoff)
		return out;
	else
		return 0.0f;
}

