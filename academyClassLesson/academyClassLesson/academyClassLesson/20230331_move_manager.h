#pragma once

class C20230331_MOVE;

class C20230331_MOVE_MANAGER
{
private:
	C20230331_MOVE** m_ppMove;
	int m_nMoveLength;

public:
	C20230331_MOVE_MANAGER() = default;
	~C20230331_MOVE_MANAGER();
	
	void init();
	C20230331_MOVE* getMove(int nIndex);
	
};