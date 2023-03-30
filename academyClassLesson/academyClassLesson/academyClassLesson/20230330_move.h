#pragma once
#include<stdio.h>
// 자동으로 public 추상 클래스
__interface C20230330_MOVE_INTERFACE
{
	// 자동으로 public 순수 가상 함수
	void move();
};

class C20230330_MOVE abstract : public C20230330_MOVE_INTERFACE
{
public:
	C20230330_MOVE() = default;
	C20230330_MOVE& operator=(const C20230330_MOVE& other) = delete;
	C20230330_MOVE(const C20230330_MOVE& other) = delete;
	virtual ~C20230330_MOVE() = default;
	// 자동으로 public 가상 함수
	virtual void move() override;
};
		
