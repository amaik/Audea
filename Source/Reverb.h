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
	float mix = 0.0f;
	float decay = 0.0f;	//in ms
	float size = 0.0f; //represented ind Reflectiontime in ms
	float delayLen = 0.0f;
	float prevSample = 0.0f;

	float *delay;

public:
	Reverb(float sampleRate);
	~Reverb();

	void setMix(float newMix){ mix = newMix;}
	void setDecay(float newDecay){ decay = newDecay; }
	
	void setSize(float newSize);
	void process(float* left, float *right);
};




#endif  // REVERB_H_INCLUDED
