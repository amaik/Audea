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
	x_n_1_Left = 0;
	x_n_2_Left = 0;

	y_n_1_Left = 0;
	y_n_2_Left = 0;

	x_n_1_Right = 0;
	x_n_2_Right = 0;

	y_n_1_Right = 0;
	y_n_2_Right = 0;

	w0 = 0;
	sinw0 = 0;
	cosw0 = 0;
	alpha = 0;


}

float Filter::processFilterLeft(float leftSample)
{
	/*y[n] = (b0 / a0)*x[n] + (b1 / a0)*x[n - 1] + (b2 / a0)*x[n - 2]
		- (a1 / a0)*y[n - 1] - (a2 / a0)*y[n - 2]*/
	float leftUnprocessed = leftSample;
	
	float leftProcessed = (computeB0() * leftUnprocessed) + (computeB1() * x_n_1_Left) + (computeB2() * x_n_2_Left)
		- (computeA1() * y_n_1_Left) - (computeA2() * y_n_2_Left);

	x_n_2_Left = x_n_1_Left;
	x_n_1_Left = leftUnprocessed;

	y_n_2_Left = y_n_1_Left;
	y_n_1_Left = leftProcessed;


	return leftProcessed;
}

float Filter::processFilterRight(float rightSample)
{
	/*y[n] = (b0 / a0)*x[n] + (b1 / a0)*x[n - 1] + (b2 / a0)*x[n - 2]
	- (a1 / a0)*y[n - 1] - (a2 / a0)*y[n - 2]*/
	float rightUnprocessed = rightSample;

	float rightProcessed = (computeB0() * rightUnprocessed) + (computeB1() * x_n_1_Right) + (computeB2() * x_n_2_Right)
		- (computeA1() * y_n_1_Right) - (computeA2() * y_n_2_Right);

	x_n_2_Right = x_n_1_Right;
	x_n_1_Right = rightUnprocessed;

	y_n_2_Right = y_n_1_Right;
	y_n_1_Right = rightProcessed;
	
	
	return rightProcessed;
}