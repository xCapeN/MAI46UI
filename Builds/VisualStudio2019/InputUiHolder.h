#pragma once
#include <JuceHeader.h>
#include <InputUIComponent.h>
#include <regex>
using namespace juce;
class InputUiHolder :public Component
    ,
   private Timer
{
public :
    InputUiHolder()
    {
        
        
        
        currentDemo4.reset(new InputUIComponentStat1("Input 4/5",150, 0));
        currentDemo2.reset(new InputUIComponentStat1("Input 3/2", 0,0));
        currentDemo.reset(new InputUIComponentStat1("Virtual 1 / 2", 150, 0));
        //currentDemo1.reset(new InputUIComponentStat1("Input 1/2", 0, 0));
        if (currentDemo != nullptr || currentDemo2 != nullptr)
        {
            
            addAndMakeVisible(currentDemo.get());
            //addAndMakeVisible(currentDemo1.get());
            addAndMakeVisible(currentDemo2.get());
           // addAndMakeVisible(currentDemo4.get());
            //startTimerHz(60);
            resized();
        }

        setOpaque(true);
        setSize(300, 330);
    }

    InputUiHolder( int mode,std::string componentName = "")
    {        

        //juce::String pkasd(sdk);
        //if (pkasd == "") {
        //    pkasd = "Virtual 1 / 2";
        //}
        //OpenButtonListener* opButtonListener = new OpenButtonListener();
        opButtonListener.reset(new OpenButtonListener(klad));
        cMode01.reset(new ControlLabelMode01());
        juce::String pkasd(componentName);
        if(pkasd == "") pkasd = "Virtual 1 / 2";
        if (mode == 2) {
            stest = pkasd;
            currentDemo.reset(new InputUIComponentStat2(pkasd, 0, 0));
            //currentDemo2.reset(new InputUIComponentStat1("Input 3/2", 0, 0));
            //currentDemo.reset(new InputUIComponentStat1("Virtual 1 / 2", 0, 0));
            //currentDemo1.reset(new InputUIComponentStat1("Input 1/2", 0, 0));
            if (currentDemo != nullptr || currentDemo2 != nullptr)
            {
                //currentDemo2.get()->setBounds(150, 0, 150, 330);
                addAndMakeVisible(currentDemo.get());
                //addAndMakeVisible(currentDemo2.get());
                //currentDemo2.get()->toFront(false);
                //addAndMakeVisible(currentDemo1.get());
                // addAndMakeVisible(currentDemo4.get());
                //startTimerHz(15);
                resized();
            }

            setOpaque(true);
            setSize(75, 333);
            testSlider.reset(new Slider(Slider::SliderStyle::LinearBarVertical,Slider::TextEntryBoxPosition::NoTextBox));
            testSlider.get()->setBounds(14,15,8,300);
            testSlider.get()->setRange(0.0, 1.0, 0.01);
            //testSlider.get()->setMinValue(0.0, false);


            addAndMakeVisible(testSlider.get());

            testSlider1.reset(new Slider(Slider::SliderStyle::LinearBarVertical, Slider::TextEntryBoxPosition::NoTextBox));
            testSlider1.get()->setBounds(26, 15, 8, 300);
            testSlider1.get()->setRange(0.0, 1.0, 0.01);
            addAndMakeVisible(testSlider1.get());

            testSlider.get()->setEnabled(false);
            //testSlider.get()->setValue(100);
            


            //addAndMakeVisible(openButton.get());

            Image normal = ImageCache::getFromMemory(BinaryData::D_png, BinaryData::D_pngSize);
            Image normal2 = ImageCache::getFromMemory(BinaryData::T_png, BinaryData::T_pngSize);
            Image normal3 = ImageCache::getFromMemory(BinaryData::close_png, BinaryData::close_pngSize);
            Image normal4 = ImageCache::getFromMemory(BinaryData::open_png, BinaryData::open_pngSize);

            openButton.reset(new ImageButton("compileOpenButton"));
            
            openButton.get()->addListener(opButtonListener.get());
            openButton.get()->setImages(true, true, true, normal4, 1, Colours::transparentWhite, normal4, 1, Colours::transparentWhite, normal4, 1, Colours::transparentWhite);
            openButton.get()->setBounds(130, 240, 20, 10);

            closeButton.reset(new ImageButton("compileCloseButton"));
            closeButton.get()->setImages(true,true,true, normal3,1,Colours::transparentWhite, normal3,1, Colours::transparentWhite, normal3,1, Colours::transparentWhite);
            closeButton.get()->setEnabled(true);
            //closeButton.get()->setButtonText("T");
            
            closeButton.get()->setBounds(0,323,10, 10);
            closeButton.get()->addListener(opButtonListener.get());
            addAndMakeVisible(closeButton.get());


            Image linkOn = ImageCache::getFromMemory(BinaryData::ButtonLinkNormal_png, BinaryData::ButtonLinkNormal_pngSize);
            linkOnButton.reset(new ImageButton("linkOnButton"));
            linkOnButton.get()->setImages(true, true, true, linkOn, 1, Colours::transparentWhite, linkOn, 1, Colours::transparentWhite, linkOn, 1, Colours::transparentWhite);
            linkOnButton.get()->setBounds(75, 305, 20, 20);
            linkOnButton.get()->addListener(opButtonListener.get());

            Image linkOff = ImageCache::getFromMemory(BinaryData::ButtonLinkSelected_png, BinaryData::ButtonLinkSelected_pngSize);
            linkOffButton.reset(new ImageButton("linkOffButton"));
            linkOffButton.get()->setImages(true, true, true, linkOff, 1, Colours::transparentWhite, linkOff, 1, Colours::transparentWhite, linkOff, 1, Colours::transparentWhite);
            linkOffButton.get()->setBounds(75, 305, 20, 20);
            linkOffButton.get()->addListener(opButtonListener.get());
            //linkOffButton.get()->addListener(opButtonListener.get());
            //openButton.get()->setImages()
        }
        else if (mode == 3) {
            currentDemo.reset(new InputUIComponentStat3(pkasd, 0, 0));
            //currentDemo1.reset(new InputUIComponentStat1("Input 1/2", 0, 0));
            if (currentDemo != nullptr || currentDemo2 != nullptr)
            {

                addAndMakeVisible(currentDemo.get());
                //addAndMakeVisible(currentDemo1.get());
                // addAndMakeVisible(currentDemo4.get());
               // startTimerHz(5);
                resized();
            }
            
            setOpaque(true);
            setSize(180, 333);
        }
        //this = newholder;
    }

    void paint(Graphics& g) override
    {
        String s = this->getName();
        g.fillCheckerBoard(getLocalBounds().toFloat(), 48.0f, 48.0f,
            Colours::lightgrey, Colours::white);
    }

    void setSampleSliderValue(float sample1,float sample2 = -1) {
        if (sample2 == -1) sample2 = sample1;
        testSlider.get()->setValue(sample1 );
        testSlider1.get()->setValue(sample2 );
    }

    void setDemoSliderValue(float value1, float value2 = -1) {
        if (currentDemo != nullptr) {
            currentDemo.get()->setBounsSliderValue(value1);
        }
    }

    void timerCallback() override
    {
        if (currentDemo != nullptr)
            currentDemo->repaint();
        //if (currentDemo1 != nullptr)
        //    currentDemo1->repaint();
        //if (currentDemo2 != nullptr)
        //    currentDemo2->repaint();
        //if (currentDemo4 != nullptr)
        //    currentDemo4->repaint();
    }

    void setDemo(int flag)
    {
       // if (currentDemo1 != nullptr)
            //removeChildComponent(currentDemo1);
        //currentDemo.get()->setLookAndFeel(nullptr);
        //currentDemo2.get()->setLookAndFeel(nullptr);
        //currentDemo.reset(newDemo);
        //currentDemo2.reset(nullptr);
        switch (flag) {
        case 1: {
            if (currentDemo != nullptr)
                removeChildComponent(currentDemo.get());
            currentDemo.reset(new InputUIComponentStat3(stest, 0, 0));
            if (currentDemo != nullptr)
            {
                addAndMakeVisible(currentDemo.get());


                //开关测试问题
                //setSize(150, 333);
                testSlider.get()->setBounds(50, 40, 10, 200);
                testSlider1.get()->setBounds(65, 40, 10, 200);
                removeChildComponent(closeButton.get());
                //removeChildComponent(currentDemo.get());
                addAndMakeVisible(openButton.get());
                //currentDemo2.reset(new InputUIComponentStat1("Input 3/2",150, 0));
                //addAndMakeVisible(currentDemo2.get());


                linkOnButton.get()->setBounds(65, 305, 20, 20);
                addAndMakeVisible(linkOnButton.get());

                setSize(150, 333);

                linkOnButton.get()->toFront(false);
                currentDemo.get()->toBack();
                //currentDemo2.get()->toBack();
                resized();
            }
        }break;
        case 2: {
            if (currentDemo != nullptr)
                removeChildComponent(currentDemo.get());
            currentDemo.reset(new InputUIComponentStat2(stest, 0, 0));
            if (currentDemo != nullptr)
            {
                addAndMakeVisible(currentDemo.get());


                //开关测试问题
                //setSize(150, 333);
                testSlider.get()->setBounds(14, 15, 8, 300);
                testSlider1.get()->setBounds(26, 15, 8, 300);
                removeChildComponent(openButton.get());
                //removeChildComponent(currentDemo.get());
                addAndMakeVisible(closeButton.get());
                //currentDemo2.reset(new InputUIComponentStat1("Input 3/2",150, 0));
                //addAndMakeVisible(currentDemo2.get());



                setSize(75, 333);


                currentDemo.get()->toBack();
                //currentDemo2.get()->toBack();
                resized();
            }}
              break;

        case 3: {
            if (currentDemo != nullptr)
                removeChildComponent(currentDemo.get());
            currentDemo.reset(new InputUIComponentStat1(stest, 0, 0));
            currentDemo2.reset(new InputUIComponentStat1("dasd", 0, 0));
            if (currentDemo != nullptr)
            {
                addAndMakeVisible(currentDemo.get());

                currentDemo2.get()->setBounds(150, 0, 150, 333);
                addAndMakeVisible(currentDemo2.get());

                testSlider.get()->setBounds(50, 40, 8, 200);
                testSlider1.get()->setBounds(200, 40, 8, 200);


                linkOffButton.get()->setBounds(140, 305, 20, 20);
                removeChildComponent(linkOnButton.get());
                addAndMakeVisible(linkOffButton.get());


                setSize(300, 333);

                linkOffButton.get()->toFront(false);
                testSlider1.get()->toFront(false);
                testSlider.get()->toFront(false);
                currentDemo.get()->toBack();
                //currentDemo2.get()->toBack();
                resized();
            }
        
        }
              break;
        case 4: {
            if (currentDemo != nullptr)
                removeChildComponent(currentDemo.get());
            if (currentDemo2 != nullptr)
                removeChildComponent(currentDemo2.get());
            currentDemo.reset(new InputUIComponentStat3(stest, 0, 0));
            if (currentDemo != nullptr)
            {
                addAndMakeVisible(currentDemo.get());


                //开关测试问题
                //setSize(150, 333);
                testSlider.get()->setBounds(50, 40, 10, 200);
                testSlider1.get()->setBounds(65, 40, 10, 200);
                //removeChildComponent(closeButton.get());
                ////removeChildComponent(currentDemo.get());
                //addAndMakeVisible(openButton.get());
                //currentDemo2.reset(new InputUIComponentStat1("Input 3/2",150, 0));
                //addAndMakeVisible(currentDemo2.get());

                removeChildComponent(linkOffButton.get());
                //addAndMakeVisible(linkOffButton.get());
                linkOnButton.get()->setBounds(65, 305, 20, 20);
                addAndMakeVisible(linkOnButton.get());

                setSize(150, 333);

                linkOnButton.get()->toFront(false);
                currentDemo.get()->toBack();
                //currentDemo2.get()->toBack();
                resized();
            }}
              break;
        }
        
        if (getParentComponent() != nullptr) {
            getParentComponent()->repaint();

        }
        
    }

    void resized() override
    {
        if (currentDemo != nullptr)
            currentDemo->setBounds(getLocalBounds());
        //if (currentDemo2 != nullptr)
        //    currentDemo2->setBounds(getLocalBounds());
        //if (currentDemo4 != nullptr)
        //    currentDemo4->setBounds(getLocalBounds());
    }
    /// <summary>
    /// checkLinkAndOpen方法，用来检查UI界面操作状态
    /// 如果linkFlag == true ,则此时两个通道为合并状态
    /// -------若此时 closeFlag_All == true , 则为合并缩略状态
    /// 如果linkFlag == false ,则此时两个通道为分离状态（holder转变为持有两个Demo
    /// -------此时 closeFlag_First == true ，这通道1 为缩略状态 | 为 false 则反之
    /// -------此时 closeFlag_Second == true ，这通道2 为缩略状态
    /// </summary>
    /// <param name="message"></param>
    int checkLinkAndOpen(String name ) {
        //linkFlag = !linkFlag;
        if (name == "compileCloseButton") {
            linkFlag = true;
            closeFlag_All = false;
            closeFlag_First = true;
            closeFlag_Second = true;
            return 1;
        }
        else if (name == "compileOpenButton") {
            linkFlag = true;
            closeFlag_All = true;
            closeFlag_First = true;
            closeFlag_Second = true;
            return 2;
        }
        else if (name == "linkOnButton") {
            linkFlag = false;
            closeFlag_All = false;
            closeFlag_First = false;
            closeFlag_Second = false;
            return 3;
        }
        else if (name == "linkOffButton") {
            linkFlag = true;
            closeFlag_All = false;           
            return 4;
        }
        return 0;

    }

    void setIndex(int index) {
        inputHolderIndex = index;
    }

    int getIndex() {
        return inputHolderIndex;
    }

    class OpenButtonListener : public Button::Listener {
    public:
        OpenButtonListener() = default;
        OpenButtonListener(int& stage) {
            parentstage = stage;
        };
        //UIExtendButtonListener(const String& name) ;
        //void UIExtendButtonListener::buttonClicked(juce::Button*) override;

        void buttonClicked(Button* btn) override {
            parentstage++;

            iph = (InputUiHolder*)btn->getParentComponent();
            int flag = iph->checkLinkAndOpen(btn->getName());
            iph->setDemo(flag);

        };
        void buttonStateChanged(Button*) override {
            int ksadli = 0;
        };
        int parentstage = 0;
        InputUiHolder* iph;
    };
private :
   // InputUIComponent* currentDemo = nullptr;
    InputUIComponentContainer* ddaw; 
    std::unique_ptr<InputUIComponentContainer> currentDemo;
    //std::unique_ptr<InputUIComponentContainer> currentDemo1;
    std::unique_ptr<InputUIComponentContainer> currentDemo2;
    std::unique_ptr<InputUIComponentContainer> currentDemo3;
    std::unique_ptr<InputUIComponentContainer> currentDemo4;
    std::unique_ptr<InputUIComponentContainer> currentDemo5;
     //InputUIComponentContainer* currentDemo1 = nullptr;
    std::unique_ptr<Slider> testSlider;
    std::unique_ptr<Slider> testSlider1;
    std::unique_ptr<ControlLabelMode01>  cMode01;
    std::unique_ptr<OpenButtonListener>  opButtonListener;

    std::unique_ptr<ImageButton> openButton;
    std::unique_ptr<ImageButton> closeButton;
    std::unique_ptr<ImageButton> linkOnButton;
    std::unique_ptr<ImageButton> linkOffButton;


    int klad = 0;
    String stest = "";
    bool linkFlag = true;
    bool closeFlag_All = true;
    bool closeFlag_First = false;
    bool closeFlag_Second = false;
    int inputHolderIndex = -1;
    //JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(InputUiHolder)
};


class DemoHolderComponent : public Component,
    private Timer
{
public:
    DemoHolderComponent()
    {
        setOpaque(true);
    }

    void paint(Graphics& g) override
    {
        g.fillCheckerBoard(getLocalBounds().toFloat(), 48.0f, 48.0f,
            Colours::lightgrey, Colours::white);
    }

    void timerCallback() override
    {
        if (currentDemo != nullptr)
            currentDemo->repaint();
    }

    //void setDemo(GraphicsDemoBase* newDemo)
    //{
    //    if (currentDemo != nullptr)
    //        removeChildComponent(currentDemo);

    //    currentDemo = newDemo;

    //    if (currentDemo != nullptr)
    //    {
    //        addAndMakeVisible(currentDemo);
    //        startTimerHz(120);
    //        resized();
    //    }
    //}

    void resized() override
    {
        if (currentDemo != nullptr)
            currentDemo->setBounds(getLocalBounds());
    }

private:
    Component* currentDemo = nullptr;
};