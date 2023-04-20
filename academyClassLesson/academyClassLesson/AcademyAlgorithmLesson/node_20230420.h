#pragma once

class C_LINKED_LIST_20230420;

class C_NODE_20230420
{
	friend class C_LINKED_LIST_20230420;
private:
	int m_nData;
	C_NODE_20230420* m_pNextNode;
	C_NODE_20230420* m_pPreviousNode;

private:
	C_NODE_20230420() = default;
	~C_NODE_20230420() = default;
	
public:
	int getData();
	C_NODE_20230420* getNextNode();
	
	//delete copy assignment and operator =
	C_NODE_20230420(const C_NODE_20230420& other) = delete;
	C_NODE_20230420& operator=(const C_NODE_20230420& other) = delete;
};