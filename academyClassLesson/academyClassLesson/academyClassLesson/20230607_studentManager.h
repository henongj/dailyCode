#pragma once
#include<map>
#include"20230607_Student.h"

class C20230607_STUDENT_MANAGER
{
private:
	std::map<int, C20230607_STUDENT*> m_mapStudent;

public:
	C20230607_STUDENT_MANAGER() = default;
	
	void init();
	void release();
	
	bool addStudent(int nID, const char* pName);
	bool eraseStudent(int nID, const char* pName);

	C20230607_STUDENT* findStudent(int nID);
	
};
	