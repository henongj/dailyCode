#include "20230607_librarySystem.h"

void C20230607_librarySystem::init()
{
	m_studentManager.init();
	m_bookManager.init();
	m_mapBorrowedBook.clear();
}

void C20230607_librarySystem::release()
{
	m_studentManager.release();
	m_bookManager.release();
	m_mapBorrowedBook.clear();
}

bool C20230607_librarySystem::addStudent(int nID, const char* pName)
{
	return m_studentManager.addStudent(nID, pName);
}

bool C20230607_librarySystem::addBook(int nID, const char* pBookName)
{
	return m_bookManager.addBook(nID, pBookName);
}

bool C20230607_librarySystem::rentBook(int nStudentID, int nBookID)
{
	C20230607_Book* pBook = m_bookManager.findBook(nBookID);
	C20230607_STUDENT* pStudent = m_studentManager.findStudent(nStudentID);

	if (pBook == nullptr)
	{
		printf("id와 일치하는 책이 없습니다 %d\n", nBookID);
		return false;
	}

	if (pStudent == nullptr)
	{
		printf("id와 일치하는 학생이 없습니다 %d\n", nStudentID);
		return false;
	}

	std::map<C20230607_STUDENT*, std::list<C20230607_Book*>>::iterator iter = m_mapBorrowedBook.find(pStudent);
	
	if (iter == m_mapBorrowedBook.end())
	{
		std::list<C20230607_Book*> listBorrowedBook{};
		listBorrowedBook.push_back(pBook);
		m_mapBorrowedBook.insert({ pStudent, listBorrowedBook });
	}
	else
	{
		std::list<C20230607_Book*>& listBorrowedBook = iter->second;
		listBorrowedBook.push_back(pBook);
	}
	
	return true;
}

bool C20230607_librarySystem::returnBook(int nStudentID, int nBookID)
{
	C20230607_Book* pBook = m_bookManager.findBook(nBookID);
	C20230607_STUDENT* pStudent = m_studentManager.findStudent(nStudentID);

	if (pBook == nullptr)
	{
		printf("id와 일치하는 책이 없습니다 %d\n", nBookID);
		return false;
	}

	if (pStudent == nullptr)
	{
		printf("id와 일치하는 학생이 없습니다 %d\n", nStudentID);
		return false;
	}

	std::map<C20230607_STUDENT*, std::list<C20230607_Book*>>::iterator iter = m_mapBorrowedBook.find(pStudent);
	// 빌린 책 목록
	std::list<C20230607_Book*>& listBorrowedBook = iter->second;

	std::list<C20230607_Book*>::iterator iterBook = listBorrowedBook.begin();
	bool bFind = false;
	while (!bFind && iterBook != listBorrowedBook.end())
	{
		if ((*iterBook)->getID() == nBookID)
		{
			listBorrowedBook.erase(iterBook);
			bFind = true;
		}
		++iterBook;
	}

	return bFind;
}

void C20230607_librarySystem::printAllBorrowedBook(void)
{
	std::map<C20230607_STUDENT*, std::list<C20230607_Book*>>::iterator iter = m_mapBorrowedBook.begin();
	while (iter != m_mapBorrowedBook.end())
	{
		C20230607_STUDENT* pStudent = iter->first;
		std::list<C20230607_Book*>& listBorrowedBook = iter->second;

		pStudent->printInfo();
		std::list<C20230607_Book*>::iterator iterBook = listBorrowedBook.begin();
		while (iterBook != listBorrowedBook.end())
		{
			C20230607_Book* pBook = *iterBook;
			printf("빌린 책 이름 : %s\n", pBook->getBookName().c_str());
			++iterBook;
		}
		++iter;
	}
}


