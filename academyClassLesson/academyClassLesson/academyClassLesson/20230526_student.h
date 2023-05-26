#pragma once
#include<string>

class C20230526_Student
{
private:
	std::string		m_strName;
	std::string		m_strMajor;
	int				m_nGrade;

public:
	C20230526_Student() = default;
	~C20230526_Student() = default;
	
	C20230526_Student(const C20230526_Student&) = delete;
	C20230526_Student& operator=(const C20230526_Student&) = delete;

	void init(const char* pName, const char* pClass, int nGrade);
	void printStudentInfo();
};