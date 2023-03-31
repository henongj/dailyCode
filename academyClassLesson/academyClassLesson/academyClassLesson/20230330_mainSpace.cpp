#include<iostream>

#include"20230330_duck.h"
#include"20230330_walk.h"
#include"20230330_swim.h"
#include"20230330_run.h"
int mainSpace03_20230330(void)
{
	C_20230330_DUCK cDuck[3]{};

	C_20230330_WALK* pWalk{};

	//아까와 다르게 각자 다른 walk를 들고있다
	pWalk = new C_20230330_WALK{};
	pWalk->setSpeed(10);
	cDuck[0].setMove(pWalk);

	pWalk = new C_20230330_WALK{};
	pWalk->setSpeed(20);
	cDuck[1].setMove(pWalk);

	pWalk = new C_20230330_WALK{};
	pWalk->setSpeed(30);
	cDuck[2].setMove(pWalk);

	for (int i = 0; i < 3; i++)
		cDuck[i].getMove()->move();

	return 0;
}
int mainSpace02_20230330(void)
{
	C_20230330_WALK cWalk{};
	C_20230330_RUN cRun{};
	C_20230330_SWIM cSwim{};

	C_20230330_DUCK arDuck[4]{};

	cWalk.setSpeed(10);
	cRun.setSpeed(20);
	cSwim.setSpeed(30);

	arDuck[0].setMove(&cWalk);
	arDuck[1].setMove(&cRun);
	arDuck[2].setMove(&cSwim);
	arDuck[3].setMove(&cRun);

	printf("_________________");

	for (int i = 0; i < 4; i++)
		arDuck[i].getMove()->move();

	printf("_________________");

	cRun.setSpeed(10);

	for (int i = 0; i < 4; i++)
		arDuck[i].getMove()->move();

	return 0;
}

int mainSpace01_20230330(void)
{
	C_20230330_DUCK cDuck{};
	C_20230330_WALK cWalk{};
	C_20230330_RUN cRun{};
	C_20230330_SWIM cSwim{};

	cDuck.setMove(&cWalk);
	cDuck.getMove()->move();

	cDuck.setMove(&cRun);
	cDuck.getMove()->move();

	cDuck.setMove(&cSwim);
	cDuck.getMove()->move();


	return 0;
}
