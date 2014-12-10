/*
  ==============================================================================

    AllPassFilter.h
    Created: 24 Nov 2014 2:59:20pm
    Author:  Alex

  ==============================================================================
*/

#ifndef ALLPASSFILTER_H_INCLUDED
#define ALLPASSFILTER_H_INCLUDED
#include "Filter.h"

class AllPassFilter : public Filter
{

public:
	AllPassFilter(float *Q = nullptr) :
		Filter(Q)
	{
	}
	~AllPassFilter();
	double computeB0() override;
	double computeB1() override;
	double computeB2() override;
	double computeA1() override;
	double computeA2() override;
};



#endif  // ALLPASSFILTER_H_INCLUDED
