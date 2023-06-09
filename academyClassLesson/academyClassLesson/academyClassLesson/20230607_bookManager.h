#pragma once
#include<set>
#include<list>
#include<stdio.h>
#include<map>
#include"20230607_Student.h"
class C20230607_bookManager
{
private:
	struct S_INFO
	{
		int nID;
		C20230607_STUDENT* pStudent;
		std::map<std::string,std::list<std::string>> mapBookData;
	};
private:
	std::set<S_INFO> m_setInfo;
	S_INFO* pInfoBuffer;
	C20230607_STUDENT* pStudentBuffer;
		
private:
	void registStudent(int nID, const char* pStudentName, std::set<S_INFO>::iterator iter);
	
public:
	C20230607_bookManager() = default;
	~C20230607_bookManager() = default;
	// 추가/ 삭제/ 검색해야함
	// 동적할당 해제 전부해야함
	
	void init();
	void release();

	void addBook(int nID, const char* pStudentName, const char* pBookName);
	
	void printAll(void);
};
