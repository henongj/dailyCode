#include "20230530_move.h"

void C20230530_Move_Water::move()
{
	printf("Water move\n");
}

void C20230530_Move_Water::printMoveSound(void)
{
	printf("Water move sound func\n");
}

void C20230530_Move_Water::printMoveSpeed(void)
{
	printf("Water move speed func\n");
}

void C20230530_Move_Water::setSpeed(int nSpeed)
{
	m_nSpeed = nSpeed;
}

void C20230530_Move_Water::setDirection(float fDirection)
{
	m_fDirection = fDirection;
}

int C20230530_Move_Water::getSpeed(void)
{
	return m_nSpeed;
}

float C20230530_Move_Water::getDirection(void)
{
	return m_fDirection;
}

void C20230530_Move_Land::move()
{
	printf("Land move\n");
}

void C20230530_Move_Land::printMoveSound(void)
{
	printf("Land move sound func\n");
}

void C20230530_Move_Land::printMoveSpeed(void)
{
	printf("Land move speed func\n");
}

void C20230530_Move_Land::setSpeed(int nSpeed)
{
	m_nSpeed = nSpeed;
}

void C20230530_Move_Land::setDirection(float fDirection)
{
	m_fDirection = fDirection;
}

int C20230530_Move_Land::getSpeed(void)
{
	return m_nSpeed;
}

float C20230530_Move_Land::getDirection(void)
{
	return m_fDirection;
}
