#pragma once

#include"20230531_command.h"

class C20230531_BUTTON
{
private:
	C20230531_COMMAND* m_pCommand;

public:
	C20230531_BUTTON() = default;
	
	void setCommand(C20230531_COMMAND* pCommand);
	void OnClick();
};