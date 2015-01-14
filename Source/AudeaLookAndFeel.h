/*
  ==============================================================================

    AudeaLookAndFeel.h
    Created: 14 Jan 2015 2:04:47pm
    Author:  Felix Rolshausen

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h";

#ifndef AUDEALOOKANDFEEL_H_INCLUDED
#define AUDEALOOKANDFEEL_H_INCLUDED

class AudeaLookAndFeel : public LookAndFeel_V3{

public:
	AudeaLookAndFeel()
	{
		rotarySliderImage = ;
	}
	;
	~AudeaLookAndFeel();


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
	Image rotarySliderImage;
	File sliderImageFile;


};





#endif  // AUDEALOOKANDFEEL_H_INCLUDED
