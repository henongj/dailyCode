#pragma once
#include"20230531_command.h"
#include"stdio.h"

class C20230531_LAMP
{
public:
	void lampOn();
};

class C20230531_LAMP_COMMAND : public C20230531_COMMAND
{
private:
	C20230531_LAMP* m_pLamp;
public:
	C20230531_LAMP_COMMAND(C20230531_LAMP* pLamp);
	virtual ~C20230531_LAMP_COMMAND() = default;

	virtual void execute() override;
};