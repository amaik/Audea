/*
  ==============================================================================

    WaveShaper.h
    Created: 10 Dec 2014 5:55:13pm
    Author:  Alex

  ==============================================================================
*/

#ifndef WAVESHAPER_H_INCLUDED
#define WAVESHAPER_H_INCLUDED
#include "Effect.h"
class WaveShaper : public Effect
{
	float *drive;
public:
	WaveShaper(float *drv): 
		drive(drv)
	{
	}
	~WaveShaper(){}
	void process(float *left, float *right);
};




#endif  // WAVESHAPER_H_INCLUDED
