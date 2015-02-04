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
	x_n_1_Left  = 0;
	x_n_2_Left  = 0;

	y_n_1_Left  = 0;
	y_n_2_Left  = 0;

	x_n_1_Right = 0;
	x_n_2_Right = 0;

	y_n_1_Right = 0;
	y_n_2_Right = 0;

	w0 = 0;
	sinw0 = 0;
	cosw0 = 0;
	alpha = 0;


}

float Filter::processFilterRight(float sample)
{
	/*y[n] = (b0 / a0)*x[n] + (b1 / a0)*x[n - 1] + (b2 / a0)*x[n - 2]
		- (a1 / a0)*y[n - 1] - (a2 / a0)*y[n - 2]*/
	float unprocessed = sample;
	double a0 = computeA0();

	float processed = (computeB0()/a0 * unprocessed) 
		+ (computeB1() /a0 * x_n_1_Right)
		+ (computeB2() /a0 * x_n_2_Right)
		- (computeA1() /a0 * y_n_1_Right)
		- (computeA2() /a0 * y_n_2_Right);

	x_n_2_Right = x_n_1_Right;
	x_n_1_Right = unprocessed;

	y_n_2_Right = y_n_1_Right;
	y_n_1_Right = processed;


	return processed;
}

float Filter::processFilterLeft(float sample)
{
	/*y[n] = (b0 / a0)*x[n] + (b1 / a0)*x[n - 1] + (b2 / a0)*x[n - 2]
	- (a1 / a0)*y[n - 1] - (a2 / a0)*y[n - 2]*/
	float unprocessed = sample;
	double a0 = computeA0();

	float processed = (computeB0() /a0 * unprocessed)
		+ (computeB1() /a0 * x_n_1_Left)
		+ (computeB2() /a0 * x_n_2_Left)
		- (computeA1() /a0 * y_n_1_Left)
		- (computeA2() /a0 * y_n_2_Left);

	x_n_2_Left = x_n_1_Left;
	x_n_1_Left = unprocessed;

	y_n_2_Left = y_n_1_Left;
	y_n_1_Left = processed;


	return processed;
}