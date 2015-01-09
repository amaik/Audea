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
	float Mix;
	float Feedback;
	std::atomic<int> delayPositionLeft = 0;
	std::atomic<int> delayPositionRight = 0;

public:
	Delay(int lengthLeft, int lengthRight);
	~Delay();

	void process(float* left, float *right);

	void setMix(float newValue){ Mix = newValue; }
	void setFeedback(float newValue){ Feedback = newValue; }
	float getMix(){ return Mix; }
	float getFeedback(){ return Feedback; }
	float getLenght(){ return LeftLength; }

	void setDelayBufferLengthRight(int newlength);
	void setDelayBufferLengthLeft(int newlength);


};




#endif  // DELAY_H_INCLUDED
