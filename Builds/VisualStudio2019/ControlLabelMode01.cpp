#include "ControlLabelMode01.h"

ControlLabelMode01::ControlLabelMode01() :LookAndFeel_V4() {
    //File imageSliderUpFile = File();
    //ImageCache::getFromMemory(BinaryData::ButtonLinkNormal_png, BinaryData::ButtonLinkNormal_pngSize);

    imageSliderUp = ImageCache::getFromMemory(BinaryData::SliderVec_png, BinaryData::SliderVec_pngSize);
    imageSliderHor = ImageCache::getFromMemory(BinaryData::SliderHorizon_png, BinaryData::SliderHorizon_pngSize);
}

void ControlLabelMode01::drawLabel(Graphics& g, Label& label)
{
	//g.fillAll(label.findColour(Label::backgroundColourId));
	g.setColour(label.findColour(Label::backgroundColourId));
	g.fillRoundedRectangle(label.getLocalBounds().toFloat(), label.getWidth() / 2.7);
	//g.fillRoundedRectangle(0,0, label.getWidth(), label.getHeight(), 20);

	if (!label.isBeingEdited())
	{
		auto alpha = label.isEnabled() ? 1.0f : 0.5f;
		const Font font(getLabelFont(label));

		g.setColour(label.findColour(Label::textColourId).withMultipliedAlpha(alpha));
		g.setFont(font);

		auto textArea = getLabelBorderSize(label).subtractedFrom(label.getLocalBounds());

		g.drawFittedText(label.getText(), textArea, label.getJustificationType(),
			jmax(1, (int)(textArea.getHeight() / font.getHeight())),
			label.getMinimumHorizontalScale());

		
		//label.attachToComponent(, false);
		g.setColour(label.findColour(Label::outlineColourId).withMultipliedAlpha(alpha));
	}
	else if (label.isEnabled())
	{
		g.setColour(label.findColour(Label::outlineColourId));
	}
	g.drawRoundedRectangle(label.getLocalBounds().toFloat(), label.getWidth() / 2.7, 1);
	//g.drawRoundedRectangle(
	//	0,              // x
	//	0,              // y
	//	label.getWidth(),   // width
	//	label.getHeight(),  // height
	//	20,              // cornerSize
	//	2               // lineThickness
	//);

}

void ControlLabelMode01::drawLinearSlider(Graphics& g, int x, int y, int width, int height,
    float sliderPos,
    float minSliderPos,
    float maxSliderPos,
    const Slider::SliderStyle style, Slider& slider)
{Path pathSliderScale;
if (slider.isBar())
{
    if (slider.isVertical()) {
        if ((float)height * 0.3 < sliderPos) {
            g.setGradientFill(ColourGradient(Colours::yellow, 10.0f, 10.0f,
                Colours::green, 10.0f + (float)width - 1.0f, 10.0f + (float)y + ((float)height * 1.3), false));
            //g.setColour (slider.findColour (Slider::trackColourId));

            g.fillRect(slider.isHorizontal() ? Rectangle<float>(static_cast<float> (x), (float)y + 0.5f, sliderPos - (float)x, (float)height - 1.0f)
                : Rectangle<float>((float)x + 0.5f, sliderPos, (float)width - 1.0f, (float)y + ((float)height - sliderPos)));



        }
        else {
            g.setGradientFill(ColourGradient(Colours::yellow, 10.0f, 10.0f,
                Colours::green, 10.0f + (float)width - 1.0f, 10.0f + (float)y + ((float)height * 1.3), false));
            //g.setColour (slider.findColour (Slider::trackColourId));

            g.fillRect(slider.isHorizontal() ? Rectangle<float>(static_cast<float> (x), (float)y + 0.5f, sliderPos - (float)x, (float)height - 1.0f)
                : Rectangle<float>((float)x + 0.5f, ((float)y + (float)height * 0.3),
                    (float)width - 1.0f, (float)y + ((float)height - (float)height * 0.3)));

            g.setGradientFill(ColourGradient(Colours::red, 10.0f, 10.0f,
                Colours::yellow, 10.0f + (float)width - 1.0f, 10.0f + (float)y + ((float)height * 0.3), false));

            g.fillRect(slider.isHorizontal() ? Rectangle<float>(static_cast<float> (x), (float)y + 0.5f, sliderPos - (float)x, (float)height - 1.0f)
                : Rectangle<float>((float)x + 0.5f, sliderPos,
                    (float)width - 1.0f, (float)height * 0.3 - (float)y - ((float)sliderPos)));
            /* g.setGradientFill(ColourGradient(Colours::red, 10.0f, 10.0f,
                 Colours::yellow, 10.0f + (float)width - 1.0f, 10.0f + (float)y + ((float)height*0.3 ), false));*/
        }
    }
    else if (slider.isHorizontal()) {
        if ((float)width * 0.7 > sliderPos) {
            g.setGradientFill(ColourGradient(Colours::yellow, 10.0f, 10.0f,
                Colours::green, 10.0f + (float)width - 1.0f, 10.0f + (float)y + ((float)height * 1.3), false));
            //g.setColour (slider.findColour (Slider::trackColourId));

            g.fillRect(slider.isHorizontal() ? Rectangle<float>(static_cast<float> (x), (float)y + 0.5f, sliderPos - (float)x, (float)height - 1.0f)
                : Rectangle<float>((float)x + 0.5f, sliderPos, (float)width - 1.0f, (float)y + ((float)height - sliderPos)));



        }
        else {
            g.setGradientFill(ColourGradient(Colours::yellow, (width) * 0.7 + 2.0f, 0.0f,
                Colours::red,  (float)width , 10.0f + (float)y, false));
            //g.setColour (slider.findColour (Slider::trackColourId));

            g.fillRect(slider.isHorizontal() ? Rectangle<float>(static_cast<float> (width)* 0.7, (float)y, sliderPos - (float)width * 0.7, (float)height - 1.0f)
                : Rectangle<float>((float)x + 0.5f, ((float)y + (float)height * 0.3),
                    (float)width - 1.0f, (float)y + ((float)height - (float)height * 0.3)));

            g.setGradientFill(ColourGradient(Colours::green, 10.0f, 10.0f,
                Colours::yellow, 10.0f + (float)width * 0.6f, 10.0f + (float)y , false));

            g.fillRect(slider.isHorizontal() ? Rectangle<float>(static_cast<float> (x) - 0.5f, (float)y , (float)width * 0.7 , (float)height - 1.0f)
                : Rectangle<float>((float)x + 0.5f, sliderPos,
                    (float)width - 1.0f, (float)height * 0.3 - (float)y - ((float)sliderPos)));
            /* g.setGradientFill(ColourGradient(Colours::red, 10.0f, 10.0f,
                 Colours::yellow, 10.0f + (float)width - 1.0f, 10.0f + (float)y + ((float)height*0.3 ), false));*/
        }
    }
}
    else
    {
        auto isTwoVal = (style == Slider::SliderStyle::TwoValueVertical || style == Slider::SliderStyle::TwoValueHorizontal);
        auto isThreeVal = (style == Slider::SliderStyle::ThreeValueVertical || style == Slider::SliderStyle::ThreeValueHorizontal);

        auto trackWidth = jmin(12.0f, slider.isHorizontal() ? (float)height * 0.25f : (float)width * 0.25f);

        Point<float> startPoint(slider.isHorizontal() ? (float)x : (float)x + (float)width * 0.5f,
            slider.isHorizontal() ? (float)y + (float)(height  ) * 0.5f : (float)(height - (10 )   + y));

        Point<float> endPoint(slider.isHorizontal() ? (float)(width + x) : startPoint.x,
            slider.isHorizontal() ? startPoint.y : (float)(y + (10  )));

        /// <summary>
        /// DrawScale »­¿Ì¶ÈÏß
        /// </summary>
        Path pathSliderScale;
        if (slider.isHorizontal() ) { Point<float> scalePointStart; }
        else { 
        
            for (int index = 0; index < 6; index++) {
                Point<float> scalePointStart = { endPoint.getX() - 20 , endPoint.getY() + index * (height - 40)/5 };
                Point<float> scalePointEnd = { endPoint.getX() + 20 , endPoint.getY() + index * (height - 40) / 5 };
                pathSliderScale.startNewSubPath(scalePointStart);
                pathSliderScale.lineTo(scalePointEnd);
            }
        }
        g.setColour(slider.findColour(Slider::backgroundColourId));
        g.strokePath(pathSliderScale, { 3.0f, PathStrokeType::beveled, PathStrokeType::butt });
        ////


        Path backgroundTrack;
        backgroundTrack.startNewSubPath(startPoint);
        backgroundTrack.lineTo(endPoint);
        g.setColour(slider.findColour(Slider::trackColourId));
        g.strokePath(backgroundTrack, { trackWidth, PathStrokeType::beveled, PathStrokeType::rounded });

        Path valueTrack;
        Point<float> minPoint, maxPoint, thumbPoint;

        if (isTwoVal || isThreeVal)
        {
            minPoint = { slider.isHorizontal() ? minSliderPos : (float)width * 0.5f,
                         slider.isHorizontal() ? (float)height * 0.5f : minSliderPos };

            if (isThreeVal)
                thumbPoint = { slider.isHorizontal() ? sliderPos : (float)width * 0.5f,
                               slider.isHorizontal() ? (float)height * 0.5f : sliderPos };

            maxPoint = { slider.isHorizontal() ? maxSliderPos : (float)width * 0.5f,
                         slider.isHorizontal() ? (float)height * 0.5f : maxSliderPos };
        }
        else
        {
            auto kx = slider.isHorizontal() ? sliderPos : ((float)x + (float)width * 0.5f);
            auto ky = slider.isHorizontal() ? ((float)y + (float)height * 0.5f) : sliderPos;
            if (ky > startPoint.getY()) ky = startPoint.getY();
            else if (ky < endPoint.getY())ky = endPoint.getY();
            minPoint = startPoint;
            maxPoint = { kx, ky };
        }

        auto thumbWidth = getSliderThumbRadius(slider);

        valueTrack.startNewSubPath(minPoint);
        valueTrack.lineTo(isThreeVal ? thumbPoint : maxPoint);

        g.setColour(slider.findColour(Slider::trackColourId));
        g.strokePath(valueTrack, { trackWidth, PathStrokeType::curved, PathStrokeType::rounded });

        if (!isTwoVal)
        {
            g.setColour(slider.findColour(Slider::thumbColourId));
            g.setColour(Colours::green);
            //g.fillEllipse(Rectangle<float>(static_cast<float> (thumbWidth), static_cast<float> (thumbWidth)).withCentre(isThreeVal ? thumbPoint : maxPoint));
            if (slider.getSliderStyle() == Slider::SliderStyle::LinearVertical) {
                //Point<float> imagePoint = { maxPoint.getX() ,maxPoint.getY() + 20 };
                g.drawImage(imageSliderUp,
                    Rectangle<float>(static_cast<float> (18  ), static_cast<float> (28 )).withCentre(isThreeVal ? thumbPoint : maxPoint));
            }
            else {
                g.drawImage(imageSliderHor,
                    Rectangle<float>(static_cast<float> (15), static_cast<float> (30.0f)).withCentre(isThreeVal ? thumbPoint : maxPoint));
            }
            
        }

        if (isTwoVal || isThreeVal)
        {
            auto sr = jmin(trackWidth, (slider.isHorizontal() ? (float)height : (float)width) * 0.4f);
            auto pointerColour = slider.findColour(Slider::thumbColourId);

            if (slider.isHorizontal())
            {
                drawPointer(g, minSliderPos - sr,
                    jmax(0.0f, (float)y + (float)height * 0.5f - trackWidth * 2.0f),
                    trackWidth * 2.0f, pointerColour, 2);

                drawPointer(g, maxSliderPos - trackWidth,
                    jmin((float)(y + height) - trackWidth * 2.0f, (float)y + (float)height * 0.5f),
                    trackWidth * 2.0f, pointerColour, 4);
            }
            else
            {
                drawPointer(g, jmax(0.0f, (float)x + (float)width * 0.5f - trackWidth * 2.0f),
                    minSliderPos - trackWidth,
                    trackWidth * 2.0f, pointerColour, 1);

                drawPointer(g, jmin((float)(x + width) - trackWidth * 2.0f, (float)x + (float)width * 0.5f), maxSliderPos - sr,
                    trackWidth * 2.0f, pointerColour, 3);
            }
        }
    }
}