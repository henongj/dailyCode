#include<iostream>


namespace academyLecture_2023_02_13
{

	void fArrayAndPointer(void)
	{
		int arData[5]{ 5,4,3,2,1 };

		int* p{};

		p = arData; // int[5] �� ������ ���� �ְų� , &arData[0] , int* �� ������ ���� �ִ�.
		p = &arData[0]; // ���� ǥ���̴�

		// �׷��ٸ� int 5�� ¥���� �����͸� ������
		//�̰� �ǵ��� �ٰ� �ƴϴ�. �����Ͱ� 5���� �迭�� �Ǵ� ���̰�, 5��¥�� �迭�� ����Ű�� �����Ͱ� �ƴϴ�
		int* arPtr1[5]{ nullptr, nullptr, nullptr, nullptr, nullptr };


		//�̰��� int 5��¥�� �������̴�
		int(*arPtr2)[5] {};
		arPtr2 = &arData;

		// *arPtr2; // �̰� 0������ �ּҰ��� ���� �ְ�, int 5���� �ǹ��� ���� �ִ�.
		for (int i = 0; i < 5; i++)
			printf("%d ", (*arPtr2)[i]);


		// ��� int 5��¥�� �ּҰ�, int 5���� ��ζ�� ��
		printf("\n�̸��� ���� int [5]�� ���, ���� �� ����\n");
		printf("%zd\n", arPtr2);

		// ��� int ��δ� �´µ� �̸��� ���� int�� �ּҰ��̴�.
		printf("\n *�� ���̸� int [5]�� ����. �� �迭[0]�� �ּҰ� ���´� \n");
		printf("%zd\n", *arPtr2);

		//�̰� ���� ���´�.
		printf("\n *�� �� �� ���̸� int [5]�� ����, �� �迭�� ���� ������ �� \n");
		printf("%zd\n", **arPtr2);
		printf("\n(*arPtr2)[3] �迭ó�� �����ص� ���´�\n");
		printf("%zd\n", (*arPtr2)[3]);


		int* pSeperate{};
		int** ppSeperate{};

		pSeperate = arData;
		ppSeperate = &pSeperate;

		printf("\n�̰� �����Ͷ� ���� �����͸� ��Ƽ� ������ �����ϴ� ���\n");
		printf("pSeperate : %zd\n", pSeperate);
		printf("ppSeperate : %zd\n", ppSeperate);
		printf(" �� �ּҰ��� �ٸ��ݾ�. \n");
		printf("(*ppSeperate)[3] : %zd\n", (*ppSeperate)[3]);
		/*


		*/
	}
	
}
