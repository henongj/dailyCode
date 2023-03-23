#include<iostream>

#include"20230322_class01.h"

#include"20230322_class02.h"

void _callByValueFunc(C_20230322_class01 c20230322_class01);
void _callByValueFunc02(C20230322_class02 c20230322_class02);

int _20230322mainSpace_01(void)
{
	C_20230322_class01 c20230322_class01{};

	c20230322_class01.setData(100);
	printf("%d\n", c20230322_class01.getData());

	//얕은 복사면 터진다 왜? 함수를 부르고 끝나면서 소멸자가 호출되고, main이 끝나면서 또 delete하기 때문에
	_callByValueFunc(c20230322_class01);

	return 0;
}

void _20230322mainSpace_02(void)
{
	int* pMain{};
	pMain = new int{};
	*pMain = 100;

	C20230322_class02 c20230322_class02{};
	c20230322_class02.init(pMain);

	c20230322_class02.setData(200);

	printf("%d\n", c20230322_class02.getData());
	printf("%d\n", *pMain);
	//이러면 안 된다. 왜냐면 빌려온 메모리를 외부 함수로 접근하는 짓이다.
	_callByValueFunc02(c20230322_class02);

	delete pMain;

}

void _callByValueFunc(C_20230322_class01 c20230322_class01)
{
	printf("%d\n", c20230322_class01.getData());
}
void _callByValueFunc02(C20230322_class02 c20230322_class02)
{
	printf("%d\n", c20230322_class02.getData());
}
