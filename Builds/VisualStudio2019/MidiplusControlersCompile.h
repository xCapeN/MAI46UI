#pragma once
#include "InputUiHolder.h"
#include "DriverOutputUI.h"
#include "juce_hid/juce_hid.h"
//#include <iostream>



#ifdef JUCE_WINDOWS
// Windows multimedia device
#include <Mmdeviceapi.h>
#include <Functiondiscoverykeys_devpkey.h>
////
////// WASAPI
#include <Audiopolicy.h>
#include <Audioclient.h>
#include <vector>
#include <random>
#include <cstring>
#include <atlstr.h>
#include "endpointvolume.h"
#include <audioenginebaseapo.h>
//#define REFTIMES_PER_SEC  10000000ll
//#define REFTIMES_PER_MILLISEC  10000
//
#define EXIT_ON_ERROR(hres)  \
              if (FAILED(hres)) { goto Exit; }
#define SAFE_RELEASE(punk)  \
              if ((punk) != NULL)  \
                { (punk)->Release(); (punk) = NULL; }
//
//const IID IID_IDeviceTopology = __uuidof(IDeviceTopology);
//const IID IID_IPart = __uuidof(IPart);
//
//
//static BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);
//static void DrawPeakMeter(HWND, float);

//
//void SetVolumTextBoxText(TextButton* tB, string mp) {
//    //const MessageManagerLock mmLock;
//    tB->setButtonText(mp);
//}
//
//void ReadVolumSample(TextButton* tB, IAudioMeterInformation* iami) {
//    float pSampleValue = 0;
//    while (true) {
//
//        string mp = std::to_string(iami->GetPeakValue(&pSampleValue));
//        //std::thread tfboys(SetVolumTextBoxText, tB, mp);
//    }
//}
//
//struct SampleTextBundle {
//    TextButton* tB;
//    IAudioMeterInformation* iami;
//};
//
//DWORD WINAPI SampleReadThread(LPVOID lpParam)
//{
//    //cout << "in thread1@!" << endl;
//
//    //DWORD dReturn = WaitForSingleObject(hEvent, INFINITE);
//
//
//    SampleTextBundle* myReadP = (SampleTextBundle*)(lpParam);
//    SampleTextBundle myRead = *myReadP;
//
//    //myRead.aSliders[0]->setValue(100);
//
//
//    //std::thread tfboys(foo, myRead.aSliders[0]);
//    //myRead.aSliders[0]->setValue(100);
//
//    unsigned char data[64];
//    float lastVolumBytes = 0;
//    myRead.iami->GetPeakValue(&lastVolumBytes);
//    //std::thread Sampleboys(SetVolumTextBoxText, myRead.tB, std::to_string(lastVolumBytes));
//    std::thread Sampleboys;
//    //Sampleboys.detach();
//    size_t datalength = 64;
//    while (true)
//    {
//        myRead.iami->GetPeakValue(&lastVolumBytes);
//        //myRead.tB->setButtonText(std::to_string(lastVolumBytes));
//
//        //std::thread Sampleboys(SetVolumTextBoxText, myRead.tB, std::to_string(lastVolumBytes));
//        //Sampleboys.
//        SetVolumTextBoxText(myRead.tB, std::to_string(lastVolumBytes));
//        //Sampleboys.~thread();
//        Sleep(50);
//    }
//
//    //SetEvent(hEvent);
//    return 0;
//}
#endif // JUCE_WINDOWS
class MidiplusControlersCompile : public Component
{
public:
	MidiplusControlersCompile(/*ControllersComponent& cc,*/ const String& name)
		: Component(name)
	{


		inputHolders.add(new InputUiHolder(3));
		addAndMakeVisible(inputHolders.getFirst());
		InputUiHolder* input2 = new InputUiHolder(3);
		input2->setBounds(300, 0, 300, 330);

		inputHolders.add(input2);
		addAndMakeVisible(inputHolders.getLast());

		InputUiHolder* input3 = new InputUiHolder(2);
		input3->setBounds(600, 0, 75, 330);
		//input3->setDemo(new InputUIComponentStat2("Virtual 1 / 2", 0, 0));
		inputHolders.add(input3);

		addAndMakeVisible(inputHolders[2]);


		InputUiHolder* input4 = new InputUiHolder(2);
		input4->setBounds(675, 0, 75, 330);
		//input3->setDemo(new InputUIComponentStat2("Virtual 1 / 2", 0, 0));
		inputHolders.add(input4);

		addAndMakeVisible(inputHolders[3]);

		InputUiHolder* input5 = new InputUiHolder(2);
		input5->setBounds(750, 0, 75, 330);
		//input3->setDemo(new InputUIComponentStat2("Virtual 1 / 2", 0, 0));
		inputHolders.add(input5);

		addAndMakeVisible(inputHolders[4]);

		InputUiHolder* input6 = new InputUiHolder(2);
		input6->setBounds(825, 0, 75, 330);
		//input3->setDemo(new InputUIComponentStat2("Virtual 1 / 2", 0, 0));
		inputHolders.add(input6);

		addAndMakeVisible(inputHolders[5]);

		InputUiHolder* input7 = new InputUiHolder(2);
		input7->setBounds(900, 0, 75, 330);
		//input3->setDemo(new InputUIComponentStat2("Virtual 1 / 2", 0, 0));
		inputHolders.add(input7);

		addAndMakeVisible(inputHolders[6]);

		InputUiHolder* input8 = new InputUiHolder(3);
		input8->setBounds(975, 0, 150, 330);
		//input3->setDemo(new InputUIComponentStat2("Virtual 1 / 2", 0, 0));
		inputHolders.add(input8);

		addAndMakeVisible(inputHolders[7]);

		//InputUiHolder* input9 = new InputUiHolder(2);
		//input9->setBounds(1050, 0, 300, 300);
		////input3->setDemo(new InputUIComponentStat2("Virtual 1 / 2", 0, 0));
		//inputHolders.add(input9);

		//addAndMakeVisible(inputHolders[8]);

		setSize(1150, 330);
	}
#ifdef  JUCE_WINDOWS
	MidiplusControlersCompile(/*ControllersComponent& cc,*/ const String& name, std::vector<IMMDevice*> inputDevices)
		: Component(name)
	{
		std::vector<std::string> vString;

		HRESULT hr;
		PROPVARIANT proName;
		IPropertyStore* pPropertyStore = NULL;
		for (size_t index = 0; index < inputDevices.size(); index++) {
			hr = inputDevices.at(index)->OpenPropertyStore(STGM_READ, &pPropertyStore);
			hr = pPropertyStore->GetValue(PKEY_Device_FriendlyName, &proName);
			CString pk = proName.pwszVal;
			vString.push_back(pk.GetString());
		}
		std::regex  reg("^[a-zA-Z0-9\\s/]*");
		std::vector<std::string> vChannel;
		for (int index = 0; index < vString.size(); index++) {

			std::sregex_iterator pos(vString.at(index).begin(), vString.at(index).cend(), reg);
			std::string sdk = "";
			for (decltype(pos) end; pos != end; ++pos) {
				sdk = pos->str();
				vChannel.push_back(sdk);
			}
		}

		auto DevArray = hid::getAllDevicesAvailable();
		hid::DeviceInfo* HidDevInfo;
		for (auto index = DevArray.begin(); index != DevArray.end(); index++) {
			String as = (*index).getProductString();
			if ((*index).getProductString().contains("STUDIO M") || (*index).getProductString().contains("TITAN")) {
				HidDevInfo = (index);

				
				//HandleHidDeviceMessage(klopa);
				//threadIo = &klopa;
			}
		}
		hid::DeviceIO klopa = hid::connect(*HidDevInfo);
		int count = 0;
		for each (std::string channelName in vChannel)
		{
			if (channelName.find("ADAT")) {
				InputUiHolder* input = new InputUiHolder(2, klopa,channelName);
				input->setBounds(0 + count * 75, 0, 75, 333);
	
				inputHolders.add(input);
				
				addAndMakeVisible(inputHolders.getLast());
				count++;

				for (int nameindex = 0; nameindex < 7; nameindex++) {
					if (channelName.find(inJucename[nameindex]) != -1) {
						input->setIndex(nameindex);
						realIndex.push_back(nameindex);
						break;
					}
				}
			}


		}
		sort(realIndex.begin(),realIndex.end());
		setSize(1150, 333);
	}
#endif //  Juce_Window
	OwnedArray<InputUiHolder>* getInputHolders() {
		return &inputHolders;
	}

	std::vector<int> getInputIndex() {
		return realIndex;
	}

	void paint(Graphics& g) override
	{
		
		//
		int currentWidth = 0 , currentHeight = 0;
		for (auto index = inputHolders.begin(); index != inputHolders.end(); index++) {
			int k = (*index)->getBounds().getHeight();
			int p = (*index)->getBounds().getWidth();
			(*index)->setBounds(0 + currentWidth, 0, p, k);
			currentWidth += p;
		}


		//{
		//    // A ScopedSaveState will return the Graphics context to the state it was at the time of
		//    // construction when it goes out of scope. We use it here to avoid clipping the fps text
		//    const Graphics::ScopedSaveState state(g);


		//    // take a note of the time before the render
		//    startTime = Time::getMillisecondCounterHiRes();

		//    // then let the demo draw itself..
		//    drawDemo(g);
		//}
	}
	
private:
	OwnedArray<InputUiHolder> inputHolders;
	///
///这里先自定义一个数组来保存顺序
/// 
	std::string outJucename[8] = { "Analog Out 1/2","Monitor","OTG","Phone Out","OPT","Virtual Out 1/2","Virtual Out 3/4","Virtual Out 5/6" };
	std::string inJucename[7] = { "INPUT 1/2 ","OTG","PHONE IN","SPDIF/ADAT","Virtual In 1/2 ","Virtual In 3/4 ","Virtual In 5/6 " };
	std::vector<int> realIndex;

};

class MidiplusControlersCompile_OutPut : public Component
{
public:
	MidiplusControlersCompile_OutPut(/*ControllersComponent& cc,*/ const String& name)
		: Component(name)
	{
		inputHolders.add(new InputUiHolder(3));
		addAndMakeVisible(inputHolders.getFirst());
		InputUiHolder* input2 = new InputUiHolder(3);
		input2->setBounds(300, 0, 300, 330);
		inputHolders.add(input2);
		addAndMakeVisible(inputHolders.getLast());

		InputUiHolder* input3 = new InputUiHolder(2);
		input3->setBounds(600, 0, 300, 330);
		//input3->setDemo(new InputUIComponentStat2("Virtual 1 / 2", 0, 0));
		inputHolders.add(input3);

		addAndMakeVisible(inputHolders[2]);


		InputUiHolder* input4 = new InputUiHolder(2);
		input4->setBounds(675, 0, 75, 330);
		//input3->setDemo(new InputUIComponentStat2("Virtual 1 / 2", 0, 0));
		inputHolders.add(input4);

		addAndMakeVisible(inputHolders[3]);

		InputUiHolder* input5 = new InputUiHolder(2);
		input5->setBounds(750, 0, 75, 330);
		//input3->setDemo(new InputUIComponentStat2("Virtual 1 / 2", 0, 0));
		inputHolders.add(input5);

		addAndMakeVisible(inputHolders[4]);

		//InputUiHolder* input6 = new InputUiHolder(2);
		//input6->setBounds(825, 0, 75, 300);
		////input3->setDemo(new InputUIComponentStat2("Virtual 1 / 2", 0, 0));
		//inputHolders.add(input6);

		//addAndMakeVisible(inputHolders[5]);

		//InputUiHolder* input7 = new InputUiHolder(2);
		//input7->setBounds(900, 0, 75, 300);
		////input3->setDemo(new InputUIComponentStat2("Virtual 1 / 2", 0, 0));
		//inputHolders.add(input7);

		//addAndMakeVisible(inputHolders[6]);

		InputUiHolder* input8 = new InputUiHolder(3);
		input8->setBounds(825, 0, 150, 330);
		//input3->setDemo(new InputUIComponentStat2("Virtual 1 / 2", 0, 0));
		inputHolders.add(input8);

		addAndMakeVisible(inputHolders[5]);

		//InputUiHolder* input9 = new InputUiHolder(2);
		//input9->setBounds(1050, 0, 300, 300);
		////input3->setDemo(new InputUIComponentStat2("Virtual 1 / 2", 0, 0));
		//inputHolders.add(input9);

		//addAndMakeVisible(inputHolders[8]);

		setSize(1120, 333);
	}

	MidiplusControlersCompile_OutPut(/*ControllersComponent& cc,*/ const String& name,std::vector<IMMDevice*> outputDevices)
		: Component(name)
	{

		std::vector<std::string> vString;
#ifdef  JUCE_WINDOWS
		HRESULT hr;
		PROPVARIANT proName;
		IPropertyStore* pPropertyStore = NULL;
		for (size_t index = 0; index < outputDevices.size(); index++) {
			hr = outputDevices.at(index)->OpenPropertyStore(STGM_READ, &pPropertyStore);
			hr = pPropertyStore->GetValue(PKEY_Device_FriendlyName, &proName);
			CString pk = proName.pwszVal;
			vString.push_back(pk.GetString());
		}
		std::regex  reg("^[a-zA-Z0-9\\s/]*");
		std::vector<std::string> vChannel;
		for (int index = 0; index < vString.size(); index++) {

			std::sregex_iterator pos(vString.at(index).begin(), vString.at(index).cend(), reg);
			std::string sdk = "";
			for (decltype(pos) end; pos != end; ++pos) {
				sdk = pos->str();
				vChannel.push_back(sdk);
			}
		}



		auto DevArray = hid::getAllDevicesAvailable();
		hid::DeviceInfo* HidDevInfo;
		for (auto index = DevArray.begin(); index != DevArray.end(); index++) {
			String as = (*index).getProductString();
			if ((*index).getProductString().contains("STUDIO M") || (*index).getProductString().contains("TITAN")) {
				HidDevInfo = (index);


				//HandleHidDeviceMessage(klopa);
				//threadIo = &klopa;
			}
		}
		hid::DeviceIO klopa = hid::connect(*HidDevInfo);

#endif //  Juce_Window
		int count = 0;
		for each (std::string channelName in vChannel)
		{
			if (channelName.find("ADAT")) {
				InputUiHolder* output = new InputUiHolder(2, klopa,channelName);
				output->setBounds(0 + count * 75, 0, 75, 330);
				inputHolders.add(output);
				addAndMakeVisible(inputHolders.getLast());
				count++;
			}
		}




		setSize(1120, 330);
	}


	void paint(Graphics& g) override
	{
		int p = 0; 
		//auto startTime = 0.0;

		//{
		//    // A ScopedSaveState will return the Graphics context to the state it was at the time of
		//    // construction when it goes out of scope. We use it here to avoid clipping the fps text
		//    const Graphics::ScopedSaveState state(g);


		//    // take a note of the time before the render
		//    startTime = Time::getMillisecondCounterHiRes();

		//    // then let the demo draw itself..
		//    drawDemo(g);
		//}
	}
private:
	OwnedArray<InputUiHolder> inputHolders;
	//这里是混音通道，应该不需要
	std::string outJucename[8] = { "Analog Out 1/2","Monitor","OTG","Phone Out","OPT","Virtual Out 1/2","Virtual Out 3/4","Virtual Out 5/6" };
	std::string inJucename[7] = { "Analog In 1/2 ","OTG","Phone In","OPT","Virtual In 1/2 ","Virtual In 3/4 ","Virtual In 5/6 " };
};


class MidiplusControlersCompile_ALL : public Component
{
public:
	MidiplusControlersCompile_ALL(/*ControllersComponent& cc,*/ const String& name)
		: Component(name)
	{
		//klopa = InitHidDevice();

#ifdef JUCE_WINDOWS

		///扫描终结点
		HRESULT hr;
		IMMDeviceCollection* outputCollection = NULL;
		IMMDeviceCollection* inputCollection = NULL;
		IMMDeviceEnumerator* pEnumerator = NULL;
		IMMDevice* pDevice = NULL;
		UINT rpcd = 0;
		UINT rpcInputd = 0;
		UINT* pcdevice = &rpcd;
		UINT* pcInputDevice = &rpcInputd;
		IMMDevice* opDevice = NULL;
		IAudioMeterInformation* iami = NULL;
		IAudioEndpointVolume* iaev = NULL;
		ISimpleAudioVolume* isav = NULL;
		DWORD qHardwareSupport = 4;
		IAudioClient* iAC = NULL;
		static float peak = 0;
		PROPVARIANT proName;
		IPropertyStore* pPropertyStore = NULL;
		hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL,
			CLSCTX_ALL, IID_PPV_ARGS(&pEnumerator));

		//Topo
		IDeviceTopology* pDevTopoEndpt = NULL;
		IConnector* pConnEndpt = NULL;
		IConnector* pConnHWDev = NULL;
		IPart* pPartConn = NULL;
		IDeviceTopology** ppDevTopo = NULL;

		IAudioMute* iAM = NULL;
		IAudioAutoGainControl* iAAGC = NULL;
		IConnector* pConnToWave = NULL;
		IAudioOutputSelector* daada = NULL;
		//EXIT_ON_ERROR(hr);

		hr = pEnumerator->EnumAudioEndpoints(eRender, DEVICE_STATE_ACTIVE, &outputCollection);
		//EXIT_ON_ERROR(hr);
		outputCollection->GetCount(pcdevice);
		int sampleindex = 0;
		//EXIT_ON_ERROR(hr);
		for (UINT i = 0; i < *pcdevice; i++) {

			outputCollection->Item(i, &opDevice);
			hr = opDevice->OpenPropertyStore(STGM_READ, &pPropertyStore);
			//EXIT_ON_ERROR(hr);
			PropVariantInit(&proName);
			hr = pPropertyStore->GetValue(PKEY_Device_FriendlyName, &proName);
			//EXIT_ON_ERROR(hr);
			//std::string pk = "cd";
			CString pk = proName.pwszVal;
			//const char* pCStrKey = pk.c_str();
			//wchar_t* j = &pk;
			//pk == "Realtek Digital Output (Realtek(R) Audio)"
			//auto jkldas = pk.Find("HEADPHONE");

			//if ((pk.Find("HEADPHONE") != 0xffffffff) && pk.Find("TITAN 6") != -1
			//    )

			if (pk.Find("Studio") != -1
				|| pk.Find("STUDIO") != -1) {
				WAVEFORMATEX* pwfx = NULL;
				LPWSTR wstrID = NULL;
				opDevice->GetId(&wstrID);
				hr = pEnumerator->GetDevice(wstrID, &pDevice);

				outputEndpoint.push_back(opDevice);

				///绘制监控volum采样的框
				if (pDevice != NULL) {
					hr = pDevice->Activate(__uuidof(IAudioMeterInformation), CLSCTX_ALL,
						NULL, (void**)&iami);
					//EXIT_ON_ERROR(hr);
					hr = iami->QueryHardwareSupport(&qHardwareSupport);
					//EXIT_ON_ERROR(hr);
					iami->GetPeakValue(&peak);
					//
					//TextButton* sampleTextButton = new TextButton(std::to_string(peak));

					//if (pk.Find("HEADPHONE") != -1) {
					//    sampleTextButton->setBounds(540 + 0 * 100, 240, 100, 60);
					//}
					//else if (pk.Find("MONITOR") != -1) {
					//    sampleTextButton->setBounds(540 + 1 * 100, 240, 100, 60);
					//}
					//else if (pk.Find("OTG") != -1) {
					//    sampleTextButton->setBounds(540 + 2 * 100, 240, 100, 60);
					//}
					//else if (pk.Find("SPDIF") != -1) {
					//    sampleTextButton->setBounds(540 + 3 * 100, 240, 100, 60);
					//}
					//else if (pk.Find("PHONE") != -1) {
					//    sampleTextButton->setBounds(540 + 4 * 100, 240, 100, 60);
					//}


					//addAndMakeVisible(sampleTextButton);

					//pDevice->GetState()

					//SampleTextBundle sTB = { sampleTextButton ,iami };
					//sampleVolumReader = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)SampleReadThread, (LPVOID)(&sTB), 0, NULL);
					//std::thread svtt(ReadVolumSample, sampleTextButton, iami);
					//try {
					//   // std::thread Sampleboys(SetVolumTextBoxText, sampleTextButton, std::to_string(peak));
					//}
					//catch (...) {

					//}
				}





				IAudioSessionManager2* iASM2 = NULL;
				pDevice->Activate(__uuidof(IAudioSessionManager2), CLSCTX_ALL, NULL, (void**)&iASM2);
				LPWSTR pswSession = NULL;
				IAudioSessionEnumerator* pSessionList = NULL;
				IAudioSessionControl* pSessionControl = NULL;
				int cbSessionCount = 0;
				iASM2->GetSessionEnumerator(&pSessionList);
				pSessionList->GetCount(&cbSessionCount);
				for (int index = 0; index < cbSessionCount; index++)
				{
					CoTaskMemFree(pswSession);
					SAFE_RELEASE(pSessionControl);

					// Get the <n>th session.
					hr = pSessionList->GetSession(index, &pSessionControl);

					hr = pSessionControl->GetDisplayName(&pswSession);
					GUID pRetVal;

					pSessionControl->GetGroupingParam(&pRetVal);

					wprintf_s(L"Session proName: %s\n", pswSession);
				}

				IAudioSessionEnumerator* PKLAD = NULL;


			}

			else if (pk.Find("TITAN") != -1
				) {
				WAVEFORMATEX* pwfx = NULL;
				LPWSTR wstrID = NULL;
				opDevice->GetId(&wstrID);
				hr = pEnumerator->GetDevice(wstrID, &pDevice);

				outputEndpoint.push_back(opDevice);

				///绘制监控volum采样的框
				if (pDevice != NULL) {
					hr = pDevice->Activate(__uuidof(IAudioMeterInformation), CLSCTX_ALL,
						NULL, (void**)&iami);
					//EXIT_ON_ERROR(hr);
					hr = iami->QueryHardwareSupport(&qHardwareSupport);
					//EXIT_ON_ERROR(hr);
					iami->GetPeakValue(&peak);
					
				}
			}
			PropVariantClear(&proName);
		}

		hr = pEnumerator->EnumAudioEndpoints(eCapture, DEVICE_STATE_ACTIVE, &inputCollection);
		inputCollection->GetCount(pcInputDevice);
		for (UINT i = 0; i < *pcInputDevice; i++) {

			inputCollection->Item(i, &opDevice);
			hr = opDevice->OpenPropertyStore(STGM_READ, &pPropertyStore);
			//EXIT_ON_ERROR(hr);
			PropVariantInit(&proName);
			hr = pPropertyStore->GetValue(PKEY_Device_FriendlyName, &proName);
			//EXIT_ON_ERROR(hr);
			//std::string pk = "cd";
			CString pk = proName.pwszVal;
			//const char* pCStrKey = pk.c_str();
			//wchar_t* j = &pk;
			//pk == "Realtek Digital Output (Realtek(R) Audio)"
			//auto jkldas = pk.Find("HEADPHONE");

			//if ((pk.Find("HEADPHONE") != 0xffffffff) && pk.Find("TITAN 6") != -1
			//    )

			if (pk.Find("Studio") != -1
				|| pk.Find("STUDIO") != -1) {
				WAVEFORMATEX* pwfx = NULL;
				LPWSTR wstrID = NULL;
				opDevice->GetId(&wstrID);
				
				hr = pEnumerator->GetDevice(wstrID, &pDevice);

				inputEndpoint.push_back(opDevice);


			}
			else if (pk.Find("TITAN") != -1
				) {
				WAVEFORMATEX* pwfx = NULL;
				LPWSTR wstrID = NULL;
				opDevice->GetId(&wstrID);
				hr = pEnumerator->GetDevice(wstrID, &pDevice);

				inputEndpoint.push_back(opDevice);


			}
			PropVariantClear(&proName);
		}

#endif

		BorderSize<int> p = { 1,1,1,1 };
		Font pf = Font(12.0f);
		labelMixerTitle.reset(new Label("title"));
		labelMixerTitle.get()->setText("Mixer Control", dontSendNotification);
		labelMixerTitle.get()->setBounds(0, 0, 1250, 15);
		labelMixerTitle.get()->setColour(Label::ColourIds::textColourId, Colours::lightgrey);
		labelMixerTitle.get()->setColour(Label::ColourIds::backgroundColourId, Colours::black);
		labelMixerTitle.get()->setJustificationType(Justification::centred);
		labelMixerTitle.get()->setBorderSize(p);


		labelHeadPhoneTitle.reset(new Label("title"));
		labelHeadPhoneTitle.get()->setText("HEADPHONE OUTPUT", dontSendNotification);
		labelHeadPhoneTitle.get()->setFont(pf);
		//labelHeadPhoneTitle.get().font
		labelHeadPhoneTitle.get()->setBounds(0, 16, 130, 15);
		labelHeadPhoneTitle.get()->setColour(Label::ColourIds::textColourId, Colours::black);
		labelHeadPhoneTitle.get()->setColour(Label::ColourIds::backgroundColourId, Colours::grey);
		//labelHeadPhoneTitle.get()->setJustificationType(Justification::centred);
		labelHeadPhoneTitle.get()->setBorderSize(p);

		labelVirtualTitle.reset(new Label("title"));
		labelVirtualTitle.get()->setText("VIRTUAL OUTPUT", dontSendNotification);
		labelVirtualTitle.get()->setFont(pf);
		//labelHeadPhoneTitle.get().font
		labelVirtualTitle.get()->setBounds(0, 430, 130, 15);
		labelVirtualTitle.get()->setColour(Label::ColourIds::textColourId, Colours::black);
		labelVirtualTitle.get()->setColour(Label::ColourIds::backgroundColourId, Colours::grey);
		//labelHeadPhoneTitle.get()->setJustificationType(Justification::centred);
		labelVirtualTitle.get()->setBorderSize(p);

		labelHardWareInputTitle.reset(new Label("labelHardWareInputTitle"));
		labelHardWareInputTitle.get()->setText("HARDWARE INPUT", dontSendNotification);
		labelHardWareInputTitle.get()->setFont(pf);
		labelHardWareInputTitle.get()->setBounds(130, 15, 1120, 15);
		labelHardWareInputTitle.get()->setColour(Label::ColourIds::textColourId, Colours::black);
		labelHardWareInputTitle.get()->setColour(Label::ColourIds::backgroundColourId, Colours::grey);
		//labelHeadPhoneTitle.get()->setJustificationType(Justification::centred);
		labelHardWareInputTitle.get()->setBorderSize(p);

		labelHardWareOutputTitle.reset(new Label("labelHardWareOutputTitle"));
		labelHardWareOutputTitle.get()->setText("HARDWARE OUTPUT", dontSendNotification);
		labelHardWareOutputTitle.get()->setFont(pf);
		labelHardWareOutputTitle.get()->setBounds(130, 365, 1120, 15);
		labelHardWareOutputTitle.get()->setColour(Label::ColourIds::textColourId, Colours::black);
		labelHardWareOutputTitle.get()->setColour(Label::ColourIds::backgroundColourId, Colours::grey);
		//labelHeadPhoneTitle.get()->setJustificationType(Justification::centred);
		labelHardWareOutputTitle.get()->setBorderSize(p);
		
		//labelMixerTitle.get()->setColour(Label::ColourIds::, Colours::black);
		addAndMakeVisible(labelMixerTitle.get());
		addAndMakeVisible(labelHeadPhoneTitle.get());
		addAndMakeVisible(labelVirtualTitle.get());
		addAndMakeVisible(labelHardWareInputTitle.get());
		addAndMakeVisible(labelHardWareOutputTitle.get());


		inputCompile.reset(new MidiplusControlersCompile("dd", inputEndpoint));
		inputCompile.get()->setBounds(130, 30, 1120, 333);

		//inputCompile.get()->setBorderSize(p);
		addAndMakeVisible(inputCompile.get());

		inputCompile2.reset(new MidiplusControlersCompile_OutPut("dd",outputEndpoint));
		inputCompile2.get()->setBounds(130, 380, 1120, 333);
		//inputCompile.get()->setBorderSize(p);
		addAndMakeVisible(inputCompile2.get());


		///硬件Hid控制初始化相关
#ifdef  JUCE_WINDOWS
		std::vector<std::string> vString;
		for (size_t index = 0; index < outputEndpoint.size(); index++) {
			hr = outputEndpoint.at(index)->OpenPropertyStore(STGM_READ, &pPropertyStore);
			hr = pPropertyStore->GetValue(PKEY_Device_FriendlyName, &proName);
			CString pk = proName.pwszVal;
			vString.push_back(pk.GetString());
		}
		std::regex  reg("^[a-zA-Z0-9\\s/]*");
		std::vector<std::string> vChannel;
		for (int index = 0; index < vString.size(); index++) {

			std::sregex_iterator pos(vString.at(index).begin(), vString.at(index).cend(), reg);
			std::string sdk = "";
			for (decltype(pos) end; pos != end; ++pos) {
				sdk = pos->str();
				vChannel.push_back(sdk);
			}
		}



#endif //  Juce_Window
		int coed = 0;
		int cohd = 0;
		for (int index = 0; index < outputEndpoint.size(); index++) {
			if (!(vChannel.at(index)).find("Virtual")) {
				int i = 0;
				//DriverOutputUI();
				////std::string names = "Virtual"
				//doui.setName(vChannel.at(index));
				//doui.setBounds(0,31 + 82 * coed ,130,82);
				hardwareOutputUIs.add(new DriverOutputUI(vChannel.at(index)));
				(*(hardwareOutputUIs.end() - 1))->setBounds(0, 445 + 82 * coed, 130, 82);
				coed++;
				addAndMakeVisible((*(hardwareOutputUIs.end() - 1)));

			}
			else if ((vChannel.at(index)).find("ADAT")  ) {
				hardwareOutputUIs.add(new DriverOutputUI(vChannel.at(index)));
				(*(hardwareOutputUIs.end() - 1))->setBounds(0, 31 + 80 * cohd, 130, 80);
				cohd++;
				addAndMakeVisible((*(hardwareOutputUIs.end() - 1)));
			}
		}



		outputUI2.reset(new DriverOutputUI());
		outputUI2.get()->setBounds(0, 110, 130, 82);
		//inputCompile.get()->setBorderSize(p);


		outputUI1.reset(new DriverOutputUI());
		//outputUI1.get()->setBoundsRelative(0.5,0.5,0.5,0.5);
		outputUI1.get()->setBounds(0, 31, 130, 82);
		//inputCompile.get()->setBorderSize(p);

		outputUI3.reset(new DriverOutputUI());
		outputUI3.get()->setBounds(0, 190, 130, 82);
		//inputCompile.get()->setBorderSize(p);

		outputUI4.reset(new DriverOutputUI());
		outputUI4.get()->setBounds(0, 270, 130, 82);
		//inputCompile.get()->setBorderSize(p);

		outputUI5.reset(new DriverOutputUI());
		outputUI5.get()->setBounds(0, 350, 130, 82);
		//inputCompile.get()->setBorderSize(p);


		//addAndMakeVisible(outputUI1.get());
		//addAndMakeVisible(outputUI2.get());
		//addAndMakeVisible(outputUI3.get());
		//addAndMakeVisible(outputUI4.get());
		//addAndMakeVisible(outputUI5.get());

		//outputUI6.reset(new DriverOutputUI());
		//outputUI6.get()->setBounds(0, 445, 130, 84);
		////inputCompile.get()->setBorderSize(p);


		//outputUI7.reset(new DriverOutputUI());
		//outputUI7.get()->setBounds(0, 529, 130, 86);
		////inputCompile.get()->setBorderSize(p);

		//outputUI8.reset(new DriverOutputUI());
		//outputUI8.get()->setBounds(0, 615, 130, 84);
		////inputCompile.get()->setBorderSize(p);

		//outputUI9.reset(new DriverOutputUI());
		//outputUI9.get()->setBounds(0, 800, 130, 85);
		//inputCompile.get()->setBorderSize(p);
		//addAndMakeVisible(outputUI6.get());
		//addAndMakeVisible(outputUI7.get());
		//addAndMakeVisible(outputUI8.get());
		//addAndMakeVisible(outputUI9.get());


		threadPool.reset(new ThreadPool());
		threadSampleListener.reset(new ThreadSampleListener("sampleListener"));
		threadSampleListener.get()->startThread();
		threadSampleListener.get()->launch([this] {WindowsSampleListen(outputEndpoint); });
		//threadPool.get()->addJob();

		//threadPool.get()->addJob()
		threadHidListener.reset(new ThreadHidListener("hidListener",0,&hardwareOutputUIs,&inputCompile));
		threadHidListener.get()->startThread();
		//threadHidListener.get()->launch([this] {HandleHidDeviceMessage(klopa); });
		setSize(1250, 700);
		logoPoint = { 1175,650 };
	}

	void paint(Graphics& g) override
	{
		g.setColour(Colours::black);
		//inputCompile.get()->setBoundsRelative(0.0f, 0.0f, 0.5f, 0.5f);
		labelHeadPhoneTitle.get()->setBoundsRelative(0.0f, 0.0208f, 0.104f, 0.0208f);
		labelHardWareInputTitle.get()->setBoundsRelative(0.104f, 0.0208f, 0.896f, 0.0208f);
		labelMixerTitle.get()->setBoundsRelative(0.0f, 0.0f, 1.0f, 0.0208f);
		g.setOpacity(getAlpha());
		//g.drawRect(10, 10, rectSize, rectSize, 5);
		g.fillRect(130, 380, 1120, 333);
		g.fillRect(130, 30, 1120, 333);
		g.drawImage(ImageCache::getFromMemory(BinaryData::TITANLogo_png, BinaryData::TITANLogo_pngSize),
			juce::Rectangle<float>(static_cast<float> (110), static_cast<float> (70)).withCentre(logoPoint));
		if (threadSampleListener.get()->pk == 100) {
			int asd = 1;
		}
		//auto startTime = 0.0;

		//{
		//    // A ScopedSaveState will return the Graphics context to the state it was at the time of
		//    // construction when it goes out of scope. We use it here to avoid clipping the fps text
		//    const Graphics::ScopedSaveState state(g);


		//    // take a note of the time before the render
		//    startTime = Time::getMillisecondCounterHiRes();

		//    // then let the demo draw itself..
		//    drawDemo(g);
		//}
	}
private:
	//OwnedArray<InputUiHolder> inputHolders;
	std::unique_ptr<Label> labelMixerTitle;
	std::unique_ptr<Label> labelHeadPhoneTitle;
	std::unique_ptr<Label> labelVirtualTitle;
	std::unique_ptr<Label> labelHardWareInputTitle;
	std::unique_ptr<Label> labelHardWareOutputTitle;
	std::unique_ptr< MidiplusControlersCompile> inputCompile;
	std::unique_ptr< MidiplusControlersCompile_OutPut> inputCompile2;

	OwnedArray<DriverOutputUI> hardwareOutputUIs;

	std::unique_ptr<DriverOutputUI > outputUI1;
	std::unique_ptr< DriverOutputUI> outputUI2;
	std::unique_ptr< DriverOutputUI> outputUI3;
	std::unique_ptr< DriverOutputUI> outputUI4;
	std::unique_ptr< DriverOutputUI> outputUI5;

	std::unique_ptr< DriverOutputUI> outputUI6;
	std::unique_ptr< DriverOutputUI> outputUI7;
	std::unique_ptr< DriverOutputUI> outputUI8;
	std::unique_ptr< DriverOutputUI> outputUI9;

	std::unique_ptr< ThreadPool> threadPool;
	
	class ThreadHidListener : public Thread {
	public:

		ThreadHidListener(const String& threadName,
			size_t 	threadStackSize, OwnedArray<DriverOutputUI>* oa, std::unique_ptr< MidiplusControlersCompile>* inputcompile
		) : Thread(threadName, threadStackSize) {
			hardwareOutputUIs = oa;
			inputCompile = inputcompile;
		}

		void run() override {
			//int a = 0;
			//while (++pk < 100) {
			//	a += 5; 
			//	
			//}
			auto DevArray = hid::getAllDevicesAvailable();

			for (auto index = DevArray.begin(); index != DevArray.end(); index++) {
				String as = (*index).getProductString();
				if ((*index).getProductString().contains("STUDIO M") || (*index).getProductString().contains("TITAN")) {
					hid::DeviceInfo* HidDevInfo = (index);

					hid::DeviceIO klopa = hid::connect(*HidDevInfo);
					//HandleHidDeviceMessage(klopa);
					threadIo = &klopa;
				}

			}
			//unsigned char data1[6] = { 0xF0, 0x7E, 0X7F, 0X06, 0X01, 0XF7 };
			//threadIo->write(data1,6);
			unsigned char* data;
			//klopa->disconnect();
			size_t dataSize = 64;
			DWORD SLEEPTIME = 1;
			HandleHidDeviceMessage(threadIo);
		}
		int pk = 1;
	private:
		hid::DeviceIO* threadIo;

		void HandleHidDeviceMessage(hid::DeviceIO* klopa ) {
			unsigned char data[64];
			//klopa->disconnect();
			size_t dataSize = 64;
			DWORD SLEEPTIME = 1;		
			//unsigned char data1[6] = {0xF0, 0x7E, 0X7F, 0X06, 0X01, 0XF7 };
			int initHid = 0;
			//(**inputCompile).getInputHolders()->getFirst();
			while (true) {
				//if (initHid == 0) { threadIo->write(data1, 6); initHid++; }
				Result result = klopa->readTimeout(data, dataSize, 10000);

				//Result result = klopa->readTimeout(data, dataSize,10000);
				if (result.getErrorMessage().contains( "no bytes")) {
					int ko = 1;
				}
				else if (result.getErrorMessage() != "") {
					int kd = 0;
				}
				//Result result = (*klopa).readTimeout(data, dataSize, 10000);
				if (result != Result::ok()) {
					//klopa->disconnect();
					SLEEPTIME = 100;
				}
				else {
					SLEEPTIME = 1;
					dataDeal(data);
				}
				
				Sleep(SLEEPTIME);
				const MessageManagerLock mmLock;
				//(**inputCompile).getInputHolders()->getFirst()->setDemoSliderValue(100.0);
				for (int index = 0; index < 8; index++) {
					if (statusKey[index] == 1) {
						statusKey[index] = 0 ;
						ChangeValuesUI(index);
						/*(*hardwareOutputUIs).getFirst()->getSlider();*/
					}
				}
				int da = 0;
			}

			//
			int da = 0;
		}

		void dataDeal(unsigned char data[64]) {
			std::vector<byte>* selectedStatus;
			switch (data[4]) {
			case 0x21: {
				selectedStatus = &buttonStatus;
				statusKey[0] = 1;
			}
					 break;
			case 0x22: {
				selectedStatus = &sliderStatus;
				statusKey[1] = 1; }
					 break;
			case 0x23: {
				selectedStatus = &ledStatus;
				statusKey[2] = 1;
			}
					 break;
			case 0x24: {selectedStatus = &optStatus; statusKey[3] = 1; }
					 break;
			case 0x25: {selectedStatus = &muteStatus; statusKey[4] = 1; }
					 break;
			case 0x26: {selectedStatus = &stainStatus; statusKey[5] = 1; }
					 break;
			case 0x27: {selectedStatus = &elecStatus; statusKey[6] = 1; }
					 break;
			case 0x28: {selectedStatus = &balanceStatus; statusKey[7] = 1; }
					 break;
			}

			for (int index = 0; index < 64; index++) {
				if ((*selectedStatus).size() < 64)(*selectedStatus).push_back(data[index]);
				else if ((*selectedStatus).at(index) != data[index])
				{
					(*selectedStatus).at(index) = data[index];

				}
			}
			int lk = (*selectedStatus).size();
			int k = 0;
		}

		void ChangeValuesUI(int index) {
			switch (index) {
			case 0: {
				int buttonvalue[11];
				if (buttonStatus.at(6) == 0x06)
				{
					//设置Button
					for (int time = 0; time < 11; time++) {
						buttonvalue[time] = ((buttonStatus.at(7 + time )));
					}
					int k = 0;
				}
			}break;
			case 1: {
				int slidervalue[10];
				if (sliderStatus.at(6) == 0x14)
				{
					for (int time = 0; time < 10; time++) {
						slidervalue[time] =  ( (sliderStatus.at(7 + time * 2) & 0x7f ) << 8 | sliderStatus.at(8 + time * 2) ) * 
							(( (sliderStatus.at(7 + time * 2) & 0x80 ) > 1 ? -1 : 1));
						if (time > 4) //进行设置Input和output  
						{
							if (getflag == 0 ) {
								inputHolders = (**inputCompile).getInputHolders();
								inindex = (**inputCompile).getInputIndex();
								getflag =  1;
							}

						}
					}

					if (getflag == 1) {
						for (auto index = inputHolders->begin(); index != inputHolders->end(); index++) {
							int kd =  (*index)->getIndex();
							if (kd != -1 && kd < 4) {
								if (kd > 0) { (*index)->setDemoSliderValue(slidervalue[kd + 1] / 10.0); }
								else {
									(*index)->setDemoSliderValue(slidervalue[0] / 10.0, slidervalue[1] / 10.0);
								}
							}
						}
					}

					int k = 0;
				}
			}break;
			case 2: {
				int ledvalue[1];
				if (ledStatus.at(6) == 0x01)
				{
					for (int time = 0; time < 1; time++) {
						ledvalue[time] = ((ledStatus.at(7 + time)));
					}
					int k = 0;
				}
			}break;
			case 3: {
				int optvalue[1];
				if (optStatus.at(6) == 0x01)
				{
					for (int time = 0; time < 1; time++) {
						optvalue[time] = ((optStatus.at(7 + time)));
					}
					int k = 0;
				}
			}break;
			case 4: {
				int mutevalue[10];
				if (muteStatus.at(6) == 0x0a)
				{
					for (int time = 0; time < 10; time++) {
						mutevalue[time] = ((muteStatus.at(7 + time)));
					}
					int k = 0;
				}
			}break;
			case 5: {
				int stainvalue[1];
				if (stainStatus.at(6) == 0x01)
				{
					for (int time = 0; time < 1; time++) {
						stainvalue[time] = ((stainStatus.at(7 + time)));
					}
					int k = 0;
				}
			}break;
			case 6: {
				int elecvalue[1];
				if (elecStatus.at(6) == 0x01)
				{
					for (int time = 0; time < 1; time++) {
						elecvalue[time] = ((elecStatus.at(7 + time)));
					}
					int k = 0;
				}
			}break;
			case 7: {
				int balvalue[1];
				if (balanceStatus.at(6) == 0x01)
				{
					for (int time = 0; time < 1; time++) {
						balvalue[time] = ((balanceStatus.at(7 + time)));
					}
					int k = 0;
				}
			}break;
			}
		}
		std::vector<byte> buttonStatus;		//按键信息配置  
		std::vector<byte> sliderStatus;		//硬件音量信息配置
		//std::vector<byte> buttonStatus; //硬件音量信息配置
		std::vector<byte> ledStatus; //LED信息配置
		std::vector<byte> optStatus; //OPT状态切换配置
		std::vector<byte> muteStatus; //硬件静音状态配置
		std::vector<byte> stainStatus; //高低阻抗耳机切换配置
		std::vector<byte> elecStatus;//高低电压切换配置
		std::vector<byte> balanceStatus;//平衡切换配置
		OwnedArray<DriverOutputUI>* hardwareOutputUIs;
		int getflag = 0;
		OwnedArray<InputUiHolder>* inputHolders;
		std::vector<int> inindex;

		std::unique_ptr< MidiplusControlersCompile>* inputCompile;
		//std::unique_ptr< MidiplusControlersCompile_OutPut> inputCompile2;
		int statusKey[8] = {0,0,0,0,0,0,0,0};
	};

	class ThreadSampleListener : public Thread {
	public :

		ThreadSampleListener(const String& threadName,
			size_t 	threadStackSize = 0
		) : Thread(threadName, threadStackSize) {
			
		}

		void run() override {
			//int a = 0;
			//while (++pk < 100) {
			//	a += 5; 
			//	
			//}
		}
		int pk = 1;
	private :
		
	};

	/// <summary>
	/// Juce Hid 读取线程 和 修改线程
	/// </summary>
	/// 
	/// 
	int DFU_vid;
	int DFU_pid;
	String PrticName;
	hid::DeviceIO* klopa;
	hid::DeviceIO* InitHidDevice() {
		auto DevArray = hid::getAllDevicesAvailable();
		
		for (auto index = DevArray.begin(); index != DevArray.end(); index++) {
			String as = (*index).getProductString();
			if ((*index).getProductString().contains("STUDIO M")) {
				hid::DeviceInfo*  HidDevInfo = (index);
				DFU_vid = (*index).getVendorId();
				DFU_pid = (*index).getProductId();
				PrticName = (*index).getProductString();
				hid::DeviceIO klopa = hid::connect(*HidDevInfo);
				//HandleHidDeviceMessage(klopa);
				return &klopa;
			}
		}
		
		auto isconn = hid::isConnected();
		auto psd = isconn;
		//HandleHidDeviceMessage();
	}




	std::unique_ptr< ThreadSampleListener> threadSampleListener;
	std::unique_ptr< ThreadHidListener> threadHidListener;
	hid::DeviceInfo* currentDevice;

#ifdef JUCE_WINDOWS
	std::vector<IMMDevice*> outputEndpoint;
	std::vector<IMMDevice*> inputEndpoint;
	
	std::vector<IAudioEndpointVolume*> inputVolumnEndpoint;
	

	void WindowsSampleListen(std::vector<IMMDevice*> outputEndpoint) {
		IAudioMeterInformation* iami;
		IAudioEndpointVolume* iaev;
		float peak = 0;
		std::vector<IAudioMeterInformation*> iamis;
		std::vector<IAudioEndpointVolume*> iaevs;
		std::vector<float> peaks;
		std::vector<float> levels;
		OwnedArray<InputUiHolder>* inputHolders_Ptr = inputCompile.get()->getInputHolders();
		int count = 0;
		for (auto index = outputEndpoint.begin(); index != outputEndpoint.end(); index++) {
			(*index)->Activate(__uuidof(IAudioMeterInformation), CLSCTX_ALL,
				NULL, (void**)&iami);
			(*index)->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_ALL,
				NULL, (void**)&iaev);
			iamis.push_back(iami);
			iaevs.push_back(iaev);
			imaiValumnStructs.push_back( ImaiValumnStruct{ count,0 });
			peaks.push_back(0.0f);
			levels.push_back(0.0f); levels.push_back(0.0f);

			count++;
		}
		int peakchange = 0;
		while (true) {
			int iamisIndex = 0 ;
			float  a[2] = {0,0};
			UINT32 t213 = 0,t3213= 1;
			for (auto index = iamis.begin(); index != iamis.end(); index++) {
				IAudioMeterInformation* iami = *index;
				iami->GetPeakValue(&peak);
				iami->GetMeteringChannelCount(&t213);
				iami->GetChannelsPeakValues(t213, a);

				float level1 = 0;
				float level2 = 0;
				iaevs.at(iamisIndex)->GetChannelVolumeLevelScalar(0, &level1);
				iaevs.at(iamisIndex)->GetChannelVolumeLevelScalar(1, &level2);
				if (levels.at(iamisIndex * 2 + 0) != level1 || levels.at(iamisIndex * 2 + 0) != level2) {
					levels.at(iamisIndex * 2 + 0) = level1;
					levels.at(iamisIndex * 2 + 1) = level2;
				}
				float k = *a;
				//iami->GetChannelsPeakValues(t3213, &t2);
				if (peaks.at(iamisIndex) != peak) {
					peaks.at(iamisIndex) = peak;
					peakchange = 1;
				}
				/*int kosad = 1;*/
				//if (peak != imaiValumnStructs.at(iamisIndex).peak) {
				//	const MessageManagerLock mmLock;
				//	(*inputHolders_Ptr).getFirst()->setSampleSliderValue(peak);
				//	imaiValumnStructs.at(iamisIndex).peak = peak;
				//}
				iamisIndex++;
			}
			if (peakchange == 1) {
				peakchange = 0;
				int holderPtr = 0;
				const MessageManagerLock mmLock;
				for (auto index = (*inputHolders_Ptr).begin(); index != (*inputHolders_Ptr).end(); index++) {
					(*index)->setSampleSliderValue(peaks.at(holderPtr) * levels.at(holderPtr * 2 + 0), peaks.at(holderPtr)* levels.at(holderPtr * 2 + 1));
					holderPtr++;
				}
				holderPtr = 0;
				for (auto index = (hardwareOutputUIs).begin(); index != (hardwareOutputUIs).end(); index++) {
					(*index)->setSampleSliderValue(peaks.at(holderPtr) * levels.at(holderPtr * 2 + 0), peaks.at(holderPtr) * levels.at(holderPtr * 2 + 1));
					holderPtr++;
				}
				//hardwareOutputUIs
			}
			Sleep(10);
		}
	}

#endif
	struct ImaiValumnStruct {
		int index;
		float peak;
	};
	Point<float> logoPoint;
	std::vector<ImaiValumnStruct> imaiValumnStructs;

	///
///这里先自定义一个数组来保存顺序
/// 
	String outJucename[8] = { "Analog Out 1/2","Monitor","OTG","Phone Out","OPT","Virtual Out 1/2","Virtual Out 3/4","Virtual Out 5/6" };
	String inJucename[7] = { "Input 1/2","OTG","Phone In","OPT","Virtual In 1/2","Virtual In 3/4","Virtual In 5/6" };
};


