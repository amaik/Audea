/*
  ==============================================================================

    LFO.h
    Created: 14 Jan 2015 4:21:02pm
    Author:  Alex

  ==============================================================================
*/

#ifndef LFO_H_INCLUDED
#define LFO_H_INCLUDED
#include "../JuceLibraryCode/JuceHeader.h"

class LFO
{
	//Wave settings
	float index = 0;
	float increment = 0;
	float frequency = 0.15;
	float samplerate = 0;

	enum destination
	{
		None,
		FilterCutoff,
		Volume,
		Pan
	};

	float *amount;


public:	
	//Constructor - Desctructor
	LFO(float frq, int smplrate, float* amt);
	~LFO();
	
	//public methods and fields
	int destination = 0;
	void calculateIncrement();
	float getNextVolumeOffset();
	float getNextPanOffset();
	int getNextCutoffFrqOffset();

	//Getters Setters
	void setFrequency(float frq){ frequency = frq; }
	float getFrequency(){ return frequency; }
	void setSamplerate(int smplrate){ samplerate = smplrate; }
	int getSamplerate(){ return samplerate; }

};




#endif  // LFO_H_INCLUDED
