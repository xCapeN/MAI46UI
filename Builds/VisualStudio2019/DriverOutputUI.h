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
    //����ָ��
    
    std::unique_ptr<juce::Slider> textSlider;
    std::unique_ptr<juce::Slider> textSlider2;
    std::unique_ptr<juce::Slider> textSlider3;
    std::unique_ptr<juce::Slider> textSlider4;


    //��ťָ��
    std::unique_ptr<juce::TextButton> linkButton; //���������ر�Channel���ӵİ�ť
    //T,D��ťָ��
    std::unique_ptr<juce::TextButton> buttonTChannel1;
    std::unique_ptr<juce::TextButton> buttonDChannel1;
    std::unique_ptr<juce::TextButton> buttonTChannel2;
    std::unique_ptr<juce::TextButton> buttonDChannel2;
    std::unique_ptr<juce::TextButton> buttonTChannelAll;
    std::unique_ptr<juce::TextButton> buttonDChannelAll;
    //������Solo��ťָ��
    std::unique_ptr<juce::TextButton> buttonMuteChannel1;
    std::unique_ptr<juce::TextButton> buttonMuteChannel2;
    std::unique_ptr<juce::TextButton> buttonMuteChannelAll;
    std::unique_ptr<juce::TextButton> buttonSoloChannel1;
    std::unique_ptr<juce::TextButton> buttonSoloChannel2;
    std::unique_ptr<juce::TextButton> buttonSoloChannelAll;

    //��չ��ť
    std::unique_ptr<juce::TextButton> buttonChangeMode1;


    std::unique_ptr<juce::TextButton> textButtonSpe2;
    std::unique_ptr<juce::TextButton> textButtonMonitor2;

    //ͼƬ����ָ��
    std::unique_ptr<juce::ImageComponent> textImageComponent;
    std::unique_ptr<juce::ImageComponent> textImageComponent01;
    std::unique_ptr<juce::ImageComponent> textImageComponent02;

    //����-���л���
    JuceSlider mode1_JuceSliderChannel1;
    JuceSlider mode1_JuceSliderChannel2;
    juce::OwnedArray<juce::Slider> sliders;

    // std::unique_ptr<juce::ImageCache> textImageCache;
    //������ʾLabel
    std::unique_ptr<juce::Label> mode1_LabelName;
    std::unique_ptr<juce::Label> mode2_LabelName;
    std::unique_ptr<juce::Label> mode3_LabelNameChannel1;
    std::unique_ptr<juce::Label> mode3_LabelNameChannel2;

    //��������
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

