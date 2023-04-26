#pragma once


void binarySearch_20230426(int* arData, int nLength, int nTarget, int*& pResult);

class C20230426_biniarySearch
{
private:
	int m_nLength;
	int* m_pArrayData;
	
private:

public:
	C20230426_biniarySearch() = default;
	~C20230426_biniarySearch() = default;
	
	C20230426_biniarySearch& operator=(const C20230426_biniarySearch& rhs) = delete;
	C20230426_biniarySearch(const C20230426_biniarySearch&) = delete;

	void init(int* pArray, int nLength);
	void release();
	void print();

	void search_loop(int nTarget, int*& pResult);
	void search_recursion_logic(int* pArrayData, int nLength, int nTarget, int*& pResult);

};