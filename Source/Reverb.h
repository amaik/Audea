/*
  ==============================================================================

    Reverb.h
    Created: 9 Jan 2015 3:10:31pm
    Author:  Alex

  ==============================================================================
*/

#ifndef REVERB_H_INCLUDED
#define REVERB_H_INCLUDED
class Reverb{
	float *mix;
	float *decay;	//in ms
	float *size; //represented ind Reflectiontime in ms
	float delayLen = 0.0f;
	float prevSample = 0.0f;

	float *delay;

public:
	Reverb(float sampleRate,float *mix, float *decay, float *size);
	~Reverb();

	void setDelayLenght(float newSize);
	void process(float* left, float *right);
};




#endif  // REVERB_H_INCLUDED
