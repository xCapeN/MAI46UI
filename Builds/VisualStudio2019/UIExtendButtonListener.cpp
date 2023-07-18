#include "UIExtendButtonListener.h"
//void UIExtendButtonListener::buttonClicked(juce::Button* btn)  {
//	if (true) {
//		//removeChildComponent
//	}
//	int p = 0;
//	
//
//}

//void UIExtendButtonListener::paintButton(Graphics& g, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown)
//{
//	auto& lf = getLookAndFeel();
//
//	lf.drawButtonBackground(g, *this,
//		findColour(getToggleState() ? buttonOnColourId : buttonColourId),
//		shouldDrawButtonAsHighlighted, shouldDrawButtonAsDown);
//
//	//lf.drawButtonText(g, *this, shouldDrawButtonAsHighlighted, shouldDrawButtonAsDown);
//}
//UIExtendButtonListener::UIExtendButtonListener(const String& name) : Button(name){
//	
//}

void UIExtendButtonListener::buttonClicked(Button* b) {
	if (b->getState()) {
		b->setColour(TextButton::ColourIds::buttonOnColourId, Colours::lightblue);
	}
	else {
		b->setColour(TextButton::ColourIds::buttonOnColourId, Colours::black);
	}
}

void UIExtendButtonListener::buttonStateChanged(Button* b) {

}