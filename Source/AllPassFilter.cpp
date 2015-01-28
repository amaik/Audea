/*
  ==============================================================================

    AllPassFilter.cpp
    Created: 24 Nov 2014 2:59:20pm
    Author:  Alex

  ==============================================================================
*/

#include "AllPassFilter.h"


double AllPassFilter::computeB0() 
{
	return 1 - alpha;
}

double AllPassFilter::computeB1()
{
	return -2 * cosw0;
}

double AllPassFilter::computeB2()
{
	return 1 + alpha;
}

double AllPassFilter::computeA0()
{
	return 1 + alpha;
}

double AllPassFilter::computeA1()
{
	return -2 * cosw0;
}

double AllPassFilter::computeA2()
{
	return 1 - alpha;
}