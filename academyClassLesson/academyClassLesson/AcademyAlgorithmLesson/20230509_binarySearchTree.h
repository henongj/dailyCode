#pragma once

class C_BST_20230509
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
	void findMaxNode(S_NODE*& pMaxNode, S_NODE*& pMaxNodeParent);
	void eraseNode(S_NODE* pNode, S_NODE* pParent);
public:
	C_BST_20230509() = default;
	~C_BST_20230509() = default;

	C_BST_20230509& operator=(const C_BST_20230509& rhs) = delete;
	C_BST_20230509(const C_BST_20230509& rhs) = delete;

	bool add(int nData);
	void erase(int nData);
	bool find(int nData);

	void print(void);
};