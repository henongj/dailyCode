#pragma once
#include<list>

class C20230517_table
{
public:
	enum class e_result
	{
		E_OUT = 0,
		E_BALL,
		E_STRIKE,
		E_MAX
	};

private:
	e_result m_arTable[10];

public:
	C20230517_table() = default;
	void init(std::list<int>::iterator iterBegin, std::list<int>::iterator iterEnd);

	e_result getResult(int nNumber);
	void printTable(void);

};