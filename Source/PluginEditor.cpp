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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
AudeaAudioProcessorEditor::AudeaAudioProcessorEditor (AudeaAudioProcessor* ownerFilter)
    : AudioProcessorEditor(ownerFilter),
      midiKeyboard(ownerFilter->keyboardState,MidiKeyboardComponent::horizontalKeyboard)
{
    addAndMakeVisible (FlangerMixLabel = new Label ("FlangerMixLabel",
                                                    TRANS("Mix")));
    FlangerMixLabel->setFont (Font (15.00f, Font::bold));
    FlangerMixLabel->setJustificationType (Justification::centredLeft);
    FlangerMixLabel->setEditable (false, false, false);
    FlangerMixLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    FlangerMixLabel->setColour (TextEditor::textColourId, Colours::black);
    FlangerMixLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (FlangerDelayLabel = new Label ("FlangerDelayLabel",
                                                      TRANS("Delay")));
    FlangerDelayLabel->setFont (Font (15.00f, Font::bold));
    FlangerDelayLabel->setJustificationType (Justification::centredLeft);
    FlangerDelayLabel->setEditable (false, false, false);
    FlangerDelayLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    FlangerDelayLabel->setColour (TextEditor::textColourId, Colours::black);
    FlangerDelayLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (ChorusMixLabel = new Label ("ChorusMixLabel",
                                                   TRANS("Mix")));
    ChorusMixLabel->setFont (Font (15.00f, Font::bold));
    ChorusMixLabel->setJustificationType (Justification::centredLeft);
    ChorusMixLabel->setEditable (false, false, false);
    ChorusMixLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    ChorusMixLabel->setColour (TextEditor::textColourId, Colours::black);
    ChorusMixLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (ReverbWidthLabel = new Label ("ReverbWidthLabel",
                                                     TRANS("Width")));
    ReverbWidthLabel->setFont (Font (15.00f, Font::bold));
    ReverbWidthLabel->setJustificationType (Justification::centredLeft);
    ReverbWidthLabel->setEditable (false, false, false);
    ReverbWidthLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    ReverbWidthLabel->setColour (TextEditor::textColourId, Colours::black);
    ReverbWidthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (FlangerFeedbackLabel = new Label ("FlangerFeedbackLabel",
                                                         TRANS("FB")));
    FlangerFeedbackLabel->setFont (Font (15.00f, Font::bold));
    FlangerFeedbackLabel->setJustificationType (Justification::centredLeft);
    FlangerFeedbackLabel->setEditable (false, false, false);
    FlangerFeedbackLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    FlangerFeedbackLabel->setColour (TextEditor::textColourId, Colours::black);
    FlangerFeedbackLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (ChorusRateLabel = new Label ("ChorusRateLabel",
                                                    TRANS("Rate")));
    ChorusRateLabel->setFont (Font (15.00f, Font::bold));
    ChorusRateLabel->setJustificationType (Justification::centredLeft);
    ChorusRateLabel->setEditable (false, false, false);
    ChorusRateLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    ChorusRateLabel->setColour (TextEditor::textColourId, Colours::black);
    ChorusRateLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (DistortionLabel = new Label ("DistortionLabel",
                                                    TRANS("Distortion")));
    DistortionLabel->setFont (Font (15.00f, Font::plain));
    DistortionLabel->setJustificationType (Justification::centredLeft);
    DistortionLabel->setEditable (false, false, false);
    DistortionLabel->setColour (TextEditor::textColourId, Colours::black);
    DistortionLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (FlangerLabel = new Label ("FlangerLabel",
                                                 TRANS("Flanger")));
    FlangerLabel->setFont (Font (15.00f, Font::plain));
    FlangerLabel->setJustificationType (Justification::centredLeft);
    FlangerLabel->setEditable (false, false, false);
    FlangerLabel->setColour (TextEditor::textColourId, Colours::black);
    FlangerLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (ChorusLabel = new Label ("ChorusLabel",
                                                TRANS("Chorus")));
    ChorusLabel->setFont (Font (15.00f, Font::plain));
    ChorusLabel->setJustificationType (Justification::centredLeft);
    ChorusLabel->setEditable (false, false, false);
    ChorusLabel->setColour (TextEditor::textColourId, Colours::black);
    ChorusLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (FlangerFeedbackSlider = new Slider ("FlangerFeedbackSlider"));
    FlangerFeedbackSlider->setRange (0, 0.99, 0.01);
    FlangerFeedbackSlider->setSliderStyle (Slider::LinearHorizontal);
    FlangerFeedbackSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    FlangerFeedbackSlider->addListener (this);

    addAndMakeVisible (FlangerDelaySlider = new Slider ("FlangerDelaySlider"));
    FlangerDelaySlider->setRange (1, 10, 0.1);
    FlangerDelaySlider->setSliderStyle (Slider::LinearHorizontal);
    FlangerDelaySlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    FlangerDelaySlider->addListener (this);

    addAndMakeVisible (FlangerMixSlider = new Slider ("FlangerMixSlider"));
    FlangerMixSlider->setRange (0, 0.5, 0.01);
    FlangerMixSlider->setSliderStyle (Slider::LinearHorizontal);
    FlangerMixSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    FlangerMixSlider->addListener (this);

    addAndMakeVisible (ReverbMixSlider = new Slider ("ReverbMixSlider"));
    ReverbMixSlider->setRange (0, 1, 0.01);
    ReverbMixSlider->setSliderStyle (Slider::LinearHorizontal);
    ReverbMixSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    ReverbMixSlider->addListener (this);

    addAndMakeVisible (DistortionAmountSlider = new Slider ("DistortionAmountSlider"));
    DistortionAmountSlider->setRange (0, 99, 0.1);
    DistortionAmountSlider->setSliderStyle (Slider::LinearHorizontal);
    DistortionAmountSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    DistortionAmountSlider->addListener (this);

    addAndMakeVisible (ChorusRateSlider = new Slider ("ChorusRateSlider"));
    ChorusRateSlider->setRange (1.25, 25, 0.1);
    ChorusRateSlider->setSliderStyle (Slider::LinearHorizontal);
    ChorusRateSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    ChorusRateSlider->addListener (this);

    addAndMakeVisible (ChorusMixSlider = new Slider ("ChorusMixSlider"));
    ChorusMixSlider->setRange (0, 0.5, 0.01);
    ChorusMixSlider->setSliderStyle (Slider::LinearHorizontal);
    ChorusMixSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    ChorusMixSlider->addListener (this);

    addAndMakeVisible (ReverbLabel = new Label ("ReverbLabel",
                                                TRANS("Reverb")));
    ReverbLabel->setFont (Font (15.00f, Font::plain));
    ReverbLabel->setJustificationType (Justification::centredLeft);
    ReverbLabel->setEditable (false, false, false);
    ReverbLabel->setColour (TextEditor::textColourId, Colours::black);
    ReverbLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (DistortionAmountLabel = new Label ("DistortionAmountLabel",
                                                          TRANS("Amount\n")));
    DistortionAmountLabel->setFont (Font (15.00f, Font::bold));
    DistortionAmountLabel->setJustificationType (Justification::centredLeft);
    DistortionAmountLabel->setEditable (false, false, false);
    DistortionAmountLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    DistortionAmountLabel->setColour (TextEditor::textColourId, Colours::black);
    DistortionAmountLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (ReverbWidthSlider = new Slider ("ReverbWidthSlider"));
    ReverbWidthSlider->setRange (0, 1, 0.01);
    ReverbWidthSlider->setSliderStyle (Slider::LinearHorizontal);
    ReverbWidthSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    ReverbWidthSlider->addListener (this);

    addAndMakeVisible (ReverbSizeSlider = new Slider ("ReverbSizeSlider"));
    ReverbSizeSlider->setRange (0, 1, 0.01);
    ReverbSizeSlider->setSliderStyle (Slider::LinearHorizontal);
    ReverbSizeSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    ReverbSizeSlider->addListener (this);

    addAndMakeVisible (ReverbSizeLabel = new Label ("ReverbSizeLabel",
                                                    TRANS("Size")));
    ReverbSizeLabel->setFont (Font (15.00f, Font::bold));
    ReverbSizeLabel->setJustificationType (Justification::centredLeft);
    ReverbSizeLabel->setEditable (false, false, false);
    ReverbSizeLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    ReverbSizeLabel->setColour (TextEditor::textColourId, Colours::black);
    ReverbSizeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (ReverbMixLabel = new Label ("ReverbMixLabel",
                                                   TRANS("Mix")));
    ReverbMixLabel->setFont (Font (15.00f, Font::bold));
    ReverbMixLabel->setJustificationType (Justification::centredLeft);
    ReverbMixLabel->setEditable (false, false, false);
    ReverbMixLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    ReverbMixLabel->setColour (TextEditor::textColourId, Colours::black);
    ReverbMixLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (OscOneBox = new ComboBox ("OscOneBox"));
    OscOneBox->setEditableText (false);
    OscOneBox->setJustificationType (Justification::centredLeft);
    OscOneBox->setTextWhenNothingSelected (TRANS("Sine"));
    OscOneBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    OscOneBox->addItem (TRANS("Sine"), 1);
    OscOneBox->addItem (TRANS("Triangle"), 2);
    OscOneBox->addItem (TRANS("Square"), 3);
    OscOneBox->addItem (TRANS("Saw"), 4);
    OscOneBox->addItem (TRANS("Noise"), 5);
    OscOneBox->addListener (this);

    addAndMakeVisible (OscTwoBox = new ComboBox ("OscTwoBox"));
    OscTwoBox->setEditableText (false);
    OscTwoBox->setJustificationType (Justification::centredLeft);
    OscTwoBox->setTextWhenNothingSelected (TRANS("Sine"));
    OscTwoBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    OscTwoBox->addItem (TRANS("Sine"), 1);
    OscTwoBox->addItem (TRANS("Triangle"), 2);
    OscTwoBox->addItem (TRANS("Square"), 3);
    OscTwoBox->addItem (TRANS("Saw"), 4);
    OscTwoBox->addItem (TRANS("Noise"), 5);
    OscTwoBox->addListener (this);

    addAndMakeVisible (OscTwoIsOn = new ToggleButton ("OscTwoIsOn"));
    OscTwoIsOn->setButtonText (String::empty);
    OscTwoIsOn->addListener (this);

    addAndMakeVisible (OscVoicesSlider = new Slider ("OscVoicesSlider"));
    OscVoicesSlider->setRange (1, 14, 1);
    OscVoicesSlider->setSliderStyle (Slider::IncDecButtons);
    OscVoicesSlider->setTextBoxStyle (Slider::TextBoxAbove, false, 40, 20);
    OscVoicesSlider->addListener (this);

    addAndMakeVisible (OscTwoAmpSlider = new Slider ("OscTwoAmpSlider"));
    OscTwoAmpSlider->setRange (0, 1, 0.01);
    OscTwoAmpSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    OscTwoAmpSlider->setTextBoxStyle (Slider::NoTextBox, false, 20, 20);
    OscTwoAmpSlider->addListener (this);

    addAndMakeVisible (OscTwoTuneSlider = new Slider ("OscTwoTuneSlider"));
    OscTwoTuneSlider->setRange (-24, 24, 1);
    OscTwoTuneSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    OscTwoTuneSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 28, 20);
    OscTwoTuneSlider->addListener (this);

    addAndMakeVisible (OscOneAmpSlider = new Slider ("OscOneAmpSlider"));
    OscOneAmpSlider->setRange (0, 1, 0.01);
    OscOneAmpSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    OscOneAmpSlider->setTextBoxStyle (Slider::NoTextBox, false, 30, 20);
    OscOneAmpSlider->addListener (this);

    addAndMakeVisible (AmpEnvAttackSlider = new Slider ("AmpEnvAttackSlider"));
    AmpEnvAttackSlider->setRange (0, 5000, 1);
    AmpEnvAttackSlider->setSliderStyle (Slider::LinearVertical);
    AmpEnvAttackSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    AmpEnvAttackSlider->addListener (this);
    AmpEnvAttackSlider->setSkewFactor (0.7);

    addAndMakeVisible (AmpEnvDecaySlider = new Slider ("AmpEnvDecaySlider"));
    AmpEnvDecaySlider->setRange (0, 5000, 1);
    AmpEnvDecaySlider->setSliderStyle (Slider::LinearVertical);
    AmpEnvDecaySlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    AmpEnvDecaySlider->addListener (this);
    AmpEnvDecaySlider->setSkewFactor (0.7);

    addAndMakeVisible (AmpEnvSustainSlider = new Slider ("AmpEnvSustainSlider"));
    AmpEnvSustainSlider->setRange (0, 1, 0.01);
    AmpEnvSustainSlider->setSliderStyle (Slider::LinearVertical);
    AmpEnvSustainSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    AmpEnvSustainSlider->addListener (this);

    addAndMakeVisible (AmpEnvReleaseSlider = new Slider ("AmpEnvReleaseSlider"));
    AmpEnvReleaseSlider->setRange (0, 5000, 1);
    AmpEnvReleaseSlider->setSliderStyle (Slider::LinearVertical);
    AmpEnvReleaseSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    AmpEnvReleaseSlider->addListener (this);
    AmpEnvReleaseSlider->setSkewFactor (0.7);

    addAndMakeVisible (FilterEnvAttackSlider = new Slider ("FilterEnvAttackSlider"));
    FilterEnvAttackSlider->setRange (0, 5000, 1);
    FilterEnvAttackSlider->setSliderStyle (Slider::LinearVertical);
    FilterEnvAttackSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    FilterEnvAttackSlider->addListener (this);
    FilterEnvAttackSlider->setSkewFactor (0.6);

    addAndMakeVisible (FilterEnvDecaySlider = new Slider ("FilterEnvDecaySlider"));
    FilterEnvDecaySlider->setRange (0, 5000, 1);
    FilterEnvDecaySlider->setSliderStyle (Slider::LinearVertical);
    FilterEnvDecaySlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    FilterEnvDecaySlider->addListener (this);
    FilterEnvDecaySlider->setSkewFactor (0.6);

    addAndMakeVisible (FilterEnvSustainSlider = new Slider ("FilterEnvSustainSlider"));
    FilterEnvSustainSlider->setRange (0, 5000, 1);
    FilterEnvSustainSlider->setSliderStyle (Slider::LinearVertical);
    FilterEnvSustainSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    FilterEnvSustainSlider->addListener (this);

    addAndMakeVisible (FilterEnvReleaseSlider = new Slider ("FilterEnvReleaseSlider"));
    FilterEnvReleaseSlider->setRange (0, 5000, 1);
    FilterEnvReleaseSlider->setSliderStyle (Slider::LinearVertical);
    FilterEnvReleaseSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    FilterEnvReleaseSlider->addListener (this);
    FilterEnvReleaseSlider->setSkewFactor (0.6);

    addAndMakeVisible (FilterTypeBox = new ComboBox ("FilterTypeBox"));
    FilterTypeBox->setEditableText (false);
    FilterTypeBox->setJustificationType (Justification::centredLeft);
    FilterTypeBox->setTextWhenNothingSelected (String::empty);
    FilterTypeBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    FilterTypeBox->addItem (TRANS("Lowpass"), 1);
    FilterTypeBox->addItem (TRANS("Bandpass"), 2);
    FilterTypeBox->addItem (TRANS("Highpass"), 3);
    FilterTypeBox->addItem (TRANS("BandReject"), 4);
    FilterTypeBox->addItem (TRANS("Allpass"), 5);
    FilterTypeBox->addListener (this);

    addAndMakeVisible (FilterCutoffSlider = new Slider ("FilterCutoffSlider"));
    FilterCutoffSlider->setRange (40, 20000, 1);
    FilterCutoffSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    FilterCutoffSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    FilterCutoffSlider->addListener (this);
    FilterCutoffSlider->setSkewFactor (0.5);

    addAndMakeVisible (FilterResonanceSlider = new Slider ("FilterResonanceSlider"));
    FilterResonanceSlider->setRange (0.5, 5, 0.01);
    FilterResonanceSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    FilterResonanceSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    FilterResonanceSlider->addListener (this);

    addAndMakeVisible (FilterEnvelopeSlider = new Slider ("FilterEnvelopeSlider"));
    FilterEnvelopeSlider->setRange (0, 5000, 1);
    FilterEnvelopeSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    FilterEnvelopeSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    FilterEnvelopeSlider->addListener (this);

    addAndMakeVisible (FlangerIsOn = new ToggleButton ("FlangerIsOn"));
    FlangerIsOn->setButtonText (String::empty);
    FlangerIsOn->addListener (this);

    addAndMakeVisible (ChorusIsOn = new ToggleButton ("ChorusIsOn"));
    ChorusIsOn->setButtonText (String::empty);
    ChorusIsOn->addListener (this);

    addAndMakeVisible (ReverbIsOn = new ToggleButton ("ReverbIsOn"));
    ReverbIsOn->setButtonText (String::empty);
    ReverbIsOn->addListener (this);

    addAndMakeVisible (DistortionIsOn = new ToggleButton ("DistortionIsOn"));
    DistortionIsOn->setButtonText (String::empty);
    DistortionIsOn->addListener (this);

    addAndMakeVisible (DelayMixSlider = new Slider ("DelayMixSlider"));
    DelayMixSlider->setRange (0, 1, 0.01);
    DelayMixSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    DelayMixSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    DelayMixSlider->addListener (this);

    addAndMakeVisible (DelayFeedbackSlider = new Slider ("DelayFeedbackSlider"));
    DelayFeedbackSlider->setRange (0, 0.99, 0.01);
    DelayFeedbackSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    DelayFeedbackSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    DelayFeedbackSlider->addListener (this);

    addAndMakeVisible (DelayRateLeftBox = new ComboBox ("DelayRateLeftBox"));
    DelayRateLeftBox->setEditableText (false);
    DelayRateLeftBox->setJustificationType (Justification::centredLeft);
    DelayRateLeftBox->setTextWhenNothingSelected (String::empty);
    DelayRateLeftBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    DelayRateLeftBox->addItem (TRANS("1/1"), 1);
    DelayRateLeftBox->addItem (TRANS("1/2"), 2);
    DelayRateLeftBox->addItem (TRANS("1/4"), 3);
    DelayRateLeftBox->addItem (TRANS("1/8"), 4);
    DelayRateLeftBox->addItem (TRANS("1/16"), 5);
    DelayRateLeftBox->addItem (TRANS("1/32"), 6);
    DelayRateLeftBox->addListener (this);

    addAndMakeVisible (DelayRateRightBox = new ComboBox ("DelayRateRightBox"));
    DelayRateRightBox->setEditableText (false);
    DelayRateRightBox->setJustificationType (Justification::centredLeft);
    DelayRateRightBox->setTextWhenNothingSelected (String::empty);
    DelayRateRightBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    DelayRateRightBox->addItem (TRANS("1/1"), 1);
    DelayRateRightBox->addItem (TRANS("1/2"), 2);
    DelayRateRightBox->addItem (TRANS("1/4"), 3);
    DelayRateRightBox->addItem (TRANS("1/8"), 4);
    DelayRateRightBox->addItem (TRANS("1/16"), 5);
    DelayRateRightBox->addItem (TRANS("1/32"), 6);
    DelayRateRightBox->addListener (this);

    addAndMakeVisible (DelayIsOn = new ToggleButton ("DelayIsOn"));
    DelayIsOn->setButtonText (String::empty);
    DelayIsOn->addListener (this);

    addAndMakeVisible (LFODestinationBox = new ComboBox ("LFODestinationBox"));
    LFODestinationBox->setEditableText (false);
    LFODestinationBox->setJustificationType (Justification::centredLeft);
    LFODestinationBox->setTextWhenNothingSelected (String::empty);
    LFODestinationBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    LFODestinationBox->addItem (TRANS("None"), 1);
    LFODestinationBox->addItem (TRANS("FilterCutoff"), 2);
    LFODestinationBox->addItem (TRANS("Volume"), 3);
    LFODestinationBox->addItem (TRANS("Pan"), 4);
    LFODestinationBox->addListener (this);

    addAndMakeVisible (LFOAmountSlider = new Slider ("LFOAmountSlider"));
    LFOAmountSlider->setRange (0, 1, 0.01);
    LFOAmountSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    LFOAmountSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    LFOAmountSlider->addListener (this);

    addAndMakeVisible (LFORateBox = new ComboBox ("LFORateBox"));
    LFORateBox->setEditableText (false);
    LFORateBox->setJustificationType (Justification::centredLeft);
    LFORateBox->setTextWhenNothingSelected (String::empty);
    LFORateBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    LFORateBox->addItem (TRANS("1/1"), 1);
    LFORateBox->addItem (TRANS("1/2"), 2);
    LFORateBox->addItem (TRANS("1/3"), 3);
    LFORateBox->addItem (TRANS("1/4"), 4);
    LFORateBox->addItem (TRANS("1/6"), 5);
    LFORateBox->addItem (TRANS("1/8"), 6);
    LFORateBox->addItem (TRANS("1/12"), 7);
    LFORateBox->addItem (TRANS("1/16"), 8);
    LFORateBox->addItem (TRANS("1/24"), 9);
    LFORateBox->addItem (TRANS("1/32"), 10);
    LFORateBox->addListener (this);

    addAndMakeVisible (GlobalVolumeSlider = new Slider ("GlobalVolumeSlider"));
    GlobalVolumeSlider->setRange (0, 1.5, 0.01);
    GlobalVolumeSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    GlobalVolumeSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    GlobalVolumeSlider->addListener (this);

    addAndMakeVisible (GlobalPanSlider = new Slider ("GlobalPanSlider"));
    GlobalPanSlider->setRange (0, 1, 0.01);
    GlobalPanSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    GlobalPanSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    GlobalPanSlider->addListener (this);

    addAndMakeVisible (SavePresetButton = new TextButton ("SavePresetButton"));
    SavePresetButton->setButtonText (String::empty);
    SavePresetButton->addListener (this);

    addAndMakeVisible (LoadPresetButton = new TextButton ("LoadPresetButton"));
    LoadPresetButton->setButtonText (String::empty);
    LoadPresetButton->addListener (this);

    addAndMakeVisible (FlangerUIButton = new ToggleButton ("FlangerUIButton"));
    FlangerUIButton->setButtonText (String::empty);
    FlangerUIButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight | Button::ConnectedOnTop | Button::ConnectedOnBottom);
    FlangerUIButton->addListener (this);

    addAndMakeVisible (DistortionUIButton = new ToggleButton ("DistortionUIButton"));
    DistortionUIButton->setButtonText (String::empty);
    DistortionUIButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight | Button::ConnectedOnTop | Button::ConnectedOnBottom);
    DistortionUIButton->addListener (this);

    addAndMakeVisible (ChorusUIButton = new ToggleButton ("ChorusUIButton"));
    ChorusUIButton->setButtonText (String::empty);
    ChorusUIButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight | Button::ConnectedOnTop | Button::ConnectedOnBottom);
    ChorusUIButton->addListener (this);

    addAndMakeVisible (ReverbUIButton = new ToggleButton ("ReverbUIButton"));
    ReverbUIButton->setButtonText (String::empty);
    ReverbUIButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight | Button::ConnectedOnTop | Button::ConnectedOnBottom);
    ReverbUIButton->addListener (this);


    //[UserPreSize]

	FlangerUIButton->setToggleState(true, false);
	changeFlangerUIState(true);
	changeChorusUIState(false);
	changeDistortionUIState(false);
	changeReverbUIState(false);
	//add the midi keyboard component
	addAndMakeVisible(midiKeyboard);

    //[/UserPreSize]

    setSize (800, 620);


    //[Constructor] You can add your own custom stuff here..
	getProcessor()->RequestUIUpdate();//UI update must be done each time a new editor is constructed
	startTimer(200);//starts timer with interval of 200m

	//Gui - LookAndFeel
	lookAndFeel1 = new AudeaLookAndFeel1();
	lookAndFeel2 = new AudeaLookAndFeel2();
	LookAndFeel::setDefaultLookAndFeel(lookAndFeel2);
	GlobalPanSlider->setLookAndFeel(lookAndFeel1);
	GlobalVolumeSlider->setLookAndFeel(lookAndFeel1);
	FilterEnvAttackSlider->setLookAndFeel(lookAndFeel1);
	FilterEnvDecaySlider->setLookAndFeel(lookAndFeel1);
	FilterEnvSustainSlider->setLookAndFeel(lookAndFeel1);
	FilterEnvReleaseSlider->setLookAndFeel(lookAndFeel1);
	FlangerDelaySlider->setLookAndFeel(lookAndFeel1);
	DelayIsOn->setLookAndFeel(lookAndFeel1);
	OscTwoIsOn->setLookAndFeel(lookAndFeel1);
	DistortionIsOn->setLookAndFeel(lookAndFeel1);
	FlangerIsOn->setLookAndFeel(lookAndFeel1);
	ReverbIsOn->setLookAndFeel(lookAndFeel1);
	ChorusIsOn->setLookAndFeel(lookAndFeel1);
	OscVoicesSlider->setLookAndFeel(lookAndFeel1);
	OscTwoTuneSlider->setLookAndFeel(lookAndFeel1);

    //[/Constructor]
}

AudeaAudioProcessorEditor::~AudeaAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    FlangerMixLabel = nullptr;
    FlangerDelayLabel = nullptr;
    ChorusMixLabel = nullptr;
    ReverbWidthLabel = nullptr;
    FlangerFeedbackLabel = nullptr;
    ChorusRateLabel = nullptr;
    DistortionLabel = nullptr;
    FlangerLabel = nullptr;
    ChorusLabel = nullptr;
    FlangerFeedbackSlider = nullptr;
    FlangerDelaySlider = nullptr;
    FlangerMixSlider = nullptr;
    ReverbMixSlider = nullptr;
    DistortionAmountSlider = nullptr;
    ChorusRateSlider = nullptr;
    ChorusMixSlider = nullptr;
    ReverbLabel = nullptr;
    DistortionAmountLabel = nullptr;
    ReverbWidthSlider = nullptr;
    ReverbSizeSlider = nullptr;
    ReverbSizeLabel = nullptr;
    ReverbMixLabel = nullptr;
    OscOneBox = nullptr;
    OscTwoBox = nullptr;
    OscTwoIsOn = nullptr;
    OscVoicesSlider = nullptr;
    OscTwoAmpSlider = nullptr;
    OscTwoTuneSlider = nullptr;
    OscOneAmpSlider = nullptr;
    AmpEnvAttackSlider = nullptr;
    AmpEnvDecaySlider = nullptr;
    AmpEnvSustainSlider = nullptr;
    AmpEnvReleaseSlider = nullptr;
    FilterEnvAttackSlider = nullptr;
    FilterEnvDecaySlider = nullptr;
    FilterEnvSustainSlider = nullptr;
    FilterEnvReleaseSlider = nullptr;
    FilterTypeBox = nullptr;
    FilterCutoffSlider = nullptr;
    FilterResonanceSlider = nullptr;
    FilterEnvelopeSlider = nullptr;
    FlangerIsOn = nullptr;
    ChorusIsOn = nullptr;
    ReverbIsOn = nullptr;
    DistortionIsOn = nullptr;
    DelayMixSlider = nullptr;
    DelayFeedbackSlider = nullptr;
    DelayRateLeftBox = nullptr;
    DelayRateRightBox = nullptr;
    DelayIsOn = nullptr;
    LFODestinationBox = nullptr;
    LFOAmountSlider = nullptr;
    LFORateBox = nullptr;
    GlobalVolumeSlider = nullptr;
    GlobalPanSlider = nullptr;
    SavePresetButton = nullptr;
    LoadPresetButton = nullptr;
    FlangerUIButton = nullptr;
    DistortionUIButton = nullptr;
    ChorusUIButton = nullptr;
    ReverbUIButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
	delete lookAndFeel1;
	delete lookAndFeel2;
    //[/Destructor]
}

//==============================================================================
void AudeaAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff401f09));

    //[UserPaint] Add your own custom painting code here..
	backGroundImgFile = pluginLocation.getParentDirectory().getParentDirectory().getParentDirectory().getParentDirectory().getChildFile(backGroundImgPath);
	Image backgroundImg = ImageFileFormat::loadFrom(backGroundImgFile);
	g.drawImageAt(backgroundImg, 0, 0);
    //[/UserPaint]
}

void AudeaAudioProcessorEditor::resized()
{
    FlangerMixLabel->setBounds (218, 458, 40, 24);
    FlangerDelayLabel->setBounds (221, 433, 88, 24);
    ChorusMixLabel->setBounds (219, 435, 86, 24);
    ReverbWidthLabel->setBounds (221, 438, 86, 24);
    FlangerFeedbackLabel->setBounds (220, 411, 88, 32);
    ChorusRateLabel->setBounds (220, 411, 80, 24);
    DistortionLabel->setBounds (208, 367, 257, 48);
    FlangerLabel->setBounds (208, 367, 168, 48);
    ChorusLabel->setBounds (210, 368, 184, 48);
    FlangerFeedbackSlider->setBounds (311, 407, 296, 35);
    FlangerDelaySlider->setBounds (311, 431, 296, 26);
    FlangerMixSlider->setBounds (312, 454, 296, 37);
    ReverbMixSlider->setBounds (312, 454, 296, 40);
    DistortionAmountSlider->setBounds (311, 407, 297, 40);
    ChorusRateSlider->setBounds (311, 407, 297, 40);
    ChorusMixSlider->setBounds (311, 431, 296, 40);
    ReverbLabel->setBounds (208, 368, 184, 56);
    DistortionAmountLabel->setBounds (222, 409, 72, 24);
    ReverbWidthSlider->setBounds (311, 431, 296, 40);
    ReverbSizeSlider->setBounds (311, 407, 297, 40);
    ReverbSizeLabel->setBounds (220, 412, 79, 24);
    ReverbMixLabel->setBounds (218, 458, 87, 24);
    OscOneBox->setBounds (87, 151, 56, 16);
    OscTwoBox->setBounds (87, 214, 56, 16);
    OscTwoIsOn->setBounds (80, 188, 24, 24);
    OscVoicesSlider->setBounds (98, 281, 64, 32);
    OscTwoAmpSlider->setBounds (162, 214, 27, 24);
    OscTwoTuneSlider->setBounds (205, 212, 30, 45);
    OscOneAmpSlider->setBounds (166, 146, 40, 24);
    AmpEnvAttackSlider->setBounds (617, 118, 40, 130);
    AmpEnvDecaySlider->setBounds (644, 118, 40, 130);
    AmpEnvSustainSlider->setBounds (670, 119, 40, 129);
    AmpEnvReleaseSlider->setBounds (696, 119, 40, 129);
    FilterEnvAttackSlider->setBounds (280, 240, 33, 88);
    FilterEnvDecaySlider->setBounds (309, 240, 40, 88);
    FilterEnvSustainSlider->setBounds (335, 240, 40, 88);
    FilterEnvReleaseSlider->setBounds (362, 240, 47, 88);
    FilterTypeBox->setBounds (272, 96, 120, 16);
    FilterCutoffSlider->setBounds (363, 190, 24, 24);
    FilterResonanceSlider->setBounds (363, 159, 24, 24);
    FilterEnvelopeSlider->setBounds (363, 128, 24, 24);
    FlangerIsOn->setBounds (368, 376, 24, 24);
    ChorusIsOn->setBounds (352, 376, 24, 24);
    ReverbIsOn->setBounds (352, 376, 24, 24);
    DistortionIsOn->setBounds (395, 376, 24, 24);
    DelayMixSlider->setBounds (450, 301, 24, 24);
    DelayFeedbackSlider->setBounds (528, 300, 24, 24);
    DelayRateLeftBox->setBounds (440, 232, 104, 16);
    DelayRateRightBox->setBounds (440, 267, 104, 16);
    DelayIsOn->setBounds (520, 184, 24, 24);
    LFODestinationBox->setBounds (439, 116, 104, 16);
    LFOAmountSlider->setBounds (465, 150, 24, 24);
    LFORateBox->setBounds (518, 148, 48, 16);
    GlobalVolumeSlider->setBounds (94, 389, 104, 92);
    GlobalPanSlider->setBounds (626, 389, 104, 97);
    SavePresetButton->setBounds (631, 485, 80, 14);
    LoadPresetButton->setBounds (94, 485, 80, 14);
    FlangerUIButton->setBounds (299, 478, 56, 38);
    DistortionUIButton->setBounds (347, 477, 56, 40);
    ChorusUIButton->setBounds (395, 477, 56, 38);
    ReverbUIButton->setBounds (443, 477, 56, 40);
    //[UserResized] Add your own custom resize handling here..
	const int keyboardHeight = 70;
	midiKeyboard.setBounds(4, getHeight() - keyboardHeight - 4, getWidth() - 8, keyboardHeight);
    //[/UserResized]
}

void AudeaAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
	AudeaAudioProcessor* ourProcessor = getProcessor();
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == FlangerFeedbackSlider)
    {
        //[UserSliderCode_FlangerFeedbackSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::FlangerFeedback, (float)sliderThatWasMoved->getValue());
        //[/UserSliderCode_FlangerFeedbackSlider]
    }
    else if (sliderThatWasMoved == FlangerDelaySlider)
    {
        //[UserSliderCode_FlangerDelaySlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::FlangerDelay, (float)sliderThatWasMoved->getValue());
        //[/UserSliderCode_FlangerDelaySlider]
    }
    else if (sliderThatWasMoved == FlangerMixSlider)
    {
        //[UserSliderCode_FlangerMixSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::FlangerMix, (float)sliderThatWasMoved->getValue());
        //[/UserSliderCode_FlangerMixSlider]
    }
    else if (sliderThatWasMoved == ReverbMixSlider)
    {
        //[UserSliderCode_ReverbMixSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::ReverbMix, (float)sliderThatWasMoved->getValue());
        //[/UserSliderCode_ReverbMixSlider]
    }
    else if (sliderThatWasMoved == DistortionAmountSlider)
    {
        //[UserSliderCode_DistortionAmountSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::DistortionAmt, (float)sliderThatWasMoved->getValue());
        //[/UserSliderCode_DistortionAmountSlider]
    }
    else if (sliderThatWasMoved == ChorusRateSlider)
    {
        //[UserSliderCode_ChorusRateSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::ChorusRate, (float)sliderThatWasMoved->getValue());
        //[/UserSliderCode_ChorusRateSlider]
    }
    else if (sliderThatWasMoved == ChorusMixSlider)
    {
        //[UserSliderCode_ChorusMixSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::ChorusMix, (float)sliderThatWasMoved->getValue());
        //[/UserSliderCode_ChorusMixSlider]
    }
    else if (sliderThatWasMoved == ReverbWidthSlider)
    {
        //[UserSliderCode_ReverbWidthSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::ReverbWidth, (float)sliderThatWasMoved->getValue());
        //[/UserSliderCode_ReverbWidthSlider]
    }
    else if (sliderThatWasMoved == ReverbSizeSlider)
    {
        //[UserSliderCode_ReverbSizeSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::ReverbSize, (float)sliderThatWasMoved->getValue());
        //[/UserSliderCode_ReverbSizeSlider]
    }
    else if (sliderThatWasMoved == OscVoicesSlider)
    {
        //[UserSliderCode_OscVoicesSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::OscVoices,(float) sliderThatWasMoved->getValue());
        //[/UserSliderCode_OscVoicesSlider]
    }
    else if (sliderThatWasMoved == OscTwoAmpSlider)
    {
        //[UserSliderCode_OscTwoAmpSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::Osc2Amp,(float) sliderThatWasMoved->getValue());
        //[/UserSliderCode_OscTwoAmpSlider]
    }
    else if (sliderThatWasMoved == OscTwoTuneSlider)
    {
        //[UserSliderCode_OscTwoTuneSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::Osc2Tune,(float) sliderThatWasMoved->getValue());
        //[/UserSliderCode_OscTwoTuneSlider]
    }
    else if (sliderThatWasMoved == OscOneAmpSlider)
    {
        //[UserSliderCode_OscOneAmpSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::Osc1Amp,(float) sliderThatWasMoved->getValue());
        //[/UserSliderCode_OscOneAmpSlider]
    }
    else if (sliderThatWasMoved == AmpEnvAttackSlider)
    {
        //[UserSliderCode_AmpEnvAttackSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::AmpEnvAttack,(float) sliderThatWasMoved->getValue());
        //[/UserSliderCode_AmpEnvAttackSlider]
    }
    else if (sliderThatWasMoved == AmpEnvDecaySlider)
    {
        //[UserSliderCode_AmpEnvDecaySlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::AmpEnvDecay,(float) sliderThatWasMoved->getValue());
        //[/UserSliderCode_AmpEnvDecaySlider]
    }
    else if (sliderThatWasMoved == AmpEnvSustainSlider)
    {
        //[UserSliderCode_AmpEnvSustainSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::AmpEnvSustain,(float) sliderThatWasMoved->getValue());
        //[/UserSliderCode_AmpEnvSustainSlider]
    }
    else if (sliderThatWasMoved == AmpEnvReleaseSlider)
    {
        //[UserSliderCode_AmpEnvReleaseSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::AmpEnvRelease,(float) sliderThatWasMoved->getValue());
        //[/UserSliderCode_AmpEnvReleaseSlider]
    }
    else if (sliderThatWasMoved == FilterEnvAttackSlider)
    {
        //[UserSliderCode_FilterEnvAttackSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::FilterEnvAttack, (float)sliderThatWasMoved->getValue());
        //[/UserSliderCode_FilterEnvAttackSlider]
    }
    else if (sliderThatWasMoved == FilterEnvDecaySlider)
    {
        //[UserSliderCode_FilterEnvDecaySlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::FilterEnvDecay, (float)sliderThatWasMoved->getValue());
        //[/UserSliderCode_FilterEnvDecaySlider]
    }
    else if (sliderThatWasMoved == FilterEnvSustainSlider)
    {
        //[UserSliderCode_FilterEnvSustainSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::FilterEnvSustain, (float)sliderThatWasMoved->getValue());
        //[/UserSliderCode_FilterEnvSustainSlider]
    }
    else if (sliderThatWasMoved == FilterEnvReleaseSlider)
    {
        //[UserSliderCode_FilterEnvReleaseSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::FilterEnvRelease, (float)sliderThatWasMoved->getValue());
        //[/UserSliderCode_FilterEnvReleaseSlider]
    }
    else if (sliderThatWasMoved == FilterCutoffSlider)
    {
        //[UserSliderCode_FilterCutoffSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::FilterCutoff, (float)sliderThatWasMoved->getValue());
        //[/UserSliderCode_FilterCutoffSlider]
    }
    else if (sliderThatWasMoved == FilterResonanceSlider)
    {
        //[UserSliderCode_FilterResonanceSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::FilterRes, (float)sliderThatWasMoved->getValue());
        //[/UserSliderCode_FilterResonanceSlider]
    }
    else if (sliderThatWasMoved == FilterEnvelopeSlider)
    {
        //[UserSliderCode_FilterEnvelopeSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::FilterEnvAmt, (float)sliderThatWasMoved->getValue());
        //[/UserSliderCode_FilterEnvelopeSlider]
    }
    else if (sliderThatWasMoved == DelayMixSlider)
    {
        //[UserSliderCode_DelayMixSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::DelayMix, (float)sliderThatWasMoved->getValue());
        //[/UserSliderCode_DelayMixSlider]
    }
    else if (sliderThatWasMoved == DelayFeedbackSlider)
    {
        //[UserSliderCode_DelayFeedbackSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::DelayFeedback, (float)sliderThatWasMoved->getValue());
        //[/UserSliderCode_DelayFeedbackSlider]
    }
    else if (sliderThatWasMoved == LFOAmountSlider)
    {
        //[UserSliderCode_LFOAmountSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::LFOAmount, (float)sliderThatWasMoved->getValue());
        //[/UserSliderCode_LFOAmountSlider]
    }
    else if (sliderThatWasMoved == GlobalVolumeSlider)
    {
        //[UserSliderCode_GlobalVolumeSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::GlobalGain, (float)sliderThatWasMoved->getValue());
        //[/UserSliderCode_GlobalVolumeSlider]
    }
    else if (sliderThatWasMoved == GlobalPanSlider)
    {
        //[UserSliderCode_GlobalPanSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::GlobalPan, (float)sliderThatWasMoved->getValue());
        //[/UserSliderCode_GlobalPanSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void AudeaAudioProcessorEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
	AudeaAudioProcessor * ourProcessor = getProcessor();
	float id =(float) comboBoxThatHasChanged->getSelectedId();
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == OscOneBox)
    {
        //[UserComboBoxCode_OscOneBox] -- add your combo box handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::Osc1WaveForm, id);
        //[/UserComboBoxCode_OscOneBox]
    }
    else if (comboBoxThatHasChanged == OscTwoBox)
    {
        //[UserComboBoxCode_OscTwoBox] -- add your combo box handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::Osc2WaveForm, id);
        //[/UserComboBoxCode_OscTwoBox]
    }
    else if (comboBoxThatHasChanged == FilterTypeBox)
    {
        //[UserComboBoxCode_FilterTypeBox] -- add your combo box handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::FilterType, id);
        //[/UserComboBoxCode_FilterTypeBox]
    }
    else if (comboBoxThatHasChanged == DelayRateLeftBox)
    {
        //[UserComboBoxCode_DelayRateLeftBox] -- add your combo box handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::DelayLenLeft, id);
        //[/UserComboBoxCode_DelayRateLeftBox]
    }
    else if (comboBoxThatHasChanged == DelayRateRightBox)
    {
        //[UserComboBoxCode_DelayRateRightBox] -- add your combo box handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::DelayLenRight, id);
        //[/UserComboBoxCode_DelayRateRightBox]
    }
    else if (comboBoxThatHasChanged == LFODestinationBox)
    {
        //[UserComboBoxCode_LFODestinationBox] -- add your combo box handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::LFODestination, id);
        //[/UserComboBoxCode_LFODestinationBox]
    }
    else if (comboBoxThatHasChanged == LFORateBox)
    {
        //[UserComboBoxCode_LFORateBox] -- add your combo box handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::LFORate, id);
        //[/UserComboBoxCode_LFORateBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void AudeaAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
	AudeaAudioProcessor* ourProcessor = getProcessor();
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == OscTwoIsOn)
    {
        //[UserButtonCode_OscTwoIsOn] -- add your button handler code here..
		if (buttonThatWasClicked->getToggleState())
			ourProcessor->setParameter(AudeaAudioProcessor::Osc2IsOn, 1.0f);
		else
			ourProcessor->setParameter(AudeaAudioProcessor::Osc2IsOn, 0.0f);
        //[/UserButtonCode_OscTwoIsOn]
    }
    else if (buttonThatWasClicked == FlangerIsOn)
    {
        //[UserButtonCode_FlangerIsOn] -- add your button handler code here..
		if (buttonThatWasClicked->getToggleState())
			ourProcessor->setParameter(AudeaAudioProcessor::FlangerIsOn, 1.0f);
		else
			ourProcessor->setParameter(AudeaAudioProcessor::FlangerIsOn, 0.0f);
        //[/UserButtonCode_FlangerIsOn]
    }
    else if (buttonThatWasClicked == ChorusIsOn)
    {
        //[UserButtonCode_ChorusIsOn] -- add your button handler code here..
		if (buttonThatWasClicked->getToggleState())
			ourProcessor->setParameter(AudeaAudioProcessor::ChorusIsOn, 1.0f);
		else
			ourProcessor->setParameter(AudeaAudioProcessor::ChorusIsOn, 0.0f);
        //[/UserButtonCode_ChorusIsOn]
    }
    else if (buttonThatWasClicked == ReverbIsOn)
    {
        //[UserButtonCode_ReverbIsOn] -- add your button handler code here..
		if (buttonThatWasClicked->getToggleState())
			ourProcessor->setParameter(AudeaAudioProcessor::ReverbIsOn, 1.0f);
		else
			ourProcessor->setParameter(AudeaAudioProcessor::ReverbIsOn, 0.0f);
        //[/UserButtonCode_ReverbIsOn]
    }
    else if (buttonThatWasClicked == DistortionIsOn)
    {
        //[UserButtonCode_DistortionIsOn] -- add your button handler code here..
		if (buttonThatWasClicked->getToggleState())
			ourProcessor->setParameter(AudeaAudioProcessor::DistortionIsOn, 1.0f);
		else
			ourProcessor->setParameter(AudeaAudioProcessor::DistortionIsOn, 0.0f);
        //[/UserButtonCode_DistortionIsOn]
    }
    else if (buttonThatWasClicked == DelayIsOn)
    {
        //[UserButtonCode_DelayIsOn] -- add your button handler code here..
		if (buttonThatWasClicked->getToggleState())
			ourProcessor->setParameter(AudeaAudioProcessor::DelayIsOn, 1.0f);
		else
			ourProcessor->setParameter(AudeaAudioProcessor::DelayIsOn, 0.0f);
        //[/UserButtonCode_DelayIsOn]
    }
    else if (buttonThatWasClicked == SavePresetButton)
    {
        //[UserButtonCode_SavePresetButton] -- add your button handler code here..
		FileChooser myChooser("Please select the file...",
				File::getSpecialLocation(File::userHomeDirectory),
				"*.audea");
		if (myChooser.browseForFileToOpen())
		{
			File file(myChooser.getResult());
			ourProcessor->savePreset(file);
		}
        //[/UserButtonCode_SavePresetButton]
    }
    else if (buttonThatWasClicked == LoadPresetButton)
    {
        //[UserButtonCode_LoadPresetButton] -- add your button handler code here..
		FileChooser myChooser("Please select the preset you want to load...",
			File::getSpecialLocation(File::userHomeDirectory),
			"*.audea");
		if (myChooser.browseForFileToOpen())
		{
			File file(myChooser.getResult());
			ourProcessor->loadPreset(file);
		}
        //[/UserButtonCode_LoadPresetButton]
    }
    else if (buttonThatWasClicked == FlangerUIButton)
    {
        //[UserButtonCode_FlangerUIButton] -- add your button handler code here..
		switch (effectState){
		case Flanger:	FlangerUIButton->setToggleState(true, false);
			break;
		case Distortion:DistortionUIButton->setToggleState(false,false);
			changeDistortionUIState(false);
			break;
		case Chorus:ChorusUIButton->setToggleState(false, false);
			changeChorusUIState(false);
			break;
		case Reverb:ReverbUIButton->setToggleState(false, false);
			changeReverbUIState(false);
			break;
		}
		changeFlangerUIState(true);
		effectState = Flanger;
        //[/UserButtonCode_FlangerUIButton]
    }
    else if (buttonThatWasClicked == DistortionUIButton)
    {
        //[UserButtonCode_DistortionUIButton] -- add your button handler code here..
		switch (effectState){
		case Flanger:	FlangerUIButton->setToggleState(false, false);
			changeFlangerUIState(false);
			break;
		case Distortion:DistortionUIButton->setToggleState(true, false);
			break;
		case Chorus:ChorusUIButton->setToggleState(false, false);
			changeChorusUIState(false);
			break;
		case Reverb:ReverbUIButton->setToggleState(false, false);
			changeReverbUIState(false);
			break;
		}
		changeDistortionUIState(true);
		effectState = Distortion;
        //[/UserButtonCode_DistortionUIButton]
    }
    else if (buttonThatWasClicked == ChorusUIButton)
    {
        //[UserButtonCode_ChorusUIButton] -- add your button handler code here..
		switch (effectState){
		case Flanger:	FlangerUIButton->setToggleState(false, false);
			changeFlangerUIState(false);
			break;
		case Distortion:DistortionUIButton->setToggleState(false, false);
			changeDistortionUIState(false);
			break;
		case Chorus:ChorusUIButton->setToggleState(true, false);
			break;
		case Reverb:ReverbUIButton->setToggleState(false, false);
			changeReverbUIState(false);
			break;
		}
		changeChorusUIState(true);
		effectState = Chorus;
        //[/UserButtonCode_ChorusUIButton]
    }
    else if (buttonThatWasClicked == ReverbUIButton)
    {
        //[UserButtonCode_ReverbUIButton] -- add your button handler code here..
		switch (effectState){
		case Flanger:	FlangerUIButton->setToggleState(false, false);
			changeFlangerUIState(false);
			break;
		case Distortion:DistortionUIButton->setToggleState(false, false);
			changeDistortionUIState(false);
			break;
		case Chorus:ChorusUIButton->setToggleState(false, false);
			changeChorusUIState(false);
			break;
		case Reverb:ReverbUIButton->setToggleState(true, false);
			break;
		}
		changeReverbUIState(true);
		effectState = Reverb;
        //[/UserButtonCode_ReverbUIButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void AudeaAudioProcessorEditor::timerCallback()
{
	AudeaAudioProcessor* ourProcessor = getProcessor();

	if (ourProcessor->NeedsUIUpdate())
	{//load your UI components with internal state information form plug-in - example:
		OscTwoIsOn->setToggleState(1.0f == ourProcessor->getParameter(AudeaAudioProcessor::Osc2IsOn), juce::dontSendNotification);
		OscVoicesSlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::OscVoices));
		OscOneBox->setSelectedId((int)ourProcessor->getParameter(AudeaAudioProcessor::Osc1WaveForm), juce::dontSendNotification);
		OscTwoBox->setSelectedId((int)ourProcessor->getParameter(AudeaAudioProcessor::Osc2WaveForm), juce::dontSendNotification);
		OscTwoAmpSlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::Osc2Amp));
		OscTwoTuneSlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::Osc2Tune));
		OscOneAmpSlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::Osc1Amp));
		AmpEnvAttackSlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::AmpEnvAttack));
		AmpEnvDecaySlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::AmpEnvDecay));
		AmpEnvSustainSlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::AmpEnvSustain));
		AmpEnvReleaseSlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::AmpEnvRelease));
		FilterTypeBox->setSelectedId((int)ourProcessor->getParameter(AudeaAudioProcessor::FilterType), juce::dontSendNotification);
		FilterCutoffSlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::FilterCutoff));
		FilterResonanceSlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::FilterRes));
		FilterEnvelopeSlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::FilterEnvAmt));
		FilterEnvAttackSlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::FilterEnvAttack));
		FilterEnvDecaySlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::FilterEnvDecay));
		FilterEnvSustainSlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::FilterEnvSustain));
		FilterEnvReleaseSlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::FilterEnvRelease));
		DelayFeedbackSlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::DelayFeedback));
		DelayMixSlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::DelayMix));
		DelayRateRightBox->setSelectedId((int)ourProcessor->getParameter(AudeaAudioProcessor::DelayLenRight), juce::dontSendNotification);
		DelayIsOn->setToggleState(1.0f == ourProcessor->getParameter(AudeaAudioProcessor::DelayIsOn), juce::dontSendNotification);
		DelayRateLeftBox->setSelectedId((int)ourProcessor->getParameter(AudeaAudioProcessor::DelayLenLeft), juce::dontSendNotification);
		FlangerMixSlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::FlangerMix));
		FlangerFeedbackSlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::FlangerFeedback));
		FlangerDelaySlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::FlangerDelay));
		FlangerIsOn->setToggleState(1.0f == ourProcessor->getParameter(AudeaAudioProcessor::FlangerIsOn), juce::dontSendNotification);
		ChorusIsOn->setToggleState(1.0f == ourProcessor->getParameter(AudeaAudioProcessor::ChorusIsOn), juce::dontSendNotification);
		ChorusMixSlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::ChorusMix));
		ChorusRateSlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::ChorusRate));
		DistortionIsOn->setToggleState(1.0f == ourProcessor->getParameter(AudeaAudioProcessor::DistortionIsOn), juce::dontSendNotification);
		DistortionAmountSlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::DistortionAmt));
		ReverbIsOn->setToggleState(1.0f == ourProcessor->getParameter(AudeaAudioProcessor::ReverbIsOn), juce::dontSendNotification);
		ReverbMixSlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::ReverbMix));
		ReverbSizeSlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::ReverbSize));
		ReverbWidthSlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::ReverbWidth));
		GlobalVolumeSlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::GlobalGain));
		GlobalPanSlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::GlobalPan));
		LFOAmountSlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::LFOAmount));
		LFORateBox->setSelectedId((int)ourProcessor->getParameter(AudeaAudioProcessor::LFORate), juce::dontSendNotification);
		LFODestinationBox->setSelectedId((int)ourProcessor->getParameter(AudeaAudioProcessor::LFODestination), juce::dontSendNotification);

		//repeat for "OtherParams"..
		ourProcessor->ClearUIUpdateFlag();
	}

}

void AudeaAudioProcessorEditor::changeFlangerUIState(bool value)
{
	FlangerDelayLabel->setVisible(value);
	FlangerDelaySlider->setVisible(value);
	FlangerFeedbackLabel->setVisible(value);
	FlangerFeedbackSlider->setVisible(value);
	FlangerIsOn->setVisible(value);
	FlangerLabel->setVisible(value);
	FlangerMixLabel->setVisible(value);
	FlangerMixSlider->setVisible(value);
}
void AudeaAudioProcessorEditor::changeDistortionUIState(bool value)
{
	DistortionAmountLabel->setVisible(value);
	DistortionAmountSlider->setVisible(value);
	DistortionIsOn->setVisible(value);
	DistortionLabel->setVisible(value);
}
void AudeaAudioProcessorEditor::changeChorusUIState(bool value)
{
	ChorusIsOn->setVisible(value);
	ChorusLabel->setVisible(value);
	ChorusMixLabel->setVisible(value);
	ChorusMixSlider->setVisible(value);
	ChorusRateLabel->setVisible(value);
	ChorusRateSlider->setVisible(value);
}
void AudeaAudioProcessorEditor::changeReverbUIState(bool value)
{
	ReverbIsOn->setVisible(value);
	ReverbLabel->setVisible(value);
	ReverbMixLabel->setVisible(value);
	ReverbMixSlider->setVisible(value);
	ReverbSizeLabel->setVisible(value);
	ReverbSizeSlider->setVisible(value);
	ReverbWidthLabel->setVisible(value);
	ReverbWidthSlider->setVisible(value);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="AudeaAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="AudeaAudioProcessor* ownerFilter" variableInitialisers="AudioProcessorEditor(ownerFilter),&#10;midiKeyboard(ownerFilter-&gt;keyboardState,MidiKeyboardComponent::horizontalKeyboard)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="800" initialHeight="620">
  <BACKGROUND backgroundColour="ff401f09"/>
  <LABEL name="FlangerMixLabel" id="c0699ca2f76a7f24" memberName="FlangerMixLabel"
         virtualName="" explicitFocusOrder="0" pos="218 458 40 24" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="Mix" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="FlangerDelayLabel" id="272eb6964a7114f0" memberName="FlangerDelayLabel"
         virtualName="" explicitFocusOrder="0" pos="221 433 88 24" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="Delay" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="ChorusMixLabel" id="b4ad33fdd8052ed9" memberName="ChorusMixLabel"
         virtualName="" explicitFocusOrder="0" pos="219 435 86 24" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="Mix" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="ReverbWidthLabel" id="9d1ccd10ad6d1c44" memberName="ReverbWidthLabel"
         virtualName="" explicitFocusOrder="0" pos="221 438 86 24" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="Width" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="FlangerFeedbackLabel" id="fdc662dd4cb4641" memberName="FlangerFeedbackLabel"
         virtualName="" explicitFocusOrder="0" pos="220 411 88 32" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="FB" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="ChorusRateLabel" id="e0f7b956e48ef71c" memberName="ChorusRateLabel"
         virtualName="" explicitFocusOrder="0" pos="220 411 80 24" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="Rate" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="DistortionLabel" id="b173d143f99d7088" memberName="DistortionLabel"
         virtualName="" explicitFocusOrder="0" pos="208 367 257 48" edTextCol="ff000000"
         edBkgCol="0" labelText="Distortion" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="FlangerLabel" id="5ec9329753b3d00a" memberName="FlangerLabel"
         virtualName="" explicitFocusOrder="0" pos="208 367 168 48" edTextCol="ff000000"
         edBkgCol="0" labelText="Flanger" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="ChorusLabel" id="5719d28c1a4ccd5a" memberName="ChorusLabel"
         virtualName="" explicitFocusOrder="0" pos="210 368 184 48" edTextCol="ff000000"
         edBkgCol="0" labelText="Chorus" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="FlangerFeedbackSlider" id="55f1dc6792ca6a21" memberName="FlangerFeedbackSlider"
          virtualName="" explicitFocusOrder="0" pos="311 407 296 35" min="0"
          max="0.98999999999999999" int="0.01" style="LinearHorizontal"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="FlangerDelaySlider" id="c1a82d56f3ba0cc4" memberName="FlangerDelaySlider"
          virtualName="" explicitFocusOrder="0" pos="311 431 296 26" min="1"
          max="10" int="0.10000000000000001" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="FlangerMixSlider" id="319d434bc47c41de" memberName="FlangerMixSlider"
          virtualName="" explicitFocusOrder="0" pos="312 454 296 37" min="0"
          max="0.5" int="0.01" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="ReverbMixSlider" id="d849c3dbe7a16d9f" memberName="ReverbMixSlider"
          virtualName="" explicitFocusOrder="0" pos="312 454 296 40" min="0"
          max="1" int="0.01" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="DistortionAmountSlider" id="7332128eca099479" memberName="DistortionAmountSlider"
          virtualName="" explicitFocusOrder="0" pos="311 407 297 40" min="0"
          max="99" int="0.10000000000000001" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="ChorusRateSlider" id="c43bd9eda52e3985" memberName="ChorusRateSlider"
          virtualName="" explicitFocusOrder="0" pos="311 407 297 40" min="1.25"
          max="25" int="0.10000000000000001" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="ChorusMixSlider" id="e459f174052e0ff2" memberName="ChorusMixSlider"
          virtualName="" explicitFocusOrder="0" pos="311 431 296 40" min="0"
          max="0.5" int="0.01" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="ReverbLabel" id="263233fc263bb9ce" memberName="ReverbLabel"
         virtualName="" explicitFocusOrder="0" pos="208 368 184 56" edTextCol="ff000000"
         edBkgCol="0" labelText="Reverb" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="DistortionAmountLabel" id="be66008f7bf2db32" memberName="DistortionAmountLabel"
         virtualName="" explicitFocusOrder="0" pos="222 409 72 24" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="Amount&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <SLIDER name="ReverbWidthSlider" id="ec827733ecdec647" memberName="ReverbWidthSlider"
          virtualName="" explicitFocusOrder="0" pos="311 431 296 40" min="0"
          max="1" int="0.01" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="ReverbSizeSlider" id="14c637fa440025d0" memberName="ReverbSizeSlider"
          virtualName="" explicitFocusOrder="0" pos="311 407 297 40" min="0"
          max="1" int="0.01" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="ReverbSizeLabel" id="cacb75ef18d579f3" memberName="ReverbSizeLabel"
         virtualName="" explicitFocusOrder="0" pos="220 412 79 24" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="Size" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="ReverbMixLabel" id="b0762b0e2e30b987" memberName="ReverbMixLabel"
         virtualName="" explicitFocusOrder="0" pos="218 458 87 24" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="Mix" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <COMBOBOX name="OscOneBox" id="3f82eca8fbc59029" memberName="OscOneBox"
            virtualName="" explicitFocusOrder="0" pos="87 151 56 16" editable="0"
            layout="33" items="Sine&#10;Triangle&#10;Square&#10;Saw&#10;Noise"
            textWhenNonSelected="Sine" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="OscTwoBox" id="9658df6ae373fec0" memberName="OscTwoBox"
            virtualName="" explicitFocusOrder="0" pos="87 214 56 16" editable="0"
            layout="33" items="Sine&#10;Triangle&#10;Square&#10;Saw&#10;Noise"
            textWhenNonSelected="Sine" textWhenNoItems="(no choices)"/>
  <TOGGLEBUTTON name="OscTwoIsOn" id="5c67889c9b18a785" memberName="OscTwoIsOn"
                virtualName="" explicitFocusOrder="0" pos="80 188 24 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <SLIDER name="OscVoicesSlider" id="6bc9606b0691e0d2" memberName="OscVoicesSlider"
          virtualName="" explicitFocusOrder="0" pos="98 281 64 32" min="1"
          max="14" int="1" style="IncDecButtons" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="OscTwoAmpSlider" id="518b8887fab7548c" memberName="OscTwoAmpSlider"
          virtualName="" explicitFocusOrder="0" pos="162 214 27 24" min="0"
          max="1" int="0.01" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="20" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="OscTwoTuneSlider" id="ac82cf89dc2fc12c" memberName="OscTwoTuneSlider"
          virtualName="" explicitFocusOrder="0" pos="205 212 30 45" min="-24"
          max="24" int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="28" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="OscOneAmpSlider" id="a081a349e74fa1fb" memberName="OscOneAmpSlider"
          virtualName="" explicitFocusOrder="0" pos="166 146 40 24" min="0"
          max="1" int="0.01" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="30" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="AmpEnvAttackSlider" id="4f8a01927368655c" memberName="AmpEnvAttackSlider"
          virtualName="" explicitFocusOrder="0" pos="617 118 40 130" min="0"
          max="5000" int="1" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="0.69999999999999996"/>
  <SLIDER name="AmpEnvDecaySlider" id="876fe0c32f235f00" memberName="AmpEnvDecaySlider"
          virtualName="" explicitFocusOrder="0" pos="644 118 40 130" min="0"
          max="5000" int="1" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="0.69999999999999996"/>
  <SLIDER name="AmpEnvSustainSlider" id="bc13734e5ac8dc58" memberName="AmpEnvSustainSlider"
          virtualName="" explicitFocusOrder="0" pos="670 119 40 129" min="0"
          max="1" int="0.01" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="AmpEnvReleaseSlider" id="3147e31e839bd086" memberName="AmpEnvReleaseSlider"
          virtualName="" explicitFocusOrder="0" pos="696 119 40 129" min="0"
          max="5000" int="1" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="0.69999999999999996"/>
  <SLIDER name="FilterEnvAttackSlider" id="17c6e681fdd783f7" memberName="FilterEnvAttackSlider"
          virtualName="" explicitFocusOrder="0" pos="280 240 33 88" min="0"
          max="5000" int="1" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="0.59999999999999998"/>
  <SLIDER name="FilterEnvDecaySlider" id="4073d86d63ba585" memberName="FilterEnvDecaySlider"
          virtualName="" explicitFocusOrder="0" pos="309 240 40 88" min="0"
          max="5000" int="1" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="0.59999999999999998"/>
  <SLIDER name="FilterEnvSustainSlider" id="c9aba9c92603734c" memberName="FilterEnvSustainSlider"
          virtualName="" explicitFocusOrder="0" pos="335 240 40 88" min="0"
          max="5000" int="1" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="FilterEnvReleaseSlider" id="9eea865174507345" memberName="FilterEnvReleaseSlider"
          virtualName="" explicitFocusOrder="0" pos="362 240 47 88" min="0"
          max="5000" int="1" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="0.59999999999999998"/>
  <COMBOBOX name="FilterTypeBox" id="8076a0c91218e0e3" memberName="FilterTypeBox"
            virtualName="" explicitFocusOrder="0" pos="272 96 120 16" editable="0"
            layout="33" items="Lowpass&#10;Bandpass&#10;Highpass&#10;BandReject&#10;Allpass"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="FilterCutoffSlider" id="290abad0411db05d" memberName="FilterCutoffSlider"
          virtualName="" explicitFocusOrder="0" pos="363 190 24 24" min="40"
          max="20000" int="1" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="0.5"/>
  <SLIDER name="FilterResonanceSlider" id="72b8c8fcc7e3a9a5" memberName="FilterResonanceSlider"
          virtualName="" explicitFocusOrder="0" pos="363 159 24 24" min="0.5"
          max="5" int="0.01" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="FilterEnvelopeSlider" id="654dbb7b23a5e6b2" memberName="FilterEnvelopeSlider"
          virtualName="" explicitFocusOrder="0" pos="363 128 24 24" min="0"
          max="5000" int="1" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <TOGGLEBUTTON name="FlangerIsOn" id="a34be7e02470739c" memberName="FlangerIsOn"
                virtualName="" explicitFocusOrder="0" pos="368 376 24 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="ChorusIsOn" id="505699439b1f920e" memberName="ChorusIsOn"
                virtualName="" explicitFocusOrder="0" pos="352 376 24 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="ReverbIsOn" id="c6e156e132276275" memberName="ReverbIsOn"
                virtualName="" explicitFocusOrder="0" pos="352 376 24 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="DistortionIsOn" id="6cc597398b435cf2" memberName="DistortionIsOn"
                virtualName="" explicitFocusOrder="0" pos="395 376 24 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <SLIDER name="DelayMixSlider" id="6159a703559ee993" memberName="DelayMixSlider"
          virtualName="" explicitFocusOrder="0" pos="450 301 24 24" min="0"
          max="1" int="0.01" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="DelayFeedbackSlider" id="f08fbb5aea530b08" memberName="DelayFeedbackSlider"
          virtualName="" explicitFocusOrder="0" pos="528 300 24 24" min="0"
          max="0.98999999999999999" int="0.01" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="DelayRateLeftBox" id="62978c8037a61708" memberName="DelayRateLeftBox"
            virtualName="" explicitFocusOrder="0" pos="440 232 104 16" editable="0"
            layout="33" items="1/1&#10;1/2&#10;1/4&#10;1/8&#10;1/16&#10;1/32"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="DelayRateRightBox" id="225ec4c2f6a5cb97" memberName="DelayRateRightBox"
            virtualName="" explicitFocusOrder="0" pos="440 267 104 16" editable="0"
            layout="33" items="1/1&#10;1/2&#10;1/4&#10;1/8&#10;1/16&#10;1/32"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <TOGGLEBUTTON name="DelayIsOn" id="6cbb8654d1fd046d" memberName="DelayIsOn"
                virtualName="" explicitFocusOrder="0" pos="520 184 24 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <COMBOBOX name="LFODestinationBox" id="9bcda03ffed93fb9" memberName="LFODestinationBox"
            virtualName="" explicitFocusOrder="0" pos="439 116 104 16" editable="0"
            layout="33" items="None&#10;FilterCutoff&#10;Volume&#10;Pan"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="LFOAmountSlider" id="5f882442e23151cd" memberName="LFOAmountSlider"
          virtualName="" explicitFocusOrder="0" pos="465 150 24 24" min="0"
          max="1" int="0.01" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="LFORateBox" id="a255da4f656aae8d" memberName="LFORateBox"
            virtualName="" explicitFocusOrder="0" pos="518 148 48 16" editable="0"
            layout="33" items="1/1&#10;1/2&#10;1/3&#10;1/4&#10;1/6&#10;1/8&#10;1/12&#10;1/16&#10;1/24&#10;1/32"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="GlobalVolumeSlider" id="1f6431dfbd6c5f62" memberName="GlobalVolumeSlider"
          virtualName="" explicitFocusOrder="0" pos="94 389 104 92" min="0"
          max="1.5" int="0.01" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="GlobalPanSlider" id="72a0c666b8af61fd" memberName="GlobalPanSlider"
          virtualName="" explicitFocusOrder="0" pos="626 389 104 97" min="0"
          max="1" int="0.01" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="SavePresetButton" id="d275c33d0d3e1621" memberName="SavePresetButton"
              virtualName="" explicitFocusOrder="0" pos="631 485 80 14" buttonText=""
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="LoadPresetButton" id="9c176d2ed7323d52" memberName="LoadPresetButton"
              virtualName="" explicitFocusOrder="0" pos="94 485 80 14" buttonText=""
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="FlangerUIButton" id="23bf4b30c34296ee" memberName="FlangerUIButton"
                virtualName="" explicitFocusOrder="0" pos="299 478 56 38" buttonText=""
                connectedEdges="15" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="DistortionUIButton" id="18e18e9ee4814f9d" memberName="DistortionUIButton"
                virtualName="" explicitFocusOrder="0" pos="347 477 56 40" buttonText=""
                connectedEdges="15" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="ChorusUIButton" id="40e76ee8da06b18d" memberName="ChorusUIButton"
                virtualName="" explicitFocusOrder="0" pos="395 477 56 38" buttonText=""
                connectedEdges="15" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="ReverbUIButton" id="51f90337ab9e0954" memberName="ReverbUIButton"
                virtualName="" explicitFocusOrder="0" pos="443 477 56 40" buttonText=""
                connectedEdges="15" needsCallback="1" radioGroupId="0" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
