#pragma once
#include<iostream>

__interface C20230331_MOVE_INTERFACE
{
	void Move() const;
	void upgrade();
};

class C20230331_MOVE abstract : public C20230331_MOVE_INTERFACE
{
protected:
	int m_nData;
	
public:
	virtual ~C20230331_MOVE() = default;
	C20230331_MOVE() = default;
	
	C20230331_MOVE(const C20230331_MOVE&) = delete;
	C20230331_MOVE& operator=(const C20230331_MOVE&) = delete;

	virtual void Move() const override;
};


class C20230331_WALK : public C20230331_MOVE
{
public:
	virtual ~C20230331_WALK() = default;
	C20230331_WALK() = default;
	
	C20230331_WALK(const C20230331_WALK&) = delete;
	C20230331_WALK& operator=(const C20230331_WALK&) = delete;

	virtual void Move() const override;
	virtual void upgrade() override;
	
};


class C20230331_SWIM : public C20230331_MOVE
{
public:
	virtual ~C20230331_SWIM() = default;
	C20230331_SWIM() = default;

	C20230331_SWIM(const C20230331_SWIM&) = delete;
	C20230331_SWIM& operator=(const C20230331_SWIM&) = delete;

	virtual void Move() const override;
	virtual void upgrade() override;

};

class C20230331_FLY : public C20230331_MOVE
{
public:
	virtual ~C20230331_FLY() = default;
	C20230331_FLY() = default;

	C20230331_FLY(const C20230331_FLY&) = delete;
	C20230331_FLY& operator=(const C20230331_FLY&) = delete;

	virtual void Move() const override;
	virtual void upgrade() override;

};
