/*
  ==============================================================================

    Delay.h
    Created: 10 Dec 2014 11:16:12am
    Author:  Alex

  ==============================================================================
*/

#ifndef DELAY_H_INCLUDED
#define DELAY_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include <atomic>



class Delay{
	std::atomic<float> *delayBufferLeft;
	std::atomic<int> LeftLength;
	std::atomic<float> *delayBufferRight;
	std::atomic<int> RightLength;
	float* mix;
	float* feedback;
	std::atomic<int> delayPositionLeft = 0;
	std::atomic<int> delayPositionRight = 0;

public:
	Delay(int lengthLeft, int lengthRight,float *mx, float *fb);
	~Delay();

	void process(float* left, float *right);


	float getLenght(){ return LeftLength; }

	void setDelayBufferLengthRight(int newlength);
	void setDelayBufferLengthLeft(int newlength);


};




#endif  // DELAY_H_INCLUDED
