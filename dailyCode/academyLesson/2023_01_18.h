#include<iostream>
namespace lecture_2023_01_18
{
	void fGetAreaOfRectangle(void)
	{
		int nWidth{};
		int nHeight{};
		int nArea{};

		std::cin >> nWidth;
		std::cin >> nHeight;

		nArea = nWidth * nHeight;

		std::cout << "¸éÀû : " << nArea << std::endl;

	}
}