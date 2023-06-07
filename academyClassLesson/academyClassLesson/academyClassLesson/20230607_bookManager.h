#pragma once
#include<set>
#include<list>
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

public:
	// 추가/ 삭제/ 검색해야함
	// 동적할당 해제 전부해야함
	
};
