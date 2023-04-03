#pragma once


#include<iostream>

class C20230403_parentClass abstract
{
public:
	C20230403_parentClass(int nData);
	virtual ~C20230403_parentClass() = default;

	const C20230403_parentClass& operator=(const C20230403_parentClass& rhs) = delete;
	C20230403_parentClass(const C20230403_parentClass& rhs) = delete;
};

class C20230403_childClass : public C20230403_parentClass
{
public:
	C20230403_childClass(int nData);
};


