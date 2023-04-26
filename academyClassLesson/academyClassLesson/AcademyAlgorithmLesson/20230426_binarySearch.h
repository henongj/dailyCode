#pragma once

class C20230426_biniarySearch
{
private:
	int m_nLength;
	int* m_pArrayData;
public:
	C20230426_biniarySearch() = default;
	~C20230426_biniarySearch() = default;
	
	C20230426_biniarySearch& operator=(const C20230426_biniarySearch& rhs) = delete;
	C20230426_biniarySearch(const C20230426_biniarySearch&) = delete;

	void init(int* pArray, int nLength);
	void release();
	void print();

	void getDataAddress(int nTarget, int* pResult);
	
};