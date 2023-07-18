#pragma once
#include <JuceHeader.h>
//#include "DriverOutputUI.h"
using namespace juce;
class UIExtendButtonListener : public Button ::Listener
{
public :

	UIExtendButtonListener() = default;
    //UIExtendButtonListener(const String& name) ;
	//void UIExtendButtonListener::buttonClicked(juce::Button*) override;
    enum ColourIds
    {
        buttonColourId = 0x1000100,  /**< The colour used to fill the button shape (when the button is toggled
                                                           'off'). The look-and-feel class might re-interpret this to add
                                                           effects, etc. */
                                                           buttonOnColourId = 0x1000101,  /**< The colour used to fill the button shape (when the button is toggled
                                                                                                              'on'). The look-and-feel class might re-interpret this to add
                                                                                                              effects, etc. */
                                                                                                              textColourOffId = 0x1000102,  /**< The colour to use for the button's text when the button's toggle state is "off". */
                                                                                                              textColourOnId = 0x1000103   /**< The colour to use for the button's text.when the button's toggle state is "on". */
    };
    
    void buttonClicked(Button*) override;
    void buttonStateChanged(Button*) override;

private:
	// Í¨¹ý Button ¼Ì³Ð
	//void paintButton(Graphics& g, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override;
    //DriverInputUI driverInputUI;

    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UIExtendButtonListener)
};
