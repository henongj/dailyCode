#include"230314_move.h"
#include<iostream>


C_MOVE::C_MOVE(float fSpeed)
	: m_fSpeed{ fSpeed }
{
	setSpeed(fSpeed);
}

void C_MOVE::setSpeed(float fSpeed)
{
	m_fSpeed = fSpeed;
}

float C_MOVE::getSpeed(void)
{
	return m_fSpeed;
}
