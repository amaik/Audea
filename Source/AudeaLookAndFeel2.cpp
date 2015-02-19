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
	SmallSliderImgFile = pluginLocation.getParentDirectory().getParentDirectory().getParentDirectory().getParentDirectory().getChildFile(SmallSliderImgPath);
	SliderBarImgFile = pluginLocation.getParentDirectory().getParentDirectory().getParentDirectory().getParentDirectory().getChildFile(SliderBarImgPath);
	SmallSliderImg = ImageFileFormat::loadFrom(SmallSliderImgFile);
	SliderBarImg = ImageFileFormat::loadFrom(SliderBarImgFile);

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

void AudeaLookAndFeel2::drawLinearSlider(Graphics& g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle, Slider& slider)
{
	g.drawImageAt(SliderBarImg, x, y);
};