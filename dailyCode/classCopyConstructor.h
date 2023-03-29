#pragma once

class ClassCopyConstructor
{
private:
	int m_nData1;
	int m_nData2;
public:
	ClassCopyConstructor() = default;
	void init(int nData1, int nData2);
	
	// ban Copy constructor
	ClassCopyConstructor(const ClassCopyConstructor&) = delete;
	// ban Copy assignment operator
	ClassCopyConstructor& operator=(const ClassCopyConstructor&) = delete;
	
	~ClassCopyConstructor() = default;
};