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
#include "ModulatorEffect.h"

class Flanger : public ModulatorEffect{

public:
	Flanger(float samplesPerSecond,float *mix,float *fb);
	~Flanger();
};



#endif  // FLANGER_H_INCLUDED
