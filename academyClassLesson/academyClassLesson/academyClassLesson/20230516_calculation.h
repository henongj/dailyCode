#pragma once

class C20230516_calculation
{
public:
	enum class E_OPERATOR
	{
		E_ADD,
		E_SUB,
		E_MUL,
		E_DIV,
		E_MOD,
		E_Length
	};

private:
	int m_nData1;
	int m_nData2;
	int m_nResult;
	void (C20230516_calculation::* m_arrFunc[(int)(E_OPERATOR::E_Length)])(void);

private:
	void add();
	void sub();
	void mul();
	void div();
	void mod();
	
public:
	C20230516_calculation() = default;
	void init(void);
	
	void setData(int nData1, int nData2);
	void update(E_OPERATOR eOperator);
	int getResult(void);

};