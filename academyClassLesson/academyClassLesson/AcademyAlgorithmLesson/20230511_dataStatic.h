#pragma once

class C20230511_DATA
{
private:
	static int m_nDataStatic;
	int m_nDataClass;
public:

	void setDataClass(int nData);
	int getDataClass();

	static void setDataStatic(int nData);
	static int getDataStatic();
};