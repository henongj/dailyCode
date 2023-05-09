#pragma once

class C20230509_BinarySearchTree
{
private:
	struct S_Node
	{
		int nData;
		S_Node* pLeft;
		S_Node* pRight;
	};

private:
	S_Node* m_pRootNode;

private:
	S_Node** findNode(S_Node** ppNode, int nData);
	void printNode(S_Node* pNode);
	S_Node* createNode(int nData);
public:
	C20230509_BinarySearchTree() = default;
	~C20230509_BinarySearchTree() = default;

	const C20230509_BinarySearchTree& operator=(const C20230509_BinarySearchTree& rhs) = delete;
	C20230509_BinarySearchTree(const C20230509_BinarySearchTree& rhs) = delete;

	bool add(int nData);
	void print();
	void erase(int nData);
};