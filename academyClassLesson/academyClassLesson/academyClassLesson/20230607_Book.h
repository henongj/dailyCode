#pragma once
#include<map>
#include<string>
class C20230607_Book
{
private:
	int m_nID;
	std::string m_strBookName;

public:
	C20230607_Book(int nID, const char* pBookName);
	~C20230607_Book() = default;

	//delete copy , assgin operator
	C20230607_Book(const C20230607_Book&) = delete;
	C20230607_Book& operator=(const C20230607_Book&) = delete;

	void setId(int nID);
	void setBookName(const char* pBookName);
	
	int getID(void);
	std::string getBookName(void);
};