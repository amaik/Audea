/*
  ==============================================================================

    HighPassFilter.h
    Created: 24 Nov 2014 2:58:12pm
    Author:  Alex

  ==============================================================================
*/

#ifndef HIGHPASSFILTER_H_INCLUDED
#define HIGHPASSFILTER_H_INCLUDED
#include "Filter.h"

class HighPassFilter : public Filter
{

public:
	HighPassFilter(float *Q = nullptr, float samplerate = 41000) :
		Filter(Q,samplerate)
	{
	}
	~HighPassFilter();
	double computeB0() override;
	double computeB1() override;
	double computeB2() override;
	double computeA1() override;
	double computeA2() override;
};






#endif  // HIGHPASSFILTER_H_INCLUDED
