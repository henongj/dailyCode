#pragma once
#pragma once

class C20230426_HEAP
{
private:
	enum
	{
		E_NULL = 0,
	};

private:
	int* m_pBuffer;
	int m_nLength;
	int m_nCount;

private:
	void swapData(int& nDst, int& nSrc);
	bool add_recursion_logic(int nIndex, int nUp);
	void erase();
	int getBig(int n1, int n2);
public:
	C20230426_HEAP() = default;
	~C20230426_HEAP() = default;

	//delete copy assnginment and operator =
	C20230426_HEAP& operator=(const C20230426_HEAP&) = delete;
	C20230426_HEAP(const C20230426_HEAP&) = delete;

	void init(int nLength);
	void release(void);

	bool add(int nData);
	bool add_recursion(int nData);

	void print(void);
	int getLength(void);
	bool pop(void);

};