#pragma once
#include<stdio.h>
// �ڵ����� public �߻� Ŭ����
__interface C20230330_MOVE_INTERFACE
{
	// �ڵ����� public ���� ���� �Լ�
	void move();
};

class C20230330_MOVE abstract : public C20230330_MOVE_INTERFACE
{
protected:
	int m_nSpeed;
public:
	C20230330_MOVE() = default;
	C20230330_MOVE& operator=(const C20230330_MOVE& other) = delete;
	C20230330_MOVE(const C20230330_MOVE& other) = delete;
	virtual ~C20230330_MOVE() = default;

	void setSpeed(int nSpeed);
	// �ڵ����� public ���� �Լ�
	virtual void move() abstract;
};
		