#pragma once
#include <JuceHeader.h>
#include "InputUiHolder.h"
#include "ExtendDetailButton.h"
#include "ExtendLinkButton.h"

class UIHolderControlButtonList : public Component ,private Button::Listener {
public :
	UIHolderControlButtonList(InputUiHolder& holder): inputUIHolder(holder){
		inputUIComponentStats.add(new InputUIComponentStat1("Stat1"));
		inputUIComponentStats.add(new InputUIComponentStat2("Stat2"));
	}

private :
	InputUiHolder inputUIHolder;
	std::unique_ptr<ExtendDetailButton> detailButtonAll;
	std::unique_ptr<ExtendDetailButton> detailButtonChannel1;
	std::unique_ptr<ExtendDetailButton> detailButtonChannel2;
	std::unique_ptr<ExtendDetailButton> linkButton;
	OwnedArray<InputUIComponentContainer> inputUIComponentStats;
	
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UIHolderControlButtonList)
};