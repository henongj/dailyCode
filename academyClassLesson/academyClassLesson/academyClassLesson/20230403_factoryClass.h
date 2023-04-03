#pragma once

class C20230403_MOVE abstract
{
private:
public:
	virtual ~C20230403_MOVE() = default;
	virtual void move() abstract;
	C20230403_MOVE() = default;

	// delete copy constructor, copy assignment operator
	C20230403_MOVE(const C20230403_MOVE&) = delete;
	C20230403_MOVE& operator=(const C20230403_MOVE&) = delete;
	
};

class C20230403_WALK : public C20230403_MOVE
{
private:
public:
	virtual ~C20230403_WALK() = default;
	virtual void move() override;
	C20230403_WALK() = default;

	// delete copy constructor, copy assignment operator
	C20230403_WALK(const C20230403_WALK&) = delete;
	C20230403_WALK& operator=(const C20230403_WALK&) = delete;
};

class C20230403_SWIM : public C20230403_MOVE
{
private:
public:
	virtual ~C20230403_SWIM() = default;
	virtual void move() override;
	C20230403_SWIM() = default;

	// delete copy constructor, copy assignment operator
	C20230403_SWIM(const C20230403_SWIM&) = delete;
	C20230403_SWIM& operator=(const C20230403_SWIM&) = delete;
};

class C20230403_FLY : public C20230403_MOVE
{
private:
public:
	// C20230403_MOVE을(를) 통해 상속됨
	virtual void move() override;
	C20230403_FLY() = default;

	// delete copy constructor, copy assignment operator
	C20230403_FLY(const C20230403_FLY&) = delete;
	C20230403_FLY& operator=(const C20230403_FLY&) = delete;
};