#pragma once


class C20230329_ANIMAL abstract
{
private:	
public:
	// 빈 클래스
	virtual ~C20230329_ANIMAL() = default;
	C20230329_ANIMAL() = default;
	C20230329_ANIMAL(const C20230329_ANIMAL&) = delete;
	C20230329_ANIMAL& operator = (const C20230329_ANIMAL&) = delete;

	// 명시적으로 확장을 요구하는 함수
	virtual void move() abstract;
};