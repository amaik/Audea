/*
  ==============================================================================

    Delay.cpp
    Created: 10 Dec 2014 11:16:12am
    Author:  Alex

  ==============================================================================
*/

#include "Delay.h"

void Delay::process(float* left, float *right){

	//left
	float in = *left;
	*left = (in * (1 - Mix)) + ((delayBufferLeft[delayPositionLeft.load()].load()) * (Mix));
	delayBufferLeft[delayPositionLeft.load()].store(((delayBufferLeft[delayPositionLeft.load()].load()) * Feedback) + in);
	delayPositionLeft++;
	if (delayPositionLeft.load() >= LeftLength.load())
		delayPositionLeft.store(0);


	//right
	in = *right;
	*right = (in * (1 - Mix)) + ((delayBufferRight[delayPositionRight.load()].load()) * (Mix));
	delayBufferRight[delayPositionRight.load()].store(((delayBufferRight[delayPositionRight.load()].load()) * Feedback) + in);
	delayPositionRight++;
	if (delayPositionRight.load() >= RightLength.load())
		delayPositionRight.store(0);

}