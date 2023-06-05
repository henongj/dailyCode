#include<iostream>
#include "20230605_data.h"

bool C20230605_DATA::isInside(int nY, int nX)
{
	if (nX >= 10 || nX < 0 || nY < 0 || nY >= 10)
		return false;

	return true;
}

void C20230605_DATA::resetCheckField(void)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			m_arCheck[i][j] = false;
		}
	}
}

C20230605_DATA::C20230605_DATA() :
	m_arData{}, m_arCheck{}, m_arDirectionClockwise{}
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			m_arData[i][j] = rand() % 3 + 1;
			m_arCheck[i][j] = false;
		}
	}
	/*
	ºÏ (-1, 0)
	ºÏµ¿(-1, 1)	
	µ¿(0, 1)
	³²µ¿(1, 1)
	³²(1, 0)
	³²¼­(1, -1)
	¼­(0, -1)
	ºÏ¼­(-1, -1)
	*/
	m_arDirectionClockwise[0][0] = -1;	m_arDirectionClockwise[0][1] = 0;
	m_arDirectionClockwise[1][0] = -1;	m_arDirectionClockwise[1][1] = 1;
	m_arDirectionClockwise[2][0] = 0;	m_arDirectionClockwise[2][1] = 1;
	m_arDirectionClockwise[3][0] = 1;	m_arDirectionClockwise[3][1] = 1;
	m_arDirectionClockwise[4][0] = 1;	m_arDirectionClockwise[4][1] = 0;
	m_arDirectionClockwise[5][0] = 1;	m_arDirectionClockwise[5][1] = -1;
	m_arDirectionClockwise[6][0] = 0;	m_arDirectionClockwise[6][1] = -1;
	m_arDirectionClockwise[7][0] = -1;	m_arDirectionClockwise[7][1] = -1;

}

void C20230605_DATA::print(void)
{
	printf("\n-------------------------------------------------\n");
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%d ", m_arData[i][j]);
		}
		printf("\n");
	}
}

void C20230605_DATA::erase(int nY, int nX)
{
	int nEraseValue = m_arData[nY][nX];
	printf("erase(%d, %d) : %d \n", nY, nX, nEraseValue);
	
	eraseAdjacentNode(nY, nX, nEraseValue);

	for (auto iter = m_listPositionBackUp.begin(); iter != m_listPositionBackUp.end(); iter++)
		**iter = false;
	
	m_listPositionBackUp.clear();
}


void C20230605_DATA::eraseAdjacentNode(int nY, int nX, int nValue)
{
	if (!isInside(nY, nX) || m_arCheck[nY][nX] || m_arData[nY][nX] != nValue)
		return;
	
	m_arCheck[nY][nX] = true;
	m_arData[nY][nX] = 0;
	m_listPositionBackUp.push_back(&m_arCheck[nY][nX]);
	
	for (int nDirection = 0; nDirection < 8; nDirection++)
	{
		int nYposAdjacent = nY + m_arDirectionClockwise[nDirection][0];
		int nXposAdjacent = nX + m_arDirectionClockwise[nDirection][1];

		eraseAdjacentNode(nYposAdjacent, nXposAdjacent, nValue);
	}
}
