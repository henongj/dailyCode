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
			printf("A��\n");
			break;
		}
		case 8:
			printf("B��\n");
			break;
		case 7:
			printf("C��\n");
			break;
		case 6:
			printf("D��\n");
			break;
		default:
			printf("�̴� ������ F�� \n");
			break;
		}

	}
}