#include"20230531_lamp.h"

void C20230531_LAMP::lampOn()
{
	printf("lampOn On\n");
}

C20230531_LAMP_COMMAND::C20230531_LAMP_COMMAND(C20230531_LAMP* pAlam)
	: m_pLamp{}
{
	m_pLamp = pAlam;
}

void C20230531_LAMP_COMMAND::execute()
{
	m_pLamp->lampOn();
}
