#include<iostream>

namespace academyLecture_2023_02_13
{
	void fBasicPointer(void)
	{
		int nData{};
		int* p{};

		nData = 120;
		p = &nData;
		// p 는 경로
		// *p 는 nData의 값
		// &p는 p의 주소

		// *p의 값은?
		printf("%d\n", *p);

		// *p의 주소를 출력하고 싶다면?
		printf("%p\n", &(*p));
		// nData의 주소를 출력하고 싶다면?
		printf("%p\n", &nData);

		{
			int nTemp{};
			nTemp = 100;
			p = &nTemp;
		}
		// p는 nTemp의 주소를 가리키고 있다.
		// 이거 터진거다. 그런데 돌아간다.
		printf("%d\n", *p);

		p = nullptr;

		int* p1{};
		int* p2{};
		// 같은 것을 참조하는 포인터
		p1 = p2 = new int{};

		*p1 = 100;
		// 죽어버린 메모리
		delete p2;

		// 다시 대입
		*p1 = 9;

		// 죽은 메모리 사용. 하지만 사용.
		printf("%d\n", *p1);
		
		int* p3{};

		p1 = &nData;
		p2 = &nData;
		p3 = &nData;

		*p1 = 9;

		printf("%d\n", *p3);
		
	}
}