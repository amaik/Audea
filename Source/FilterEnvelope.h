/*
  ==============================================================================

    FilterEnvelope.h
    Created: 18 Nov 2014 9:04:53pm
    Author:  Alex

  ==============================================================================
*/

#ifndef FILTERENVELOPE_H_INCLUDED
#define FILTERENVELOPE_H_INCLUDED

class FilterEnvelope
{

	float *attackTime;
	float *decayTime;
	float *sustainLevel;
	float *releaseTime;
	
	float *cutoffFrequency;
	float *envAmt;
	//float *Q;

	double cutoffFrequencyBuffer = 0.0f;
	double frequencyDifference = 0.0f;

	double attackNumSamples,
		decayNumSamples,
		releaseNumSamples;

	double attackIncr,
		decayIncr,
		releaseIncr;

	double sampleRate = 48000;


	bool isRelease = false;
	int envState = Attack;

	//HelperMethods

public:
	//Constructors
	FilterEnvelope(float *attackTime = nullptr, float *decayTime = nullptr, float *sustainLevel = nullptr, float *releaseTime = nullptr, float *cutoff = nullptr, float *envAmt = nullptr /*,float *Q = nullptr*/)
		: attackTime(attackTime),
		decayTime(decayTime),
		sustainLevel(sustainLevel),
		releaseTime(releaseTime),
		cutoffFrequency(cutoff),
		envAmt(envAmt)/*,
		Q(Q)*/
	{

	};

	~FilterEnvelope() {};

	//Public Methods
	void initSegments(); // Set the duration of the segments in Samples
	float getNextCutoffFrequency();
	bool isStartRelease();
	void StartRelease();
	void StopRelease();
	void setEnvState(int id);
	int getEnvState();

	//Setters, Getters, Misc
	void setSampleRate(double smRate) { sampleRate = smRate; }
	enum States{
		Attack,
		Decay,
		Sustain,
		Release
	};
};




#endif  // FILTERENVELOPE_H_INCLUDED
