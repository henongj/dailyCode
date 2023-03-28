
#include"20230328_SubClass01.h"
#include"20230328_SubClass02.h"
#include"20230328_SubClass03.h"
#include"20230328_SubClass04.h"


int mainSpace05_20230328(void)
{
	C20230328_SUPERCLASS_ANIMAL* arAnimal[3]{};

	arAnimal[0] = new C20230328_SUBCLASS_CAT;
	arAnimal[1] = new C20230328_SUBCLASS_HUMAN;
	arAnimal[2] = new C20230328_SUBCLASS_BIRD;

	for (int i = 0; i < 3; i++)
	{
		arAnimal[i]->move();
	}

	for (int i = 0; i < 3; i++)
	{
		delete arAnimal[i];
	}
	return 0;
}



int mainSpace04_20230328(void)
{
	C20230328_SUPERCLASS_ANIMAL* pSuper{};

	printf("\n");
	pSuper = new C20230328_SUBCLASS_CAT{};

	pSuper->move();
	pSuper->C20230328_SUPERCLASS_ANIMAL::move();

	delete pSuper;

	return 0;
}
int mainSpace03_20230328(void)
{

	C20230328_SUBCLASS_CAT C_Cat{};

	C_Cat.move();
	C_Cat.C20230328_SUPERCLASS_ANIMAL::move();
	return 0;
}

int mainSpace01_20230328(void)
{
	// 이런 방식으론 안 쓴다. 
	C20230328_SUBCLASS C_Sub01{};
	
	return 0;
}

int mainSpace02_20230328(void)
{
	C20230328_SUPERCLASS* pSuper{};
	pSuper = new C20230328_SUBCLASS{};
	// 메모리 누수
	delete pSuper;

	return 0;
}