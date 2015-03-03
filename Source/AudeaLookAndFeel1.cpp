/*
  ==============================================================================

    AudeaLookAndFeel.cpp
    Created: 14 Jan 2015 2:04:47pm
    Author:  Felix Rolshausen

  ==============================================================================
*/

#include "AudeaLookAndFeel1.h"

AudeaLookAndFeel1::AudeaLookAndFeel1()
{
	SmallSliderImgFile = resourcesDirectory.getChildFile(SmallSliderImgPath);
	BigSliderImgFile = resourcesDirectory.getChildFile(BigSliderImgPath);
	HorizontalSliderOneTenImgFile = resourcesDirectory.getChildFile(HorizontalSliderOneTenImgPath);
	SmallVertSliderImgFile = resourcesDirectory.getChildFile(SmallVertSliderImgPath);
	SmallVerticalSliderKnobImgFile = resourcesDirectory.getChildFile(SmallVerticalSliderKnobImgPath);
	HorizontalSliderKnobImgFile = resourcesDirectory.getChildFile(HorizontalSliderKnobImgPath);
	SmallSliderImg = ImageFileFormat::loadFrom(SmallSliderImgFile);
	BigSliderImg = ImageFileFormat::loadFrom(BigSliderImgFile);
	HorizontalSliderOneTenImg =ImageFileFormat::loadFrom(HorizontalSliderOneTenImgFile);
	SmallVertSliderImg = ImageFileFormat::loadFrom(SmallVertSliderImgFile);
	SmallVerticalSliderKnobImg = ImageFileFormat::loadFrom(SmallVerticalSliderKnobImgFile);
	HorizontalSliderKnobImg = ImageFileFormat::loadFrom(HorizontalSliderKnobImgFile);
};

AudeaLookAndFeel1::~AudeaLookAndFeel1(){};

void AudeaLookAndFeel1::drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, Slider& slider)
{	
	AffineTransform rotator;
	if (!slider.isMouseOverOrDragging())
	{
		if (slider.getName() == String("OscTwoTuneSlider")){
			g.drawImage(SmallSliderImg, x, y, width, height, 0, 0, width, height);
		}
		else
		{
			g.drawImage(BigSliderImg, x, y, width, height, 0, 0, width, height);
		}
	}
	if (slider.getName() == String("OscTwoTuneSlider"))
	{
		g.drawImageTransformed(SmallSliderImg, rotator.rotated((float)sliderPosProportional*(rotaryEndAngle / 2), (float)(SmallSliderImg.getWidth() / 2), (float)(SmallSliderImg.getHeight() / 2)), false);
	}
	else
	{
		g.drawImageTransformed(BigSliderImg, rotator.rotated((float)sliderPosProportional*(rotaryEndAngle / 2), (float)(BigSliderImg.getWidth() / 2), (float)(BigSliderImg.getHeight() / 2)), false);
	}
};

void AudeaLookAndFeel1::drawLinearSliderBackground(Graphics& g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle style, Slider& slider)
{
	if (style == Slider::LinearHorizontal)
	{
		g.drawImageAt(HorizontalSliderOneTenImg, x, y);
	}
	else
	{
		g.drawImageAt(SmallVertSliderImg, x, y);
	}
	;
};

void AudeaLookAndFeel1::drawLinearSliderThumb(Graphics& g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle style, Slider& slider)
{
	if (style == Slider::LinearVertical)
	{
		g.setOpacity(1.0);
		int centerX = x-17;
		int centerY = sliderPos - 23;
		g.drawImageAt(SmallVerticalSliderKnobImg, centerX, centerY);
	}
	else
	{
		g.setOpacity(1.0);
		int centerX = sliderPos;
		int centerY = y+11;
		g.drawImageAt(HorizontalSliderKnobImg, centerX, centerY);
	}
};