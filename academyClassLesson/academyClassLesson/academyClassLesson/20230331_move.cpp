#include "20230331_move.h"

void C20230331_MOVE::Move() const
{
	printf("MOVE MOVE %d : ", m_nData);
}


void C20230331_WALK::Move() const
{
	C20230331_MOVE::Move();
	printf("WALK WALK \n");
}

void C20230331_WALK::upgrade()
{
	m_nData++;
}

void C20230331_SWIM::Move() const
{
	C20230331_MOVE::Move();
	printf("SWIM SWIM \n");
}

void C20230331_SWIM::upgrade()
{
	printf("SWIM can't upgrade \n");
}

void C20230331_FLY::Move() const
{
	C20230331_MOVE::Move();
	printf("FLY FLY \n");
}

void C20230331_FLY::upgrade()
{
	m_nData += 7;
}
