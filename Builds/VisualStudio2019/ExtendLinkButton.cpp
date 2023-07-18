#include "ExtendLinkButton.h"

void ExtendLinkButton::paintButton(Graphics& g, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown)
{
    auto& lf = getLookAndFeel();

    lf.drawButtonBackground(g, *this,
        findColour(getToggleState() ? buttonOnColourId : buttonColourId),
        shouldDrawButtonAsHighlighted, shouldDrawButtonAsDown);

    //lf.drawButtonText(g, *this, shouldDrawButtonAsHighlighted, shouldDrawButtonAsDown);
}

void ExtendLinkButton::colourChanged()
{
    repaint();
}
ExtendLinkButton::ExtendLinkButton(): Button("dd") {
    //buttonName = "dd";
}
ExtendLinkButton::ExtendLinkButton(const String& name) : Button(name)
{
}

ExtendLinkButton::ExtendLinkButton(const String& name, InputUiHolder& holder) : Button(name)
{
    
}
