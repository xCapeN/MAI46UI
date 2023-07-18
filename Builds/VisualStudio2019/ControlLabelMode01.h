#pragma once
#include <JuceHeader.h>
using namespace juce;
class ControlLabelMode01 : public LookAndFeel_V4 {
public: 
	ControlLabelMode01() ;
	void drawLabel(Graphics&, Label&);
	void drawLinearSlider(Graphics& g, int x, int y, int width, int height,
		float sliderPos,
		float minSliderPos,
		float maxSliderPos,
		const Slider::SliderStyle style, Slider& slider);

	//void drawLevelMeter(Graphics& g, int width, int height, float level);
	Image imageSliderUp;
	Image imageSliderHor;
	
	Path mypath;
};