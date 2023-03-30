#pragma once

class C20230330_MOVE;

class C_20230330_DUCK
{
private:
	C20230330_MOVE* m_pMove;
	
public:
	C_20230330_DUCK() = default;
	void setMove(C20230330_MOVE* pMove);
	C20230330_MOVE* getMove();
	
};