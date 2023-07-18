#include "MainComponent.h"
#include "UIExtendButtonListener.h"
#include "DriverOutputUI.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (600, 800);
    //DriverOutputUI* driverOutputUI = new DriverOutputUI();
    //dOutputUIs.add(driverOutputUI);
    //addAndMakeVisible(driverOutputUI);
    //DriverOutputUI* driverOutputUI1 = new DriverOutputUI();
    //driverOutputUI1->setBounds(0, 200, 175, 100);
    /*dOutputUIs.add(driverOutputUI1);*/

    //DriverInputUI* driverinputUI1 = new DriverInputUI();
    //dInputUIs.add(driverinputUI1);
    //addAndMakeVisible(driverinputUI1);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setFont (juce::Font (16.0f));
    g.setColour (juce::Colours::white);
    g.drawText ("Hello World!", getLocalBounds(), juce::Justification::centred, true);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
