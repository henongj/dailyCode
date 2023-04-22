#pragma once

class C_linked_list_2023_04_21;

class C_node_2023_04_21
{
	friend class C_linked_list_2023_04_21;

private:
	int m_nData;
	C_node_2023_04_21* m_pPrevNode;
	C_node_2023_04_21* m_pNextNode;

public:
	C_node_2023_04_21();
	~C_node_2023_04_21() = default;

	//delete copy assignment and operator =
	C_node_2023_04_21(const C_node_2023_04_21& other) = delete;
	C_node_2023_04_21& operator=(const C_node_2023_04_21& other) = delete;
	
	int getData();
	C_node_2023_04_21* getNextNode();

};