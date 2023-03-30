#include<iostream>

#include"20230330_duck.h"
#include"20230330_walk.h"
#include"20230330_swim.h"
#include"20230330_run.h"

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
