#pragma once
#include<iostream>

namespace academyLecture_2023_03_06
{

	struct S_DATA
	{
		int nData1;
		int nData2;
		float fData1;
		float fData2;
	};
	
	void countAlphabet(void)
	{
		char strOfAlphabet[256] = "asdfNNfobauQWFrowetaieboyAAvhpnfoYqHErJahfEDGaDWzxcqryuiokjnm";
		int arrCharacterCount[256]{};

		for (int i = 0; i < 256 && strOfAlphabet[i] != '\0'; i++)
			arrCharacterCount[strOfAlphabet[i]] = arrCharacterCount[strOfAlphabet[i]] + 1;


		for (int i = 0; i < 256; i++)
		{
			if (arrCharacterCount[i] > 0)
			{
				printf("%2c %2d\n", (char)i, arrCharacterCount[i]);
			}
		}
	}
	
	void mainSpace(void)
	{
		S_DATA sData{};

		sData.nData1 = 1;
	}
}
