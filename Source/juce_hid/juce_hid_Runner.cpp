#include "juce_hid/juce_hid.h"
#if JUCE_MAC
#include "hid/hidapi_mac.c"
#elif JUCE_WINDOWS
#include  <Windows.h>
#else
#error Trying to include the HID API on an unsupported platform!
#endif

#include <Windows.h>
#include <vector>
class hid_Runner
{
public:
	hid_Runner(hid::DeviceIO dio);
	~hid_Runner();

private:
#if JUCE_WINDOWS
	HANDLE hidReader;
	HANDLE hidWriter;

	HANDLE hEvent = NULL;
	
#endif // JUCE_WINDOWS

	
};

hid_Runner::hid_Runner(hid::DeviceIO dio)
{
	hEvent = CreateEvent(NULL, TRUE, TRUE, NULL);
	hidReader = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProc1,(LPVOID)(&dio), 0, NULL);
	Sleep(200);
	//hidWriter = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProc2, NULL, 0, NULL);
	//Sleep(200);
}

hid_Runner::~hid_Runner()
{
}

#if JUCE_WINDOWS
DWORD WINAPI ThreadProc1(LPVOID lpParam);
DWORD WINAPI ThreadProc2(LPVOID lpParam);

DWORD WINAPI ThreadProc1(LPVOID lpParam)
{
	//cout << "in thread1@!" << endl;

	//DWORD dReturn = WaitForSingleObject(hEvent, INFINITE);

	hid::DeviceIO* myReadP = (hid::DeviceIO*)(lpParam);
	hid::DeviceIO myRead = *myReadP;
	unsigned char data[64];
	size_t datalength = 64; 
	while (true)
	{
		if (!myRead.connect()) {
			myRead.read(data,datalength);
		}
	}

	//SetEvent(hEvent);
	return 0;
}
#endif