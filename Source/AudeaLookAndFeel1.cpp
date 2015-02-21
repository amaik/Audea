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
	BigSliderImgFile = pluginLocation.getParentDirectory().getParentDirectory().getParentDirectory().getParentDirectory().getChildFile(BigSliderImgPath);
	HorizontalSliderOneTenImgFile = pluginLocation.getParentDirectory().getParentDirectory().getParentDirectory().getParentDirectory().getChildFile(HorizontalSliderOneTenImgPath);
	SmallVertSliderImgFile = pluginLocation.getParentDirectory().getParentDirectory().getParentDirectory().getParentDirectory().getChildFile(SmallVertSliderImgPath);
	BigSliderImg = ImageFileFormat::loadFrom(BigSliderImgFile);
	HorizontalSliderOneTenImg =ImageFileFormat::loadFrom(HorizontalSliderOneTenImgFile);
	SmallVertSliderImg = ImageFileFormat::loadFrom(SmallVertSliderImgFile);
};

AudeaLookAndFeel1::~AudeaLookAndFeel1(){};

void AudeaLookAndFeel1::drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, Slider& slider)
{	
	AffineTransform rotator;
	if (!slider.isMouseOverOrDragging())
	{
		g.drawImage(BigSliderImg, x, y, width, height, 0, 0, width, height);
	}
	g.drawImageTransformed(BigSliderImg, rotator.rotated((float)sliderPosProportional*(rotaryEndAngle/2), (float)(BigSliderImg.getWidth() / 2), (float)(BigSliderImg.getHeight() / 2)), false);
};

void AudeaLookAndFeel1::drawLinearSlider(Graphics& g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle style, Slider& slider)
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