/*
  ==============================================================================

    LowPassFilter.cpp
    Created: 24 Nov 2014 2:57:43pm
    Author:  Alex

  ==============================================================================
*/

#include "LowPassFilter.h"
double LowPassFilter::computeB0()
{
	return (1 - cosw0)/2;
}

double LowPassFilter::computeB1()
{
	return 1 - cosw0;
}

double LowPassFilter::computeB2()
{
	return (1 - cosw0)/2;
}

double LowPassFilter::computeA0()
{
	return 1 + alpha;
}

double LowPassFilter::computeA1()
{
	return (-2) * cosw0;
}

double LowPassFilter::computeA2()
{
	return 1 - alpha;
}