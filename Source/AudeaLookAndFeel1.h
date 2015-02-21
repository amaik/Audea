/*
  ==============================================================================

    AudeaLookAndFeel.h
    Created: 14 Jan 2015 2:04:47pm
    Author:  Felix Rolshausen

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h";

#ifndef AUDEALOOKANDFEEL1_H_INCLUDED
#define AUDEALOOKANDFEEL1_H_INCLUDED

class AudeaLookAndFeel1 : public LookAndFeel_V3{

public:
	AudeaLookAndFeel1();
	~AudeaLookAndFeel1();

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
	String BigSliderImgPath = "Resources/SliderBig.png";
	String HorizontalSliderOneTenImgPath = "Resources/HorizontalSliderOneTen.png";
	String SmallVertSliderImgPath = "Resources/VertSliderSmall.png";
	File BigSliderImgFile;
	File HorizontalSliderOneTenImgFile;
	File SmallVertSliderImgFile;
	Image BigSliderImg;
	Image HorizontalSliderOneTenImg;
	Image SmallVertSliderImg;


};





#endif  // AUDEALOOKANDFEEL_H_INCLUDED
