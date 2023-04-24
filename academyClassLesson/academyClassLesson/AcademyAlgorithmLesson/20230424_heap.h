#pragma once

class C20230424_HEAP
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
public:
	C20230424_HEAP() = default;
	~C20230424_HEAP() = default;
	
	//delete copy assnginment and operator =
	C20230424_HEAP& operator=(const C20230424_HEAP&) = delete;
	C20230424_HEAP(const C20230424_HEAP&) = delete;

	void init(int nLength);
	void release(void);
	bool add(int nData);
	void print(void);
	int getLength(void);
};