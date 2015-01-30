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
    addAndMakeVisible (ReverbGroup = new GroupComponent ("ReverbGroup",
                                                         TRANS("Reverb")));
    ReverbGroup->setColour (GroupComponent::outlineColourId, Colour (0x669c1900));
    ReverbGroup->setColour (GroupComponent::textColourId, Colour (0xffff6843));

    addAndMakeVisible (ChorusGroup = new GroupComponent ("ChorusGroup",
                                                         TRANS("Chorus")));
    ChorusGroup->setColour (GroupComponent::outlineColourId, Colour (0x669c1900));
    ChorusGroup->setColour (GroupComponent::textColourId, Colour (0xffff6843));

    addAndMakeVisible (DistortionGroup = new GroupComponent ("DistortionGroup",
                                                             TRANS("Distortion")));
    DistortionGroup->setColour (GroupComponent::outlineColourId, Colour (0x669c1900));
    DistortionGroup->setColour (GroupComponent::textColourId, Colour (0xffff6843));

    addAndMakeVisible (FlangerGroup = new GroupComponent ("FlangerGroup",
                                                          TRANS("Flanger")));
    FlangerGroup->setColour (GroupComponent::outlineColourId, Colour (0x669c1900));
    FlangerGroup->setColour (GroupComponent::textColourId, Colour (0xffff6843));

    addAndMakeVisible (DelayGroup = new GroupComponent ("DelayGroup",
                                                        TRANS("Delay")));
    DelayGroup->setColour (GroupComponent::outlineColourId, Colour (0x669c1900));
    DelayGroup->setColour (GroupComponent::textColourId, Colour (0xffff6843));

    addAndMakeVisible (AmpEnvelopeGroup2 = new GroupComponent ("AmpEnvelopeGroup",
                                                               TRANS("LFO")));
    AmpEnvelopeGroup2->setColour (GroupComponent::outlineColourId, Colour (0x669c1900));
    AmpEnvelopeGroup2->setColour (GroupComponent::textColourId, Colour (0xffff6843));

    addAndMakeVisible (FilterGroup = new GroupComponent ("FilterGroup",
                                                         TRANS("Filter")));
    FilterGroup->setColour (GroupComponent::outlineColourId, Colour (0x669c1900));
    FilterGroup->setColour (GroupComponent::textColourId, Colour (0xffff6843));

    addAndMakeVisible (AmpEnvelopeGroup = new GroupComponent ("AmpEnvelopeGroup",
                                                              TRANS("Amp - Envelope")));
    AmpEnvelopeGroup->setColour (GroupComponent::outlineColourId, Colour (0x669c1900));
    AmpEnvelopeGroup->setColour (GroupComponent::textColourId, Colour (0xffff6843));

    addAndMakeVisible (GenerateGroup = new GroupComponent ("GenerateGroup",
                                                           TRANS("Generate")));
    GenerateGroup->setTextLabelPosition (Justification::centredLeft);
    GenerateGroup->setColour (GroupComponent::outlineColourId, Colour (0x669c1900));
    GenerateGroup->setColour (GroupComponent::textColourId, Colour (0xffff6843));

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

    addAndMakeVisible (OscOneLabel = new Label ("OscOneLabel",
                                                TRANS("OSC 1")));
    OscOneLabel->setFont (Font (15.00f, Font::bold));
    OscOneLabel->setJustificationType (Justification::centredLeft);
    OscOneLabel->setEditable (false, false, false);
    OscOneLabel->setColour (Label::backgroundColourId, Colour (0x00000000));
    OscOneLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    OscOneLabel->setColour (TextEditor::textColourId, Colours::black);
    OscOneLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (OscTwoLabel = new Label ("OscTwoLabel",
                                                TRANS("OSC 2")));
    OscTwoLabel->setFont (Font (15.00f, Font::bold));
    OscTwoLabel->setJustificationType (Justification::centredLeft);
    OscTwoLabel->setEditable (false, false, false);
    OscTwoLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    OscTwoLabel->setColour (TextEditor::textColourId, Colours::black);
    OscTwoLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

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

    addAndMakeVisible (OscThreeLabel = new Label ("OscThreeLabel",
                                                  TRANS("OSC 3")));
    OscThreeLabel->setFont (Font (15.00f, Font::bold));
    OscThreeLabel->setJustificationType (Justification::centredLeft);
    OscThreeLabel->setEditable (false, false, false);
    OscThreeLabel->setColour (Label::backgroundColourId, Colour (0x00000000));
    OscThreeLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    OscThreeLabel->setColour (TextEditor::textColourId, Colours::black);
    OscThreeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (OscThreeBox = new ComboBox ("OscThreeBox"));
    OscThreeBox->setEditableText (false);
    OscThreeBox->setJustificationType (Justification::centredLeft);
    OscThreeBox->setTextWhenNothingSelected (TRANS("Sine"));
    OscThreeBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    OscThreeBox->addItem (TRANS("Sine"), 1);
    OscThreeBox->addItem (TRANS("Triangle"), 2);
    OscThreeBox->addItem (TRANS("Square"), 3);
    OscThreeBox->addItem (TRANS("Saw"), 4);
    OscThreeBox->addItem (TRANS("Noise"), 5);
    OscThreeBox->addListener (this);

    addAndMakeVisible (OscTwoIsOn = new ToggleButton ("OscTwoIsOn"));
    OscTwoIsOn->setButtonText (String::empty);
    OscTwoIsOn->addListener (this);

    addAndMakeVisible (OscThreeIsOn = new ToggleButton ("OscThreeIsOn"));
    OscThreeIsOn->setButtonText (String::empty);
    OscThreeIsOn->addListener (this);

    addAndMakeVisible (OscVoicesLabel = new Label ("OscVoicesLabel",
                                                   TRANS("Voices")));
    OscVoicesLabel->setFont (Font (15.00f, Font::bold));
    OscVoicesLabel->setJustificationType (Justification::centredLeft);
    OscVoicesLabel->setEditable (false, false, false);
    OscVoicesLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    OscVoicesLabel->setColour (TextEditor::textColourId, Colours::black);
    OscVoicesLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

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

    addAndMakeVisible (OscThreeAmpSlider = new Slider ("OscThreeAmpSlider"));
    OscThreeAmpSlider->setRange (0, 1, 0.01);
    OscThreeAmpSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    OscThreeAmpSlider->setTextBoxStyle (Slider::NoTextBox, false, 20, 20);
    OscThreeAmpSlider->addListener (this);

    addAndMakeVisible (OscTwoTuneSlider = new Slider ("OscTwoTuneSlider"));
    OscTwoTuneSlider->setRange (-24, 24, 1);
    OscTwoTuneSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    OscTwoTuneSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 28, 20);
    OscTwoTuneSlider->addListener (this);

    addAndMakeVisible (OscThreeTuneSlider = new Slider ("OscThreeTuneSlider"));
    OscThreeTuneSlider->setRange (-24, 24, 1);
    OscThreeTuneSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    OscThreeTuneSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 28, 20);
    OscThreeTuneSlider->addListener (this);

    addAndMakeVisible (OscOneAmpSlider = new Slider ("OscOneAmpSlider"));
    OscOneAmpSlider->setRange (0, 1, 0.01);
    OscOneAmpSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    OscOneAmpSlider->setTextBoxStyle (Slider::NoTextBox, false, 30, 20);
    OscOneAmpSlider->addListener (this);

    addAndMakeVisible (AmpLabel = new Label ("AmpLabel",
                                             TRANS("Amp")));
    AmpLabel->setFont (Font (15.00f, Font::bold));
    AmpLabel->setJustificationType (Justification::centredLeft);
    AmpLabel->setEditable (false, false, false);
    AmpLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    AmpLabel->setColour (TextEditor::textColourId, Colours::black);
    AmpLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (TuneLabel = new Label ("TuneLabel",
                                              TRANS("Tune")));
    TuneLabel->setFont (Font (15.00f, Font::bold));
    TuneLabel->setJustificationType (Justification::centredLeft);
    TuneLabel->setEditable (false, false, false);
    TuneLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    TuneLabel->setColour (TextEditor::textColourId, Colours::black);
    TuneLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

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

    addAndMakeVisible (AmpEnvAttackLabel = new Label ("AmpEnvAttackLabel",
                                                      TRANS("A")));
    AmpEnvAttackLabel->setFont (Font (15.00f, Font::bold));
    AmpEnvAttackLabel->setJustificationType (Justification::centredLeft);
    AmpEnvAttackLabel->setEditable (false, false, false);
    AmpEnvAttackLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    AmpEnvAttackLabel->setColour (TextEditor::textColourId, Colours::black);
    AmpEnvAttackLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (AmpEnvDecayLabel = new Label ("AmpEnvDecayLabel",
                                                     TRANS("D")));
    AmpEnvDecayLabel->setFont (Font (15.00f, Font::bold));
    AmpEnvDecayLabel->setJustificationType (Justification::centredLeft);
    AmpEnvDecayLabel->setEditable (false, false, false);
    AmpEnvDecayLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    AmpEnvDecayLabel->setColour (TextEditor::textColourId, Colours::black);
    AmpEnvDecayLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (AmpEnvSustainLabel = new Label ("AmpEnvSustainLabel",
                                                       TRANS("S")));
    AmpEnvSustainLabel->setFont (Font (15.00f, Font::bold));
    AmpEnvSustainLabel->setJustificationType (Justification::centredLeft);
    AmpEnvSustainLabel->setEditable (false, false, false);
    AmpEnvSustainLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    AmpEnvSustainLabel->setColour (TextEditor::textColourId, Colours::black);
    AmpEnvSustainLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (AmpEnvReleaseLabel = new Label ("AmpEnvReleaseLabel",
                                                       TRANS("R")));
    AmpEnvReleaseLabel->setFont (Font (15.00f, Font::bold));
    AmpEnvReleaseLabel->setJustificationType (Justification::centredLeft);
    AmpEnvReleaseLabel->setEditable (false, false, false);
    AmpEnvReleaseLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    AmpEnvReleaseLabel->setColour (TextEditor::textColourId, Colours::black);
    AmpEnvReleaseLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (FilterEnvAttackLabel = new Label ("FilterEnvAttackLabel",
                                                         TRANS("A")));
    FilterEnvAttackLabel->setFont (Font (15.00f, Font::bold));
    FilterEnvAttackLabel->setJustificationType (Justification::centredLeft);
    FilterEnvAttackLabel->setEditable (false, false, false);
    FilterEnvAttackLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    FilterEnvAttackLabel->setColour (TextEditor::textColourId, Colours::black);
    FilterEnvAttackLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (FilterEnvDecayLabel = new Label ("FilterEnvDecayLabel",
                                                        TRANS("D")));
    FilterEnvDecayLabel->setFont (Font (15.00f, Font::bold));
    FilterEnvDecayLabel->setJustificationType (Justification::centredLeft);
    FilterEnvDecayLabel->setEditable (false, false, false);
    FilterEnvDecayLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    FilterEnvDecayLabel->setColour (TextEditor::textColourId, Colours::black);
    FilterEnvDecayLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (FilterEnvSustainLabel = new Label ("FilterEnvSustainLabel",
                                                          TRANS("S")));
    FilterEnvSustainLabel->setFont (Font (15.00f, Font::bold));
    FilterEnvSustainLabel->setJustificationType (Justification::centredLeft);
    FilterEnvSustainLabel->setEditable (false, false, false);
    FilterEnvSustainLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    FilterEnvSustainLabel->setColour (TextEditor::textColourId, Colours::black);
    FilterEnvSustainLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (FilterEnvReleaseLabel = new Label ("FilterEnvReleaseLabel",
                                                          TRANS("R")));
    FilterEnvReleaseLabel->setFont (Font (15.00f, Font::bold));
    FilterEnvReleaseLabel->setJustificationType (Justification::centredLeft);
    FilterEnvReleaseLabel->setEditable (false, false, false);
    FilterEnvReleaseLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    FilterEnvReleaseLabel->setColour (TextEditor::textColourId, Colours::black);
    FilterEnvReleaseLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

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
    FilterCutoffSlider->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    FilterCutoffSlider->addListener (this);
    FilterCutoffSlider->setSkewFactor (0.5);

    addAndMakeVisible (FilterResonanceSlider = new Slider ("FilterResonanceSlider"));
    FilterResonanceSlider->setRange (0.5, 5, 0.01);
    FilterResonanceSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    FilterResonanceSlider->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    FilterResonanceSlider->addListener (this);

    addAndMakeVisible (FilterEnvelopeSlider = new Slider ("FilterEnvelopeSlider"));
    FilterEnvelopeSlider->setRange (0, 5000, 1);
    FilterEnvelopeSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    FilterEnvelopeSlider->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    FilterEnvelopeSlider->addListener (this);

    addAndMakeVisible (FilterCutoffLabel = new Label ("FilterCutoffLabel",
                                                      TRANS("Cutoff")));
    FilterCutoffLabel->setFont (Font (15.00f, Font::bold));
    FilterCutoffLabel->setJustificationType (Justification::centredLeft);
    FilterCutoffLabel->setEditable (false, false, false);
    FilterCutoffLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    FilterCutoffLabel->setColour (TextEditor::textColourId, Colours::black);
    FilterCutoffLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (FilterResLabel = new Label ("FilterResLabel",
                                                   TRANS("Res")));
    FilterResLabel->setFont (Font (15.00f, Font::bold));
    FilterResLabel->setJustificationType (Justification::centredLeft);
    FilterResLabel->setEditable (false, false, false);
    FilterResLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    FilterResLabel->setColour (TextEditor::textColourId, Colours::black);
    FilterResLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (FilterEnvelopeLabel = new Label ("FilterEnvelopeLabel",
                                                        TRANS("Envelope")));
    FilterEnvelopeLabel->setFont (Font (15.00f, Font::bold));
    FilterEnvelopeLabel->setJustificationType (Justification::centredLeft);
    FilterEnvelopeLabel->setEditable (false, false, false);
    FilterEnvelopeLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    FilterEnvelopeLabel->setColour (TextEditor::textColourId, Colours::black);
    FilterEnvelopeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (ReverbMixSlider = new Slider ("ReverbMixSlider"));
    ReverbMixSlider->setRange (0, 1, 0.01);
    ReverbMixSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    ReverbMixSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    ReverbMixSlider->addListener (this);

    addAndMakeVisible (ReverbSizeSlider = new Slider ("ReverbSizeSlider"));
    ReverbSizeSlider->setRange (0, 1, 0.01);
    ReverbSizeSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    ReverbSizeSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    ReverbSizeSlider->addListener (this);

    addAndMakeVisible (ReverbMixLabel = new Label ("ReverbMixLabel",
                                                   TRANS("Mix")));
    ReverbMixLabel->setFont (Font (15.00f, Font::bold));
    ReverbMixLabel->setJustificationType (Justification::centredLeft);
    ReverbMixLabel->setEditable (false, false, false);
    ReverbMixLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    ReverbMixLabel->setColour (TextEditor::textColourId, Colours::black);
    ReverbMixLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (ReverbSizeLabel = new Label ("ReverbSizeLabel",
                                                    TRANS("Size")));
    ReverbSizeLabel->setFont (Font (15.00f, Font::bold));
    ReverbSizeLabel->setJustificationType (Justification::centredLeft);
    ReverbSizeLabel->setEditable (false, false, false);
    ReverbSizeLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    ReverbSizeLabel->setColour (TextEditor::textColourId, Colours::black);
    ReverbSizeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (ChorusMixLabel = new Label ("ChorusMixLabel",
                                                   TRANS("Mix")));
    ChorusMixLabel->setFont (Font (15.00f, Font::bold));
    ChorusMixLabel->setJustificationType (Justification::centredLeft);
    ChorusMixLabel->setEditable (false, false, false);
    ChorusMixLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    ChorusMixLabel->setColour (TextEditor::textColourId, Colours::black);
    ChorusMixLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (ChorusRateSlider = new Slider ("ChorusRateSlider"));
    ChorusRateSlider->setRange (1.25, 25, 0.1);
    ChorusRateSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    ChorusRateSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    ChorusRateSlider->addListener (this);

    addAndMakeVisible (ChorusMixSlider = new Slider ("ChorusMixSlider"));
    ChorusMixSlider->setRange (0, 0.5, 0.01);
    ChorusMixSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    ChorusMixSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    ChorusMixSlider->addListener (this);

    addAndMakeVisible (ChorusRateLabel = new Label ("ChorusRateLabel",
                                                    TRANS("Rate")));
    ChorusRateLabel->setFont (Font (15.00f, Font::bold));
    ChorusRateLabel->setJustificationType (Justification::centredLeft);
    ChorusRateLabel->setEditable (false, false, false);
    ChorusRateLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    ChorusRateLabel->setColour (TextEditor::textColourId, Colours::black);
    ChorusRateLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (FlangerFeedbackSlider = new Slider ("FlangerFeedbackSlider"));
    FlangerFeedbackSlider->setRange (0, 0.99, 0.01);
    FlangerFeedbackSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    FlangerFeedbackSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    FlangerFeedbackSlider->addListener (this);

    addAndMakeVisible (FlangerDelayLabel = new Label ("FlangerDelayLabel",
                                                      TRANS("Delay")));
    FlangerDelayLabel->setFont (Font (15.00f, Font::bold));
    FlangerDelayLabel->setJustificationType (Justification::centredLeft);
    FlangerDelayLabel->setEditable (false, false, false);
    FlangerDelayLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    FlangerDelayLabel->setColour (TextEditor::textColourId, Colours::black);
    FlangerDelayLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (FlangerFeedbackLabel = new Label ("FlangerFeedbackLabel",
                                                         TRANS("FB")));
    FlangerFeedbackLabel->setFont (Font (15.00f, Font::bold));
    FlangerFeedbackLabel->setJustificationType (Justification::centredLeft);
    FlangerFeedbackLabel->setEditable (false, false, false);
    FlangerFeedbackLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    FlangerFeedbackLabel->setColour (TextEditor::textColourId, Colours::black);
    FlangerFeedbackLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (FlangerDelaySlider = new Slider ("FlangerDelaySlider"));
    FlangerDelaySlider->setRange (1, 10, 0.1);
    FlangerDelaySlider->setSliderStyle (Slider::RotaryVerticalDrag);
    FlangerDelaySlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    FlangerDelaySlider->addListener (this);

    addAndMakeVisible (FlangerIsOn = new ToggleButton ("FlangerIsOn"));
    FlangerIsOn->setButtonText (String::empty);
    FlangerIsOn->addListener (this);

    addAndMakeVisible (ChorusIsOn = new ToggleButton ("ChorusIsOn"));
    ChorusIsOn->setButtonText (String::empty);
    ChorusIsOn->addListener (this);

    addAndMakeVisible (ReverbIsOn = new ToggleButton ("ReverbIsOn"));
    ReverbIsOn->setButtonText (String::empty);
    ReverbIsOn->addListener (this);

    addAndMakeVisible (DistortionAmountSlider = new Slider ("DistortionAmountSlider"));
    DistortionAmountSlider->setRange (0, 99, 0.1);
    DistortionAmountSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    DistortionAmountSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    DistortionAmountSlider->addListener (this);

    addAndMakeVisible (DistortionIsOn = new ToggleButton ("DistortionIsOn"));
    DistortionIsOn->setButtonText (String::empty);
    DistortionIsOn->addListener (this);

    addAndMakeVisible (DistortionAmountLabel = new Label ("DistortionAmountLabel",
                                                          TRANS("Amount\n")));
    DistortionAmountLabel->setFont (Font (15.00f, Font::bold));
    DistortionAmountLabel->setJustificationType (Justification::centredLeft);
    DistortionAmountLabel->setEditable (false, false, false);
    DistortionAmountLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    DistortionAmountLabel->setColour (TextEditor::textColourId, Colours::black);
    DistortionAmountLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (FlangerMixLabel = new Label ("FlangerMixLabel",
                                                    TRANS("Mix")));
    FlangerMixLabel->setFont (Font (15.00f, Font::bold));
    FlangerMixLabel->setJustificationType (Justification::centredLeft);
    FlangerMixLabel->setEditable (false, false, false);
    FlangerMixLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    FlangerMixLabel->setColour (TextEditor::textColourId, Colours::black);
    FlangerMixLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (FlangerMixSlider = new Slider ("FlangerMixSlider"));
    FlangerMixSlider->setRange (0, 0.5, 0.01);
    FlangerMixSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    FlangerMixSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    FlangerMixSlider->addListener (this);

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

    addAndMakeVisible (DelayRateLeftLabel = new Label ("DelayRateLeftLabel",
                                                       TRANS("Rate - Left")));
    DelayRateLeftLabel->setFont (Font (15.00f, Font::bold));
    DelayRateLeftLabel->setJustificationType (Justification::centredLeft);
    DelayRateLeftLabel->setEditable (false, false, false);
    DelayRateLeftLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    DelayRateLeftLabel->setColour (TextEditor::textColourId, Colours::black);
    DelayRateLeftLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (DelayMixLabel = new Label ("DelayMixLabel",
                                                  TRANS("Mix")));
    DelayMixLabel->setFont (Font (15.00f, Font::bold));
    DelayMixLabel->setJustificationType (Justification::centredLeft);
    DelayMixLabel->setEditable (false, false, false);
    DelayMixLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    DelayMixLabel->setColour (TextEditor::textColourId, Colours::black);
    DelayMixLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (DelayFeedbackLabel = new Label ("DelayFeedbackLabel",
                                                       TRANS("FB")));
    DelayFeedbackLabel->setFont (Font (15.00f, Font::bold));
    DelayFeedbackLabel->setJustificationType (Justification::centredLeft);
    DelayFeedbackLabel->setEditable (false, false, false);
    DelayFeedbackLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    DelayFeedbackLabel->setColour (TextEditor::textColourId, Colours::black);
    DelayFeedbackLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (DelayRateRightLabel = new Label ("DelayRateRightLabel",
                                                        TRANS("Rate - Right")));
    DelayRateRightLabel->setFont (Font (15.00f, Font::bold));
    DelayRateRightLabel->setJustificationType (Justification::centredLeft);
    DelayRateRightLabel->setEditable (false, false, false);
    DelayRateRightLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    DelayRateRightLabel->setColour (TextEditor::textColourId, Colours::black);
    DelayRateRightLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

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

    addAndMakeVisible (LFODestinationLabel = new Label ("LFODestinationLabel",
                                                        TRANS("Destination")));
    LFODestinationLabel->setFont (Font (15.00f, Font::bold));
    LFODestinationLabel->setJustificationType (Justification::centredLeft);
    LFODestinationLabel->setEditable (false, false, false);
    LFODestinationLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    LFODestinationLabel->setColour (TextEditor::textColourId, Colours::black);
    LFODestinationLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (LFOAmountLabel = new Label ("LFOAmountLabel",
                                                   TRANS("Amount")));
    LFOAmountLabel->setFont (Font (15.00f, Font::bold));
    LFOAmountLabel->setJustificationType (Justification::centredLeft);
    LFOAmountLabel->setEditable (false, false, false);
    LFOAmountLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    LFOAmountLabel->setColour (TextEditor::textColourId, Colours::black);
    LFOAmountLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (LFORateLabel = new Label ("LFORateLabel",
                                                 TRANS("Rate")));
    LFORateLabel->setFont (Font (15.00f, Font::bold));
    LFORateLabel->setJustificationType (Justification::centredLeft);
    LFORateLabel->setEditable (false, false, false);
    LFORateLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    LFORateLabel->setColour (TextEditor::textColourId, Colours::black);
    LFORateLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

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

    addAndMakeVisible (ReverbWidthLabel = new Label ("ReverbWidthLabel",
                                                     TRANS("Width")));
    ReverbWidthLabel->setFont (Font (15.00f, Font::bold));
    ReverbWidthLabel->setJustificationType (Justification::centredLeft);
    ReverbWidthLabel->setEditable (false, false, false);
    ReverbWidthLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    ReverbWidthLabel->setColour (TextEditor::textColourId, Colours::black);
    ReverbWidthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (ReverbWidthSlider = new Slider ("ReverbWidthSlider"));
    ReverbWidthSlider->setRange (0, 1, 0.01);
    ReverbWidthSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    ReverbWidthSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    ReverbWidthSlider->addListener (this);

    addAndMakeVisible (GlobalVolumeLabel = new Label ("GlobalVolumeLabel",
                                                      TRANS("Volume")));
    GlobalVolumeLabel->setFont (Font (15.00f, Font::bold));
    GlobalVolumeLabel->setJustificationType (Justification::centredLeft);
    GlobalVolumeLabel->setEditable (false, false, false);
    GlobalVolumeLabel->setColour (Label::backgroundColourId, Colour (0x00000000));
    GlobalVolumeLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    GlobalVolumeLabel->setColour (TextEditor::textColourId, Colours::black);
    GlobalVolumeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (GlobalPanLabel = new Label ("GlobalPanLabel",
                                                   TRANS("Pan")));
    GlobalPanLabel->setFont (Font (15.00f, Font::bold));
    GlobalPanLabel->setJustificationType (Justification::centredLeft);
    GlobalPanLabel->setEditable (false, false, false);
    GlobalPanLabel->setColour (Label::backgroundColourId, Colour (0x00000000));
    GlobalPanLabel->setColour (Label::textColourId, Colour (0xffb2ff8b));
    GlobalPanLabel->setColour (TextEditor::textColourId, Colours::black);
    GlobalPanLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

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


    //[UserPreSize]

	//add the midi keyboard component
	addAndMakeVisible(midiKeyboard);

    //[/UserPreSize]

    setSize (800, 700);


    //[Constructor] You can add your own custom stuff here..
	getProcessor()->RequestUIUpdate();//UI update must be done each time a new editor is constructed
	startTimer(200);//starts timer with interval of 200ms
    //[/Constructor]
}

AudeaAudioProcessorEditor::~AudeaAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    ReverbGroup = nullptr;
    ChorusGroup = nullptr;
    DistortionGroup = nullptr;
    FlangerGroup = nullptr;
    DelayGroup = nullptr;
    AmpEnvelopeGroup2 = nullptr;
    FilterGroup = nullptr;
    AmpEnvelopeGroup = nullptr;
    GenerateGroup = nullptr;
    OscOneBox = nullptr;
    OscOneLabel = nullptr;
    OscTwoLabel = nullptr;
    OscTwoBox = nullptr;
    OscThreeLabel = nullptr;
    OscThreeBox = nullptr;
    OscTwoIsOn = nullptr;
    OscThreeIsOn = nullptr;
    OscVoicesLabel = nullptr;
    OscVoicesSlider = nullptr;
    OscTwoAmpSlider = nullptr;
    OscThreeAmpSlider = nullptr;
    OscTwoTuneSlider = nullptr;
    OscThreeTuneSlider = nullptr;
    OscOneAmpSlider = nullptr;
    AmpLabel = nullptr;
    TuneLabel = nullptr;
    AmpEnvAttackSlider = nullptr;
    AmpEnvDecaySlider = nullptr;
    AmpEnvSustainSlider = nullptr;
    AmpEnvReleaseSlider = nullptr;
    AmpEnvAttackLabel = nullptr;
    AmpEnvDecayLabel = nullptr;
    AmpEnvSustainLabel = nullptr;
    AmpEnvReleaseLabel = nullptr;
    FilterEnvAttackLabel = nullptr;
    FilterEnvDecayLabel = nullptr;
    FilterEnvSustainLabel = nullptr;
    FilterEnvReleaseLabel = nullptr;
    FilterEnvAttackSlider = nullptr;
    FilterEnvDecaySlider = nullptr;
    FilterEnvSustainSlider = nullptr;
    FilterEnvReleaseSlider = nullptr;
    FilterTypeBox = nullptr;
    FilterCutoffSlider = nullptr;
    FilterResonanceSlider = nullptr;
    FilterEnvelopeSlider = nullptr;
    FilterCutoffLabel = nullptr;
    FilterResLabel = nullptr;
    FilterEnvelopeLabel = nullptr;
    ReverbMixSlider = nullptr;
    ReverbSizeSlider = nullptr;
    ReverbMixLabel = nullptr;
    ReverbSizeLabel = nullptr;
    ChorusMixLabel = nullptr;
    ChorusRateSlider = nullptr;
    ChorusMixSlider = nullptr;
    ChorusRateLabel = nullptr;
    FlangerFeedbackSlider = nullptr;
    FlangerDelayLabel = nullptr;
    FlangerFeedbackLabel = nullptr;
    FlangerDelaySlider = nullptr;
    FlangerIsOn = nullptr;
    ChorusIsOn = nullptr;
    ReverbIsOn = nullptr;
    DistortionAmountSlider = nullptr;
    DistortionIsOn = nullptr;
    DistortionAmountLabel = nullptr;
    FlangerMixLabel = nullptr;
    FlangerMixSlider = nullptr;
    DelayMixSlider = nullptr;
    DelayFeedbackSlider = nullptr;
    DelayRateLeftBox = nullptr;
    DelayRateRightBox = nullptr;
    DelayIsOn = nullptr;
    DelayRateLeftLabel = nullptr;
    DelayMixLabel = nullptr;
    DelayFeedbackLabel = nullptr;
    DelayRateRightLabel = nullptr;
    LFODestinationBox = nullptr;
    LFOAmountSlider = nullptr;
    LFODestinationLabel = nullptr;
    LFOAmountLabel = nullptr;
    LFORateLabel = nullptr;
    LFORateBox = nullptr;
    ReverbWidthLabel = nullptr;
    ReverbWidthSlider = nullptr;
    GlobalVolumeLabel = nullptr;
    GlobalPanLabel = nullptr;
    GlobalVolumeSlider = nullptr;
    GlobalPanSlider = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void AudeaAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff18140f));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void AudeaAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    ReverbGroup->setBounds (640, 224, 72, 232);
    ChorusGroup->setBounds (552, 224, 88, 232);
    DistortionGroup->setBounds (464, 224, 88, 232);
    FlangerGroup->setBounds (376, 224, 88, 232);
    DelayGroup->setBounds (192, 224, 184, 232);
    AmpEnvelopeGroup2->setBounds (0, 224, 192, 232);
    FilterGroup->setBounds (496, 0, 216, 232);
    AmpEnvelopeGroup->setBounds (304, 0, 192, 232);
    GenerateGroup->setBounds (0, 0, 304, 232);
    OscOneBox->setBounds (24, 48, 72, 24);
    OscOneLabel->setBounds (24, 16, 72, 24);
    OscTwoLabel->setBounds (24, 80, 72, 24);
    OscTwoBox->setBounds (24, 112, 72, 24);
    OscThreeLabel->setBounds (24, 144, 72, 24);
    OscThreeBox->setBounds (24, 176, 72, 24);
    OscTwoIsOn->setBounds (0, 112, 24, 24);
    OscThreeIsOn->setBounds (0, 176, 24, 24);
    OscVoicesLabel->setBounds (216, 16, 64, 24);
    OscVoicesSlider->setBounds (200, 40, 88, 40);
    OscTwoAmpSlider->setBounds (112, 104, 48, 32);
    OscThreeAmpSlider->setBounds (112, 168, 48, 32);
    OscTwoTuneSlider->setBounds (192, 104, 72, 32);
    OscThreeTuneSlider->setBounds (192, 168, 72, 32);
    OscOneAmpSlider->setBounds (112, 40, 48, 32);
    AmpLabel->setBounds (112, 16, 47, 24);
    TuneLabel->setBounds (200, 80, 47, 24);
    AmpEnvAttackSlider->setBounds (320, 56, 40, 144);
    AmpEnvDecaySlider->setBounds (360, 56, 40, 144);
    AmpEnvSustainSlider->setBounds (400, 56, 40, 144);
    AmpEnvReleaseSlider->setBounds (440, 56, 40, 144);
    AmpEnvAttackLabel->setBounds (328, 24, 24, 24);
    AmpEnvDecayLabel->setBounds (368, 24, 24, 24);
    AmpEnvSustainLabel->setBounds (408, 24, 24, 24);
    AmpEnvReleaseLabel->setBounds (448, 24, 24, 24);
    FilterEnvAttackLabel->setBounds (512, 120, 24, 24);
    FilterEnvDecayLabel->setBounds (560, 120, 24, 24);
    FilterEnvSustainLabel->setBounds (608, 120, 24, 24);
    FilterEnvReleaseLabel->setBounds (656, 120, 24, 24);
    FilterEnvAttackSlider->setBounds (504, 144, 40, 80);
    FilterEnvDecaySlider->setBounds (552, 144, 40, 80);
    FilterEnvSustainSlider->setBounds (600, 144, 40, 80);
    FilterEnvReleaseSlider->setBounds (648, 144, 40, 80);
    FilterTypeBox->setBounds (528, 16, 150, 16);
    FilterCutoffSlider->setBounds (520, 72, 39, 40);
    FilterResonanceSlider->setBounds (576, 72, 39, 40);
    FilterEnvelopeSlider->setBounds (640, 72, 39, 40);
    FilterCutoffLabel->setBounds (512, 40, 48, 24);
    FilterResLabel->setBounds (576, 40, 48, 24);
    FilterEnvelopeLabel->setBounds (632, 40, 72, 24);
    ReverbMixSlider->setBounds (656, 384, 39, 40);
    ReverbSizeSlider->setBounds (656, 256, 39, 40);
    ReverbMixLabel->setBounds (656, 360, 40, 24);
    ReverbSizeLabel->setBounds (656, 240, 40, 24);
    ChorusMixLabel->setBounds (576, 344, 40, 24);
    ChorusRateSlider->setBounds (576, 288, 39, 40);
    ChorusMixSlider->setBounds (576, 376, 39, 40);
    ChorusRateLabel->setBounds (576, 256, 40, 24);
    FlangerFeedbackSlider->setBounds (400, 264, 39, 40);
    FlangerDelayLabel->setBounds (392, 304, 48, 24);
    FlangerFeedbackLabel->setBounds (408, 240, 32, 32);
    FlangerDelaySlider->setBounds (400, 328, 39, 40);
    FlangerIsOn->setBounds (384, 232, 24, 24);
    ChorusIsOn->setBounds (560, 232, 24, 24);
    ReverbIsOn->setBounds (648, 232, 24, 24);
    DistortionAmountSlider->setBounds (488, 328, 39, 40);
    DistortionIsOn->setBounds (472, 232, 24, 24);
    DistortionAmountLabel->setBounds (472, 296, 72, 24);
    FlangerMixLabel->setBounds (400, 360, 40, 24);
    FlangerMixSlider->setBounds (400, 384, 39, 40);
    DelayMixSlider->setBounds (224, 384, 39, 40);
    DelayFeedbackSlider->setBounds (288, 384, 39, 40);
    DelayRateLeftBox->setBounds (224, 264, 120, 24);
    DelayRateRightBox->setBounds (224, 320, 120, 24);
    DelayIsOn->setBounds (200, 240, 24, 24);
    DelayRateLeftLabel->setBounds (232, 232, 96, 32);
    DelayMixLabel->setBounds (224, 352, 32, 32);
    DelayFeedbackLabel->setBounds (296, 352, 32, 32);
    DelayRateRightLabel->setBounds (232, 288, 96, 32);
    LFODestinationBox->setBounds (32, 304, 120, 24);
    LFOAmountSlider->setBounds (24, 384, 39, 40);
    LFODestinationLabel->setBounds (48, 264, 96, 32);
    LFOAmountLabel->setBounds (16, 344, 64, 32);
    LFORateLabel->setBounds (112, 344, 48, 32);
    LFORateBox->setBounds (104, 392, 64, 24);
    ReverbWidthLabel->setBounds (656, 296, 40, 24);
    ReverbWidthSlider->setBounds (656, 320, 39, 40);
    GlobalVolumeLabel->setBounds (0, 456, 72, 24);
    GlobalPanLabel->setBounds (368, 456, 72, 24);
    GlobalVolumeSlider->setBounds (56, 464, 104, 80);
    GlobalPanSlider->setBounds (408, 464, 104, 80);
    //[UserResized] Add your own custom resize handling here..
	const int keyboardHeight = 70;
	midiKeyboard.setBounds(4, getHeight() - keyboardHeight - 4, getWidth() - 8, keyboardHeight);
    //[/UserResized]
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
    else if (comboBoxThatHasChanged == OscThreeBox)
    {
        //[UserComboBoxCode_OscThreeBox] -- add your combo box handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::Osc3WaveForm, id);
        //[/UserComboBoxCode_OscThreeBox]
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
    else if (buttonThatWasClicked == OscThreeIsOn)
    {
        //[UserButtonCode_OscThreeIsOn] -- add your button handler code here..
		if (buttonThatWasClicked->getToggleState())
			ourProcessor->setParameter(AudeaAudioProcessor::Osc3IsOn, 1.0f);
		else
			ourProcessor->setParameter(AudeaAudioProcessor::Osc3IsOn, 0.0f);
        //[/UserButtonCode_OscThreeIsOn]
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

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void AudeaAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
	AudeaAudioProcessor* ourProcessor = getProcessor();
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == OscVoicesSlider)
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
    else if (sliderThatWasMoved == OscThreeAmpSlider)
    {
        //[UserSliderCode_OscThreeAmpSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::Osc3Amp,(float) sliderThatWasMoved->getValue());
        //[/UserSliderCode_OscThreeAmpSlider]
    }
    else if (sliderThatWasMoved == OscTwoTuneSlider)
    {
        //[UserSliderCode_OscTwoTuneSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::Osc2Tune,(float) sliderThatWasMoved->getValue());
        //[/UserSliderCode_OscTwoTuneSlider]
    }
    else if (sliderThatWasMoved == OscThreeTuneSlider)
    {
        //[UserSliderCode_OscThreeTuneSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::Osc3Tune,(float) sliderThatWasMoved->getValue());
        //[/UserSliderCode_OscThreeTuneSlider]
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
    else if (sliderThatWasMoved == ReverbMixSlider)
    {
        //[UserSliderCode_ReverbMixSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::ReverbMix, (float)sliderThatWasMoved->getValue());
        //[/UserSliderCode_ReverbMixSlider]
    }
    else if (sliderThatWasMoved == ReverbSizeSlider)
    {
        //[UserSliderCode_ReverbSizeSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::ReverbSize, (float)sliderThatWasMoved->getValue());
        //[/UserSliderCode_ReverbSizeSlider]
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
    else if (sliderThatWasMoved == FlangerFeedbackSlider)
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
    else if (sliderThatWasMoved == DistortionAmountSlider)
    {
        //[UserSliderCode_DistortionAmountSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::DistortionAmt, (float)sliderThatWasMoved->getValue());
        //[/UserSliderCode_DistortionAmountSlider]
    }
    else if (sliderThatWasMoved == FlangerMixSlider)
    {
        //[UserSliderCode_FlangerMixSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::FlangerMix, (float)sliderThatWasMoved->getValue());
        //[/UserSliderCode_FlangerMixSlider]
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
    else if (sliderThatWasMoved == ReverbWidthSlider)
    {
        //[UserSliderCode_ReverbWidthSlider] -- add your slider handling code here..
		ourProcessor->setParameter(AudeaAudioProcessor::ReverbWidth, (float)sliderThatWasMoved->getValue());
        //[/UserSliderCode_ReverbWidthSlider]
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



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void AudeaAudioProcessorEditor::timerCallback()
{
	AudeaAudioProcessor* ourProcessor = getProcessor();

	if (ourProcessor->NeedsUIUpdate())
	{//load your UI components with internal state information form plug-in - example:
		OscTwoIsOn->setToggleState(1.0f == ourProcessor->getParameter(AudeaAudioProcessor::Osc2IsOn), juce::dontSendNotification);
		OscThreeIsOn->setToggleState(1.0f == ourProcessor->getParameter(AudeaAudioProcessor::Osc3IsOn), juce::dontSendNotification);
		OscVoicesSlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::OscVoices));
		OscOneBox->setSelectedId((int)ourProcessor->getParameter(AudeaAudioProcessor::Osc1WaveForm), juce::dontSendNotification);
		OscTwoBox->setSelectedId((int)ourProcessor->getParameter(AudeaAudioProcessor::Osc2WaveForm), juce::dontSendNotification);
		OscThreeBox->setSelectedId((int)ourProcessor->getParameter(AudeaAudioProcessor::Osc3WaveForm), juce::dontSendNotification);
		OscTwoAmpSlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::Osc2Amp));
		OscThreeAmpSlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::Osc3Amp));
		OscTwoTuneSlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::Osc2Tune));
		OscThreeTuneSlider->setValue(ourProcessor->getParameter(AudeaAudioProcessor::Osc3Tune));
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
                 fixedSize="0" initialWidth="800" initialHeight="700">
  <BACKGROUND backgroundColour="ff18140f"/>
  <GROUPCOMPONENT name="ReverbGroup" id="acdcfe1f8849f242" memberName="ReverbGroup"
                  virtualName="" explicitFocusOrder="0" pos="640 224 72 232" outlinecol="669c1900"
                  textcol="ffff6843" title="Reverb"/>
  <GROUPCOMPONENT name="ChorusGroup" id="629e066a47fb15ad" memberName="ChorusGroup"
                  virtualName="" explicitFocusOrder="0" pos="552 224 88 232" outlinecol="669c1900"
                  textcol="ffff6843" title="Chorus"/>
  <GROUPCOMPONENT name="DistortionGroup" id="8c6d4bb8760c6864" memberName="DistortionGroup"
                  virtualName="" explicitFocusOrder="0" pos="464 224 88 232" outlinecol="669c1900"
                  textcol="ffff6843" title="Distortion"/>
  <GROUPCOMPONENT name="FlangerGroup" id="2eaa69bf8247db64" memberName="FlangerGroup"
                  virtualName="" explicitFocusOrder="0" pos="376 224 88 232" outlinecol="669c1900"
                  textcol="ffff6843" title="Flanger"/>
  <GROUPCOMPONENT name="DelayGroup" id="c21ee9a3378d5a6c" memberName="DelayGroup"
                  virtualName="" explicitFocusOrder="0" pos="192 224 184 232" outlinecol="669c1900"
                  textcol="ffff6843" title="Delay"/>
  <GROUPCOMPONENT name="AmpEnvelopeGroup" id="1f18ab0c32b8d2ef" memberName="AmpEnvelopeGroup2"
                  virtualName="" explicitFocusOrder="0" pos="0 224 192 232" outlinecol="669c1900"
                  textcol="ffff6843" title="LFO"/>
  <GROUPCOMPONENT name="FilterGroup" id="34a14c2689008b75" memberName="FilterGroup"
                  virtualName="" explicitFocusOrder="0" pos="496 0 216 232" outlinecol="669c1900"
                  textcol="ffff6843" title="Filter"/>
  <GROUPCOMPONENT name="AmpEnvelopeGroup" id="f0cf1bd5a2430236" memberName="AmpEnvelopeGroup"
                  virtualName="" explicitFocusOrder="0" pos="304 0 192 232" outlinecol="669c1900"
                  textcol="ffff6843" title="Amp - Envelope"/>
  <GROUPCOMPONENT name="GenerateGroup" id="1b59c0a40d979543" memberName="GenerateGroup"
                  virtualName="" explicitFocusOrder="0" pos="0 0 304 232" outlinecol="669c1900"
                  textcol="ffff6843" title="Generate" textpos="33"/>
  <COMBOBOX name="OscOneBox" id="3f82eca8fbc59029" memberName="OscOneBox"
            virtualName="" explicitFocusOrder="0" pos="24 48 72 24" editable="0"
            layout="33" items="Sine&#10;Triangle&#10;Square&#10;Saw&#10;Noise"
            textWhenNonSelected="Sine" textWhenNoItems="(no choices)"/>
  <LABEL name="OscOneLabel" id="23854e377a376a9a" memberName="OscOneLabel"
         virtualName="" explicitFocusOrder="0" pos="24 16 72 24" bkgCol="0"
         textCol="ffb2ff8b" edTextCol="ff000000" edBkgCol="0" labelText="OSC 1"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="OscTwoLabel" id="80b92a6d3da041d7" memberName="OscTwoLabel"
         virtualName="" explicitFocusOrder="0" pos="24 80 72 24" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="OSC 2" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <COMBOBOX name="OscTwoBox" id="9658df6ae373fec0" memberName="OscTwoBox"
            virtualName="" explicitFocusOrder="0" pos="24 112 72 24" editable="0"
            layout="33" items="Sine&#10;Triangle&#10;Square&#10;Saw&#10;Noise"
            textWhenNonSelected="Sine" textWhenNoItems="(no choices)"/>
  <LABEL name="OscThreeLabel" id="a7d5854077b1ec9e" memberName="OscThreeLabel"
         virtualName="" explicitFocusOrder="0" pos="24 144 72 24" bkgCol="0"
         textCol="ffb2ff8b" edTextCol="ff000000" edBkgCol="0" labelText="OSC 3"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="1" italic="0" justification="33"/>
  <COMBOBOX name="OscThreeBox" id="c3eda3b88ca10927" memberName="OscThreeBox"
            virtualName="" explicitFocusOrder="0" pos="24 176 72 24" editable="0"
            layout="33" items="Sine&#10;Triangle&#10;Square&#10;Saw&#10;Noise"
            textWhenNonSelected="Sine" textWhenNoItems="(no choices)"/>
  <TOGGLEBUTTON name="OscTwoIsOn" id="5c67889c9b18a785" memberName="OscTwoIsOn"
                virtualName="" explicitFocusOrder="0" pos="0 112 24 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="OscThreeIsOn" id="c9adbddbb706dd06" memberName="OscThreeIsOn"
                virtualName="" explicitFocusOrder="0" pos="0 176 24 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="OscVoicesLabel" id="ad98ae9f583cce49" memberName="OscVoicesLabel"
         virtualName="" explicitFocusOrder="0" pos="216 16 64 24" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="Voices" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <SLIDER name="OscVoicesSlider" id="6bc9606b0691e0d2" memberName="OscVoicesSlider"
          virtualName="" explicitFocusOrder="0" pos="200 40 88 40" min="1"
          max="14" int="1" style="IncDecButtons" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="OscTwoAmpSlider" id="518b8887fab7548c" memberName="OscTwoAmpSlider"
          virtualName="" explicitFocusOrder="0" pos="112 104 48 32" min="0"
          max="1" int="0.01" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="20" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="OscThreeAmpSlider" id="b4ae512fc2b37548" memberName="OscThreeAmpSlider"
          virtualName="" explicitFocusOrder="0" pos="112 168 48 32" min="0"
          max="1" int="0.01" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="20" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="OscTwoTuneSlider" id="ac82cf89dc2fc12c" memberName="OscTwoTuneSlider"
          virtualName="" explicitFocusOrder="0" pos="192 104 72 32" min="-24"
          max="24" int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="28" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="OscThreeTuneSlider" id="436a66f4321d169b" memberName="OscThreeTuneSlider"
          virtualName="" explicitFocusOrder="0" pos="192 168 72 32" min="-24"
          max="24" int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="28" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="OscOneAmpSlider" id="a081a349e74fa1fb" memberName="OscOneAmpSlider"
          virtualName="" explicitFocusOrder="0" pos="112 40 48 32" min="0"
          max="1" int="0.01" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="30" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="AmpLabel" id="8c8284e7aa750e8e" memberName="AmpLabel" virtualName=""
         explicitFocusOrder="0" pos="112 16 47 24" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="Amp" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="TuneLabel" id="733fecb2ba92fcae" memberName="TuneLabel"
         virtualName="" explicitFocusOrder="0" pos="200 80 47 24" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="Tune" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <SLIDER name="AmpEnvAttackSlider" id="4f8a01927368655c" memberName="AmpEnvAttackSlider"
          virtualName="" explicitFocusOrder="0" pos="320 56 40 144" min="0"
          max="5000" int="1" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="0.69999999999999996"/>
  <SLIDER name="AmpEnvDecaySlider" id="876fe0c32f235f00" memberName="AmpEnvDecaySlider"
          virtualName="" explicitFocusOrder="0" pos="360 56 40 144" min="0"
          max="5000" int="1" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="0.69999999999999996"/>
  <SLIDER name="AmpEnvSustainSlider" id="bc13734e5ac8dc58" memberName="AmpEnvSustainSlider"
          virtualName="" explicitFocusOrder="0" pos="400 56 40 144" min="0"
          max="1" int="0.01" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="AmpEnvReleaseSlider" id="3147e31e839bd086" memberName="AmpEnvReleaseSlider"
          virtualName="" explicitFocusOrder="0" pos="440 56 40 144" min="0"
          max="5000" int="1" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="0.69999999999999996"/>
  <LABEL name="AmpEnvAttackLabel" id="675c93b93a42f2b4" memberName="AmpEnvAttackLabel"
         virtualName="" explicitFocusOrder="0" pos="328 24 24 24" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="A" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="AmpEnvDecayLabel" id="cf1eb2ff18322695" memberName="AmpEnvDecayLabel"
         virtualName="" explicitFocusOrder="0" pos="368 24 24 24" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="D" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="AmpEnvSustainLabel" id="c28e48a072fb03be" memberName="AmpEnvSustainLabel"
         virtualName="" explicitFocusOrder="0" pos="408 24 24 24" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="S" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="AmpEnvReleaseLabel" id="bdb70944e9013ae7" memberName="AmpEnvReleaseLabel"
         virtualName="" explicitFocusOrder="0" pos="448 24 24 24" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="R" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="FilterEnvAttackLabel" id="4695c6f213cd256b" memberName="FilterEnvAttackLabel"
         virtualName="" explicitFocusOrder="0" pos="512 120 24 24" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="A" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="FilterEnvDecayLabel" id="70ec896ab585366f" memberName="FilterEnvDecayLabel"
         virtualName="" explicitFocusOrder="0" pos="560 120 24 24" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="D" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="FilterEnvSustainLabel" id="960e70083f617ad7" memberName="FilterEnvSustainLabel"
         virtualName="" explicitFocusOrder="0" pos="608 120 24 24" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="S" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="FilterEnvReleaseLabel" id="3601e6d859db0297" memberName="FilterEnvReleaseLabel"
         virtualName="" explicitFocusOrder="0" pos="656 120 24 24" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="R" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <SLIDER name="FilterEnvAttackSlider" id="17c6e681fdd783f7" memberName="FilterEnvAttackSlider"
          virtualName="" explicitFocusOrder="0" pos="504 144 40 80" min="0"
          max="5000" int="1" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="0.59999999999999998"/>
  <SLIDER name="FilterEnvDecaySlider" id="4073d86d63ba585" memberName="FilterEnvDecaySlider"
          virtualName="" explicitFocusOrder="0" pos="552 144 40 80" min="0"
          max="5000" int="1" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="0.59999999999999998"/>
  <SLIDER name="FilterEnvSustainSlider" id="c9aba9c92603734c" memberName="FilterEnvSustainSlider"
          virtualName="" explicitFocusOrder="0" pos="600 144 40 80" min="0"
          max="5000" int="1" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="FilterEnvReleaseSlider" id="9eea865174507345" memberName="FilterEnvReleaseSlider"
          virtualName="" explicitFocusOrder="0" pos="648 144 40 80" min="0"
          max="5000" int="1" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="0.59999999999999998"/>
  <COMBOBOX name="FilterTypeBox" id="8076a0c91218e0e3" memberName="FilterTypeBox"
            virtualName="" explicitFocusOrder="0" pos="528 16 150 16" editable="0"
            layout="33" items="Lowpass&#10;Bandpass&#10;Highpass&#10;BandReject&#10;Allpass"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="FilterCutoffSlider" id="290abad0411db05d" memberName="FilterCutoffSlider"
          virtualName="" explicitFocusOrder="0" pos="520 72 39 40" min="40"
          max="20000" int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="0.5"/>
  <SLIDER name="FilterResonanceSlider" id="72b8c8fcc7e3a9a5" memberName="FilterResonanceSlider"
          virtualName="" explicitFocusOrder="0" pos="576 72 39 40" min="0.5"
          max="5" int="0.01" style="RotaryVerticalDrag" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="FilterEnvelopeSlider" id="654dbb7b23a5e6b2" memberName="FilterEnvelopeSlider"
          virtualName="" explicitFocusOrder="0" pos="640 72 39 40" min="0"
          max="5000" int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="FilterCutoffLabel" id="f6e337c9abe5937" memberName="FilterCutoffLabel"
         virtualName="" explicitFocusOrder="0" pos="512 40 48 24" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="Cutoff" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="FilterResLabel" id="f43fb1111063d372" memberName="FilterResLabel"
         virtualName="" explicitFocusOrder="0" pos="576 40 48 24" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="Res" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="FilterEnvelopeLabel" id="ba5c138277650060" memberName="FilterEnvelopeLabel"
         virtualName="" explicitFocusOrder="0" pos="632 40 72 24" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="Envelope" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <SLIDER name="ReverbMixSlider" id="d849c3dbe7a16d9f" memberName="ReverbMixSlider"
          virtualName="" explicitFocusOrder="0" pos="656 384 39 40" min="0"
          max="1" int="0.01" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="ReverbSizeSlider" id="14c637fa440025d0" memberName="ReverbSizeSlider"
          virtualName="" explicitFocusOrder="0" pos="656 256 39 40" min="0"
          max="1" int="0.01" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="ReverbMixLabel" id="b0762b0e2e30b987" memberName="ReverbMixLabel"
         virtualName="" explicitFocusOrder="0" pos="656 360 40 24" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="Mix" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="ReverbSizeLabel" id="cacb75ef18d579f3" memberName="ReverbSizeLabel"
         virtualName="" explicitFocusOrder="0" pos="656 240 40 24" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="Size" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="ChorusMixLabel" id="b4ad33fdd8052ed9" memberName="ChorusMixLabel"
         virtualName="" explicitFocusOrder="0" pos="576 344 40 24" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="Mix" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <SLIDER name="ChorusRateSlider" id="c43bd9eda52e3985" memberName="ChorusRateSlider"
          virtualName="" explicitFocusOrder="0" pos="576 288 39 40" min="1.25"
          max="25" int="0.10000000000000001" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="ChorusMixSlider" id="e459f174052e0ff2" memberName="ChorusMixSlider"
          virtualName="" explicitFocusOrder="0" pos="576 376 39 40" min="0"
          max="0.5" int="0.01" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="ChorusRateLabel" id="e0f7b956e48ef71c" memberName="ChorusRateLabel"
         virtualName="" explicitFocusOrder="0" pos="576 256 40 24" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="Rate" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <SLIDER name="FlangerFeedbackSlider" id="55f1dc6792ca6a21" memberName="FlangerFeedbackSlider"
          virtualName="" explicitFocusOrder="0" pos="400 264 39 40" min="0"
          max="0.98999999999999999" int="0.01" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="FlangerDelayLabel" id="272eb6964a7114f0" memberName="FlangerDelayLabel"
         virtualName="" explicitFocusOrder="0" pos="392 304 48 24" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="Delay" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="FlangerFeedbackLabel" id="fdc662dd4cb4641" memberName="FlangerFeedbackLabel"
         virtualName="" explicitFocusOrder="0" pos="408 240 32 32" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="FB" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <SLIDER name="FlangerDelaySlider" id="c1a82d56f3ba0cc4" memberName="FlangerDelaySlider"
          virtualName="" explicitFocusOrder="0" pos="400 328 39 40" min="1"
          max="10" int="0.10000000000000001" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <TOGGLEBUTTON name="FlangerIsOn" id="a34be7e02470739c" memberName="FlangerIsOn"
                virtualName="" explicitFocusOrder="0" pos="384 232 24 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="ChorusIsOn" id="505699439b1f920e" memberName="ChorusIsOn"
                virtualName="" explicitFocusOrder="0" pos="560 232 24 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="ReverbIsOn" id="c6e156e132276275" memberName="ReverbIsOn"
                virtualName="" explicitFocusOrder="0" pos="648 232 24 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <SLIDER name="DistortionAmountSlider" id="7332128eca099479" memberName="DistortionAmountSlider"
          virtualName="" explicitFocusOrder="0" pos="488 328 39 40" min="0"
          max="99" int="0.10000000000000001" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <TOGGLEBUTTON name="DistortionIsOn" id="6cc597398b435cf2" memberName="DistortionIsOn"
                virtualName="" explicitFocusOrder="0" pos="472 232 24 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="DistortionAmountLabel" id="be66008f7bf2db32" memberName="DistortionAmountLabel"
         virtualName="" explicitFocusOrder="0" pos="472 296 72 24" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="Amount&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="FlangerMixLabel" id="c0699ca2f76a7f24" memberName="FlangerMixLabel"
         virtualName="" explicitFocusOrder="0" pos="400 360 40 24" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="Mix" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <SLIDER name="FlangerMixSlider" id="319d434bc47c41de" memberName="FlangerMixSlider"
          virtualName="" explicitFocusOrder="0" pos="400 384 39 40" min="0"
          max="0.5" int="0.01" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="DelayMixSlider" id="6159a703559ee993" memberName="DelayMixSlider"
          virtualName="" explicitFocusOrder="0" pos="224 384 39 40" min="0"
          max="1" int="0.01" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="DelayFeedbackSlider" id="f08fbb5aea530b08" memberName="DelayFeedbackSlider"
          virtualName="" explicitFocusOrder="0" pos="288 384 39 40" min="0"
          max="0.98999999999999999" int="0.01" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="DelayRateLeftBox" id="62978c8037a61708" memberName="DelayRateLeftBox"
            virtualName="" explicitFocusOrder="0" pos="224 264 120 24" editable="0"
            layout="33" items="1/1&#10;1/2&#10;1/4&#10;1/8&#10;1/16&#10;1/32"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="DelayRateRightBox" id="225ec4c2f6a5cb97" memberName="DelayRateRightBox"
            virtualName="" explicitFocusOrder="0" pos="224 320 120 24" editable="0"
            layout="33" items="1/1&#10;1/2&#10;1/4&#10;1/8&#10;1/16&#10;1/32"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <TOGGLEBUTTON name="DelayIsOn" id="6cbb8654d1fd046d" memberName="DelayIsOn"
                virtualName="" explicitFocusOrder="0" pos="200 240 24 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="DelayRateLeftLabel" id="286c9d511ea89ea2" memberName="DelayRateLeftLabel"
         virtualName="" explicitFocusOrder="0" pos="232 232 96 32" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="Rate - Left" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="DelayMixLabel" id="ea4b4356928b2f72" memberName="DelayMixLabel"
         virtualName="" explicitFocusOrder="0" pos="224 352 32 32" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="Mix" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="DelayFeedbackLabel" id="c65d61c2d4dcc603" memberName="DelayFeedbackLabel"
         virtualName="" explicitFocusOrder="0" pos="296 352 32 32" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="FB" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="DelayRateRightLabel" id="135a82273eff0c07" memberName="DelayRateRightLabel"
         virtualName="" explicitFocusOrder="0" pos="232 288 96 32" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="Rate - Right" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <COMBOBOX name="LFODestinationBox" id="9bcda03ffed93fb9" memberName="LFODestinationBox"
            virtualName="" explicitFocusOrder="0" pos="32 304 120 24" editable="0"
            layout="33" items="None&#10;FilterCutoff&#10;Volume&#10;Pan"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="LFOAmountSlider" id="5f882442e23151cd" memberName="LFOAmountSlider"
          virtualName="" explicitFocusOrder="0" pos="24 384 39 40" min="0"
          max="1" int="0.01" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="LFODestinationLabel" id="d6929965cd407937" memberName="LFODestinationLabel"
         virtualName="" explicitFocusOrder="0" pos="48 264 96 32" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="Destination" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="LFOAmountLabel" id="7f50080a208b8bbf" memberName="LFOAmountLabel"
         virtualName="" explicitFocusOrder="0" pos="16 344 64 32" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="Amount" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="LFORateLabel" id="5ff6d628d761acfc" memberName="LFORateLabel"
         virtualName="" explicitFocusOrder="0" pos="112 344 48 32" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="Rate" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <COMBOBOX name="LFORateBox" id="a255da4f656aae8d" memberName="LFORateBox"
            virtualName="" explicitFocusOrder="0" pos="104 392 64 24" editable="0"
            layout="33" items="1/1&#10;1/2&#10;1/3&#10;1/4&#10;1/6&#10;1/8&#10;1/12&#10;1/16&#10;1/24&#10;1/32"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="ReverbWidthLabel" id="9d1ccd10ad6d1c44" memberName="ReverbWidthLabel"
         virtualName="" explicitFocusOrder="0" pos="656 296 40 24" textCol="ffb2ff8b"
         edTextCol="ff000000" edBkgCol="0" labelText="Width" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <SLIDER name="ReverbWidthSlider" id="ec827733ecdec647" memberName="ReverbWidthSlider"
          virtualName="" explicitFocusOrder="0" pos="656 320 39 40" min="0"
          max="1" int="0.01" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="GlobalVolumeLabel" id="80c153321d0b3d2c" memberName="GlobalVolumeLabel"
         virtualName="" explicitFocusOrder="0" pos="0 456 72 24" bkgCol="0"
         textCol="ffb2ff8b" edTextCol="ff000000" edBkgCol="0" labelText="Volume"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="GlobalPanLabel" id="553a35605cfad4af" memberName="GlobalPanLabel"
         virtualName="" explicitFocusOrder="0" pos="368 456 72 24" bkgCol="0"
         textCol="ffb2ff8b" edTextCol="ff000000" edBkgCol="0" labelText="Pan"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="1" italic="0" justification="33"/>
  <SLIDER name="GlobalVolumeSlider" id="1f6431dfbd6c5f62" memberName="GlobalVolumeSlider"
          virtualName="" explicitFocusOrder="0" pos="56 464 104 80" min="0"
          max="1.5" int="0.01" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="GlobalPanSlider" id="72a0c666b8af61fd" memberName="GlobalPanSlider"
          virtualName="" explicitFocusOrder="0" pos="408 464 104 80" min="0"
          max="1" int="0.01" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
