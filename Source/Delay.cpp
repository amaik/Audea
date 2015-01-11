/*
  ==============================================================================

    Delay.cpp
    Created: 10 Dec 2014 11:16:12am
    Author:  Alex

  ==============================================================================
*/

#include "Delay.h"
Delay::Delay(int lengthLeft, int lengthRight,float *mx, float *fb){
	mix = mx;
	feedback = fb;
	delayBufferRight = new std::atomic<float>[lengthRight];
	memset(delayBufferRight, 0, lengthRight);
	RightLength = lengthRight;
	delayBufferLeft = new std::atomic<float>[lengthLeft];
	memset(delayBufferLeft, 0, lengthLeft);
	LeftLength = lengthLeft;
}

Delay::~Delay(){
	delete[] delayBufferLeft;
	delete[] delayBufferRight;
}

void Delay::process(float* left, float *right){

	//left
	float in = *left;
	*left = (in * (1 - *mix)) + ((delayBufferLeft[delayPositionLeft.load()].load()) * (*mix));
	delayBufferLeft[delayPositionLeft.load()].store(((delayBufferLeft[delayPositionLeft.load()].load()) * *feedback) + in);
	delayPositionLeft++;
	if (delayPositionLeft.load() >= LeftLength.load())
		delayPositionLeft.store(0);


	//right
	in = *right;
	*right = (in * (1 - *mix)) + ((delayBufferRight[delayPositionRight.load()].load()) * (*mix));
	delayBufferRight[delayPositionRight.load()].store(((delayBufferRight[delayPositionRight.load()].load()) * *feedback) + in);
	delayPositionRight++;
	if (delayPositionRight.load() >= RightLength.load())
		delayPositionRight.store(0);

}

void Delay::setDelayBufferLengthRight(int newlength){
	RightLength.store(newlength);
	delayPositionRight.store(0);
}

void Delay::setDelayBufferLengthLeft(int newlength){
	LeftLength.store(newlength);
	delayPositionLeft.store(0);
}