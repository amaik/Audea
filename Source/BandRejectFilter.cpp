/*
  ==============================================================================

    BandRejectFilter.cpp
    Created: 24 Nov 2014 2:58:49pm
    Author:  Alex

  ==============================================================================
*/

#include "BandRejectFilter.h"


double BandRejectFilter::computeB0()
{
	return 1;
}

double BandRejectFilter::computeB1()
{
	return -2 * cosw0;
}

double BandRejectFilter::computeB2()
{
	return 1;
}

double BandRejectFilter::computeA1()
{
	return -2 * cosw0;
}

double BandRejectFilter::computeA2()
{
	return 1 - alpha;
}