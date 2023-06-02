#include<set>

#include "20230530_Subject.h"
void C20230530_PLAYER::add(C20230530_OBSERVER* pObserver, int nCount)
{
	for (int i = 0; i < nCount; i++)
		m_setObserver.insert(pObserver);
}

void C20230530_PLAYER::remove(C20230530_OBSERVER* pObserver, int nCount)
{
	int nNum{};
	std::multiset<C20230530_OBSERVER*>::iterator iter = m_setObserver.find(pObserver);

	while (nNum < nCount && iter != m_setObserver.end() && *iter == pObserver)
	{
		iter = m_setObserver.erase(iter);
		nNum++;
	}
		
	if (nNum < nCount)
		printf("½ÇÆÐ");
}
void C20230530_PLAYER::notify(int nData)
{
	std::multiset<C20230530_OBSERVER*>::iterator iter = m_setObserver.begin();
	while (iter != m_setObserver.end())
	{
		(*iter)->update(nData);
		iter++;
	}
}

