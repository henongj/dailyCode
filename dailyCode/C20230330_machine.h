#pragma once

// 인터페이스 만들기
class C20230330_machine_interface abstract
{
	virtual void start() = 0;
	virtual void stop() = 0;
	
	virtual int* getFuel(int nFuel) = 0;
	virtual void setFuel(int nFuel) = 0;
};

// __interface로 인터페이스 만들기
__interface C20230330_machine_interface2
{
	void start();

	int* getFuel(int nFuel);
};

// 인터페이스를 상속받아서 추상 클래스 만들기
class C20230330_machine abstract : public C20230330_machine_interface
{
private:
	int m_nFuel;
public:
	virtual ~C20230330_machine() = default;
	C20230330_machine() = default;
	C20230330_machine(const C20230330_machine&) = delete;
	C20230330_machine& operator=(const C20230330_machine&) = delete;
};

// __interface로 인터페이스를 상속받아서 추상 클래스 만들기
class C20230330_machine2 abstract : public C20230330_machine_interface2
{
private:
	int m_nFuel;
public:
	virtual ~C20230330_machine2() = default;
	C20230330_machine2() = default;
	C20230330_machine2(const C20230330_machine2&) = delete;
	C20230330_machine2& operator=(const C20230330_machine2&) = delete;
};