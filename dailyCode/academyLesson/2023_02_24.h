#pragma once

#include<iostream>

namespace academyLecture_2023_02_23
{
	void characterProperty(void)
	{
		char arData[64]{};
		char str1[64] = "abcdef";
		char str2[7] = "������";
		char str3[5] = "aaaa";
		int nIndex{};

		nIndex = 0;

		while (str1[nIndex] != '\0')
		{
			printf("%c ", str1[nIndex]);
			nIndex++;
		}

		puts("");
		// �ι��� Ư��
		nIndex = 0;
		while (str1[nIndex])
		{
			printf("%c ", str1[nIndex]);
			nIndex++;
		}

		puts("");

		// �� ���ڸ� ���� ������ ����Ϸ��� ��������
		str3[4] = 'z';
		// str3 ���
		nIndex = 0;
		while (str3[nIndex])
		{
			printf("%c ", str3[nIndex]);
			nIndex++;
		}

		printf("\n%s", str3);

	}
	void characterPrint(void)
	{
		char c1{};
		char c2{};

		c1 = 200;
		c2 = '\b';

		printf("%d\n", c1);
		printf("ccc%c", c2);
	}
}