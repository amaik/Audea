/*
  ==============================================================================

    Effect.h
    Created: 11 Jan 2015 2:47:05pm
    Author:  Alex

  ==============================================================================
*/

#ifndef EFFECT_H_INCLUDED
#define EFFECT_H_INCLUDED
#include "../JuceLibraryCode/JuceHeader.h"

class Effect{
public:
	void virtual process(float* left, float *right) = 0;
};




#endif  // EFFECT_H_INCLUDED
