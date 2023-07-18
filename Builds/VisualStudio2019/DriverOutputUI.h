#pragma once

#include <JuceHeader.h>
#include "UIExtendButtonListener.h"
#include "ControlLabelMode01.h"
typedef std::unique_ptr<juce::Slider> JuceSlider;
class DriverOutputUI : public juce::Component /*,juce::Button::Listener*/
{
public:
    //==============================================================================
    DriverOutputUI();
    DriverOutputUI(juce::String name);
    ~DriverOutputUI() override;

    //==============================================================================
    void paint(juce::Graphics&) override;
    void resized() override;
    void getSlider();
    void setSampleSliderValue(float value1,float value2);
private:
    //==============================================================================
    // Your private member variables go here...
    std::unique_ptr<juce::TextButton> textButtonMute;
    std::unique_ptr<juce::TextButton> textButtonSolo;
    std::unique_ptr<juce::TextButton> textButtonSpe;
    std::unique_ptr<juce::TextButton> textButtonMonitor;
    std::unique_ptr<juce::ImageComponent> textImageComponent;
    std::unique_ptr<juce::ImageComponent> textImageComponent01;
    std::unique_ptr<juce::ImageComponent> textImageComponent02;
   // std::unique_ptr<juce::ImageCache> textImageCache;
    juce::OwnedArray<juce::Slider> sliders;
    std::unique_ptr<juce::Slider> textSlider;
    std::unique_ptr<juce::Slider> sampleSlider1;
    std::unique_ptr<juce::Slider> sampleSlider2;
    std::unique_ptr<juce::Label> textLabelName;
    std::unique_ptr<juce::Label> textLabelChannel;
    std::unique_ptr<ControlLabelMode01>  cMode01;
    //JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DriverOutputUI)
};

class DriverInputUI : public juce::Component, juce::Button::Listener
{
public:
    //==============================================================================
    DriverInputUI();
    
    ~DriverInputUI() override;

    //==============================================================================
    void paint(juce::Graphics&) override;
    void resized() override;
    
private:
    //==============================================================================
    // Your private member variables go here...
    //滑条指针
    
    std::unique_ptr<juce::Slider> textSlider;
    std::unique_ptr<juce::Slider> textSlider2;
    std::unique_ptr<juce::Slider> textSlider3;
    std::unique_ptr<juce::Slider> textSlider4;


    //按钮指针
    std::unique_ptr<juce::TextButton> linkButton; //用来开启关闭Channel连接的按钮
    //T,D按钮指针
    std::unique_ptr<juce::TextButton> buttonTChannel1;
    std::unique_ptr<juce::TextButton> buttonDChannel1;
    std::unique_ptr<juce::TextButton> buttonTChannel2;
    std::unique_ptr<juce::TextButton> buttonDChannel2;
    std::unique_ptr<juce::TextButton> buttonTChannelAll;
    std::unique_ptr<juce::TextButton> buttonDChannelAll;
    //静音和Solo按钮指针
    std::unique_ptr<juce::TextButton> buttonMuteChannel1;
    std::unique_ptr<juce::TextButton> buttonMuteChannel2;
    std::unique_ptr<juce::TextButton> buttonMuteChannelAll;
    std::unique_ptr<juce::TextButton> buttonSoloChannel1;
    std::unique_ptr<juce::TextButton> buttonSoloChannel2;
    std::unique_ptr<juce::TextButton> buttonSoloChannelAll;

    //扩展按钮
    std::unique_ptr<juce::TextButton> buttonChangeMode1;


    std::unique_ptr<juce::TextButton> textButtonSpe2;
    std::unique_ptr<juce::TextButton> textButtonMonitor2;

    //图片对象指针
    std::unique_ptr<juce::ImageComponent> textImageComponent;
    std::unique_ptr<juce::ImageComponent> textImageComponent01;
    std::unique_ptr<juce::ImageComponent> textImageComponent02;

    //滑条-自行绘制
    JuceSlider mode1_JuceSliderChannel1;
    JuceSlider mode1_JuceSliderChannel2;
    juce::OwnedArray<juce::Slider> sliders;

    // std::unique_ptr<juce::ImageCache> textImageCache;
    //各类提示Label
    std::unique_ptr<juce::Label> mode1_LabelName;
    std::unique_ptr<juce::Label> mode2_LabelName;
    std::unique_ptr<juce::Label> mode3_LabelNameChannel1;
    std::unique_ptr<juce::Label> mode3_LabelNameChannel2;

    //单独绘制
    std::unique_ptr<UIExtendButtonListener> uiExtendButton;

    std::unique_ptr<juce::Label> textLabelName;
    std::unique_ptr<juce::Label> textLabelChannel;
    std::unique_ptr<juce::Label> textLabelName1;
    std::unique_ptr<juce::Label> textLabelChannel2;

    juce::GlyphArrangement glyphs;
    //juce::Graphics LabelGraphics;
    int flag = 0 ;

    void DriverInputUI::buttonClicked(juce::Button*) override;
    void drawUI();

    void drawUIMode1();
    //void drawUIMode2();
    //void drawUIMode3();
    //void drawUIMode4();
    
    //JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DriverInputUI)


};

