#pragma once

__interface I20230404_MOVE
{
	//set move, get move
	void setMove(C20230404_MOVE* move);
	C20230404_MOVE* getMove();
	//init release
	void init();
	void release();
};

class C20230404_MOVE abstract : public I20230404_MOVE
{
protected:
	int m_nSpeed;
public:
	C20230404_MOVE() = default;
	virtual ~C20230404_MOVE() = default;
	
	C20230404_MOVE(const C20230404_MOVE&) = delete;
	C20230404_MOVE& operator=(const C20230404_MOVE&) = delete;
};
