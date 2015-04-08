/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_3B3995C2FEAC160B__
#define __JUCE_HEADER_3B3995C2FEAC160B__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "AudeaLookAndFeel1.h"
#include "AudeaLookAndFeel2.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class AudeaAudioProcessorEditor  : public AudioProcessorEditor,
                                   public Timer,
                                   public ButtonListener,
                                   public SliderListener,
                                   public ComboBoxListener
{
public:
    //==============================================================================
    AudeaAudioProcessorEditor (AudeaAudioProcessor* ownerFilter);
    ~AudeaAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void timerCallback();
	AudeaAudioProcessor* getProcessor() const
	{
		return static_cast<AudeaAudioProcessor*>(getAudioProcessor());
	}
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	MidiKeyboardComponent midiKeyboard;

	AudeaLookAndFeel1* lookAndFeel1;
	AudeaLookAndFeel2* lookAndFeel2;
	TooltipWindow tooltipWindow;
	//Location of the DLL
	File pluginLocation = File::getSpecialLocation(File::SpecialLocationType::currentApplicationFile);
	File resourceDirectory = pluginLocation.getParentDirectory().getParentDirectory().getParentDirectory().getParentDirectory();
	//Constants
	File backGroundImgFile;
	String backGroundImgPath ="Resources/BackgroundPure2.0.jpg";


	enum EffectState{
		Flanger,
		Distortion,
		Chorus,
		Reverb
	};

	int effectState = 0;
	void changeFlangerUIState(bool);
	void changeDistortionUIState(bool);
	void changeChorusUIState(bool);
	void changeReverbUIState(bool);
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<ToggleButton> ReverbIsOn;
    ScopedPointer<Label> FlangerMixLabel;
    ScopedPointer<Label> FlangerDelayLabel;
    ScopedPointer<Label> ChorusMixLabel;
    ScopedPointer<Label> ReverbWidthLabel;
    ScopedPointer<Label> FlangerFeedbackLabel;
    ScopedPointer<Label> ChorusRateLabel;
    ScopedPointer<Label> DistortionLabel;
    ScopedPointer<Label> FlangerLabel;
    ScopedPointer<Label> ChorusLabel;
    ScopedPointer<Slider> FlangerFeedbackSlider;
    ScopedPointer<Slider> FlangerDelaySlider;
    ScopedPointer<Slider> FlangerMixSlider;
    ScopedPointer<Slider> ReverbMixSlider;
    ScopedPointer<Slider> DistortionAmountSlider;
    ScopedPointer<Slider> ChorusRateSlider;
    ScopedPointer<Slider> ChorusMixSlider;
    ScopedPointer<Label> ReverbLabel;
    ScopedPointer<Label> DistortionAmountLabel;
    ScopedPointer<Slider> ReverbWidthSlider;
    ScopedPointer<Slider> ReverbSizeSlider;
    ScopedPointer<Label> ReverbSizeLabel;
    ScopedPointer<Label> ReverbMixLabel;
    ScopedPointer<ComboBox> OscOneBox;
    ScopedPointer<ComboBox> OscTwoBox;
    ScopedPointer<ToggleButton> OscTwoIsOn;
    ScopedPointer<Slider> OscVoicesSlider;
    ScopedPointer<Slider> OscTwoAmpSlider;
    ScopedPointer<Slider> OscTwoTuneSlider;
    ScopedPointer<Slider> OscOneAmpSlider;
    ScopedPointer<Slider> AmpEnvAttackSlider;
    ScopedPointer<Slider> AmpEnvDecaySlider;
    ScopedPointer<Slider> AmpEnvSustainSlider;
    ScopedPointer<Slider> AmpEnvReleaseSlider;
    ScopedPointer<Slider> FilterEnvAttackSlider;
    ScopedPointer<Slider> FilterEnvDecaySlider;
    ScopedPointer<Slider> FilterEnvSustainSlider;
    ScopedPointer<Slider> FilterEnvReleaseSlider;
    ScopedPointer<ComboBox> FilterTypeBox;
    ScopedPointer<Slider> FilterCutoffSlider;
    ScopedPointer<Slider> FilterResonanceSlider;
    ScopedPointer<Slider> FilterEnvelopeSlider;
    ScopedPointer<ToggleButton> FlangerIsOn;
    ScopedPointer<ToggleButton> ChorusIsOn;
    ScopedPointer<ToggleButton> DistortionIsOn;
    ScopedPointer<Slider> DelayMixSlider;
    ScopedPointer<Slider> DelayFeedbackSlider;
    ScopedPointer<ComboBox> DelayRateLeftBox;
    ScopedPointer<ComboBox> DelayRateRightBox;
    ScopedPointer<ToggleButton> DelayIsOn;
    ScopedPointer<ComboBox> LFODestinationBox;
    ScopedPointer<Slider> LFOAmountSlider;
    ScopedPointer<ComboBox> LFORateBox;
    ScopedPointer<Slider> GlobalVolumeSlider;
    ScopedPointer<Slider> GlobalPanSlider;
    ScopedPointer<TextButton> SavePresetButton;
    ScopedPointer<TextButton> LoadPresetButton;
    ScopedPointer<ToggleButton> FlangerUIButton;
    ScopedPointer<ToggleButton> DistortionUIButton;
    ScopedPointer<ToggleButton> ChorusUIButton;
    ScopedPointer<ToggleButton> ReverbUIButton;
    ScopedPointer<Label> AmpAttackLabel;
    ScopedPointer<Label> AmpDecayLabel2;
    ScopedPointer<Label> AmpSustainLabel;
    ScopedPointer<Label> AmpReleaseLabel;
    ScopedPointer<Label> FilterAttackLabel;
    ScopedPointer<Label> FilterDecayLabel2;
    ScopedPointer<Label> FilterSustainLabel;
    ScopedPointer<Label> FilterReleaseLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudeaAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_3B3995C2FEAC160B__
