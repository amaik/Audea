/*
  ==============================================================================

    Filter.cpp
    Created: 18 Nov 2014 9:06:21pm
    Author:  Alex

  ==============================================================================
*/

#include "Filter.h"

void Filter::computeVariables(FilterEnvelope *env)
{
	/* 
    w0 = 2*pi*f0/Fs

    cos(w0)
    sin(w0)

    alpha = sin(w0)/(2*Q)*/
	w0 = 2 * double_Pi * (env->getNextCutoffFrequency() / sampleRate);
	sinw0 = sin(w0);
	cosw0 = cos(w0);
	alpha = sinw0 / (2 * *Q);
}

void Filter::resetFilter()
{
	x_n_1  = 0;
	x_n_2  = 0;

	y_n_1  = 0;
	y_n_2  = 0;

	w0 = 0;
	sinw0 = 0;
	cosw0 = 0;
	alpha = 0;


}

float Filter::processFilter(float sample)
{
	/*y[n] = (b0 / a0)*x[n] + (b1 / a0)*x[n - 1] + (b2 / a0)*x[n - 2]
		- (a1 / a0)*y[n - 1] - (a2 / a0)*y[n - 2]*/
	float unprocessed = sample;
	
	float processed = (computeB0()/computeA0() * unprocessed) 
		+ (computeB1()/computeA0() * x_n_1)
		+ (computeB2()/computeA0() * x_n_2)
		- (computeA1()/computeA0() * y_n_1) 
		- (computeA2()/computeA0() * y_n_2);

	x_n_2 = x_n_1;
	x_n_1 = unprocessed;

	y_n_2 = y_n_1;
	y_n_1 = processed;


	return processed;
}