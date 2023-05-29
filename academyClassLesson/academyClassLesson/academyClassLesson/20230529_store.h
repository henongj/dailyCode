#pragma once
#include"20230529_Factory.h"
class C20230529_STORE
{
public:
	enum class E_TYPE
	{
		E_TEA,
		E_COFFE,
		E_JUICE,
		E_MAX
	};
private:
	C20230529_FACTORY* m_pFactory[(int)E_TYPE::E_MAX];
	
public:
	C20230529_STORE() = default;
	~C20230529_STORE() = default;

	void init();
	void release();

	C20230529_BEVERAGE* createDrink(E_TYPE eType);
};
