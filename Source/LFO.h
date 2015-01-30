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
#include <cmath>

class LFO
{
	//Wave settings
	float index = 0;
	float increment = 0;
	float frequency = 0.15f;
	int samplerate = 0;

	float *amount;
	int destination = 0;

public:	
	//Constructor - Desctructor
	LFO(float frq, int smplrate, float* amt);
	~LFO();
	
	//public methods and fields
	
	void calculateIncrement();
	float getNextVolumeOffset();
	float getNextPanOffset();
	int getNextCutoffFrqOffset();
	void reset();

	//Getters Setters
	void setFrequency(float frq);
	float getFrequency(){ return frequency; }
	void setSamplerate(int smplrate){ samplerate = smplrate; }
	int getSamplerate(){ return samplerate; }
	int getDestination(){ return destination; }
	void setDestination(int dest);

	//Destination Enum
	enum destination
	{
		Placeholder,
		None,
		FilterCutoff,
		Volume,
		Pan
	};
};




#endif  // LFO_H_INCLUDED
