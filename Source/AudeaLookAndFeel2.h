/*
  ==============================================================================

    AudeaLookAndFeel2.h
    Created: 13 Feb 2015 12:24:16pm
    Author:  Felix Rolshausen

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h";

#ifndef AUDEALOOKANDFEEL2_H_INCLUDED
#define AUDEALOOKANDFEEL2_H_INCLUDED

class AudeaLookAndFeel2 : public LookAndFeel_V3{

public:
	AudeaLookAndFeel2();
	~AudeaLookAndFeel2();

	void drawRotarySlider(Graphics& g,
		int x,
		int y,
		int width,
		int height,
		float sliderPosProportional,
		float rotaryStartAngle,
		float rotaryEndAngle,
		Slider& slider);

	void drawLinearSliderBackground(Graphics &,
		int x,
		int y,
		int width,
		int height,
		float sliderPos,
		float minSliderPos,
		float maxSliderPos,
		const Slider::SliderStyle,
		Slider &);

	void drawLinearSliderThumb(Graphics& g,
		int x,
		int y,
		int width,
		int height,
		float sliderPos,
		float minSliderPos,
		float maxSliderPos,
		const Slider::SliderStyle style,
		Slider& slider);

	void drawButtonBackground(Graphics &,
		Button &,
		const Colour & backgroundColour,
		bool isMouseOverButton,
		bool isButtonDown
		);

	void drawLabel(Graphics &,
		Label &);


	void drawToggleButton(Graphics &,
		ToggleButton &,
		bool  	isMouseOverButton,
		bool  	isButtonDown
		);

private:
	//Location of the DLL
	File pluginLocation = File::getSpecialLocation(File::SpecialLocationType::currentApplicationFile);
	File resourcesDirectory = pluginLocation.getParentDirectory();//.getParentDirectory().getParentDirectory().getParentDirectory();
	//Constants
	String SmallSliderImgPath = "Resources/SliderSmall.png";
	String SliderBarImgPath = "Resources/VertSlider.png";
	String HorizontalSliderTenHunImgPath = "Resources/HorizontalSliderTenHun.png";
	String VerticalSliderKnobImgPath = "Resources/VerticalSliderKnob.png";
	String HorizontalSliderKnobImgPath = "Resources/HorizontalSliderKnob.png";
	String LoadPresetButtonImgPath = "Resources/PresetLadenButton.png";
	String SavePresetButtonImgPath = "Resources/PresetSpeichernButton.png";
	String FlangerLabelImgPath = "Resources/FlangerLabel.png";
	String DistortionLabelImgPath = "Resources/DistortionLabel.png";
	String ChorusLabelImgPath = "Resources/ChorusLabel.png";
	String ReverbLabelImgPath = "Resources/ReverbLabel.png";
	String MixLabelImgPath = "Resources/MixLabel.png";
	String DelayLabelImgPath = "Resources/DelayLabel.png";
	String FeedbackLabelImgPath = "Resources/FeedbackLabel.png";
	String AmountLabelImgPath = "Resources/AmountLabel.png";
	String RateLabelImgPath = "Resources/RateLabel.png";
	String SizeLabelImgPath = "Resources/SizeLabel.png";
	String WidthLabelImgPath = "Resources/WidthLabel.png";
	String backGroundImgPath = "Resources/BackgroundPure.jpg";
	String FlangerButtonUpImgPath = "Resources/FlangerButtonUp.png";
	String DistortionButtonUpImgPath = "Resources/DistortionButtonUp.png";
	String ReverbButtonUpImgPath = "Resources/ReverbButtonUp.png";
	String ChorusButtonUpImgPath = "Resources/ChorusButtonUp.png";
	String FlangerButtonDownImgPath = "Resources/FlangerButtonDown.png";
	String DistortionButtonDownImgPath = "Resources/DistortionButtonDown.png";
	String ReverbButtonDownImgPath = "Resources/ReverbButtonDown.png";
	String ChorusButtonDownImgPath = "Resources/ChorusButtonDown.png";
	File SmallSliderImgFile;
	File SliderBarImgFile;
	File HorizontalSliderTenHunImgFile;
	File VerticalSliderKnobImgFile;
	File HorizontalSliderKnobImgFile;
	File LoadPresetButtonImgFile;
	File SavePresetButtonImgFile;
	File FlangerLabelImgFile;
	File DistortionLabelImgFile;
	File ChorusLabelImgFile;
	File ReverbLabelImgFile;
	File MixLabelImgFile;
	File DelayLabelImgFile;
	File FeedbackLabelImgFile;
	File AmountLabelImgFile;
	File RateLabelImgFile;
	File SizeLabelImgFile;
	File WidthLabelImgFile;
	File FlangerButtonUpImgFile;
	File DistortionButtonUpImgFile;
	File ReverbButtonUpImgFile;
	File ChorusButtonUpImgFile;
	File FlangerButtonDownImgFile;
	File DistortionButtonDownImgFile;
	File ReverbButtonDownImgFile;
	File ChorusButtonDownImgFile;
	Image SliderBarImg;
	Image SmallSliderImg;
	Image HorizontalSliderTenHunImg;
	Image VerticalSliderKnobImg;
	Image HorizontalSliderKnobImg;
	Image LoadPresetButtonImg;
	Image SavePresetButtonImg;
	Image FlangerLabelImg;
	Image ChorusLabelImg;
	Image DistortionLabelImg;
	Image ReverbLabelImg;
	Image MixLabelImg;
	Image DelayLabelImg;
	Image FeedbackLabelImg;
	Image AmountLabelImg;
	Image RateLabelImg;
	Image SizeLabelImg;
	Image WidthLabelImg;
	Image FlangerButtonUpImg;
	Image DistortionButtonUpImg;
	Image ReverbButtonUpImg;
	Image ChorusButtonUpImg;
	Image FlangerButtonDownImg;
	Image DistortionButtonDownImg;
	Image ReverbButtonDownImg;
	Image ChorusButtonDownImg;


};



#endif  // AUDEALOOKANDFEEL2_H_INCLUDED
