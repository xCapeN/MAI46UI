#pragma once

#include "DriverOutputUI.h"
#include "UIExtendButtonListener.h"
using namespace juce;
struct SnappingSlider : public juce::Slider
{
    double snapValue(double attemptedValue, DragMode dragMode) override
    {
        if (dragMode == notDragging)
            return attemptedValue;  // if they're entering the value in the text-box, don't mess with it.

        if (attemptedValue > 40 && attemptedValue < 60)
            return 50.0;

        return attemptedValue;
    }
};
juce::Slider* createSlider(bool isSnapping)
{
    auto* s = isSnapping ? new SnappingSlider()
        : new juce::Slider();

    //sliders.add(s);
    //addAndMakeVisible(s);
    s->setBounds(0, 65 * 0.4 , 135, 55 * 0.4);
    s->setRange(0.0, 100.0, 0.1);
    s->setPopupMenuEnabled(true);
    s->setSliderStyle(juce::Slider::SliderStyle::LinearHorizontal);
    s->setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
    //s->setValue(Random::getSystemRandom().nextDouble() * 100.0, dontSendNotification);
    return s;
}

//初始化特定的Slider为垂直滑条
juce::Slider* createSlider(JuceSlider & js, bool isSnapping,int index)
{
    auto* s = isSnapping ? new SnappingSlider()
        : new juce::Slider();

    //sliders.add(s);
    //addAndMakeVisible(s);
    s->setBounds(0 + 25*index, 15, 20, 250);
    s->setRange(0.0, 100.0, 0.1);
    s->setPopupMenuEnabled(true);
    s->setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    s->setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
    //js.reset(s);
    
    //s->setValue(Random::getSystemRandom().nextDouble() * 100.0, dontSendNotification);
    return s;
}

DriverOutputUI::DriverOutputUI()
{
    cMode01.reset(new ControlLabelMode01());
    //Font pf = Font(4.0f);
    float beilv = 0.4;
    setSize(135, 80);
    auto* slider = createSlider(false);
    //slider->setEnabled(false);
    slider->setValue(15, NotificationType::dontSendNotification);
    slider->setLookAndFeel(cMode01.get());
    slider->setColour(Slider::trackColourId, Colours::grey);
    //slider->setValue(20, false);
    sliders.add(slider);
    textButtonMute.reset(new juce::TextButton());
    textButtonMute.get()->setBounds(0 + 9, 160 *0.4, 28 , 14 );
    textButtonSolo.reset(new juce::TextButton());
    textButtonSolo.get()->setBounds(29 + 9, 160*0.4, 28, 14);
    textButtonSpe.reset(new juce::TextButton());
    textButtonSpe.get()->setBounds(60 + 9, 160 * beilv, 28, 14);
    textButtonMonitor.reset(new juce::TextButton());
    textButtonMonitor.get()->setBounds(89 + 9, 160 * beilv,28, 14);

    textButtonMute.get()->setButtonText("MUTE");
    textButtonSolo.get()->setButtonText("SOLO");
    textButtonSpe.get()->setButtonText("STEREO");
    textButtonMonitor.get()->setButtonText("LOOPBACK");
    //textButtonMute.get()->font

    juce::File jFile01 = juce::File("C:\\Users\\admin\\Pictures\\Horizon.png");
    textImageComponent01.reset(new juce::ImageComponent());

    juce::Image im2 = juce::ImageCache::getFromFile(jFile01);
    textImageComponent01.get()->setImage(im2);
    textImageComponent01.get()->setBounds(10 * beilv, 125 * beilv, 290 * beilv, 11 * beilv);

    textImageComponent02.reset(new juce::ImageComponent());
    textImageComponent02.get()->setImage(im2);
    textImageComponent02.get()->setBounds(10 * beilv, 140 * beilv, 290 * beilv, 11 * beilv);

    textImageComponent.reset(new juce::ImageComponent());
    juce::File jFile = juce::File("C:\\Users\\admin\\Pictures\\Camera Roll\\background.png");
    //textImageCache.reset(new juce::ImageCache());
    juce::Image im = juce::ImageCache::getFromFile(jFile);
    textImageComponent.get()->setImage(im);
    textImageComponent.get()->setBounds(6 * beilv, 0 * beilv, 100 * beilv, 65 * beilv);

    textLabelName.reset(new juce::Label());
    textLabelName.get()->setBounds(147 * beilv, 0 * beilv, 165 * beilv, 32 * beilv);
    textLabelName.get()->setJustificationType(juce::Justification::centred);
    juce::Font font{ 8.0f };
    textLabelName.get()->setFont(font);
    textLabelName.get()->setText("HEADPHONE", juce::NotificationType::dontSendNotification);
    
    textLabelChannel.reset(new juce::Label());
    textLabelChannel.get()->setBounds(147 * beilv, 32 * beilv, 165 * beilv, 33 * beilv);
    textLabelChannel.get()->setJustificationType(juce::Justification::centred);
    textLabelChannel.get()->setFont(font);
    textLabelChannel.get()->setText("Channel 1/2", juce::NotificationType::dontSendNotification);
    textLabelChannel.get()->setColour(juce::Label::ColourIds::backgroundColourId, Colours::grey);
    textLabelChannel.get()->setColour(juce::Label::ColourIds::textColourId, Colours::black);





    addAndMakeVisible(textButtonMute.get());
    addAndMakeVisible(textButtonSolo.get());
    addAndMakeVisible(textButtonSpe.get());
    addAndMakeVisible(textButtonMonitor.get());
    addAndMakeVisible(textImageComponent.get());
    addAndMakeVisible(textLabelName.get());
    addAndMakeVisible(textLabelChannel.get());

    addAndMakeVisible(textImageComponent01.get());
    addAndMakeVisible(textImageComponent02.get());
    addAndMakeVisible(slider);


}

DriverOutputUI::DriverOutputUI(juce::String name) : Component(name)
{
    cMode01.reset(new ControlLabelMode01());
    //Font pf = Font(4.0f);
    float beilv = 0.4;
    setSize(135, 80);
    auto* slider = createSlider(false);
    //slider->setEnabled(false);
    slider->setValue(15, NotificationType::dontSendNotification);
    slider->setLookAndFeel(cMode01.get());
    slider->setColour(Slider::trackColourId, Colours::grey);
    //slider->setValue(20, false);
    sliders.add(slider);
    textButtonMute.reset(new juce::TextButton());
    textButtonMute.get()->setBounds(0 + 9, 160 * 0.4, 28, 14);
    textButtonSolo.reset(new juce::TextButton());
    textButtonSolo.get()->setBounds(29 + 9, 160 * 0.4, 28, 14);
    textButtonSpe.reset(new juce::TextButton());
    textButtonSpe.get()->setBounds(60 + 9, 160 * beilv, 28, 14);
    textButtonMonitor.reset(new juce::TextButton());
    textButtonMonitor.get()->setBounds(89 + 9, 160 * beilv, 28, 14);

    textButtonMute.get()->setButtonText("MUTE");
    textButtonSolo.get()->setButtonText("SOLO");
    textButtonSpe.get()->setButtonText("STEREO");
    textButtonMonitor.get()->setButtonText("LOOPBACK");
    //textButtonMute.get()->font

    juce::File jFile01 = juce::File("C:\\Users\\admin\\Pictures\\Horizon.png");
    textImageComponent01.reset(new juce::ImageComponent());

    juce::Image im2 = juce::ImageCache::getFromFile(jFile01);
    textImageComponent01.get()->setImage(im2);
    textImageComponent01.get()->setBounds(10 * beilv, 125 * beilv, 290 * beilv, 11 * beilv);

    textImageComponent02.reset(new juce::ImageComponent());
    textImageComponent02.get()->setImage(im2);
    textImageComponent02.get()->setBounds(10 * beilv, 140 * beilv, 290 * beilv, 11 * beilv);

    textImageComponent.reset(new juce::ImageComponent());
    juce::File jFile = juce::File("C:\\Users\\admin\\Pictures\\Camera Roll\\background.png");
    //textImageCache.reset(new juce::ImageCache());
    juce::Image im = juce::ImageCache::getFromFile(jFile);
    textImageComponent.get()->setImage(im);
    textImageComponent.get()->setBounds(6 * beilv, 0 * beilv, 100 * beilv, 65 * beilv);

    textLabelName.reset(new juce::Label());
    textLabelName.get()->setBounds(147 * beilv, 0 * beilv, 165 * beilv, 32 * beilv);
    textLabelName.get()->setJustificationType(juce::Justification::centred);
    juce::Font font{ 8.0f };
    textLabelName.get()->setFont(font);
    textLabelName.get()->setText("HEADPHONE", juce::NotificationType::dontSendNotification);

    textLabelChannel.reset(new juce::Label());
    textLabelChannel.get()->setBounds(147 * beilv, 32 * beilv, 165 * beilv, 33 * beilv);
    textLabelChannel.get()->setJustificationType(juce::Justification::centred);
    textLabelChannel.get()->setFont(font);
    textLabelChannel.get()->setText("Channel 1/2", juce::NotificationType::dontSendNotification);
    textLabelChannel.get()->setColour(juce::Label::ColourIds::backgroundColourId, Colours::grey);
    textLabelChannel.get()->setColour(juce::Label::ColourIds::textColourId, Colours::black);



    addAndMakeVisible(textButtonMute.get());
    addAndMakeVisible(textButtonSolo.get());
    addAndMakeVisible(textButtonSpe.get());
    addAndMakeVisible(textButtonMonitor.get());
    addAndMakeVisible(textImageComponent.get());
    addAndMakeVisible(textLabelName.get());
    addAndMakeVisible(textLabelChannel.get());

    //addAndMakeVisible(textImageComponent01.get());
   // addAndMakeVisible(textImageComponent02.get());
    addAndMakeVisible(slider);


    sampleSlider1.reset(new Slider());
    sampleSlider1->setSliderStyle(Slider::SliderStyle::LinearBar);
    sampleSlider1->setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    sampleSlider1->setBounds(10 * beilv, 140 * beilv, 290 * beilv, 11 * beilv);
    sampleSlider1->setRange(0, 1, 0.01);
    sampleSlider1->setLookAndFeel(cMode01.get());
    //
    addAndMakeVisible(sampleSlider1.get());

    sampleSlider2.reset(new Slider());
    sampleSlider2->setSliderStyle(Slider::SliderStyle::LinearBar);
    sampleSlider2->setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    sampleSlider2->setBounds(10 * beilv, 125 * beilv, 290 * beilv, 11 * beilv);
    sampleSlider2->setRange(0, 1, 0.01);
    sampleSlider2->setLookAndFeel(cMode01.get());
    //sampleSlider2->setMaxValue(100.0, false);
    addAndMakeVisible(sampleSlider2.get());
}
DriverOutputUI::~DriverOutputUI()
{
}

void DriverOutputUI::setSampleSliderValue(float value1, float value2) {
    sampleSlider1.get()->setValue(value1);
    sampleSlider2.get()->setValue(value2);
}

void DriverOutputUI::getSlider() {
    sliders.getFirst()->setValue(100);
}
//==============================================================================
void DriverOutputUI::paint(juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(Colours::black);
    g.setColour(Colours::grey);
    g.drawRect(0, 0, getWidth(), getHeight(), 1);

}

void DriverOutputUI::resized()
{
    // This is called when the DriverOutputUI is resized.
    // If you add any child components, this is where you should
    // update their positions.
}



struct InputUiProperty {
    int length;
    int hight;
};
InputUiProperty ip1 = { 9,20 };
InputUiProperty ip2 = { 10,20 };
InputUiProperty ip3 = { 19,20 };
InputUiProperty ip4 = {4,20 };
std::vector<InputUiProperty> inputUiPropertys = {ip1,ip2,ip3, ip4, };


/// <summary>
/// 180 * 400 ; 200 * 400 ; 380* 400 ; 80 * 400 ; 
/// /20
/// 9:20 ; 10 : 20 ; 19 : 20 ; 4 : 20 ;
/// </summary>
DriverInputUI::DriverInputUI()
{
    //Button b = UIExtendButtonListener("dd");
    //默认初始化为input1 和 input2 分开
    setSize((*(--inputUiPropertys.end() )).length * 20 * 2 , (*(--inputUiPropertys.end())).hight * 20  );
    linkButton.reset(new juce::TextButton("ds"));
    linkButton.get()->setBounds((*(inputUiPropertys.begin())).length * 20 - 10, (*(inputUiPropertys.begin())).hight * 20 * 0.8, 20, 20);
    linkButton.get()->addListener(this);
    addAndMakeVisible(linkButton.get());
    linkButton.get()->setVisible(true);
    //添加组件,此处以函数控制，之后重绘应该也要使用
    
    //mode1 
    mode1_LabelName.reset(new Label());
    sliders.add(createSlider(mode1_JuceSliderChannel1, false,1));
    sliders.add(createSlider(mode1_JuceSliderChannel2, false,2));
    mode1_LabelName.get()->setJustificationType(Justification::verticallyCentred);
    mode1_LabelName.get()->setBounds(10, 50, 100, 200);
    mode1_LabelName.get()->setText("Virtual 1/2",NotificationType::dontSendNotification);
    buttonChangeMode1.reset(new TextButton("<"));
    //buttonChangeMode1.get()->addListener(new UIExtendButtonListener());
    buttonChangeMode1.get()->setBounds(10, 300, 40, 10);
    
    //uiExtendButton.reset(new UIExtendButtonListener("ddq"));
    //uiExtendButton.get()->setBounds(10, 50, 80, 80);
    //addAndMakeVisible(uiExtendButton.get());
    //LabelGraphics.setColour(juce::Colour(1, 1, 0));
    glyphs.addFittedText({ 20.0f }, "Virtual 1/2",
        10, -10, 60, 20, Justification::centred, 1, 0.1f);
    
    
    //sliders.add(&mode1_JuceSliderChannel1);
    addAndMakeVisible((*sliders.getFirst()));
    addAndMakeVisible((*sliders.getLast()));
    addAndMakeVisible(buttonChangeMode1.get());
    //addAndMakeVisible(mode1_LabelName.get());
    int time = 0;
    //addAndMakeVisible(sliders.getFirst());
    //for (Slider** i = sliders.begin(); i != sliders.end(); i++)
    //{
    //    time++;
    //    
    //}
    int k = 0; 
    //createSlider(mode1_JuceSliderChannel1, false);
    //createSlider(mode1_JuceSliderChannel2, false);
    //addAndMakeVisible(mode1_JuceSliderChannel2.get());
    //addAndMakeVisible(mode1_JuceSliderChannel1.get());
}

DriverInputUI::~DriverInputUI()
{
}
void DriverInputUI::buttonClicked(juce::Button*) {
    if (flag == 0) { flag = 1; 

    
    }
    else if (flag == 1) flag = 0;
}
//==============================================================================
void DriverInputUI::paint(juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
    AffineTransform t;
    t.mat00 = 0;
    t.mat01 = -1;
    t.mat11 = 0;
    t.mat10 = 1;
    //t.mat02 = 1;
    //g.setColour();
    g.setColour(Colours::white.withAlpha(getAlpha()));
    glyphs.draw(g, t);
    /*g.fillAll(juce::Colour::fromRGB(1,1,0.5));*/
}

void DriverInputUI::resized()
{
    // This is called when the DriverOutputUI is resized.
    // If you add any child components, this is where you should
    // update their positions.
}

void DriverInputUI::drawUI() {
    int sample = 0;
    switch (sample)
    {
    case 0: {}break;
    default:
        break;
    }
}

void DriverInputUI::drawUIMode1() {
    
}