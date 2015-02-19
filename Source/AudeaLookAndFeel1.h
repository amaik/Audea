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

private:
	//Location of the DLL
	File pluginLocation = File::getSpecialLocation(File::SpecialLocationType::currentApplicationFile);
	//Constants
	String BigSliderImgPath = "Resources/SliderBig.png";
	File BigSliderImgFile;
	Image BigSliderImg;


};





#endif  // AUDEALOOKANDFEEL_H_INCLUDED
