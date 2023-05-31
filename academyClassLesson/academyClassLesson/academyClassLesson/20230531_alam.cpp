#include"20230531_alam.h"

void C20230531_ALAM::alamOn()
{
	printf("Alam On\n");
}

C20230531_ALAM_COMMAND::C20230531_ALAM_COMMAND(C20230531_ALAM* pAlam)
	: m_pAlam{}
{
	m_pAlam = pAlam;
}

void C20230531_ALAM_COMMAND::execute()
{
	m_pAlam->alamOn();
}
