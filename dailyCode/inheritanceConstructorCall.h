#pragma once


class C_PATRENT_20320329
{
private:
	int m_nData;
public:
	C_PATRENT_20320329();
	~C_PATRENT_20320329();
};


class C_CHILD_20320329 : public C_PATRENT_20320329
{
private:
	int m_nData;
public:
	C_CHILD_20320329();
	~C_CHILD_20320329();
};
