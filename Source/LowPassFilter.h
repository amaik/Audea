/*
  ==============================================================================

    LowPassFilter.h
    Created: 24 Nov 2014 2:57:43pm
    Author:  Alex

  ==============================================================================
*/

#ifndef LOWPASSFILTER_H_INCLUDED
#define LOWPASSFILTER_H_INCLUDED
#include "Filter.h"

class LowPassFilter : public Filter
{

public:
	LowPassFilter(float *Q = nullptr) :
		Filter(Q)
	{
	}
	~LowPassFilter();
	double computeB0() override;
	double computeB1() override;
	double computeB2() override;
	double computeA1() override;
	double computeA2() override;
};





#endif  // LOWPASSFILTER_H_INCLUDED
