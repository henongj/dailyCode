#pragma once
#include"20230526_student.h"
#include<map>
#include<string>

class C20230526_studentManager
{
private:
	std::map<std::string, C20230526_Student*> m_mapStudent;
	std::map<std::string, C20230526_Student*>::iterator iter;

private:
public:
	C20230526_studentManager() = default;
	~C20230526_studentManager() = default;

	C20230526_studentManager& operator=(const C20230526_studentManager&) = delete;
	C20230526_studentManager(const C20230526_studentManager&) = delete;

	bool addStudent(const char* pName, const char* pClass, int nGrade);
	bool eraseStudent(const char* pName);
	
	C20230526_Student* findStudent(const char* pName);

	void clear(void);
	void printAllStudentInfo(void);
	
};
