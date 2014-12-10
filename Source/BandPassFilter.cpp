/*
  ==============================================================================

    BandPassFilter.cpp
    Created: 24 Nov 2014 2:57:58pm
    Author:  Alex

  ==============================================================================
*/

#include "BandPassFilter.h"
double BandPassFilter::computeB0()
{
	return sinw0 / 2;
}

double BandPassFilter::computeB1()
{
	return 0;
}

double BandPassFilter::computeB2()
{
	return -sinw0 / 2;
}

double BandPassFilter::computeA1()
{
	return -2 * cosw0;
}

double BandPassFilter::computeA2()
{
	return 1 - alpha;
}