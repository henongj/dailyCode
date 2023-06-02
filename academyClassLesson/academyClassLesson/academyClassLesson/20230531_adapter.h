#pragma once
#include<iostream>
#include<set>

__interface I20230531_Duck
{
	void fly();
};

class C20230531_DUCK : public I20230531_Duck
{
public:
	C20230531_DUCK() = default;
	~C20230531_DUCK() = default;

	void fly() override
	{
		std::cout << "날라간데이\n" << std::endl;
	}
};

class C20230531_Mallard : public C20230531_DUCK
{
};

class C20230531_Nomal_Duck : public C20230531_DUCK
{
};
class C20230531_Human
{
public:
	void walk()
	{
		printf("걸어간드아\n");
	}
};

class C20230531_AdapterDuck : public C20230531_DUCK
{
private:
	C20230531_Human* m_pHuman{};

public:
	C20230531_AdapterDuck(C20230531_Human* pHuman) : m_pHuman{} { m_pHuman = pHuman; }
	virtual void fly()
	{
		m_pHuman->walk();
	}
};


int mainSpace01_20230531(void)
{
	C20230531_DUCK* arDuck[4]{};
	C20230531_Human cHuman{};
	C20230531_AdapterDuck cAdapterDuck{ &cHuman };

	arDuck[0] = new C20230531_DUCK();
	arDuck[1] = new C20230531_Mallard();
	arDuck[2] = new C20230531_Nomal_Duck();
	arDuck[3] = &cAdapterDuck;
	for (int i = 0; i < 4; ++i)
	{
		arDuck[i]->fly();
	}



	return 0;
}