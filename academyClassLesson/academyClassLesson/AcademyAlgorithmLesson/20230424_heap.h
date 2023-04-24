#pragma once

class C20230424_HEAP
{
private:
	int* m_pBuffer;
	int m_nLength;
	

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
};