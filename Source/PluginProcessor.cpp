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
	UserParams[Osc1WaveForm] = 1.0f;
	UserParams[Osc1WaveForm] = 1.0f;
	UserParams[Osc2IsOn] = 0.0f; //default off
	UserParams[Osc3IsOn] = 0.0f; //default off
	UserParams[Osc2Tune] = 0.0f;
	UserParams[Osc3Tune] = 0.0f;
	UserParams[Osc1Amp] = 1.0f;
	UserParams[Osc2Amp] = 0.0f;
	UserParams[Osc3Amp] = 0.0f;
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
	UserParams[FlangerMix] = 0.0f;
	UserParams[FlangerFeedback] = 0.0f;
	UserParams[FlangerDelay] = 10.0f;
	UserParams[FlangerIsOn] = 0.0f;


	UIUpdateFlag = true; //Request UI update

	//Initialise the synthesisers
	for (int i = (int)UserParams[OscVoices]; --i >= 0;)
	{
		Envelope *env = new Envelope(&UserParams[AmpEnvAttack], &UserParams[AmpEnvDecay], &UserParams[AmpEnvSustain], &UserParams[AmpEnvRelease]);
		FilterEnvelope *filEnv = new FilterEnvelope(&UserParams[FilterEnvAttack], &UserParams[FilterEnvDecay], &UserParams[FilterEnvSustain], &UserParams[FilterEnvRelease], &UserParams[FilterCutoff], &UserParams[FilterEnvAmt]);
		synth.addVoice(
			new AudeaVoice(
				&UserParams[Osc1Amp],
				&UserParams[Osc2Amp],
				&UserParams[Osc3Amp],
				&UserParams[Osc2Tune],
				&UserParams[Osc3Tune],
				env, filter, filEnv)
		);
	}
	synth.addSound(new AudeaSound());
}

AudeaAudioProcessor::~AudeaAudioProcessor()
{
	delete filter;
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
	case Osc3WaveForm:	UserParams[Osc3WaveForm] = newValue;
						changeOscillatorWaveForm(3, (int)newValue);
		break;
	case Osc2IsOn:		UserParams[Osc2IsOn] = newValue;
		for (int i = synth.getNumVoices(); --i >= 0;)
			static_cast<AudeaVoice*>(synth.getVoice(i))->setOsc2IsOn(newValue == 1.0f);
		break;
	case Osc3IsOn:		UserParams[Osc3IsOn] = newValue;
		for (int i = synth.getNumVoices(); --i >= 0;)
			static_cast<AudeaVoice*>(synth.getVoice(i))->setOsc3IsOn(newValue == 1.0f);
		break;
	case Osc2Tune:		UserParams[Osc2Tune] = newValue;
		for (int i = synth.getNumVoices(); --i >= 0;)
			static_cast<AudeaVoice*>(synth.getVoice(i))->setOsc2Tune(&UserParams[Osc2Tune]);
		break;
	case Osc3Tune:		UserParams[Osc3Tune] = newValue;
		for (int i = synth.getNumVoices(); --i >= 0;)
			static_cast<AudeaVoice*>(synth.getVoice(i))->setOsc3Tune(&UserParams[Osc3Tune]);
		break;
	case Osc1Amp:		UserParams[Osc1Amp] = newValue;
		for (int i = synth.getNumVoices(); --i >= 0;)
			static_cast<AudeaVoice*>(synth.getVoice(i))->setOsc1Amp(&UserParams[Osc1Amp]);
		break;
	case Osc2Amp:		UserParams[Osc2Amp] = newValue;
		for (int i = synth.getNumVoices(); --i >= 0;)
			static_cast<AudeaVoice*>(synth.getVoice(i))->setOsc2Amp(&UserParams[Osc2Amp]);
		break;
	case Osc3Amp:		UserParams[Osc3Amp] = newValue;
		for (int i = synth.getNumVoices(); --i >= 0;)
			static_cast<AudeaVoice*>(synth.getVoice(i))->setOsc3Amp(&UserParams[Osc3Amp]);
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
		changeFilterType(newValue);
		break;
	case FilterCutoff:	UserParams[FilterCutoff] = newValue;
		break;
	case FilterRes:		UserParams[FilterRes] = newValue;
		break;
	case FilterEnvAmt:	UserParams[FilterEnvAmt] = newValue;
		break;
	case FilterEnvAttack:	UserParams[FilterEnvAmt] = newValue;
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
		delay->setFeedback(newValue);
		break;
	case DelayMix:          UserParams[DelayMix] = newValue;
		delay->setMix(newValue);
		break;
	case DelayIsOn:		UserParams[DelayIsOn] = newValue;
		break;
	case FlangerMix:	UserParams[FlangerMix] = newValue;
		flanger->setMix(newValue);
		break;
	case FlangerFeedback: UserParams[FlangerFeedback] = newValue;
		flanger->setFeedback(newValue);
		break;
	case FlangerDelay:	UserParams[FlangerDelay] = newValue;
		flanger->setDepth(newValue);
		flanger->updateRange();
		break;
	case FlangerIsOn:	UserParams[FlangerIsOn] = newValue;
		break;
	}
	UIUpdateFlag = true;
}

const String AudeaAudioProcessor::getParameterName (int index)
{
	switch (index)
	{
	case MasterBypass:	return "Master Bypass";
	case OscVoices:		return "Oscillator Voices";
	case Osc1WaveForm:	return "Oscillator 1 Waveform";
	case Osc2WaveForm:	return "Oscillator 2 Waveform";
	case Osc3WaveForm:	return "Oscillator 3 Waveform";
	case Osc2IsOn:		return "Oscillator 2 Bypass";
	case Osc3IsOn:		return "Oscillator 3 Bypass";
	case Osc2Tune:		return "Oscillator 2 Tune";
	case Osc3Tune:		return "Oscillator 3 Tune";
	case Osc1Amp:		return "Oscillator 1 Volume";
	case Osc2Amp:		return "Oscillator 2 Volume";
	case Osc3Amp:		return "Oscillator 3 Volume";
	case AmpEnvAttack:	return "Amplitude Envelope Attack";
	case AmpEnvDecay:	return "Amplitude Envelope Decay";
	case AmpEnvSustain:	return "Amplitude Envelope Sustain";
	case AmpEnvRelease:	return "Amplitude Envelope Release";
	case FilterType:	return "Filter Type";
	case FilterCutoff:	return "Filter Cutoff Frequency";
	case FilterRes:		return "Filter Resonance";
	case FilterEnvAmt:	return "Filter Envelope Amount";
	case FilterEnvAttack:	return "Filter Envelope Attack";
	case FilterEnvDecay:	return "Filter Envelope Decay";
	case FilterEnvSustain:	return "Filter Envelope Sustain";
	case FilterEnvRelease:	return "FIlter Envelope Release";
	case DelayFeedback:     return "Delay Feedback";
	case DelayMix:          return "Delay Mix";
	case DelayLenRight:     return "Delay Length Right";
	case DelayLenLeft:      return "Delay Length Left";
	case FlangerMix:	return "Flanger Mix";
	case FlangerFeedback: return "Flanger FeedbacK";
	case FlangerDelay:	return "Flanger Delay";
	//OtherParams...
	default:return String::empty;
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
	
	for (long i = 0; i < numSamples; i++)
	{
		if (UserParams[DelayIsOn])
			delay->process(&left[i], &right[i]);
		if (UserParams[FlangerIsOn])
			flanger->process(&left[i], &right[i]);
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
void AudeaAudioProcessor::getStateInformation (MemoryBlock& /*destData*/)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void AudeaAudioProcessor::setStateInformation (const void* /*data*/, int /*sizeInBytes*/)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
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
case 3:
	switch (wvForm){
	case Sine:		for (int i = numVoices; --i >= 0;)
		static_cast<AudeaVoice*>(synth.getVoice(i))->setOsc3WvForm(AudeaVoice::Sine);
		break;
	case Triangle:  for (int i = numVoices; --i >= 0;)
		static_cast<AudeaVoice*>(synth.getVoice(i))->setOsc3WvForm(AudeaVoice::Triangle);
		break;
	case Square:	for (int i = numVoices; --i >= 0;)
		static_cast<AudeaVoice*>(synth.getVoice(i))->setOsc3WvForm(AudeaVoice::Square);
		break;
	case Saw:		for (int i = numVoices; --i >= 0;)
		static_cast<AudeaVoice*>(synth.getVoice(i))->setOsc3WvForm(AudeaVoice::Saw);
		break;
	case Noise:		for (int i = numVoices; --i >= 0;)
		static_cast<AudeaVoice*>(synth.getVoice(i))->setOsc3WvForm(AudeaVoice::Noise);
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
		for (int i = 0; i < diff; ++i)
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
			FilterEnvelope *flEnv = new FilterEnvelope(&UserParams[FilterEnvAttack], &UserParams[FilterEnvDecay], &UserParams[FilterEnvSustain], &UserParams[FilterEnvRelease], &UserParams[FilterCutoff], &UserParams[FilterEnvAmt]);
			AudeaVoice *voice = new AudeaVoice(
									&UserParams[Osc1Amp],
									&UserParams[Osc2Amp],
									&UserParams[Osc3Amp],
									&UserParams[Osc2Tune],
									&UserParams[Osc3Tune],
									env, filter, flEnv
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
			switch ((int)UserParams[Osc3WaveForm]){
			case Sine:		voice->setOsc3WvForm(AudeaVoice::Sine);
							break;
			case Triangle:	voice->setOsc3WvForm(AudeaVoice::Triangle);
							break;
			case Square:	voice->setOsc3WvForm(AudeaVoice::Square);
							break;
			case Saw:		voice->setOsc3WvForm(AudeaVoice::Saw);
							break;
			case Noise:		voice->setOsc3WvForm(AudeaVoice::Noise);
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
	case BandPass:delete[] filter;
		filter = new BandPassFilter(&UserParams[FilterRes]);
		break;
	case LowPass:delete[] filter;
		filter = new LowPassFilter(&UserParams[FilterRes]);
		break;
	case HighPass:delete[] filter;
		filter = new HighPassFilter(&UserParams[FilterRes]);
		break;
	case BandReject:delete[] filter;
		filter = new BandRejectFilter(&UserParams[FilterRes]);
		break;
	case Allpass:delete[] filter;
		filter = new AllPassFilter(&UserParams[FilterRes]);
		break;
	}
}

void AudeaAudioProcessor::changeDelayLength(int DelayLenRight, bool left){

	float bpm;
	playHead = getPlayHead();

	if (playHead == nullptr){
		bpm = 140.0f;
	}
	else{
		playHead->getCurrentPosition(currentPositionInfo);
		bpm = currentPositionInfo.bpm;
		if (bpm == 0)
			bpm = 140.f;
	}

	float mpm = bpm / 4;                                    //measures per minute
	float secondsPerMeasure = 60 / mpm;
	float samples = getSampleRate();

	switch (DelayLenRight){
	case one:
		if (left)
			delay->setDelayBufferLengthLeft(secondsPerMeasure * samples);
		else
			delay->setDelayBufferLengthRight(secondsPerMeasure * samples);
		break;
	case half:
		if (left)
			delay->setDelayBufferLengthLeft((secondsPerMeasure / 2) * samples);
		else
			delay->setDelayBufferLengthRight((secondsPerMeasure / 2) * samples);
		break;
	case quarter:
		if (left)
			delay->setDelayBufferLengthLeft((secondsPerMeasure / 4) * samples);
		else
			delay->setDelayBufferLengthRight((secondsPerMeasure / 4) * samples);
		break;
	case eights:
		if (left)
			delay->setDelayBufferLengthLeft((secondsPerMeasure / 8) * samples);
		else
			delay->setDelayBufferLengthRight((secondsPerMeasure / 8) * samples);
		break;
	case sixteenth:
		if (left)
			delay->setDelayBufferLengthLeft((secondsPerMeasure / 16) * samples);
		else
			delay->setDelayBufferLengthRight((secondsPerMeasure / 16) * samples);
		break;
	case demisemiquaver:
		if (left)
			delay->setDelayBufferLengthLeft((secondsPerMeasure / 32) * samples);
		else
			delay->setDelayBufferLengthRight((secondsPerMeasure / 32) * samples);
		break;
	}
}

void AudeaAudioProcessor::init()
{
	float bpm;
	playHead = getPlayHead();

	if (playHead == nullptr){
		bpm = 140.0f;
	}
	else{
		playHead->getCurrentPosition(currentPositionInfo);
		bpm = currentPositionInfo.bpm;
		if (bpm == 0)
			bpm = 140.f;
	}

	float mpm = bpm / 4;                                    //measures per minute
	float secondsPerMeasure = 60 / mpm;
	float samples = getSampleRate();

	delay = new Delay((secondsPerMeasure)* samples, (secondsPerMeasure)* samples);
	flanger = new Flanger(samples);

}


//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new AudeaAudioProcessor();
}

