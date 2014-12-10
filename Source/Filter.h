/*
  ==============================================================================

    Filter.h
    Created: 18 Nov 2014 9:06:21pm
    Author:  Alex

  ==============================================================================
*/

#ifndef FILTER_H_INCLUDED
#define FILTER_H_INCLUDED
#include "JuceHeader.h"
#include "FilterEnvelope.h"
#include <cmath>
class Filter
{
protected:
	//Delayed Signals
	float x_n_1_Left = 0;
	float x_n_2_Left = 0;

	float y_n_1_Left = 0;
	float y_n_2_Left = 0;

	float x_n_1_Right = 0;
	float x_n_2_Right = 0;

	float y_n_1_Right = 0;
	float y_n_2_Right = 0;


	//variables
	double w0;
	double sinw0;
	double cosw0;
	double alpha;
	double sampleRate = 48000;
	float *Q;
public:
	Filter(float *Q = nullptr) : 
		Q(Q)
	{
	}

	void computeVariables(FilterEnvelope *env);
	void resetFilter();
	float processFilterLeft(float leftSample);
	float processFilterRight(float rightSample);
	/*  The Formula for computing the Filter 
	y[n] = (b0/a0)*x[n] + (b1/a0)*x[n-1] + (b2/a0)*x[n-2]- (a1/a0)*y[n-1] - (a2/a0)*y[n-2]
	a0 is set to 1 in this case
	*/
	virtual double computeB0() = 0;
	virtual double computeB1() = 0;
	virtual double computeB2() = 0;
	virtual double computeA1() = 0;
	virtual double computeA2() = 0;
	
	//Getter,Setter
	double getSampleRate(){ return sampleRate; }
	double setSampleRate(double smpRate){ sampleRate = smpRate; }

};



#endif  // FILTER_H_INCLUDED
