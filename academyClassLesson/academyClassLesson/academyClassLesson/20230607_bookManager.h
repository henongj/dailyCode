#pragma once
#include<set>
#include<list>
#include<stdio.h>
#include<map>
#include"20230607_Student.h"
#include"20230607_Book.h"
class C20230607_bookManager
{
private:
	std::map<int, C20230607_Book*> m_mapBook;

public:
	C20230607_bookManager() = default;
	~C20230607_bookManager() = default;
	
	void init();
	void release();

	bool addBook(int nID, const char* pBookName);
	bool eraseBook(int nID, const char* pBookName);

	C20230607_Book* findBook(int nID);
	void printAllBook(void);
};
	
	