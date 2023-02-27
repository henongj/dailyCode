#pragma once
#include<iostream>

namespace academyLecture_2023_02_27
{

	int strLength(const char* str, int nBufferLength);
	bool fillStringByOneCharacter(char* str, int nLengthOfStr, char cCharacter, int nNumOfCharacter);

	int main(void)
	{
		bool isSuccess{};

		const int nSizeOfStr{ 64 };
		char str[nSizeOfStr];

		int nNumOfCharacter{};
		char cCharacter{};

		nNumOfCharacter = 32;
		cCharacter = '4';

		isSuccess = fillStringByOneCharacter(str, nSizeOfStr, cCharacter, nNumOfCharacter);


		if (isSuccess)
			printf("%s\n", str);
		else
			printf("Error: 버퍼공간이 더 필요합니다.\n");

		return 0;
	}

	int strLength(const char* str, int nBufferLength)
	{
		int nStrLength{};

		while (str[nStrLength])
			nStrLength++;

		return nStrLength;
	}

	bool fillStringByOneCharacter(char* str, int nLengthOfStr, char cCharacter, int nNumOfCharacter)
	{
		if (nLengthOfStr <= nNumOfCharacter)
			return false;

		for (int i = 0; i < nNumOfCharacter; i++)
			str[i] = cCharacter;

		str[nNumOfCharacter] = '\0';

		return true;
	}


}