#include<iostream>

namespace lecture_2023_01_17
{
	void remind(void)
	{
		int nData1{};
		int nData2{};
		int nData3{};

		nData2 = 20;
		nData3 = 30;

		nData1 = nData2 + nData3;

		std::cout << nData1;
	}

	void firstProgramToGetRectangleArea(void)
	{
		int nRectangleWdith{};
		int nRectangleHeight{};
		int nRectangleArea{};

		nRectangleWdith = 10;
		nRectangleHeight = 20;

		nRectangleArea = nRectangleWdith * nRectangleHeight;

		std::cout << nRectangleArea << std::endl;
	}
}
