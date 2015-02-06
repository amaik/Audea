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
#include <TCHAR.H>
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
                                   public ComboBoxListener,
                                   public ButtonListener,
                                   public SliderListener
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
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);
    void buttonClicked (Button* buttonThatWasClicked);
    void sliderValueChanged (Slider* sliderThatWasMoved);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	MidiKeyboardComponent midiKeyboard;

	//Location of the DLL
	File pluginLocation = File::getSpecialLocation(File::SpecialLocationType::currentApplicationFile);
	//Constants
	File backGroundImgFile;
	String backGroundImgPath = "Resources/BackgroundPure.jpg";
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<GroupComponent> ReverbGroup;
    ScopedPointer<GroupComponent> ChorusGroup;
    ScopedPointer<GroupComponent> DistortionGroup;
    ScopedPointer<GroupComponent> FlangerGroup;
    ScopedPointer<GroupComponent> DelayGroup;
    ScopedPointer<GroupComponent> AmpEnvelopeGroup2;
    ScopedPointer<GroupComponent> FilterGroup;
    ScopedPointer<GroupComponent> AmpEnvelopeGroup;
    ScopedPointer<GroupComponent> GenerateGroup;
    ScopedPointer<ComboBox> OscOneBox;
    ScopedPointer<Label> OscOneLabel;
    ScopedPointer<Label> OscTwoLabel;
    ScopedPointer<ComboBox> OscTwoBox;
    ScopedPointer<ToggleButton> OscTwoIsOn;
    ScopedPointer<Label> OscVoicesLabel;
    ScopedPointer<Slider> OscVoicesSlider;
    ScopedPointer<Slider> OscTwoAmpSlider;
    ScopedPointer<Slider> OscTwoTuneSlider;
    ScopedPointer<Slider> OscOneAmpSlider;
    ScopedPointer<Label> AmpLabel;
    ScopedPointer<Label> TuneLabel;
    ScopedPointer<Slider> AmpEnvAttackSlider;
    ScopedPointer<Slider> AmpEnvDecaySlider;
    ScopedPointer<Slider> AmpEnvSustainSlider;
    ScopedPointer<Slider> AmpEnvReleaseSlider;
    ScopedPointer<Label> AmpEnvAttackLabel;
    ScopedPointer<Label> AmpEnvDecayLabel;
    ScopedPointer<Label> AmpEnvSustainLabel;
    ScopedPointer<Label> AmpEnvReleaseLabel;
    ScopedPointer<Label> FilterEnvAttackLabel;
    ScopedPointer<Label> FilterEnvDecayLabel;
    ScopedPointer<Label> FilterEnvSustainLabel;
    ScopedPointer<Label> FilterEnvReleaseLabel;
    ScopedPointer<Slider> FilterEnvAttackSlider;
    ScopedPointer<Slider> FilterEnvDecaySlider;
    ScopedPointer<Slider> FilterEnvSustainSlider;
    ScopedPointer<Slider> FilterEnvReleaseSlider;
    ScopedPointer<ComboBox> FilterTypeBox;
    ScopedPointer<Slider> FilterCutoffSlider;
    ScopedPointer<Slider> FilterResonanceSlider;
    ScopedPointer<Slider> FilterEnvelopeSlider;
    ScopedPointer<Label> FilterCutoffLabel;
    ScopedPointer<Label> FilterResLabel;
    ScopedPointer<Label> FilterEnvelopeLabel;
    ScopedPointer<Slider> ReverbMixSlider;
    ScopedPointer<Slider> ReverbSizeSlider;
    ScopedPointer<Label> ReverbMixLabel;
    ScopedPointer<Label> ReverbSizeLabel;
    ScopedPointer<Label> ChorusMixLabel;
    ScopedPointer<Slider> ChorusRateSlider;
    ScopedPointer<Slider> ChorusMixSlider;
    ScopedPointer<Label> ChorusRateLabel;
    ScopedPointer<Slider> FlangerFeedbackSlider;
    ScopedPointer<Label> FlangerDelayLabel;
    ScopedPointer<Label> FlangerFeedbackLabel;
    ScopedPointer<Slider> FlangerDelaySlider;
    ScopedPointer<ToggleButton> FlangerIsOn;
    ScopedPointer<ToggleButton> ChorusIsOn;
    ScopedPointer<ToggleButton> ReverbIsOn;
    ScopedPointer<Slider> DistortionAmountSlider;
    ScopedPointer<ToggleButton> DistortionIsOn;
    ScopedPointer<Label> DistortionAmountLabel;
    ScopedPointer<Label> FlangerMixLabel;
    ScopedPointer<Slider> FlangerMixSlider;
    ScopedPointer<Slider> DelayMixSlider;
    ScopedPointer<Slider> DelayFeedbackSlider;
    ScopedPointer<ComboBox> DelayRateLeftBox;
    ScopedPointer<ComboBox> DelayRateRightBox;
    ScopedPointer<ToggleButton> DelayIsOn;
    ScopedPointer<Label> DelayRateLeftLabel;
    ScopedPointer<Label> DelayMixLabel;
    ScopedPointer<Label> DelayFeedbackLabel;
    ScopedPointer<Label> DelayRateRightLabel;
    ScopedPointer<ComboBox> LFODestinationBox;
    ScopedPointer<Slider> LFOAmountSlider;
    ScopedPointer<Label> LFODestinationLabel;
    ScopedPointer<Label> LFOAmountLabel;
    ScopedPointer<Label> LFORateLabel;
    ScopedPointer<ComboBox> LFORateBox;
    ScopedPointer<Label> ReverbWidthLabel;
    ScopedPointer<Slider> ReverbWidthSlider;
    ScopedPointer<Label> GlobalVolumeLabel;
    ScopedPointer<Label> GlobalPanLabel;
    ScopedPointer<Slider> GlobalVolumeSlider;
    ScopedPointer<Slider> GlobalPanSlider;
    ScopedPointer<TextButton> SavePresetButton;
    ScopedPointer<TextButton> LoadPresetButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudeaAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_3B3995C2FEAC160B__
