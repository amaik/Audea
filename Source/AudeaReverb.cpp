/*
  ==============================================================================

    Reverb.cpp
    Created: 9 Jan 2015 3:10:31pm
    Author:  Alex

  ==============================================================================
*/

#include "AudeaReverb.h"
#include <cmath>
AudeaReverb::AudeaReverb(float sampleRate, float *mx, float *rvbT, float *sze) 
{
	mix = mx;
	rvbTime = rvbT;
	size = sze;
	//Compute maxLength
	int maxLengthDelay = 0.5 * sampleRate;
	delayLeft = new float[maxLengthDelay];
	delayRight = new float[maxLengthDelay];
	delayLen = maxLengthDelay;

	for (int i = delayLen; --i > 0;){
		delayLeft[i] = 0;
		delayRight[i] = 0;
	}
	decay = pow(0.001, *size / *rvbTime);
	delayIndex = 0;
}

AudeaReverb::~AudeaReverb()
{
	delete delayLeft;
	delete delayRight;
}

void AudeaReverb::setDelayLenght(float newSize)
{
	delayLen = newSize;
}

void AudeaReverb::process(float* left, float *right)
{
	decay = pow(0.001, *size / *rvbTime);
	float out1,out2;

	float inLeft = *left;
	out1 = delayLeft[delayIndex] * decay;
	out2 = (out1 + prevLeft) / 2;
	prevLeft = out1;
	delayLeft[delayIndex] = inLeft * (1 - *mix) + out2 * *mix;


	float inRight = *right;
	out1 = delayRight[delayIndex] * decay;
	out2 = (out1 + prevRight) / 2;
	prevRight = out1;
	delayRight[delayIndex] = inRight * (1 - *mix) + out2 * *mix;

	if (++delayIndex >= delayLen)
		delayIndex = 0;
}