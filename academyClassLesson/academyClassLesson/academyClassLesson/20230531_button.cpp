#include"20230531_button.h"

void C20230531_BUTTON::setCommand(C20230531_COMMAND* pCommand)
{
	m_pCommand = pCommand;
}

void C20230531_BUTTON::OnClick()
{
	m_pCommand->execute();
}