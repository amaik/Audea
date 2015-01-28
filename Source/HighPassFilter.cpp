/*
  ==============================================================================

    HighPassFilter.cpp
    Created: 24 Nov 2014 2:58:12pm
    Author:  Alex

  ==============================================================================
*/

#include "HighPassFilter.h"


double HighPassFilter::computeB0()
{
	return (1 + cosw0)/2;
}

double HighPassFilter::computeB1()
{
	return -(1 + cosw0);
}

double HighPassFilter::computeB2()
{
	return (1 + cosw0) / 2;
}

double HighPassFilter::computeA0()
{
	return 1 + alpha;
}
double HighPassFilter::computeA1()
{
	return -2 * cosw0;
}

double HighPassFilter::computeA2()
{
	return 1 - alpha;
}