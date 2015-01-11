/*
  ==============================================================================

    Reverb.h
    Created: 9 Jan 2015 3:10:31pm
    Author:  Alex

  ==============================================================================
*/

#ifndef AUDEAREVERB_H_INCLUDED
#define AUDEAREVERB_H_INCLUDED

#include "Effect.h"
class AudeaReverb : public Effect{

	float *mix;
	float *rvbTime;	//in ms
	float *size; //represented ind Reflectiontime in ms
	float decay = 0.0f;
	float delayLen = 0.0f;
	float prevLeft = 0.0f;
	float prevRight = 0.0f;
	int delayIndex = 0;

	float *delayLeft;

	float *delayRight;

public:
	AudeaReverb(float sampleRate,float *mx, float *rvbT, float *sze);
	~AudeaReverb();

	void setDelayLenght(float newSize);
	void process(float* left, float *right);
};




#endif  // AUDEAREVERB_H_INCLUDED
