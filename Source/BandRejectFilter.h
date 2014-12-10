/*
  ==============================================================================

    BandRejectFilter.h
    Created: 24 Nov 2014 2:58:49pm
    Author:  Alex

  ==============================================================================
*/

#ifndef BANDREJECTFILTER_H_INCLUDED
#define BANDREJECTFILTER_H_INCLUDED
#include "Filter.h"

class BandRejectFilter : public Filter
{

public:
	BandRejectFilter(float *Q = nullptr) :
		Filter(Q)
	{
	}
	~BandRejectFilter();
	double computeB0() override;
	double computeB1() override;
	double computeB2() override;
	double computeA1() override;
	double computeA2() override;
};





#endif  // BANDREJECTFILTER_H_INCLUDED
