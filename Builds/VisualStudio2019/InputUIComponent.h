#pragma once
#include <JuceHeader.h>
using namespace juce;
#include "ControlLabelMode01.h"
#include "UIExtendButtonListener.h"
/// <summary>
/// 本文件主要负责编写Input的UI类
/// 在设计中将Input UI 分为 4 种状态
/// 状态1 : 两个通道的缩略显示，其中包含了两个监控音频采样的滑条或者Path ， 一个旋转了-90°的 通道名称
/// 状态2 : 两个通道的展开显示，其中包含了两个监控音频采样的滑条或者Path ， 一个底部的通道名称 ， 两个在顶部的通道相关控制滑条 ， 两个控制按钮 Solo 和 Mute
/// 状态3 : 一个通道的缩略显示，其中包含了一个监控音频采样的滑条或者Path ， 一个旋转了-90°的 通道名称
/// 状态4 : 一个通道的展开显示，其中包含了一个监控音频采样的滑条或者Path ， 一个底部的通道名称 ， 两个在顶部的通道相关控制滑条 ， 两个控制按钮 Solo 和 Mute
/// 
/// 为了可以进行状态的转换，我们还需要添加用于控制 状态的管理类
/// 在设计中状态的转换需要： 使用相关的按钮来进行状态的控制，因此需要将UIComponent 传入到特定按钮来进行管理
/// </summary>

/// <summary>
/// InputUIComponentContainer : InputUI管理类
/// 在window环境下 使用SDK或者 endpoint进行控制
/// 当我们需要进行不同的UI状态时，通过Holder进行UI变换和对象变换
/// </summary>
class InputUIComponentContainer : public Component
{
public :
    InputUIComponentContainer(/*ControllersComponent& cc,*/ const String& name)
        : Component(name)
    {
        setOpaque(true);
    }

    void paint(Graphics& g) override
    {
        auto startTime = 0.0;

        {
            // A ScopedSaveState will return the Graphics context to the state it was at the time of
            // construction when it goes out of scope. We use it here to avoid clipping the fps text
            const Graphics::ScopedSaveState state(g);


            // take a note of the time before the render
            startTime = Time::getMillisecondCounterHiRes();

            // then let the demo draw itself..
            drawDemo(g);
        }

        //auto now = Time::getMillisecondCounterHiRes();
        //auto filtering = 0.08;

        //auto elapsedMs = now - startTime;
        //averageTimeMs += (elapsedMs - averageTimeMs) * filtering;

        //auto sinceLastRender = now - lastRenderStartTime;
        //lastRenderStartTime = now;

        //auto effectiveFPS = 1000.0 / averageTimeMs;
        //auto actualFPS = sinceLastRender > 0 ? (1000.0 / sinceLastRender) : 0;
        //averageActualFPS += (actualFPS - averageActualFPS) * filtering;

        //GlyphArrangement ga;
        //ga.addFittedText(displayFont,
        //    "Time: " + String(averageTimeMs, 2)
        //    + " ms\nEffective FPS: " + String(effectiveFPS, 1)
        //    + "\nActual FPS: " + String(averageActualFPS, 1),
        //    0, 10.0f, (float)getWidth() - 10.0f, (float)getHeight(), Justification::topRight, 3);

        //g.setColour(Colours::white.withAlpha(0.5f));
        //g.fillRect(ga.getBoundingBox(0, ga.getNumGlyphs(), true).getSmallestIntegerContainer().expanded(4));

        //g.setColour(Colours::black);
        //ga.draw(g);
    }
    void setBounsSliderValue(float value) {
        sampleSliderChannel1.get()->setValue(value);
    }


    //每个Stat都需要设置的drawD
    virtual void drawDemo(Graphics&) = 0;
    //===========================变量=================================================
    double lastRenderStartTime = 0.0, averageTimeMs = 0.0, averageActualFPS = 0.0;
    Font displayFont;
    //std::unique_ptr<SliderListener> sliderListener;
    std::unique_ptr<Slider>  sampleSliderChannel1, sampleSliderChannel2;
    std::unique_ptr<Slider> controlsSliderChannel1, controlsSliderChannel2;
    std::unique_ptr<Slider> sampleBarChannel1, sampleBarChannel2;
    std::unique_ptr<Label>  labelMin, label48, label24, label12, label6, label0;
    TextButton* controlButtonChannelT1, controlButtonChannelT2;
    TextButton* controlButtonChannelD1, controlButtonChannelD2;
    Slider* controlsSliderChannelAll;
    std::unique_ptr<ControlLabelMode01>  cMode01;



#ifdef  Windows
    //SDK或者endpoint软件

#endif //  Windows


private:
};
class InputUIComponentStat1 : public InputUIComponentContainer
{
public:
    InputUIComponentStat1(/*ControllersComponent& cc,*/ const String& name, int x, int y)
        : InputUIComponentContainer(name)
    {
        positionX = x;
        positionY = y;
        cMode01.reset(new ControlLabelMode01());

        sampleSliderChannel1.reset(new Slider("d"));
        sampleSliderChannel1->setSliderStyle(Slider::SliderStyle::LinearVertical);
        sampleSliderChannel1->setLookAndFeel(cMode01.get());
        sampleSliderChannel1->setBounds(this->getX() + x + 75, this->getY() + y + 30 , 30, 220);
        sampleSliderChannel1->setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
        sampleSliderChannel1.get()->setColour(Slider::trackColourId, Colours::lightgrey);
        sampleSliderChannel1.get()->setRange(0, 100, 1.0);
        addAndMakeVisible(sampleSliderChannel1.get());

        sampleSliderChannel2.reset(new Slider("d"));
        sampleSliderChannel2->setLookAndFeel(cMode01.get());
        sampleSliderChannel2->setBounds(x+25,y+10, 100, 30);    
        sampleSliderChannel2->setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
        sampleSliderChannel2.get()->setColour(Slider::trackColourId, Colours::lightgrey);
        addAndMakeVisible(sampleSliderChannel2.get());

        labelMin.reset(new Label("labelMin"));
        labelMin.get()->setColour(Label::ColourIds::textColourId, Colours::lightgrey);
        //labelMin.get().set
        labelMin.get()->setText("-00", dontSendNotification);
        labelMin->setBounds(x+15,y+215, 30, 30);
        addAndMakeVisible(labelMin.get());

        label48.reset(new Label("label48"));
        label48.get()->setColour(Label::ColourIds::textColourId, Colours::lightgrey);
        label48.get()->setText("-48", dontSendNotification);
        label48->setBounds(x + 15, y + 180, 30, 30);
        addAndMakeVisible(label48.get());


        label24.reset(new Label("label24"));
        label24.get()->setColour(Label::ColourIds::textColourId, Colours::lightgrey);
        label24.get()->setText("-24", dontSendNotification);
        label24->setBounds(x + 15, y + 135, 30, 30);
        addAndMakeVisible(label24.get());

        label12.reset(new Label("label12"));
        label12.get()->setColour(Label::ColourIds::textColourId, Colours::lightgrey);
        label12.get()->setText("-12", dontSendNotification);
        label12->setBounds(x + 15, y + 95, 30, 30);
        addAndMakeVisible(label12.get());

        label6.reset(new Label("label6"));
        label6.get()->setColour(Label::ColourIds::textColourId, Colours::lightgrey);
        label6.get()->setText("-6", dontSendNotification);
        label6->setBounds(x + 15, y + 65, 30, 30);
        addAndMakeVisible(label6.get());

        label0.reset(new Label("label0"));
        label0.get()->setColour(Label::ColourIds::textColourId, Colours::lightgrey);
        label0.get()->setText("0", dontSendNotification);
        label0->setBounds(x + 15, y + 35, 30, 30);
        addAndMakeVisible(label0.get());

        controlButtonChannelT1 = new TextButton("T");
        controlButtonChannelT1->setName("controlButtonChannelT1");
        controlButtonChannelT1->setBounds(x + 115, y + 155, 20, 20);
        addAndMakeVisible(controlButtonChannelT1);

        controlButtonChannelD1 = new TextButton("D");
        controlButtonChannelD1->setName("controlButtonChannelD1");
        controlButtonChannelD1->setBounds(x + 115, y + 185, 20, 20);
        addAndMakeVisible(controlButtonChannelD1);

        button00.reset(new TextButton("-00"));
        button00->setName("button00");
        button00->setBounds(x + 35, y + 250, 40, 10);
        //button00.get().set
        addAndMakeVisible(button00.get());

        labelSlider.reset(new TextButton("0"));
        labelSlider->setName("labelSlider");
        labelSlider->setBounds(x + 75, y + 250, 40, 10);
        //button00.get().set
        addAndMakeVisible(labelSlider.get());

        muteButton.reset(new TextButton("MUTE"));
        muteButton->setName("muteButton");
        muteButton->setBounds(x + 43, y + 262, 30, 15);
        //new UIExtendButtonListener();
        muteButton.get()->addListener(new UIExtendButtonListener());
        //button00.get().set
        addAndMakeVisible(muteButton.get());

        soloButton.reset(new TextButton("SOLO"));
        soloButton->setName("soloButton");
        soloButton->setBounds(x + 77, y + 262, 30, 15);
        soloButton.get()->addListener(new UIExtendButtonListener());
        //button00.get().set
        addAndMakeVisible(soloButton.get());

        labelChanName.reset(new Label("labelChanName"));
        labelChanName.get()->setColour(Label::ColourIds::textColourId, Colours::lightgrey);
        //labelMin.get().set
        labelChanName.get()->setText(name, dontSendNotification);
        labelChanName->setBounds(x+50, y + 265, 50, 50);
        addAndMakeVisible(labelChanName.get());
        setBounds(positionX, positionY, 150, 330);
        //setSize(150, 330);
        
    }

    ~InputUIComponentStat1() {
        sampleSliderChannel1.get()->setLookAndFeel(nullptr);
        sampleSliderChannel2.get()->setLookAndFeel(nullptr);
    }



    void drawDemo(Graphics& g) override
    {
        //g.addTransform(getTransform());

        const int rectSize = jmin(getWidth(), getHeight()) / 2 - 20;
        
        //g.setColour(Colours::transparentBlack.withAlpha(getAlpha()));

        //g.fillRect(-rectSize, -rectSize, rectSize, rectSize);

        //g.setGradientFill(ColourGradient(colour1, 10.0f, (float)-rectSize,
        //    colour2, 10.0f + (float)rectSize, 0.0f, false));
        //g.setOpacity(getAlpha());
        //g.fillRect(10, -rectSize, rectSize, rectSize);

        //g.setGradientFill(ColourGradient(colour1, (float)rectSize * -0.5f, 10.0f + (float)rectSize * 0.5f,
        //    colour2, 0, 10.0f + (float)rectSize, true));
        //g.setOpacity(getAlpha());
        //g.fillRect(-rectSize, 10, rectSize, rectSize);

        //g.setGradientFill(ColourGradient(colour1, 10.0f, 10.0f,
        //    colour2, 10.0f + (float)rectSize, 10.0f + (float)rectSize, false));


        g.setOpacity(getAlpha());


        g.setColour(Colours::transparentBlack.withAlpha(getAlpha()));
        g.fillRect(positionX, positionY, 150, 333);


        g.setColour(Colours::grey);
        g.drawLine(0, 0, 0, 305, 1);
        g.drawLine(0, 325, 0, 333, 1);
        //g.drawRect(0, 0, getWidth(), getHeight(), 1);
        /*glyphs.draw(g, t);*/
    }
private:
    /*AffineTransform t;
    GlyphArrangement glyphs;*/
    Colour colour1{ Colours::red }, colour2{ Colours::green };
    int positionX = 0, positionY = 0;
    std::unique_ptr<TextButton> muteButton, soloButton;
    std::unique_ptr<TextButton> button00,labelSlider ;
    std::unique_ptr<Label> labelChanName;
};
//
class InputUIComponentStat2 : public InputUIComponentContainer
{
public:
    InputUIComponentStat2(/*ControllersComponent& cc,*/ const String& name, int x, int y)
        : InputUIComponentContainer(name)
    {
        positionX = x;
        positionY = y;
        //Font()
        glyphs.addFittedText({ 12.5f }, name,
            -400, 0.5, 240, 100, Justification::centred, 15, 1.0f);
        
        t.mat00 = 0;
        t.mat01 = 1;
        t.mat11 = 0;
        t.mat10 = -1;
        sampleSliderChannel1.reset(new Slider("d"));
        sampleSliderChannel1->setLookAndFeel(cMode01.get());
        sampleSliderChannel1.get()->setRange(0, 100, 1.0);
        //sampleSliderChannel1->setBounds(100, 100, 500, 300);
        addAndMakeVisible(sampleSliderChannel1.get());
        setSize(75, 333);

    }
    void drawDemo(Graphics& g) override
    {
        //g.setFont(Font())
        g.setColour(Colours::transparentBlack.withAlpha(getAlpha()));
       
        g.fillRect(positionX, positionY, 75, 333);

        //g.drawImage(ImageCache::getFromMemory(BinaryData::LevelMeterSample_png, BinaryData::LevelMeterSample_pngSize),
        //    juce::Rectangle<float>(static_cast<float> (10), static_cast<float> (260)).withCentre(Point<float>
        //{static_cast<float>(positionX) + 10, static_cast<float>(positionY) + 150}));
        //g.drawImage(ImageCache::getFromMemory(BinaryData::LevelMeterSample_png, BinaryData::LevelMeterSample_pngSize),
        //    juce::Rectangle<float>(static_cast<float> (10), static_cast<float> (260)).withCentre(Point<float>
        //{static_cast<float>(positionX) + 25, static_cast<float>(positionY) + +150}));
        Colour a = Colour(0xFf808080); 
        a.brighter(4.0f);
        g.setColour(a);
        glyphs.draw(g, t);

        g.setColour(Colours::grey);
        float ods = getHeight();
        g.drawRect(0, 0, getWidth(), getHeight(), 1);
    }

    ~InputUIComponentStat2() {

    }
private:
    int positionX = 0, positionY = 0;
    AffineTransform t;
    GlyphArrangement glyphs;
    Colour colour1{ Colours::red }, colour2{ Colours::green };
};
//
//class InputUIComponentStat3 : public InputUIComponentContainer
//{
//};
//
//class InputUIComponentStat4 : public InputUIComponentContainer
//{
//};

class InputUIComponentStat3 : public InputUIComponentContainer
{
public:
    InputUIComponentStat3(/*ControllersComponent& cc,*/ const String& name, int x, int y)
        : InputUIComponentContainer(name)
    {
        positionX = x;
        positionY = y;
        cMode01.reset(new ControlLabelMode01());

        int klad = 0;
        //sliderListener.reset(new SliderListener(klad));


        sampleSliderChannel1.reset(new Slider("d"));
        sampleSliderChannel1->setSliderStyle(Slider::SliderStyle::LinearVertical);
        sampleSliderChannel1->setLookAndFeel(cMode01.get());
        sampleSliderChannel1->setBounds(this->getX() + x + 85, this->getY() + y + 30, 30, 220);
        sampleSliderChannel1->setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
        sampleSliderChannel1.get()->setColour(Slider::trackColourId, Colours::lightgrey);
        sampleSliderChannel1.get()->setRange(0, 100, 1.0);
        //sampleSliderChannel1.get()->addListener(sliderListener.get());
        addAndMakeVisible(sampleSliderChannel1.get());



        sampleSliderChannel2.reset(new Slider("d"));
        sampleSliderChannel2->setLookAndFeel(cMode01.get());
        sampleSliderChannel2->setBounds(x + 25, y + 10, 50, 30);
        sampleSliderChannel2->setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
        sampleSliderChannel2.get()->setColour(Slider::trackColourId, Colours::lightgrey);
        addAndMakeVisible(sampleSliderChannel2.get());

        controlsSliderChannel1.reset(new Slider("d"));
        controlsSliderChannel1->setLookAndFeel(cMode01.get());
        controlsSliderChannel1->setBounds(x + 75, y + 10, 50, 30);
        controlsSliderChannel1->setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
        controlsSliderChannel1.get()->setColour(Slider::trackColourId, Colours::lightgrey);
        addAndMakeVisible(controlsSliderChannel1.get());




        labelMin.reset(new Label("labelMin"));
        labelMin.get()->setColour(Label::ColourIds::textColourId, Colours::lightgrey);
        //labelMin.get().set
        labelMin.get()->setText("-00", dontSendNotification);
        labelMin->setBounds(x + 15, y + 215, 30, 30);
        addAndMakeVisible(labelMin.get());

        label48.reset(new Label("label48"));
        label48.get()->setColour(Label::ColourIds::textColourId, Colours::lightgrey);
        label48.get()->setText("-48", dontSendNotification);
        label48->setBounds(x + 15, y + 180, 30, 30);
        addAndMakeVisible(label48.get());


        label24.reset(new Label("label24"));
        label24.get()->setColour(Label::ColourIds::textColourId, Colours::lightgrey);
        label24.get()->setText("-24", dontSendNotification);
        label24->setBounds(x + 15, y + 135, 30, 30);
        addAndMakeVisible(label24.get());

        label12.reset(new Label("label12"));
        label12.get()->setColour(Label::ColourIds::textColourId, Colours::lightgrey);
        label12.get()->setText("-12", dontSendNotification);
        label12->setBounds(x + 15, y + 95, 30, 30);
        addAndMakeVisible(label12.get());

        label6.reset(new Label("label6"));
        label6.get()->setColour(Label::ColourIds::textColourId, Colours::lightgrey);
        label6.get()->setText("-6", dontSendNotification);
        label6->setBounds(x + 15, y + 65, 30, 30);
        addAndMakeVisible(label6.get());

        label0.reset(new Label("label0"));
        label0.get()->setColour(Label::ColourIds::textColourId, Colours::lightgrey);
        label0.get()->setText("0", dontSendNotification);
        label0->setBounds(x + 15, y + 35, 30, 30);
        addAndMakeVisible(label0.get());

        controlButtonChannelT1 = new TextButton("T");
        controlButtonChannelT1->setName("controlButtonChannelT1");
        controlButtonChannelT1->setBounds(x + 115, y + 155, 20, 20);
        addAndMakeVisible(controlButtonChannelT1);

        controlButtonChannelD1 = new TextButton("D");
        controlButtonChannelD1->setName("controlButtonChannelD1");
        controlButtonChannelD1->setBounds(x + 115, y + 185, 20, 20);
        addAndMakeVisible(controlButtonChannelD1);

        button00.reset(new TextButton("-00"));
        button00->setName("button00");
        button00->setBounds(x + 30, y + 250, 30, 10);
        //button00.get().set
        addAndMakeVisible(button00.get());

        button001.reset(new TextButton("-00"));
        button001->setName("button001");
        button001->setBounds(x + 60, y + 250, 30, 10);
        //button00.get().set
        addAndMakeVisible(button001.get());

        labelSlider.reset(new TextButton("0"));
        labelSlider->setName("labelSlider");
        labelSlider->setBounds(x + 90, y + 250, 30, 10);
        //button00.get().set
        addAndMakeVisible(labelSlider.get());

        muteButton.reset(new TextButton("MUTE"));
        muteButton->setName("muteButton");
        muteButton->setBounds(x + 43, y + 262, 30, 15);
        //button00.get().set
        addAndMakeVisible(muteButton.get());

        soloButton.reset(new TextButton("SOLO"));
        soloButton->setName("soloButton");
        soloButton->setBounds(x + 77, y + 262, 30, 15);
        //button00.get().set
        addAndMakeVisible(soloButton.get());

        labelChanName.reset(new Label("labelChanName"));
        labelChanName.get()->setColour(Label::ColourIds::textColourId, Colours::lightgrey);
        //labelMin.get().set
        labelChanName.get()->setText(name, dontSendNotification);
        labelChanName.get()->setFont(Font(14.0f));
        labelChanName->setBounds(x + 35, y + 265, 80, 50);
        addAndMakeVisible(labelChanName.get());
        setBounds(positionX, positionY, 150, 330);
        setSize(150, 330);

    }

    ~InputUIComponentStat3() {
        sampleSliderChannel1->setLookAndFeel(nullptr);
        sampleSliderChannel2->setLookAndFeel(nullptr);
        controlsSliderChannel1->setLookAndFeel(nullptr);
            //sampleSliderChannel2, controlsSliderChannel1
    }
    void drawDemo(Graphics& g) override
    {
        //g.addTransform(getTransform());

        const int rectSize = jmin(getWidth(), getHeight()) / 2 - 20;

        g.setColour(Colours::transparentBlack.withAlpha(getAlpha()));

        g.setOpacity(getAlpha());
        //g.drawRect(10, 10, rectSize, rectSize, 5);
        g.fillRect(positionX, positionY, 180, 330);
        //g.drawImage(ImageCache::getFromMemory(BinaryData::LevelMeterSample_png, BinaryData::LevelMeterSample_pngSize),
        //    juce::Rectangle<float>(static_cast<float> (10), static_cast<float> (185)).withCentre(Point<float>
        //{static_cast<float>(positionX) + 55, static_cast<float>(positionY) + 140}));

        //g.drawImage(ImageCache::getFromMemory(BinaryData::LevelMeterSample_png, BinaryData::LevelMeterSample_pngSize),
        //    juce::Rectangle<float>(static_cast<float> (10), static_cast<float> (185)).withCentre(Point<float>
        //{static_cast<float>(positionX) + 70, static_cast<float>(positionY) + 140}));

        g.setColour(Colours::grey);
        g.drawRect(0, 0, getWidth(), getHeight(), 1);
        /*glyphs.draw(g, t);*/
    }
private:
    /*AffineTransform t;
    GlyphArrangement glyphs;*/
    Colour colour1{ Colours::red }, colour2{ Colours::green };
    int positionX = 0, positionY = 0;
    std::unique_ptr<TextButton> muteButton, soloButton;
    std::unique_ptr<TextButton> button00, button001,labelSlider;
    std::unique_ptr<Label> labelChanName;
};