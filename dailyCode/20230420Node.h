#pragma once

class C_NODE20230420_1
{
private:
	int m_nData;
	C_NODE20230420_1* m_pNextNode;
	C_NODE20230420_1* m_pPreviousNode;

public:
	C_NODE20230420_1() = default;
	~C_NODE20230420_1() = default;
	
	//delete copy assignment and operator =
	C_NODE20230420_1(const C_NODE20230420_1& other) = delete;
	C_NODE20230420_1& operator=(const C_NODE20230420_1& other) = delete;

	int GetData();
	C_NODE20230420_1* GetNextNode();
};
