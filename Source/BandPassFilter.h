/*
  ==============================================================================

    BandPassFilter.h
    Created: 24 Nov 2014 2:57:58pm
    Author:  Alex

  ==============================================================================
*/

#ifndef BANDPASSFILTER_H_INCLUDED
#define BANDPASSFILTER_H_INCLUDED
#include "Filter.h"

class BandPassFilter : public Filter
{

public:
	BandPassFilter(float *Q = nullptr) :
		Filter(Q)
	{
	}
	~BandPassFilter();
	double computeB0() override;
	double computeB1() override;
	double computeB2() override;
	double computeA1() override;
	double computeA2() override;
};




#endif  // BANDPASSFILTER_H_INCLUDED
