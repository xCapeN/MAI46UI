#pragma once
#include <JuceHeader.h>
using namespace juce;
#include "InputUIComponent.h"
#include "InputUiHolder.h"
class ExtendLinkButton : public Button 
{
public:
	ExtendLinkButton() ;
    explicit ExtendLinkButton(const String& buttonName);
    ExtendLinkButton(const String& name, InputUiHolder& holder) ;
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
private:
	// Í¨¹ý Button ¼Ì³Ð
    String buName;
    InputUiHolder inputHolder;
    
    //void setinputHolder(InputUiHolder&);
	void paintButton(Graphics& g, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override;
    void colourChanged() override;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExtendLinkButton)
};



