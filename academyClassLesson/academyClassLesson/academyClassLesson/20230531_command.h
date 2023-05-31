#pragma once

class C20230531_COMMAND abstract
{
public:
	virtual ~C20230531_COMMAND() = default;
	virtual void execute() abstract;
};