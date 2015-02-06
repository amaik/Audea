/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "AudeaVoice.h"


//==============================================================================
AudeaAudioProcessor::AudeaAudioProcessor()
{	
	//initialize the UserParams
	UserParams[MasterBypass] = 0.0f;//default to not bypassed
	UserParams[OscVoices] = 4.0f;
	UserParams[Osc1WaveForm] = 1.0f;
	UserParams[Osc2WaveForm] = 1.0f;
	UserParams[Osc2IsOn] = 0.0f; //default off
	UserParams[Osc2Tune] = 0.0f;
	UserParams[Osc1Amp] = 1.0f;
	UserParams[Osc2Amp] = 0.0f;
	UserParams[AmpEnvAttack] = 0.0f;
	UserParams[AmpEnvDecay] = 0.0f;
	UserParams[AmpEnvSustain] = 1.0f;
	UserParams[AmpEnvRelease] = 0.0f;
	UserParams[FilterType] = 1.0;
	UserParams[FilterCutoff] = 20000.0;
	UserParams[FilterRes] = 1.0f;
	UserParams[FilterEnvAmt] = 0.0f;
	UserParams[FilterEnvAttack] = 0.0f;
	UserParams[FilterEnvDecay] = 0.0f;
	UserParams[FilterEnvSustain] = 1.0f;
	UserParams[FilterEnvRelease] = 0.0f;
	UserParams[DelayMix] = 0.5f;
	UserParams[DelayFeedback] = 0.5f;
	UserParams[DelayLenRight] = 2.0f;
	UserParams[DelayLenLeft] = 2.0f;
	UserParams[DelayIsOn] = 0.0f;
	UserParams[FlangerMix] = 0.5f;
	UserParams[FlangerFeedback] = 0.0f;
	UserParams[FlangerDelay] = 10.0f;
	UserParams[FlangerIsOn] = 0.0f;
	UserParams[ChorusRate] = 5.0f;
	UserParams[ChorusMix] = 0.25f;
	UserParams[ChorusIsOn] = 0.0f;
	UserParams[DistortionIsOn] = 0.0f;
	UserParams[DistortionAmt] = 0.0f;
	UserParams[ReverbIsOn] = 0.0f;
	UserParams[ReverbMix] = 0.0f;
	UserParams[ReverbSize] = 0.0f;
	UserParams[ReverbWidth] = 0.0f;
	UserParams[GlobalGain] = 1.0f;
	UserParams[GlobalPan] = 0.5f;
	UserParams[LFOAmount] = 0.0f;
	UserParams[LFODestination] = LFO::None;
	UserParams[LFORate] = NoteLenIds::one;


	UIUpdateFlag = true; //Request UI update

}

AudeaAudioProcessor::~AudeaAudioProcessor()
{
	if (filter != nullptr)
		delete filter;
	if (delay != nullptr)
		delete delay;
	if (flanger != nullptr)
		delete flanger;
	if (wvShaper != nullptr)
		delete wvShaper;
	if (chorus != nullptr)
		delete chorus;
	if (reverb != nullptr)
		delete reverb;
	if (lfo != nullptr)
		delete lfo;
}

//==============================================================================
const String AudeaAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int AudeaAudioProcessor::getNumParameters()
{
    return totalNumParam;
}

float AudeaAudioProcessor::getParameter (int index)
{	//todo: add cases for any special parameters
	if (index >= 0 && index < totalNumParam)
		return UserParams[index];
	else
		return 0.0f;//invalid index
}

void AudeaAudioProcessor::setParameter (int index, float newValue)
{	
	switch (index){
	case MasterBypass:	UserParams[MasterBypass] = newValue;
		break;
	case OscVoices:		UserParams[OscVoices] = newValue;
						updateOscillatorVoices();
		break;
	case Osc1WaveForm:	UserParams[Osc1WaveForm] = newValue;
						changeOscillatorWaveForm(1,(int) newValue);
		break;
	case Osc2WaveForm:  UserParams[Osc2WaveForm] = newValue;
						changeOscillatorWaveForm(2,(int) newValue);
		break;
	case Osc2IsOn:		UserParams[Osc2IsOn] = newValue;
		for (int i = synth.getNumVoices(); --i >= 0;)
			static_cast<AudeaVoice*>(synth.getVoice(i))->setOsc2IsOn(newValue == 1.0f);
		break;
	case Osc2Tune:		UserParams[Osc2Tune] = newValue;
		for (int i = synth.getNumVoices(); --i >= 0;)
			static_cast<AudeaVoice*>(synth.getVoice(i))->setOsc2Tune(&UserParams[Osc2Tune]);
		break;
	case Osc1Amp:		UserParams[Osc1Amp] = newValue;
		for (int i = synth.getNumVoices(); --i >= 0;)
			static_cast<AudeaVoice*>(synth.getVoice(i))->setOsc1Amp(&UserParams[Osc1Amp]);
		break;
	case Osc2Amp:		UserParams[Osc2Amp] = newValue;
		for (int i = synth.getNumVoices(); --i >= 0;)
			static_cast<AudeaVoice*>(synth.getVoice(i))->setOsc2Amp(&UserParams[Osc2Amp]);
		break;
	case AmpEnvAttack:	UserParams[AmpEnvAttack]  =	newValue;
		break;
	case AmpEnvDecay:	UserParams[AmpEnvDecay]	  = newValue;
		break;
	case AmpEnvSustain:	UserParams[AmpEnvSustain] = newValue;
		break;
	case AmpEnvRelease:	UserParams[AmpEnvRelease] = newValue;
		break;
	case FilterType:	UserParams[FilterType] = newValue;
		changeFilterType((int)newValue);
		break;
	case FilterCutoff:	UserParams[FilterCutoff] = newValue;
		break;
	case FilterRes:		UserParams[FilterRes] = newValue;
		break;
	case FilterEnvAmt:	UserParams[FilterEnvAmt] = newValue;
		break;
	case FilterEnvAttack:	UserParams[FilterEnvAttack] = newValue;
		break;
	case FilterEnvDecay:	UserParams[FilterEnvDecay] = newValue;
		break;
	case FilterEnvSustain:	UserParams[FilterEnvSustain] = newValue;
		break;
	case FilterEnvRelease:	UserParams[FilterEnvRelease] = newValue;
		break;
	case DelayLenRight:     UserParams[DelayLenRight] = newValue;
		changeDelayLength((int)newValue, false);
		break;
	case DelayLenLeft:      UserParams[DelayLenLeft] = newValue;
		changeDelayLength((int)newValue, true);
		break;
	case DelayFeedback:     UserParams[DelayFeedback] = newValue;
		break;
	case DelayMix:          UserParams[DelayMix] = newValue;
		break;
	case DelayIsOn:		UserParams[DelayIsOn] = newValue;
		break;
	case FlangerMix:	UserParams[FlangerMix] = newValue;
		break;
	case FlangerFeedback: UserParams[FlangerFeedback] = newValue;
		break;
	case FlangerDelay:	UserParams[FlangerDelay] = newValue;
		flanger->setDepth(newValue);
		flanger->updateRange();
		break;
	case FlangerIsOn:	UserParams[FlangerIsOn] = newValue;
		break;
	case DistortionAmt:	UserParams[DistortionAmt] = newValue;
		break;
	case DistortionIsOn: UserParams[DistortionIsOn] = newValue;
		break;
	case ChorusIsOn: UserParams[ChorusIsOn] = newValue;
		break;
	case ChorusMix:	UserParams[ChorusMix] = newValue;
		break;
	case ChorusRate:UserParams[ChorusRate] = newValue;
		chorus->setLFOfrequency(newValue);
		break;
	case ReverbIsOn: UserParams[ReverbIsOn] = newValue;
		break;
	case ReverbMix: UserParams[ReverbMix] = newValue;
		reverb->setMix(newValue);
		break;
	case ReverbSize: UserParams[ReverbSize] = newValue;
		reverb->setSize(newValue);
		break;
	case ReverbWidth: UserParams[ReverbWidth] = newValue;
		reverb->setWidth(newValue);
		break;
	case GlobalGain:  UserParams[GlobalGain] = newValue;
		break;
	case GlobalPan:	UserParams[GlobalPan] = newValue;
		break;
	case LFOAmount: UserParams[LFOAmount] = newValue;
		break;
	case LFODestination:UserParams[LFODestination] = newValue;
		lfo->setDestination((int)newValue);
		break;
	case LFORate: UserParams[LFORate] = newValue;
		changeLFORate((int)newValue);
		break;
	}
	UIUpdateFlag = true;
}

const String AudeaAudioProcessor::getParameterName (int index)
{
	switch (index)
	{
	case MasterBypass:		return "Master Bypass";
	case OscVoices:			return "Oscillator Voices";
	case Osc1WaveForm:		return "Oscillator 1 Waveform";
	case Osc2WaveForm:		return "Oscillator 2 Waveform";
	case Osc2IsOn:			return "Oscillator 2 Bypass";
	case Osc2Tune:			return "Oscillator 2 Tune";
	case Osc1Amp:			return "Oscillator 1 Volume";
	case Osc2Amp:			return "Oscillator 2 Volume";
	case AmpEnvAttack:		return "Amplitude Envelope Attack";
	case AmpEnvDecay:		return "Amplitude Envelope Decay";
	case AmpEnvSustain:		return "Amplitude Envelope Sustain";
	case AmpEnvRelease:		return "Amplitude Envelope Release";
	case FilterType:		return "Filter Type";
	case FilterCutoff:		return "Filter Cutoff Frequency";
	case FilterRes:			return "Filter Resonance";
	case FilterEnvAmt:		return "Filter Envelope Amount";
	case FilterEnvAttack:	return "Filter Envelope Attack";
	case FilterEnvDecay:	return "Filter Envelope Decay";
	case FilterEnvSustain:	return "Filter Envelope Sustain";
	case FilterEnvRelease:	return "FIlter Envelope Release";
	case DelayFeedback:     return "Delay Feedback";
	case DelayMix:          return "Delay Mix";
	case DelayLenRight:     return "Delay Length Right";
	case DelayLenLeft:      return "Delay Length Left";
	case FlangerMix:		return "Flanger Mix";
	case FlangerFeedback:	return "Flanger FeedbacK";
	case FlangerDelay:		return "Flanger Delay";
	case FlangerIsOn:		return "Flanger Bypass";
	case ChorusIsOn:		return "Chorus Bypass";
	case ChorusMix:			return "Chorus Mix";
	case ChorusRate:		return "Chorus Rate";
	case DistortionIsOn:	return "Distortion Bypass";
	case DistortionAmt:		return "Distortion Amount";
	case ReverbIsOn:		return "Reverb Bypass";
	case ReverbMix:			return "Reverb Mix";
	case ReverbSize:		return "Reverb RoomSize";
	case ReverbWidth:		return "Reverb DecayTime";
	case GlobalGain:		return "Global Volume Amount";
	case GlobalPan:			return "Global Pan Amount";
	case LFOAmount:			return "LFO Amount";
	case LFODestination:	return "LFO Destination";
	case LFORate:			return "LFO Frequency Rate";

	default:				return String::empty;
	}
}

const String AudeaAudioProcessor::getParameterText (int index)
{
	if (index >= 0 && index < totalNumParam)
		return String(UserParams[index]);//return parameter value as string
	else return String::empty;//invalid index
}

const String AudeaAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String AudeaAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool AudeaAudioProcessor::isInputChannelStereoPair (int /*index*/) const
{
    return true;
}

bool AudeaAudioProcessor::isOutputChannelStereoPair (int /*index*/) const
{
    return true;
}

bool AudeaAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool AudeaAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool AudeaAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double AudeaAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int AudeaAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int AudeaAudioProcessor::getCurrentProgram()
{
    return 0;
}

void AudeaAudioProcessor::setCurrentProgram (int /*index*/)
{
}

const String AudeaAudioProcessor::getProgramName (int /*index*/)
{
    return String();
}

void AudeaAudioProcessor::changeProgramName (int /*index*/, const String& /*newName*/)
{
}

//==============================================================================
void AudeaAudioProcessor::prepareToPlay (double sampleRate, int /*samplesPerBlock*/)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
	synth.setCurrentPlaybackSampleRate(sampleRate);
	keyboardState.reset();
}

void AudeaAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
	keyboardState.reset();
}

void AudeaAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
	const int numSamples = buffer.getNumSamples();
	if (!isInited)
	{
		isInited = true;
		init();
	}


	//Now pass any incoming midi messages to our keyboard state object, and let it 
	//add messages to the buffer if the user is clicking on the on-screen keys
	keyboardState.processNextMidiBuffer(midiMessages, 0,numSamples, true);

	//and now get the synth to process these midi events and generate its output
	synth.renderNextBlock(buffer, midiMessages, 0, numSamples);

	float *left = buffer.getWritePointer(0);
	float *right = buffer.getWritePointer(1);
	float panAmt = 0.0f, gainAmt = 0.0f;

		for (long i = 0; i < numSamples; i++)
		{
			//Apply the Effects to the signal
			if (UserParams[DelayIsOn])
				delay->process(&left[i], &right[i]);
			if (UserParams[FlangerIsOn])
				flanger->process(&left[i], &right[i]);
			if (UserParams[DistortionIsOn])
				wvShaper->process(&left[i], &right[i]);
			if (UserParams[ChorusIsOn])
				chorus->process(&left[i], &right[i]);
			if (UserParams[ReverbIsOn])
				reverb->process(&left[i], &right[i]);

			//if (left[i] != 0)
				//int leBreakPoint = 0;
			//Apply Filter - Compute the coefficients for the Filter
			filter->computeVariables(filEnv);
			right[i] = filter->processFilterRight(right[i]);
			left[i] = filter->processFilterLeft(left[i]);

			//Apply Gain
			gainAmt = UserParams[GlobalGain] + lfo->getNextVolumeOffset();
			if (gainAmt > 1.5) gainAmt = 1.5;
			if (gainAmt < 0.0) gainAmt = 0.0;
			right[i] *= gainAmt;
			left[i] *= gainAmt;

			//Apply Pan
			panAmt = UserParams[GlobalPan] + lfo->getNextPanOffset();
			if (panAmt > 1) panAmt = 1;
			if (panAmt < 0) panAmt = 0;
			left[i] *= 1 - panAmt;
			right[i] *= panAmt;

			//Delete old Filter
			deleteFilter();

			//For Debugging check if value in buffer overflows
			if (right[i] >1 || right[i] < -1){
				right[i] /= right[i];
			}
			if (left[i] >1 || left[i] < -1){
				left[i] /= left[i];
			}
		}
		


	// In case we have more outputs than inputs, this code clears any output
	// channels that didn't contain input data, (because these aren't
	// guaranteed to be empty - they may contain garbage).
	for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
		buffer.clear(i, 0, buffer.getNumSamples());
	
	//No MidiMessages should pass the synthesiser only an audio signal
	midiMessages.clear();
}

//==============================================================================
bool AudeaAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* AudeaAudioProcessor::createEditor()
{
    return new AudeaAudioProcessorEditor (this);
}

//==============================================================================
void AudeaAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
	
	//Save UserParams/Data to file
	XmlElement root("Root");
	XmlElement *el;
	el = root.createNewChildElement("MasterBypass");
	el->addTextElement(String(UserParams[MasterBypass]));
	el = root.createNewChildElement("OscVoices");
	el->addTextElement(String(UserParams[OscVoices]));
	el = root.createNewChildElement("Osc1WaveForm");
	el->addTextElement(String(UserParams[Osc1WaveForm]));
	el = root.createNewChildElement("Osc2WaveForm");
	el->addTextElement(String(UserParams[Osc2WaveForm]));
	el = root.createNewChildElement("Osc2Tune");
	el->addTextElement(String(UserParams[Osc2Tune]));
	el = root.createNewChildElement("Osc2IsOn");
	el->addTextElement(String(UserParams[Osc2IsOn]));
	el = root.createNewChildElement("Osc1Amp");
	el->addTextElement(String(UserParams[Osc1Amp]));
	el = root.createNewChildElement("Osc2Amp");
	el->addTextElement(String(UserParams[Osc2Amp]));
	el = root.createNewChildElement("AmpEnvAttack");
	el->addTextElement(String(UserParams[AmpEnvAttack]));
	el = root.createNewChildElement("AmpEnvDecay");
	el->addTextElement(String(UserParams[AmpEnvDecay]));
	el = root.createNewChildElement("AmpEnvSustain");
	el->addTextElement(String(UserParams[AmpEnvSustain]));
	el = root.createNewChildElement("AmpEnvRelease");
	el->addTextElement(String(UserParams[AmpEnvRelease]));
	el = root.createNewChildElement("FilterType");
	el->addTextElement(String(UserParams[FilterType]));
	el = root.createNewChildElement("FilterCutoff");
	el->addTextElement(String(UserParams[FilterCutoff]));
	el = root.createNewChildElement("FilterRes");
	el->addTextElement(String(UserParams[FilterRes]));
	el = root.createNewChildElement("FilterEnvAmt");
	el->addTextElement(String(UserParams[FilterEnvAmt]));
	el = root.createNewChildElement("FilterEnvAttack");
	el->addTextElement(String(UserParams[FilterEnvAttack]));
	el = root.createNewChildElement("FilterEnvDecay");
	el->addTextElement(String(UserParams[FilterEnvDecay]));
	el = root.createNewChildElement("FilterEnvSustain");
	el->addTextElement(String(UserParams[FilterEnvSustain]));
	el = root.createNewChildElement("FilterEnvRelease");
	el->addTextElement(String(UserParams[FilterEnvRelease]));
	el = root.createNewChildElement("DelayMix");
	el->addTextElement(String(UserParams[DelayMix]));
	el = root.createNewChildElement("DelayFeedback");
	el->addTextElement(String(UserParams[DelayFeedback]));
	el = root.createNewChildElement("DelayLenRight");
	el->addTextElement(String(UserParams[DelayLenRight]));
	el = root.createNewChildElement("DelayLenLeft");
	el->addTextElement(String(UserParams[DelayLenLeft]));
	el = root.createNewChildElement("DelayIsOn");
	el->addTextElement(String(UserParams[DelayIsOn]));
	el = root.createNewChildElement("FlangerMix");
	el->addTextElement(String(UserParams[FlangerMix]));
	el = root.createNewChildElement("FlangerFeedback");
	el->addTextElement(String(UserParams[FlangerFeedback]));
	el = root.createNewChildElement("FlangerDelay");
	el->addTextElement(String(UserParams[FlangerDelay]));
	el = root.createNewChildElement("FlangerIsOn");
	el->addTextElement(String(UserParams[FlangerIsOn]));
	el = root.createNewChildElement("ChorusRate");
	el->addTextElement(String(UserParams[ChorusRate]));
	el = root.createNewChildElement("ChorusMix");
	el->addTextElement(String(UserParams[ChorusMix]));
	el = root.createNewChildElement("ChorusIsOn");
	el->addTextElement(String(UserParams[ChorusIsOn]));
	el = root.createNewChildElement("DistortionIsOn");
	el->addTextElement(String(UserParams[DistortionIsOn]));
	el = root.createNewChildElement("DistortionAmt");
	el->addTextElement(String(UserParams[DistortionAmt]));
	el = root.createNewChildElement("ReverbIsOn");
	el->addTextElement(String(UserParams[ReverbIsOn]));
	el = root.createNewChildElement("ReverbMix");
	el->addTextElement(String(UserParams[ReverbMix]));
	el = root.createNewChildElement("ReverbSize");
	el->addTextElement(String(UserParams[ReverbSize]));
	el = root.createNewChildElement("ReverbWidth");
	el->addTextElement(String(UserParams[ReverbWidth]));
	el = root.createNewChildElement("GlobalGain");
	el->addTextElement(String(UserParams[GlobalGain]));
	el = root.createNewChildElement("GlobalPan");
	el->addTextElement(String(UserParams[GlobalPan]));
	el = root.createNewChildElement("LFOAmount");
	el->addTextElement(String(UserParams[LFOAmount]));
	el = root.createNewChildElement("LFODestination");
	el->addTextElement(String(UserParams[LFODestination]));
	el = root.createNewChildElement("LFORate");
	el->addTextElement(String(UserParams[LFORate]));
	copyXmlToBinary(root, destData);
}

void AudeaAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
	//Load UserParams/Data from file
	XmlElement* pRoot = getXmlFromBinary(data, sizeInBytes);
	if (pRoot != NULL)
	{
		forEachXmlChildElement((*pRoot), pChild)
		{
			if (pChild->hasTagName("MasterBypass")){
				String text = pChild->getAllSubText();
				setParameter(MasterBypass, text.getFloatValue());
			}
			else if (pChild->hasTagName("OscVoices")){
				String text = pChild->getAllSubText();
				setParameter(OscVoices, text.getFloatValue());
			}
			else if (pChild->hasTagName("Osc1WaveForm")){
				String text = pChild->getAllSubText();
				setParameter(Osc1WaveForm, text.getFloatValue());
			}
			else if (pChild->hasTagName("Osc2WaveForm")){
				String text = pChild->getAllSubText();
				setParameter(Osc2WaveForm, text.getFloatValue());
			}
			else if (pChild->hasTagName("Osc2Tune")){
				String text = pChild->getAllSubText();
				setParameter(Osc2Tune, text.getFloatValue());
			}
			else if (pChild->hasTagName("Osc2IsOn")){
				String text = pChild->getAllSubText();
				setParameter(Osc2IsOn, text.getFloatValue());
			}
			else if (pChild->hasTagName("Osc1Amp")){
				String text = pChild->getAllSubText();
				setParameter(Osc1Amp, text.getFloatValue());
			}
			else if (pChild->hasTagName("Osc2Amp")){
				String text = pChild->getAllSubText();
				setParameter(Osc2Amp, text.getFloatValue());
			}
			else if (pChild->hasTagName("AmpEnvAttack")){
				String text = pChild->getAllSubText();
				setParameter(AmpEnvAttack, text.getFloatValue());
			}
			else if (pChild->hasTagName("AmpEnvDecay")){
				String text = pChild->getAllSubText();
				setParameter(AmpEnvDecay, text.getFloatValue());
			}
			else if (pChild->hasTagName("AmpEnvSustain")){
				String text = pChild->getAllSubText();
				setParameter(AmpEnvSustain, text.getFloatValue());
			}
			else if (pChild->hasTagName("AmpEnvRelease")){
				String text = pChild->getAllSubText();
				setParameter(AmpEnvRelease, text.getFloatValue());
			}
			else if (pChild->hasTagName("FilterType")){
				String text = pChild->getAllSubText();
				setParameter(FilterType, text.getFloatValue());
			}
			else if (pChild->hasTagName("FilterCutoff")){
				String text = pChild->getAllSubText();
				setParameter(FilterCutoff, text.getFloatValue());
			}
			else if (pChild->hasTagName("FilterRes")){
				String text = pChild->getAllSubText();
				setParameter(FilterRes, text.getFloatValue());
			}
			else if (pChild->hasTagName("FilterEnvAmt")){
				String text = pChild->getAllSubText();
				setParameter(FilterEnvAmt, text.getFloatValue());
			}
			else if (pChild->hasTagName("FilterEnvAttack")){
				String text = pChild->getAllSubText();
				setParameter(FilterEnvAttack, text.getFloatValue());
			}
			else if (pChild->hasTagName("FilterEnvDecay")){
				String text = pChild->getAllSubText();
				setParameter(FilterEnvDecay, text.getFloatValue());
			}
			else if (pChild->hasTagName("FilterEnvSustain")){
				String text = pChild->getAllSubText();
				setParameter(FilterEnvSustain, text.getFloatValue());
			}
			else if (pChild->hasTagName("FilterEnvRelease")){
				String text = pChild->getAllSubText();
				setParameter(FilterEnvRelease, text.getFloatValue());
			}
			else if (pChild->hasTagName("DelayMix")){
				String text = pChild->getAllSubText();
				setParameter(DelayMix, text.getFloatValue());
			}
			else if (pChild->hasTagName("DelayFeedback")){
				String text = pChild->getAllSubText();
				setParameter(DelayFeedback, text.getFloatValue());
			}
			else if (pChild->hasTagName("DelayLenRight")){
				String text = pChild->getAllSubText();
				setParameter(DelayLenRight, text.getFloatValue());
			}
			else if (pChild->hasTagName("DelayLenLeft")){
				String text = pChild->getAllSubText();
				setParameter(DelayLenLeft, text.getFloatValue());
			}
			else if (pChild->hasTagName("DelayIsOn")){
				String text = pChild->getAllSubText();
				setParameter(DelayIsOn, text.getFloatValue());
			}
			else if (pChild->hasTagName("FlangerMix")){
				String text = pChild->getAllSubText();
				setParameter(FlangerMix, text.getFloatValue());
			}
			else if (pChild->hasTagName("FlangerFeedback")){
				String text = pChild->getAllSubText();
				setParameter(FlangerFeedback, text.getFloatValue());
			}
			else if (pChild->hasTagName("FlangerDelay")){
				String text = pChild->getAllSubText();
				setParameter(FlangerDelay, text.getFloatValue());
			}
			else if (pChild->hasTagName("FlangerIsOn")){
				String text = pChild->getAllSubText();
				setParameter(FlangerIsOn, text.getFloatValue());
			}
			else if (pChild->hasTagName("ChorusRate")){
				String text = pChild->getAllSubText();
				setParameter(ChorusRate, text.getFloatValue());
			}
			else if (pChild->hasTagName("ChorusMix")){
				String text = pChild->getAllSubText();
				setParameter(ChorusMix, text.getFloatValue());
			}
			else if (pChild->hasTagName("ChorusIsOn")){
				String text = pChild->getAllSubText();
				setParameter(ChorusIsOn, text.getFloatValue());
			}
			else if (pChild->hasTagName("DistortionIsOn")){
				String text = pChild->getAllSubText();
				setParameter(DistortionIsOn, text.getFloatValue());
			}
			else if (pChild->hasTagName("DistortionAmt")){
				String text = pChild->getAllSubText();
				setParameter(DistortionAmt, text.getFloatValue());
			}
			else if (pChild->hasTagName("ReverbIsOn")){
				String text = pChild->getAllSubText();
				setParameter(ReverbIsOn, text.getFloatValue());
			}
			else if (pChild->hasTagName("ReverbMix")){
				String text = pChild->getAllSubText();
				setParameter(ReverbMix, text.getFloatValue());
			}
			else if (pChild->hasTagName("ReverbSize")){
				String text = pChild->getAllSubText();
				setParameter(ReverbSize, text.getFloatValue());
			}
			else if (pChild->hasTagName("ReverbWidth")){
				String text = pChild->getAllSubText();
				setParameter(ReverbWidth, text.getFloatValue());
			}
			else if (pChild->hasTagName("GlobalGain")){
				String text = pChild->getAllSubText();
				setParameter(GlobalGain, text.getFloatValue());
			}
			else if (pChild->hasTagName("GlobalPan")){
				String text = pChild->getAllSubText();
				setParameter(GlobalPan, text.getFloatValue());
			}
			else if (pChild->hasTagName("LFOAmount")){
				String text = pChild->getAllSubText();
				setParameter(LFOAmount, text.getFloatValue());
			}
			else if (pChild->hasTagName("LFODestination")){
				String text = pChild->getAllSubText();
				setParameter(LFODestination, text.getFloatValue());
			}
			else if (pChild->hasTagName("LFORate")){
				String text = pChild->getAllSubText();
				setParameter(LFORate, text.getFloatValue());
			}
		}
		delete pRoot;
		UIUpdateFlag = true;//Request UI update
	}
}

//=====================HELPER METHODS===========================================
void AudeaAudioProcessor::changeOscillatorWaveForm(int oscID, int wvForm)
{
	int numVoices = synth.getNumVoices();
switch (oscID){
case 1:
	switch (wvForm){
	case Sine:		for (int i = numVoices; --i >= 0;)
						static_cast<AudeaVoice*>(synth.getVoice(i))->setOsc1WvForm(AudeaVoice::Sine);
					break;
	case Triangle:  for (int i = numVoices; --i >= 0;)
						static_cast<AudeaVoice*>(synth.getVoice(i))->setOsc1WvForm(AudeaVoice::Triangle);
					break;
	case Square:	for (int i = numVoices; --i >= 0;)
						static_cast<AudeaVoice*>(synth.getVoice(i))->setOsc1WvForm(AudeaVoice::Square);
					break;
	case Saw:		for (int i = numVoices; --i >= 0;)
						static_cast<AudeaVoice*>(synth.getVoice(i))->setOsc1WvForm(AudeaVoice::Saw);
					break;
	case Noise:		for (int i = numVoices; --i >= 0;)
						static_cast<AudeaVoice*>(synth.getVoice(i))->setOsc1WvForm(AudeaVoice::Noise);
					break;
	}
	break;

case 2:
	switch (wvForm){
	case Sine:		for (int i = numVoices; --i >= 0;)
		static_cast<AudeaVoice*>(synth.getVoice(i))->setOsc2WvForm(AudeaVoice::Sine);
		break;
	case Triangle:  for (int i = numVoices; --i >= 0;)
		static_cast<AudeaVoice*>(synth.getVoice(i))->setOsc2WvForm(AudeaVoice::Triangle);
		break;
	case Square:	for (int i = numVoices; --i >= 0;)
		static_cast<AudeaVoice*>(synth.getVoice(i))->setOsc2WvForm(AudeaVoice::Square);
		break;
	case Saw:		for (int i = numVoices; --i >= 0;)
		static_cast<AudeaVoice*>(synth.getVoice(i))->setOsc2WvForm(AudeaVoice::Saw);
		break;
	case Noise:		for (int i = numVoices; --i >= 0;)
		static_cast<AudeaVoice*>(synth.getVoice(i))->setOsc2WvForm(AudeaVoice::Noise);
		break;
	}
	break;
	}

}

void AudeaAudioProcessor::updateOscillatorVoices()
{	
	int currNumVoices = synth.getNumVoices();
	
	//less voices then before -> just delete
	if (UserParams[OscVoices] < currNumVoices)
	{
		int diff = currNumVoices - (int)UserParams[OscVoices];
		for (int i = 1; i <= diff; ++i)
			synth.removeVoice(currNumVoices - i);
	}
	//voices didn't change, shouldnt happen
	else if ((int)UserParams[OscVoices] == currNumVoices)
		return;
	//more voices then before, add voices and set the appropriate waveforms
	else if (currNumVoices < (int)UserParams[OscVoices])
	{
		int diff = (int)UserParams[OscVoices] - currNumVoices;
		for (int i = 0; i < diff; ++i)
		{
			Envelope *env = new Envelope(&UserParams[AmpEnvAttack], &UserParams[AmpEnvDecay], &UserParams[AmpEnvSustain], &UserParams[AmpEnvRelease]);
			AudeaVoice *voice = new AudeaVoice(
									&UserParams[Osc1Amp],
									&UserParams[Osc2Amp],
									&UserParams[Osc2Tune],
									env, filter, filEnv,&currentNotePlaying
								);
			
			switch ((int)UserParams[Osc1WaveForm]){
			case Sine:		voice->setOsc1WvForm(AudeaVoice::Sine);
							break;
			case Triangle:	voice->setOsc1WvForm(AudeaVoice::Triangle);
							break;
			case Square:	voice->setOsc1WvForm(AudeaVoice::Square);
							break;
			case Saw:		voice->setOsc1WvForm(AudeaVoice::Saw);
							break;
			case Noise:		voice->setOsc1WvForm(AudeaVoice::Noise);
							break;
			}
			switch ((int)UserParams[Osc2WaveForm]){
			case Sine:		voice->setOsc2WvForm(AudeaVoice::Sine);
							break;
			case Triangle:	voice->setOsc2WvForm(AudeaVoice::Triangle);
							break;
			case Square:	voice->setOsc2WvForm(AudeaVoice::Square);
							break;
			case Saw:		voice->setOsc2WvForm(AudeaVoice::Saw);
							break;
			case Noise:		voice->setOsc2WvForm(AudeaVoice::Noise);
							break;
			}
			synth.addVoice(voice);
		}
	}
	
}

void AudeaAudioProcessor::changeFilterType(int filterId)
{
	switch (filterId)
	{
	case BandPass:oldFilter = filter;
		filter = new BandPassFilter(&UserParams[FilterRes],getSampleRate());
		break;
	case LowPass:oldFilter = filter;
		filter = new LowPassFilter(&UserParams[FilterRes], getSampleRate());
		break;
	case HighPass:oldFilter = filter;
		filter = new HighPassFilter(&UserParams[FilterRes], getSampleRate());
		break;
	case BandReject:oldFilter = filter;
		filter = new BandRejectFilter(&UserParams[FilterRes], getSampleRate());
		break;
	case Allpass:oldFilter = filter;
		filter = new AllPassFilter(&UserParams[FilterRes], getSampleRate());
		break;
	}
	int numVoices = synth.getNumVoices();
	for (int i = numVoices; --i >= 0;)
		static_cast<AudeaVoice*>(synth.getVoice(i))->setFilter(filter);
}

void AudeaAudioProcessor::changeLFORate(int rate)
{
	setBpm();
	float mpm =(float) bpm / 4;                                    //measures per minute
	float secondsPerMeasure = 60 / mpm;

	switch (rate){
	case oneLfo:
			lfo->setFrequency(1 / secondsPerMeasure);
		break;
	case halfLfo:
			lfo->setFrequency(1 / (secondsPerMeasure / 2));
		break;
	case thirdLfo:
		lfo->setFrequency(1 / (secondsPerMeasure / 3));
		break;
	case quarterLfo:
			lfo->setFrequency(1 / (secondsPerMeasure / 4));
		break;
	case sixthLfo:
		lfo->setFrequency(1 / (secondsPerMeasure / 6));
		break;
	case eightsLfo:
			lfo->setFrequency(1 / (secondsPerMeasure / 8));
		break;
	case twelthLfo:
		lfo->setFrequency(1 / (secondsPerMeasure / 12));
		break;
	case sixteenthLfo:
			lfo->setFrequency(1 / (secondsPerMeasure / 16));
		break;
	case twentyforthLfo:
		lfo->setFrequency(1 / (secondsPerMeasure / 24));
		break;
	case demisemiquaverLfo:
			lfo->setFrequency(1 / (secondsPerMeasure / 32));
		break;
	}

}

void AudeaAudioProcessor::changeDelayLength(int DelayLen, bool left){
	setBpm();
	float mpm = (float) bpm / 4;                                    //measures per minute
	float secondsPerMeasure = 60 / mpm;
	float samples =(float) getSampleRate();

	switch (DelayLen){
	case one:
		if (left)
			delay->setDelayBufferLengthLeft((int)(secondsPerMeasure * samples));
		else
			delay->setDelayBufferLengthRight((int)(secondsPerMeasure * samples));
		break;
	case half:
		if (left)
			delay->setDelayBufferLengthLeft((int)((secondsPerMeasure / 2) * samples));
		else
			delay->setDelayBufferLengthRight((int)((secondsPerMeasure / 2) * samples));
		break;
	case quarter:
		if (left)
			delay->setDelayBufferLengthLeft((int)((secondsPerMeasure / 4) * samples));
		else
			delay->setDelayBufferLengthRight((int)((secondsPerMeasure / 4) * samples));
		break;
	case eights:
		if (left)
			delay->setDelayBufferLengthLeft((int)((secondsPerMeasure / 8) * samples));
		else
			delay->setDelayBufferLengthRight((int)((secondsPerMeasure / 8) * samples));
		break;
	case sixteenth:
		if (left)
			delay->setDelayBufferLengthLeft((int)((secondsPerMeasure / 16) * samples));
		else
			delay->setDelayBufferLengthRight((int)((secondsPerMeasure / 16) * samples));
		break;
	case demisemiquaver:
		if (left)
			delay->setDelayBufferLengthLeft((int)((secondsPerMeasure / 32) * samples));
		else
			delay->setDelayBufferLengthRight((int)((secondsPerMeasure / 32) * samples));
		break;
	}
}

void AudeaAudioProcessor::init()
{
	setBpm();
	float mpm = (float) bpm / 4;                                    //measures per minute
	float secondsPerMeasure = 60 / mpm;
	float samples = (float)getSampleRate();

	filter = new LowPassFilter(&UserParams[FilterRes],samples);
	lfo = new LFO(1 / secondsPerMeasure,(int) samples, &UserParams[LFOAmount]);
	filEnv = new FilterEnvelope(&UserParams[FilterEnvAttack], &UserParams[FilterEnvDecay], &UserParams[FilterEnvSustain], &UserParams[FilterEnvRelease], &UserParams[FilterCutoff], &UserParams[FilterEnvAmt], lfo);
	//Initialise the synthesisers
	for (int i = (int)UserParams[OscVoices]; --i >= 0;)
	{
		Envelope *env = new Envelope(&UserParams[AmpEnvAttack], &UserParams[AmpEnvDecay], &UserParams[AmpEnvSustain], &UserParams[AmpEnvRelease]);
		synth.addVoice(
			new AudeaVoice(
			&UserParams[Osc1Amp],
			&UserParams[Osc2Amp],
			&UserParams[Osc2Tune],
			env, filter, filEnv,&currentNotePlaying)
			);
	}
	synth.addSound(new AudeaSound());
	
	//Initialise the effects
	delay = new Delay((int)(secondsPerMeasure* samples), (int)(secondsPerMeasure* samples),&UserParams[DelayMix],&UserParams[DelayFeedback]);
	flanger = new Flanger(samples,&UserParams[FlangerMix],&UserParams[FlangerFeedback]);
	chorus = new Chorus(samples, &UserParams[ChorusMix]);
	reverb = new AudeaReverb(samples, UserParams[ReverbMix], UserParams[ReverbWidth], UserParams[ReverbSize]);
	

}

void AudeaAudioProcessor::setBpm()
{
	playHead = getPlayHead();

	if (playHead == nullptr){
		bpm = 140;
	}
	else{
		playHead->getCurrentPosition(currentPositionInfo);
		bpm = currentPositionInfo.bpm;
		if (bpm == 0)
			bpm = 140;
	}
}

void AudeaAudioProcessor::deleteFilter()
{
	if (oldFilter != nullptr)
	{
		delete oldFilter;
		oldFilter = nullptr;
	}
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new AudeaAudioProcessor();
}

