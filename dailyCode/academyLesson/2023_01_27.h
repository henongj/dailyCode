#include<iostream>
namespace academyLecture_2023_01_27
{
	void fSwitchCaseStatement(void)
	{
		int nData{};
		int nRadixOfTens{};

		scanf_s("%d", &nData);

		nRadixOfTens = nData / 10;

		switch (nRadixOfTens)
		{
		case 10:
		case 9:
		{
			int nCaseData{};
			printf("A임\n");
			break;
		}
		case 8:
			printf("B임\n");
			break;
		case 7:
			printf("C임\n");
			break;
		case 6:
			printf("D임\n");
			break;
		default:
			printf("미달 점수라 F임 \n");
			break;
		}

	}
}