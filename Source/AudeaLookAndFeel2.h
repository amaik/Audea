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

	void drawLinearSlider(Graphics &,
		int x,
		int y,
		int width,
		int height,
		float sliderPos,
		float minSliderPos,
		float maxSliderPos,
		const Slider::SliderStyle,
		Slider &);

private:
	//Location of the DLL
	File pluginLocation = File::getSpecialLocation(File::SpecialLocationType::currentApplicationFile);
	//Constants
	String SmallSliderImgPath = "Resources/SliderSmall.png";
	String SliderBarImgPath = "Resources/VertSlider.png";
	File SmallSliderImgFile;
	File SliderBarImgFile;
	Image SliderBarImg;
	Image SmallSliderImg;


};



#endif  // AUDEALOOKANDFEEL2_H_INCLUDED
