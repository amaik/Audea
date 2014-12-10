/*
  ==============================================================================

    AudeaWave.h
    Created: 7 Nov 2014 4:44:25pm
    Author:  Alex

  ==============================================================================
*/

#ifndef AUDEAWAVE_H_INCLUDED
#define AUDEAWAVE_H_INCLUDED
#include "JuceHeader.h"
#include "Envelope.h"
#include "Filter.h"

#define semiToneIncr 1.0594630943592953
#define PI 3.14159265358979323846

class AudeaSound : public SynthesiserSound {
public:
	AudeaSound() {}

	bool appliesToNote(int /*midiNoteNumber*/) override  { return true; }
	bool appliesToChannel(int /*midiChannel*/) override  { return true; }
};

class AudeaVoice : public SynthesiserVoice
{
protected:

	//params general
	bool soundOn = false;
	double level, tailOff;
	double twoPI = double_Pi * 2;
	static float defaultTuning;
	static float defaultAmp;
	//oscillator Params
	struct oscParams
	{
		double sawValue;
		double sawIncr;
		double sineAngle;
		double sineIncr;
		double phase;
		double phaseIncr;
		double squareMidPoint;
		float *amp;
		float *tuning;
		bool isOn;
		oscParams(float *amp = &defaultAmp, float *tuning = &defaultTuning) : amp(amp), tuning(tuning){}
	};

	oscParams osc1Params;
	oscParams osc2Params;
	oscParams osc3Params;


	//oscillator function pointers
	float(AudeaVoice::*oscOneGenerator)(oscParams*) = NULL;
	float(AudeaVoice::*oscTwoGenerator)(oscParams*) = NULL;
	float(AudeaVoice::*oscThreeGenerator)(oscParams*) = NULL;

	//Envelopes - Pointers to the Heap, has to be deleted
	Envelope *env;
	FilterEnvelope *filEnv;

	//Filter - Pointer to the Filter in the AudioProcessor
	Filter *fil; 



public:
	//constructors
	AudeaVoice( float *ampOsc1,float *ampOsc2,float *ampOsc3, float *tuningOsc2,
		float *tuningOsc3, Envelope *ev, Filter *fl, FilterEnvelope *flEnv)
	{
		defaultTuning = 0.0f;
		defaultAmp = 1.0f;
		osc1Params.amp = ampOsc1;
		osc2Params.amp = ampOsc2;
		osc3Params.amp = ampOsc3;
		
		osc2Params.tuning = tuningOsc2;
		osc3Params.tuning = tuningOsc3;

		osc1Params.isOn = true;
		osc2Params.isOn = false;
		osc3Params.isOn = false;

		oscOneGenerator = &AudeaVoice::generateSine;
		oscTwoGenerator = &AudeaVoice::generateSine;
		oscThreeGenerator = &AudeaVoice::generateSine;

		env = ev;

		fil = fl;

		filEnv = flEnv;
	}
	~AudeaVoice(){
		delete env;
	}

	enum WaveForms{
		Sine,
		Triangle,
		Saw,
		Square,
		Noise,
		TotalNumWaveForms
	};



	//overwritten methods
	bool canPlaySound(SynthesiserSound* sound) override;
	void startNote(int midiNoteNumber, float velocity, SynthesiserSound* /*sound*/, int /*currentPitchWheelPosition*/) override;
	void stopNote(float /*velocity*/, bool allowTailOff) override;
	void pitchWheelMoved(int /*newValue*/) override { /*not implemented*/ }
	void controllerMoved(int /*controllerNumber*/, int /*newValue*/) override { /*not implemented*/ }
	void renderNextBlock(AudioSampleBuffer& outputBuffer, int startSample, int numSamples) override;
	
	//Helper, Getter , Setter
	float getScatteredRand();
	double getTunedFrequency(double frequency, float tuning);
	void setOsc2IsOn(bool b){ osc2Params.isOn = b; }
	void setOsc3IsOn(bool b){ osc3Params.isOn = b; }
	void setOsc2Tune(float *tune){ osc2Params.tuning = tune; }
	void setOsc3Tune(float *tune){ osc3Params.tuning = tune; }
	void setOsc1Amp(float *value){ osc1Params.amp = value; }
	void setOsc2Amp(float *value){ osc2Params.amp = value; }
	void setOsc3Amp(float *value){ osc3Params.amp = value; }
	void setOsc1WvForm(int id){
		switch (id){
		case Sine:		oscOneGenerator = &AudeaVoice::generateSine;
			break;
		case Triangle:	oscOneGenerator = &AudeaVoice::generateTriangle;
			break;
		case Saw:		oscOneGenerator = &AudeaVoice::generateSaw;
			break;
		case Square:	oscOneGenerator = &AudeaVoice::generateSquare;
			break;
		case Noise:		oscOneGenerator = &AudeaVoice::generateNoise;
			break;
		}
	}
	void setOsc2WvForm(int id){
		switch (id){
		case Sine:		oscTwoGenerator = &AudeaVoice::generateSine;
			break;
		case Triangle:	oscTwoGenerator = &AudeaVoice::generateTriangle;
			break;
		case Saw:		oscTwoGenerator = &AudeaVoice::generateSaw;
			break;
		case Square:	oscTwoGenerator = &AudeaVoice::generateSquare;
			break;
		case Noise:		oscTwoGenerator = &AudeaVoice::generateNoise;
			break;
		}
	}
	void setOsc3WvForm(int id){
		switch (id){
		case Sine:		oscThreeGenerator = &AudeaVoice::generateSine;
			break;
		case Triangle:	oscThreeGenerator = &AudeaVoice::generateTriangle;
			break;
		case Saw:		oscThreeGenerator = &AudeaVoice::generateSaw;
			break;
		case Square:	oscThreeGenerator = &AudeaVoice::generateSquare;
			break;
		case Noise:		oscThreeGenerator = &AudeaVoice::generateNoise;
			break;
		}
	}

	//generator methods
	float generateSine(oscParams *oscP);
	float generateNoise(oscParams *oscP);
	float generateTriangle(oscParams *oscP);
	float generateSaw(oscParams *oscP);
	float generateSquare(oscParams *oscP);
};

float AudeaVoice::defaultAmp = 1.0f;
float AudeaVoice::defaultTuning = 0.0f;

#endif  // AUDEAWAVE_H_INCLUDED
