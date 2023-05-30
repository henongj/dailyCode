#pragma once
#include<set>
#include"20230530_Observer.h"

__interface I20230530_SUBJECT
{
	void add(C20230530_OBSERVER* pObserver, int nCount = 1);
	void remove(C20230530_OBSERVER* pObserver, int nCount = 1);
	void notify(int nData);
};

class C20230530_SUBJECT abstract : public I20230530_SUBJECT
{
public:
	virtual ~C20230530_SUBJECT() = default;
};

class C20230530_PLAYER : public C20230530_SUBJECT
{
private:
	std::multiset<C20230530_OBSERVER*> m_setObserver;
	int m_nCount{};

	// C20230530_SUBJECT을(를) 통해 상속됨
	virtual void add(C20230530_OBSERVER* pObserver, int nCount) override;
	virtual void remove(C20230530_OBSERVER* pObserver, int nCount = 1) override;
	virtual void notify(int nData) override;

};
