/*
  ==============================================================================

    AudeaLookAndFeel2.cpp
    Created: 13 Feb 2015 12:24:16pm
    Author:  Felix Rolshausen

  ==============================================================================
*/

#include "AudeaLookAndFeel2.h"

AudeaLookAndFeel2::AudeaLookAndFeel2()
{
	SmallSliderImgFile = resourcesDirectory.getChildFile(SmallSliderImgPath);
	SliderBarImgFile = resourcesDirectory.getChildFile(SliderBarImgPath);
	HorizontalSliderTenHunImgFile = resourcesDirectory.getChildFile(HorizontalSliderTenHunImgPath);
	HorizontalSliderKnobImgFile = resourcesDirectory.getChildFile(HorizontalSliderKnobImgPath);
	VerticalSliderKnobImgFile = resourcesDirectory.getChildFile(VerticalSliderKnobImgPath);
	LoadPresetButtonImgFile = resourcesDirectory.getChildFile(LoadPresetButtonImgPath);
	SavePresetButtonImgFile = resourcesDirectory.getChildFile(SavePresetButtonImgPath);
	FlangerLabelImgFile = resourcesDirectory.getChildFile(FlangerLabelImgPath);
	DistortionLabelImgFile = resourcesDirectory.getChildFile(DistortionLabelImgPath);
	ChorusLabelImgFile = resourcesDirectory.getChildFile(ChorusLabelImgPath);
	ReverbLabelImgFile = resourcesDirectory.getChildFile(ReverbLabelImgPath);
	MixLabelImgFile = resourcesDirectory.getChildFile(MixLabelImgPath);
	DelayLabelImgFile = resourcesDirectory.getChildFile(DelayLabelImgPath);
	FeedbackLabelImgFile = resourcesDirectory.getChildFile(FeedbackLabelImgPath);
	AmountLabelImgFile = resourcesDirectory.getChildFile(AmountLabelImgPath);
	RateLabelImgFile = resourcesDirectory.getChildFile(RateLabelImgPath);
	SizeLabelImgFile = resourcesDirectory.getChildFile(SizeLabelImgPath);
	WidthLabelImgFile = resourcesDirectory.getChildFile(WidthLabelImgPath);
	FlangerButtonUpImgFile = resourcesDirectory.getChildFile(FlangerButtonUpImgPath);
	DistortionButtonUpImgFile = resourcesDirectory.getChildFile(DistortionButtonUpImgPath);
	ReverbButtonUpImgFile = resourcesDirectory.getChildFile(ReverbButtonUpImgPath);
	ChorusButtonUpImgFile = resourcesDirectory.getChildFile(ChorusButtonUpImgPath);
	FlangerButtonDownImgFile = resourcesDirectory.getChildFile(FlangerButtonDownImgPath);
	DistortionButtonDownImgFile = resourcesDirectory.getChildFile(DistortionButtonDownImgPath);
	ReverbButtonDownImgFile = resourcesDirectory.getChildFile(ReverbButtonDownImgPath);
	ChorusButtonDownImgFile = resourcesDirectory.getChildFile(ChorusButtonDownImgPath);
	SmallSliderImg = ImageFileFormat::loadFrom(SmallSliderImgFile);
	SliderBarImg = ImageFileFormat::loadFrom(SliderBarImgFile);
	HorizontalSliderTenHunImg = ImageFileFormat::loadFrom(HorizontalSliderTenHunImgFile);
	HorizontalSliderKnobImg = ImageFileFormat::loadFrom(HorizontalSliderKnobImgFile);
	VerticalSliderKnobImg = ImageFileFormat::loadFrom(VerticalSliderKnobImgFile);
	LoadPresetButtonImg = ImageFileFormat::loadFrom(LoadPresetButtonImgFile);
	SavePresetButtonImg = ImageFileFormat::loadFrom(SavePresetButtonImgFile);
	FlangerLabelImg = ImageFileFormat::loadFrom(FlangerLabelImgFile);
	DistortionLabelImg = ImageFileFormat::loadFrom(DistortionLabelImgFile);
	ChorusLabelImg = ImageFileFormat::loadFrom(ChorusLabelImgFile);
	ReverbLabelImg = ImageFileFormat::loadFrom(ReverbLabelImgFile);
	MixLabelImg = ImageFileFormat::loadFrom(MixLabelImgFile);
	DelayLabelImg = ImageFileFormat::loadFrom(DelayLabelImgFile);
	FeedbackLabelImg = ImageFileFormat::loadFrom(FeedbackLabelImgFile);
	AmountLabelImg = ImageFileFormat::loadFrom(AmountLabelImgFile);
	RateLabelImg = ImageFileFormat::loadFrom(RateLabelImgFile);
	SizeLabelImg = ImageFileFormat::loadFrom(SizeLabelImgFile);
	WidthLabelImg = ImageFileFormat::loadFrom(WidthLabelImgFile);
	FlangerButtonUpImg = ImageFileFormat::loadFrom(FlangerButtonUpImgFile);
	DistortionButtonUpImg = ImageFileFormat::loadFrom(DistortionButtonUpImgFile);
	ReverbButtonUpImg = ImageFileFormat::loadFrom(ReverbButtonUpImgFile);
	ChorusButtonUpImg = ImageFileFormat::loadFrom(ChorusButtonUpImgFile);
	FlangerButtonDownImg = ImageFileFormat::loadFrom(FlangerButtonDownImgFile);
	DistortionButtonDownImg = ImageFileFormat::loadFrom(DistortionButtonDownImgFile);
	ReverbButtonDownImg = ImageFileFormat::loadFrom(ReverbButtonDownImgFile);
	ChorusButtonDownImg = ImageFileFormat::loadFrom(ChorusButtonDownImgFile);
};

AudeaLookAndFeel2::~AudeaLookAndFeel2(){};

void AudeaLookAndFeel2::drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, Slider& slider)
{
	AffineTransform rotator;
	if (!slider.isMouseOverOrDragging())
	{
		g.drawImage(SmallSliderImg, x, y, width, height, 0, 0, width, height);
	}
	g.drawImageTransformed(SmallSliderImg, rotator.rotated((float)sliderPosProportional*(rotaryEndAngle / 2), (float)(SmallSliderImg.getWidth() / 2), (float)(SmallSliderImg.getHeight() / 2)), false);
};

void AudeaLookAndFeel2::drawLinearSliderBackground(Graphics& g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle style, Slider& slider)
{	
	if (style == Slider::LinearVertical)
	{
		g.drawImageAt(SliderBarImg, x, y);
	}
	else
	{
		g.drawImageAt(HorizontalSliderTenHunImg, x, y);
	}
	;
};

void AudeaLookAndFeel2::drawLinearSliderThumb(Graphics& g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle style, Slider& slider)
{
	if (style == Slider::LinearVertical)
	{	
		g.setOpacity(1.0);
		int centerX = x + 2;
		int centerY = sliderPos;
		g.drawImageAt(VerticalSliderKnobImg, centerX, centerY);
	}
	else
	{
		g.setOpacity(1.0);
		int centerX = sliderPos;
		int centerY = y+11;
		g.drawImageAt(HorizontalSliderKnobImg, centerX, centerY);
	}
};

void AudeaLookAndFeel2::drawButtonBackground(Graphics & g, Button & b, const Colour & backgroundColour, bool isMouseOverButton, bool isButtonDown)
{	
	if (b.getName() == String("LoadPresetButton"))
		g.drawImageAt(LoadPresetButtonImg, 0, 0);
	if (b.getName() == String("SavePresetButton"))
		g.drawImageAt(SavePresetButtonImg, 0, 0);
	//if (b.getName == String("LoadPresetButton"))
};

void AudeaLookAndFeel2::drawLabel(Graphics &g, Label &l)
{
	if (l.getName() == String("FlangerLabel"))
		g.drawImageAt(FlangerLabelImg, 0, 0);
	else if (l.getName() == String("DistortionLabel"))
		g.drawImageAt(DistortionLabelImg, 0, 0);
	else if (l.getName() == String("ChorusLabel"))
		g.drawImageAt(ChorusLabelImg, 0, 0);
	else if (l.getName() == String("ReverbLabel"))
		g.drawImageAt(ReverbLabelImg, 0, 0);
	else if (l.getName() == String("ChorusRateLabel"))
		g.drawImageAt(RateLabelImg, 0, 0);
	else if (l.getName() == String("FlangerDelayLabel"))
		g.drawImageAt(DelayLabelImg, 0, 0);
	else if (l.getName() == String("FlangerFeedbackLabel"))
		g.drawImageAt(FeedbackLabelImg, 0, 0);
	else if (l.getName() == String("DistortionAmountLabel"))
		g.drawImageAt(AmountLabelImg, 0, 0);
	else if (l.getName() == String("ReverbMixLabel"))
		g.drawImageAt(MixLabelImg, 0, 0);
	else if (l.getName() == String("ReverbSizeLabel"))
		g.drawImageAt(SizeLabelImg, 0, 0);
	else if (l.getName() == String("ChorusMixLabel"))
		g.drawImageAt(MixLabelImg, 0, 0);
	else if (l.getName() == String("FlangerMixLabel"))
		g.drawImageAt(MixLabelImg, 0, 0);
	else if (l.getName() == String("ReverbWidthLabel"))
		g.drawImageAt(WidthLabelImg, 0, 0);
}

void AudeaLookAndFeel2::drawToggleButton(Graphics & g, ToggleButton & b, bool isMouseOverButton, bool isButtonDown)
{	
	if (b.getName() == String("FlangerUIButton"))
	{
		if (b.getToggleState())
			g.drawImageAt(FlangerButtonDownImg, 0, 10);
		else
			g.drawImageAt(FlangerButtonUpImg, 0, 0);
	}
	else if (b.getName() == String("DistortionUIButton"))
	{
		if (b.getToggleState())
			g.drawImageAt(DistortionButtonDownImg, 0, 10);
		else
			g.drawImageAt(DistortionButtonUpImg, 0, 0);
	}
	else if (b.getName() == String("ReverbUIButton"))
	{
		if (b.getToggleState())
			g.drawImageAt(ReverbButtonDownImg, 0, 10);
		else
			g.drawImageAt(ReverbButtonUpImg, 0, 0);
	}
	else if (b.getName() == String("ChorusUIButton"))
	{
		if (b.getToggleState())
			g.drawImageAt(ChorusButtonDownImg, 0, 10);
		else
			g.drawImageAt(ChorusButtonUpImg, 0, 0);
	}
};