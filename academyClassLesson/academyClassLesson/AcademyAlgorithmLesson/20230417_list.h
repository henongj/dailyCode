#pragma once

class C_LIST
{
private:
	struct S_NODE
	{
		int m_nData;
		S_NODE* pNext;
	};

	S_NODE* m_pBegin;
	S_NODE* m_pEnd;

public:
	C_LIST() = default;
	~C_LIST() = default;
	
	//delete copy constructor and copy assignment operator
	C_LIST(const C_LIST&) = delete;
	C_LIST& operator=(const C_LIST&) = delete;

	C_LIST::S_NODE* createNode(int nData, S_NODE* pNext);
	
	void add(int nData);
	void print(void);
	void remove(int nData);
};