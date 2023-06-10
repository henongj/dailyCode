#pragma once
#include<list>
#include<map>
#include<string>
#include<set>
#include<stdio.h>
#include"20230607_studentManager.h"
#include"20230607_bookManager.h"

class C20230607_librarySystem
{
private:
	C20230607_STUDENT_MANAGER m_studentManager;
	C20230607_bookManager m_bookManager;
	std::map<C20230607_STUDENT*, std::list<C20230607_Book*>> m_mapBorrowedBook;

public:
	C20230607_librarySystem() = default;
	~C20230607_librarySystem() = default;

	C20230607_librarySystem(const C20230607_librarySystem&) = delete;
	C20230607_librarySystem& operator=(const C20230607_librarySystem&) = delete;

	void init();
	void release();

	bool addStudent(int nID, const char* pName);
	bool addBook(int nID, const char* pBookName);

	bool rentBook(int nStudentID, int nBookID);
	bool returnBook(int nStudentID, int nBookID);

	void printAllBorrowedBook(void);
};
