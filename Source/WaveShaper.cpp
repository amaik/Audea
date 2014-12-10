/*
  ==============================================================================

    WaveShaper.cpp
    Created: 10 Dec 2014 5:55:13pm
    Author:  Alex

  ==============================================================================
*/

#include "WaveShaper.h"
#include <cmath>
#include "JuceHeader.h"

void WaveShaper::process(float *left, float *right)
{
	double a = sin(((*drive + 1) / 101) * (double_Pi / 2));
	double k = 2 * a / (1 - a);
	*left = ((1 + k) * *left) / (1 + k * abs(*left));
	*right = ((1 + k) * *right) / (1 + k * abs(*right));
}