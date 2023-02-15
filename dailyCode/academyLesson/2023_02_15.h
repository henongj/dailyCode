#include<iostream>


namespace academyLecture_2023_02_13
{

	void fArrayAndPointer(void)
	{
		int arData[5]{ 5,4,3,2,1 };

		int* p{};

		p = arData; // int[5] 로 인지될 수도 있거나 , &arData[0] , int* 로 인지될 수도 있다.
		p = &arData[0]; // 같은 표현이다

		// 그렇다면 int 5개 짜리의 포인터를 만들어보자
		//이건 의도한 바가 아니다. 포인터가 5개인 배열이 되는 것이고, 5개짜리 배열을 가리키는 포인터가 아니다
		int* arPtr1[5]{ nullptr, nullptr, nullptr, nullptr, nullptr };


		//이것이 int 5개짜리 포인터이다
		int(*arPtr2)[5] {};
		arPtr2 = &arData;

		// *arPtr2; // 이건 0번지의 주소값일 수도 있고, int 5개를 의미할 수도 있다.
		for (int i = 0; i < 5; i++)
			printf("%d ", (*arPtr2)[i]);


		// 얘는 int 5개짜리 주소값, int 5개의 경로라는 뜻
		printf("\n이름만 쓰면 int [5]의 경로, 아직 안 갔다\n");
		printf("%zd\n", arPtr2);

		// 얘는 int 경로는 맞는데 이름만 쓰면 int의 주소값이다.
		printf("\n *를 붙이면 int [5]에 갔다. 간 배열[0]의 주소가 나온다 \n");
		printf("%zd\n", *arPtr2);

		//이건 값이 나온다.
		printf("\n *를 두 번 붙이면 int [5]에 가서, 그 배열의 값을 꺼내온 것 \n");
		printf("%zd\n", **arPtr2);
		printf("\n(*arPtr2)[3] 배열처럼 접근해도 나온다\n");
		printf("%zd\n", (*arPtr2)[3]);


		int* pSeperate{};
		int** ppSeperate{};

		pSeperate = arData;
		ppSeperate = &pSeperate;

		printf("\n이건 포인터랑 이중 포인터를 잡아서 줄지어 연결하는 방식\n");
		printf("pSeperate : %zd\n", pSeperate);
		printf("ppSeperate : %zd\n", ppSeperate);
		printf(" ↑ 주소값이 다르잖아. \n");
		printf("(*ppSeperate)[3] : %zd\n", (*ppSeperate)[3]);
		/*


		*/
	}
	
}
