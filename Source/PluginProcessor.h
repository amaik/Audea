/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Envelope.h"
#include "FilterHeader.h"
#include "FilterEnvelope.h"
#include "Delay.h"
#include "Flanger.h"
#include "WaveShaper.h"


//==============================================================================
/**
*/
class AudeaAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    AudeaAudioProcessor();
    ~AudeaAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    int getNumParameters() override;
    float getParameter (int index) override;
    void setParameter (int index, float newValue) override;

    const String getParameterName (int index) override;
    const String getParameterText (int index) override;

    const String getInputChannelName (int channelIndex) const override;
    const String getOutputChannelName (int channelIndex) const override;
    bool isInputChannelStereoPair (int index) const override;
    bool isOutputChannelStereoPair (int index) const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool silenceInProducesSilenceOut() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
	
	//Custom Methods, Params and Public Data
	enum Parameters
	{ 
		MasterBypass = 0,
		OscVoices,
		Osc1WaveForm,
		Osc2WaveForm,
		Osc3WaveForm,
		Osc2IsOn,
		Osc3IsOn,
		Osc2Tune,
		Osc3Tune,
		Osc1Amp,
		Osc2Amp,
		Osc3Amp,
		AmpEnvAttack,
		AmpEnvDecay,
		AmpEnvSustain,
		AmpEnvRelease,
		FilterType,
		FilterCutoff,
		FilterRes,
		FilterEnvAmt,
		FilterEnvAttack,
		FilterEnvDecay,
		FilterEnvSustain,
		FilterEnvRelease,
		DelayMix,
		DelayFeedback,
		DelayLenRight,
		DelayLenLeft,
		DelayIsOn,
		FlangerMix,
		FlangerFeedback,
		FlangerDelay,
		FlangerIsOn,
		DistortionIsOn,
		DistortionAmt,
		/*OtherParams..,*/
		totalNumParam 
	};

	enum WaveFormIds
	{
		PlaceHolder = 0,
		Sine,
		Triangle,
		Square,
		Saw,
		Noise
	};

	enum FilterTypeIds
	{
		PlaceHolder2 = 0,
		LowPass,
		BandPass,
		HighPass,
		BandReject,
		Allpass
	};

	enum DelayLenIds
	{
		PlaceHolder3 = 0,
		one,
		half,
		quarter,
		eights,
		sixteenth,
		demisemiquaver
	};

	bool NeedsUIUpdate(){ return UIUpdateFlag; };
	void RequestUIUpdate(){ UIUpdateFlag = true; };
	void ClearUIUpdateFlag(){ UIUpdateFlag = false; };
	//this is kept up to date with the midid messages that arrice, and the UI component
	//registers with it so ti can represent the incoming messages
	MidiKeyboardState keyboardState;

private:
	//Private Data
	float UserParams[totalNumParam];
	bool UIUpdateFlag;
	bool isInited = false;
	
	AudioPlayHead* playHead;
	AudioPlayHead::CurrentPositionInfo currentPositionInfo;
	Delay* delay = nullptr;
	Flanger* flanger = nullptr;
	Synthesiser synth;
	Filter *filter = new AllPassFilter(&UserParams[FilterRes]);
	WaveShaper *wvShaper = new WaveShaper(&UserParams[DistortionAmt]);



	//Helper Methods
	void changeOscillatorWaveForm(int oscID, int wvForm);
	void updateOscillatorVoices();
	void changeFilterType(int filterId);
	void init();
	void changeDelayLength(int DelayLenRight, bool left);
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudeaAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
