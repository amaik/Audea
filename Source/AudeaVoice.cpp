/*
  ==============================================================================

    AudeaVoice.cpp
    Created: 10 Nov 2014 12:34:40pm
    Author:  Alex

  ==============================================================================
*/

#include "AudeaVoice.h"


bool AudeaVoice::canPlaySound(juce::SynthesiserSound* sound)
{
	return dynamic_cast<AudeaSound*> (sound) != nullptr;
}


void AudeaVoice::startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* /*sound*/, int /*currentPitchWheelPosition*/)
{
	soundOn = true;
	level = velocity * 0.15;
	tailOff = 0.0;

	double cyclesPerSecond = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
	double samplesPerCycle = getSampleRate() / cyclesPerSecond;
	double cyclesPerSample = cyclesPerSecond / getSampleRate();

	env->initSegments();
	filEnv->initSegments();
	fil->resetFilter();
	
	osc1Params.sawValue = -1;
	osc1Params.sawIncr = 2 / samplesPerCycle;
	osc1Params.sineAngle = 0.0;
	osc1Params.sineIncr = cyclesPerSample * 2.0 * double_Pi;
	osc1Params.squareMidPoint = twoPI * 1 / 2;
	osc1Params.phase = 0;
	osc1Params.phaseIncr = (twoPI / getSampleRate()) * cyclesPerSecond;

	if (osc2Params.isOn){
		cyclesPerSecond = getTunedFrequency(MidiMessage::getMidiNoteInHertz(midiNoteNumber),*osc2Params.tuning);
		samplesPerCycle = getSampleRate() / cyclesPerSecond;
		cyclesPerSample = cyclesPerSecond / getSampleRate();
		osc2Params.sawValue = -1;
		osc2Params.sawIncr = 2 / samplesPerCycle;
		osc2Params.sineAngle = 0.0;
		osc2Params.sineIncr = cyclesPerSample * 2.0 * double_Pi;
		osc2Params.squareMidPoint = twoPI * 1 / 2;
		osc2Params.phase = 0;
		osc2Params.phaseIncr = (twoPI / getSampleRate()) * cyclesPerSecond;
	}

	if (osc3Params.isOn){
		cyclesPerSecond = getTunedFrequency(MidiMessage::getMidiNoteInHertz(midiNoteNumber), *osc3Params.tuning);
		samplesPerCycle = getSampleRate() / cyclesPerSecond;
		cyclesPerSample = cyclesPerSecond / getSampleRate();
		osc3Params.sawValue = -1;
		osc3Params.sawIncr = 2 / samplesPerCycle;
		osc3Params.sineAngle = 0.0;
		osc3Params.sineIncr = cyclesPerSample * 2.0 * double_Pi;
		osc3Params.squareMidPoint = twoPI * 1 / 2;
		osc3Params.phase = 0;
		osc3Params.phaseIncr = (twoPI / getSampleRate()) * cyclesPerSecond;
	}
}

void AudeaVoice::stopNote(float /*velocity*/, bool allowTailOff)
{
	if (allowTailOff)
	{
		// start a tail-off by setting this flag. The render callback will pick up on
		// this and do a fade out, calling clearCurrentNote() when it's finished.

		env->StartRelease();
		env->setEnvState(Envelope::Release);

		filEnv->StartRelease();
		filEnv->setEnvState(FilterEnvelope::Release);
	}
	else
	{
		// we're being told to stop playing immediately, so reset everything..

		clearCurrentNote();
	}
}

void AudeaVoice::renderNextBlock(juce::AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{

	float currentSample;
	if (soundOn){
		if (env->isStartRelease())
		{
			while (--numSamples >= 0)
			{

				currentSample = (this->*oscOneGenerator)(&osc1Params);
				if(osc2Params.isOn){
					currentSample += (this->*oscTwoGenerator)(&osc2Params);
				}
				if (osc3Params.isOn){
					currentSample += (this->*oscThreeGenerator)(&osc3Params);
				}
				currentSample *= level * env->getNextMultiplier();
				if (osc3Params.isOn) currentSample *= 0.75f;
				
				//Compute the coefficients for the Filter
				fil->computeVariables(filEnv);
				for (int i = outputBuffer.getNumChannels(); --i >= 0;){
					//Filter has to be processed before the sample is written to the buffer
					if (i == 0)
						outputBuffer.addSample(i, startSample, fil->processFilterLeft(currentSample));
					else if (i == 1)
						outputBuffer.addSample(i, startSample, fil->processFilterRight(currentSample));
					else
						outputBuffer.addSample(i, startSample, currentSample);
				}

				++startSample;

				if (!env->isStartRelease())
				{
					clearCurrentNote();
					soundOn = false;
					break;
				}
			}
		}
		else
		{
			while (--numSamples >= 0)
			{

				currentSample = (this->*oscOneGenerator)(&osc1Params);
				if (osc2Params.isOn){
					currentSample += (this->*oscTwoGenerator)(&osc2Params);
				}
				if (osc3Params.isOn){
					currentSample += (this->*oscThreeGenerator)(&osc3Params);
				}
				currentSample *= level * env->getNextMultiplier();
				if (osc3Params.isOn) currentSample *= 0.75f;
				
				//Compute the coefficients of the filter
				fil->computeVariables(filEnv);
				for (int i = outputBuffer.getNumChannels(); --i >= 0;){
					//Filter has to be processed before the sample is written to the buffer
					if (i == 0)
						outputBuffer.addSample(i, startSample, fil->processFilterLeft(currentSample));
					else if (i == 1)
						outputBuffer.addSample(i, startSample, fil->processFilterRight(currentSample));
					else
						outputBuffer.addSample(i, startSample, currentSample);

				}
				++startSample;
			}
		}
	}
}

float AudeaVoice::generateSine(oscParams *oscP)
{	
	const float currentSample = (float)(sin(oscP->sineAngle) * (*oscP->amp));
	oscP->sineAngle += oscP->sineIncr;
	return currentSample;
}
float AudeaVoice::generateNoise(oscParams *oscP)
{
	float currentSample = (float)((getScatteredRand() - 1) * (*oscP->amp));
	return currentSample;
}
float AudeaVoice::generateTriangle(oscParams *oscP)
{
	double triValue = (oscP->phase * (2 / double_Pi));
	if (oscP->phase < 0)
		triValue = 1.0f + triValue;
	else
		triValue = 1.0f - triValue;
	float currentSample = (*oscP->amp) * triValue;
	if ((oscP->phase += oscP->phaseIncr) >= PI)
		oscP->phase -= twoPI;
	return currentSample;
}
float AudeaVoice::generateSaw(oscParams *oscP)
{
	float currentSample = (*oscP->amp) * oscP->sawValue ;
	oscP->sawValue += oscP->sawIncr;
	if (oscP->sawValue >= 1)
		oscP->sawValue -= 2;
	return currentSample;
}
float AudeaVoice::generateSquare(oscParams *oscP)
{
	float currentSample;
	oscP->phase += oscP->phaseIncr;
	if (oscP->phase >= twoPI)
		oscP->phase -= twoPI;
	if (oscP->phase >= oscP->squareMidPoint)
		currentSample = -1 * (*oscP->amp);
	else
		currentSample = 1 * (*oscP->amp) ;

	return currentSample;
}


double AudeaVoice::getTunedFrequency(double frequency, float tuning)
{
	double cyclesPerSecond = frequency;
	if (tuning != 0.0f){
		if (tuning < 0.0f)
			for (int i = tuning; ++i <= 0;)
				cyclesPerSecond /= semiToneIncr;
		else
			for (int i = tuning; --i >= 0;)
				cyclesPerSecond *= semiToneIncr;
		return cyclesPerSecond;
	}
	else
		return cyclesPerSecond;
}

float AudeaVoice::getScatteredRand(){

	return (((rand() / float(RAND_MAX)) * 2) + ((rand() / float(RAND_MAX)) * 2) + ((rand() / float(RAND_MAX)) * 2)
		+ ((rand() / float(RAND_MAX)) * 2) + ((rand() / float(RAND_MAX)) * 2) + ((rand() / float(RAND_MAX)) * 2)
		+ ((rand() / float(RAND_MAX)) * 2) + ((rand() / float(RAND_MAX)) * 2) + ((rand() / float(RAND_MAX)) * 2)
		+ ((rand() / float(RAND_MAX)) * 2) + ((rand() / float(RAND_MAX)) * 2) + ((rand() / float(RAND_MAX)) * 2)) / 12;
}