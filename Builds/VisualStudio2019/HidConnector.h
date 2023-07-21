#pragma once
#include <JuceHeader.h>
#include <vector>
#include <algorithm>
/// <summary>
/// 用来做交换用的类
/// </summary>

#ifndef  HConnector
#define HConnector
#endif // ! HidConnector

class HidConnector //Hid信息交换口
{
private :
	HidConnector() {

	}
public :
	static HidConnector* getInstance() {
		static HidConnector staticHidConnectorIns;
		return &staticHidConnectorIns;
	}
	struct linkData
	{
		int index;
		std::vector<unsigned char> data;
		/*int * & data;*/
	};

	bool CheckDataExist(int index) {
		if (deviceLinkData.begin() ==  deviceLinkData.end()) {
			return false;
		}
		if ((*(deviceLinkData.end() -1)).index < index) {
			return false;
		}
		for (auto dindex = deviceLinkData.begin(); dindex != deviceLinkData.end(); dindex++) {

			if ((*dindex).index == index) return true;
		}
	}

	void AddData(int index, std::vector<unsigned char> data) {
		//deviceLinkData.push_back(linkData{ index, data });
		if (CheckDataExist(index)) {
			ReplaceData(index, data);
		}
		else {
			deviceLinkData.push_back(linkData{ index, data });
		}
		//sort(deviceLinkData.begin(), deviceLinkData.end(),cmp_linkData);

		//for (int i = 0; i < 64; i++, data++) {
		//	int klasd = *data;
		//	int k = 1;
		//}

	}



	std::vector<unsigned char>  GetLinkData(int index) {
		std::vector<unsigned char> nullv;
		if (deviceLinkData.begin() == deviceLinkData.end()) {
			return nullv;
		}
		if ((*(deviceLinkData.end() - 1)).index < index) {
			return nullv;
		}
		for (auto dindex = deviceLinkData.begin(); dindex != deviceLinkData.end(); dindex++) {
			//int a[64];
			if ( (*dindex).index == index) { 
				// auto kld = std::begin((*dindex).data)
				//unsigned char asd = *kld;
				return (*dindex).data; }
		}
	}


	void ReplaceData(int index, std::vector<unsigned char> data) {
			deviceLinkData.at(index).data = data;
	}

	//int * GetLinkData(int index) {
	//	if (deviceLinkData.begin() == deviceLinkData.end()) {
	//		return false;
	//	}
	//	if ((*(deviceLinkData.end() - 1)).index < index) {
	//		return false;
	//	}
	//	for (auto dindex = deviceLinkData.begin(); dindex != deviceLinkData.end(); dindex++) {

	//		if ((*dindex).index == index) return (*dindex).data;
	//	}
	//}
	//void AddData(int index, int data[]) {
	//	//deviceLinkData.push_back(linkData{ index, data });
	//	if (CheckDataExist(index)) {
	//		ReplaceData(index, data);
	//	}
	//	else {
	//		deviceLinkData.push_back(linkData{ index, data });
	//	}
	//	//sort(deviceLinkData.begin(), deviceLinkData.end(),cmp_linkData);
	//}

	//void ReplaceData(int index, int data[]) {
	//	deviceLinkData.at(index).data = data;
	//}

	bool cmp_linkData(linkData * d1, linkData * d2) {
		return d1->index < d2->index;
	}

	int GetLength() {
		return deviceLinkData.size();
	}
private:
	std::vector<linkData> deviceLinkData;
	
};

