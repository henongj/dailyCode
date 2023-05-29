#pragma once

#include<stdio.h>

class C20230530_Move abstract
{
private:
	int m_nSpeed;
	float m_fDirection;
	
public:
	virtual ~C20230530_Move() = default;
	virtual void move() abstract;
	virtual void printMoveSound(void) abstract;
	virtual void printMoveSpeed(void) abstract;

	virtual void setSpeed(int nSpeed) abstract;
	virtual void setDirection(float fDirection) abstract;
	
	virtual int getSpeed(void) abstract;
	virtual float getDirection(void) abstract;
	
};

class C20230530_Move_Water : public C20230530_Move
{
private:
	int m_nSpeed;
	float m_fDirection;
public:
	C20230530_Move_Water() = default;
	~C20230530_Move_Water() = default;

	void move() override;
	void printMoveSound(void) override;
	void printMoveSpeed(void) override;
	
	void setSpeed(int nSpeed) override;
	void setDirection(float fDirection) override;

	int getSpeed(void) override;
	float getDirection(void) override;
	
};

class C20230530_Move_Land : public C20230530_Move
{
private:
	int m_nSpeed;
	float m_fDirection;
public:
	C20230530_Move_Land() = default;
	~C20230530_Move_Land() = default;
	// C20230530_Move을(를) 통해 상속됨
	virtual void move() override;
	virtual void printMoveSound(void) override;
	virtual void printMoveSpeed(void) override;
	virtual void setSpeed(int nSpeed) override;
	virtual void setDirection(float fDirection) override;
	virtual int getSpeed(void) override;
	virtual float getDirection(void) override;
};

