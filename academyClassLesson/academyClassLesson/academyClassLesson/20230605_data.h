#pragma once
#include<list>
class C20230605_DATA
{
private:
	int m_arData[10][10];
	bool m_arCheck[10][10];
	int m_arDirectionClockwise[8][2];
	
	std::list<bool*> m_listPositionBackUp;

private:
	void eraseAdjacentNode(int nY, int nX, int nValue);
	bool isInside(int nY, int nX);
	
	void resetCheckField(void);
	void backUpPosition(int nY, int nX);
	
public:
	C20230605_DATA();
	~C20230605_DATA() = default;

	C20230605_DATA(const C20230605_DATA& rhs) = delete;
	C20230605_DATA& operator=(const C20230605_DATA& rhs) = delete;

	void print(void);
	void erase(int nY, int nX);
};