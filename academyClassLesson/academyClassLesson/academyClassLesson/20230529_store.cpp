#include "20230529_store.h"

void C20230529_STORE::init()
{
	m_pFactory[(int)E_TYPE::E_TEA] = new C20230529_TEE_FACTORY{};
	m_pFactory[(int)E_TYPE::E_COFFE] = new C20230529_COFFE_FACTORY{};
	m_pFactory[(int)E_TYPE::E_JUICE] = new C20230529_JUICE_FACTORY{};
}

void C20230529_STORE::release()
{
	for (int i = 0; i < (int)E_TYPE::E_MAX; ++i)
		delete m_pFactory[i];
}

C20230529_BEVERAGE* C20230529_STORE::createDrink(E_TYPE eType)
{
	return m_pFactory[(int)eType]->createBeverage();
}
