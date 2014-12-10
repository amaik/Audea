/*
  ==============================================================================

    Flanger.h
    Created: 10 Dec 2014 3:20:41pm
    Author:  Felix Rolshausen

  ==============================================================================
*/

#ifndef FLANGER_H_INCLUDED
#define FLANGER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class Flanger{

public:
	Flanger(){}
	Flanger(float samplesPerMillisecond){
		center = 8.0f;
		Mix = 0.5f;
		Feedback = 0.5f;
		depth = 10.0f;
		Samples = samplesPerMillisecond;
		variableDelayLine = new float[(int)((center + (10.0f / 2)) * (Samples / 1000))];
		memset(variableDelayLine, 0, (center + (depth / 2))*(Samples / 1000));
		delayCenter = (center * (Samples / 1000));
		delayRange = (depth * (Samples / 1000)) / 2;
	}

	~Flanger(){
		delete[] variableDelayLine;
	}

	void setMix(float newMix){ Mix = newMix; };
	void setFeedback(float newFeedback){ Feedback = newFeedback; };
	void setDepth(float newDepth){ depth = newDepth; };
	void updateRange(){ delayRange = depth * (Samples / 1000); };


	void process(float* left, float *right);


private:
	float Mix;
	float Feedback;
	float depth;
	float center;
	float Samples;
	float* variableDelayLine;
	float readFract;
	int readInt;
	int delayWrite = 0;
	int delayRead;
	int delayOffset;
	int delayRange;
	int delayCenter;
};



#endif  // FLANGER_H_INCLUDED
