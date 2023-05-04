#pragma once
#pragma once

class C_BST_20230504
{
private:
	struct S_NODE
	{
		int m_nData;
		S_NODE* m_pLeft;
		S_NODE* m_pRight;
	};

private:
	S_NODE* m_pRoot;

private:
	void printNode(S_NODE* pNode);
	S_NODE* createNode(int nData);
public:
	C_BST_20230504() = default;
	~C_BST_20230504() = default;

	C_BST_20230504& operator=(const C_BST_20230504& rhs) = delete;
	C_BST_20230504(const C_BST_20230504& rhs) = delete;

	bool add(int nData);
	void erase(int nData);
	bool find(int nData);

	void print(void);
};