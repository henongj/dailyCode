#pragma once


class C20230329_ANIMAL abstract
{
private:	
public:
	// �� Ŭ����
	virtual ~C20230329_ANIMAL() = default;
	C20230329_ANIMAL() = default;
	C20230329_ANIMAL(const C20230329_ANIMAL&) = delete;
	C20230329_ANIMAL& operator = (const C20230329_ANIMAL&) = delete;

	// ��������� Ȯ���� �䱸�ϴ� �Լ�
	virtual void move() abstract;
};