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
public:
	Delay(){};
	Delay(int lengthLeft, int lengthRight){
		Mix = 0.5f;
		Feedback = 0.5f;
		delayBufferRight = new std::atomic<float>[lengthRight];
		memset(delayBufferRight, 0, lengthRight);
		RightLength = lengthRight;
		delayBufferLeft = new std::atomic<float>[lengthLeft];
		memset(delayBufferLeft, 0, lengthLeft);
		LeftLength = lengthLeft;
	}

	~Delay(){
		delete[] delayBufferLeft;
		delete[] delayBufferRight;
	}

	void process(float* left, float *right);

	void setMix(float newValue){ Mix = newValue; }
	void setFeedback(float newValue){ Feedback = newValue; }
	float getMix(){ return Mix; }
	float getFeedback(){ return Feedback; }
	float getLenght(){ return LeftLength; }

	void setDelayBufferLengthRight(int newlength){
		RightLength.store(newlength);
		delayPositionRight.store(0);
	}

	void setDelayBufferLengthLeft(int newlength){
		LeftLength.store(newlength);
		delayPositionLeft.store(0);
	}


private:
	std::atomic<float> *delayBufferLeft;
	std::atomic<int> LeftLength;
	std::atomic<float> *delayBufferRight;
	std::atomic<int> RightLength;
	float Mix;
	float Feedback;
	std::atomic<int> delayPositionLeft = 0;
	std::atomic<int> delayPositionRight = 0;
};




#endif  // DELAY_H_INCLUDED
