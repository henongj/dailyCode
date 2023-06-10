#include "20230607_Book.h"

C20230607_Book::C20230607_Book(int nID, const char* pBookName) :
	m_nID{}, m_strBookName{}
{
	m_nID = nID;
	m_strBookName = pBookName;
}

void C20230607_Book::setId(int nID)
{
	m_nID = nID;
}

void C20230607_Book::setBookName(const char* pBookName)
{
	m_strBookName = pBookName;
}

int C20230607_Book::getID(void)
{
	return m_nID;
}

std::string C20230607_Book::getBookName(void)
{
	return m_strBookName;
}
