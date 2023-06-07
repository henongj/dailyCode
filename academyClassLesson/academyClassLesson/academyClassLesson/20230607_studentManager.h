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
	C20230607_STUDENT* findStudent(int nID);

};
	