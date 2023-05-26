#include "20230526_student.h"
#include<stdio.h>
void C20230526_Student::init(const char* pName, const char* pClass, int nGrade)
{
	m_strName = pName;
	m_strMajor = pClass;
	m_nGrade = nGrade;
}

void C20230526_Student::printStudentInfo()
{
	printf("name : %s  ", m_strName.c_str());
	printf("major : %s  ", m_strMajor.c_str());
	printf("grade : %d\n", m_nGrade);
}
