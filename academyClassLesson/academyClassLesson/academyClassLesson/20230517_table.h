#pragma once


class C20230517_table
{
public:
	enum class e_result
	{
		E_OUT = 0,
		E_BALL,
		E_STRIKE,
		E_LENGTH
	};

private:
	e_result m_arTable[10];

public:
	C20230517_table() = default;
	void init(int nStrike, int nBall, int nBall2, int nBall3);

	e_result getResult(int nStrike, int nBall, int nBall2, int nBall3);
};