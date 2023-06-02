#pragma once
#include"stdio.h"
#include"20230531_command.h"

class C20230531_ALAM
{
public:
	void alamOn();
};

class C20230531_ALAM_COMMAND : public C20230531_COMMAND
{
private:
	C20230531_ALAM* m_pAlam;
public:
	C20230531_ALAM_COMMAND(C20230531_ALAM* pAlam);
	virtual ~C20230531_ALAM_COMMAND() = default;
	
	virtual void execute() override;
};