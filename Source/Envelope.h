/*
  ==============================================================================

    Envelope.h
    Created: 12 Nov 2014 4:08:07pm
    Author:  Alex

  ==============================================================================
*/

#ifndef ENVELOPE_H_INCLUDED
#define ENVELOPE_H_INCLUDED

class Envelope
{

	float *attackTime;
	float *decayTime;
	float *sustainLevel;
	float *releaseTime;

	double attackNumSamples,
		decayNumSamples,
		releaseNumSamples;
	
	double attackMultiplier,
		decayMultiplier,
		releaseMultiplier;

	double attackIncr,
		decayIncr,
		releaseIncr;

	double sampleRate = 48000;


	bool isRelease = false;
	int envState = Attack;

	//HelperMethods

public:
	//Constructors
	Envelope(float *attackTime = nullptr, float *decayTime = nullptr, float *sustainLevel = nullptr, float *releaseTime = nullptr)
	: attackTime(attackTime),
	decayTime(decayTime),
	sustainLevel(sustainLevel),
	releaseTime(releaseTime)
	{

	};

	~Envelope() {};

	//Public Methods
	void initSegments(); // Set the duration of the segments in Samples
	float getNextMultiplier();
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



#endif  // ENVELOPE_H_INCLUDED
