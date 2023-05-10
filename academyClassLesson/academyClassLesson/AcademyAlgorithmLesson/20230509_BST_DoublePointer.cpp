#include "20230509_BST_DoublePointer.h"
#include<stdio.h>
C20230509_BinarySearchTree::S_Node** C20230509_BinarySearchTree::findNode(S_Node** ppNode, int nData)
{
    if (!*ppNode)
        return ppNode;

    if((*ppNode)->nData > nData)
		return findNode(&((*ppNode)->pLeft), nData);

	if ((*ppNode)->nData < nData)
		return findNode(&((*ppNode)->pRight), nData);
    
    return ppNode;
}

void C20230509_BinarySearchTree::printNode(S_Node* pNode)
{
	if (!pNode)
		return;

	printf("%d, ", pNode->nData);
	printNode(pNode->pLeft);
	printNode(pNode->pRight);
}

C20230509_BinarySearchTree::S_Node* C20230509_BinarySearchTree::createNode(int nData)
{
    S_Node* pNode = new S_Node{};
	pNode->nData = nData;
	pNode->pLeft = nullptr;
	pNode->pRight = nullptr;

	return pNode;
}

C20230509_BinarySearchTree::S_Node** C20230509_BinarySearchTree::findMaxNode(S_Node** ppNode)
{
	if ( !(*ppNode)->pRight )
		return ppNode;

	return findMaxNode(&((*ppNode)->pRight));
	
}

bool C20230509_BinarySearchTree::add(int nData)
{
	S_Node** ppFind = findNode(&m_pRootNode, nData);
	
	// �ߺ� �����͸� ������� �ʴ´�
	// nullptr�� �ƴ϶�� �̹� �����Ͱ� �����Ѵٴ� ���̴�.
	if (*ppFind)
		return false;

	*ppFind = createNode(nData);
	
	return true;
}

void C20230509_BinarySearchTree::print()
{
	printNode(m_pRootNode);
	printf("\n");
}

void C20230509_BinarySearchTree::erase(int nData)
{
	S_Node** ppFind = findNode(&m_pRootNode, nData);

	//����� �������� �ʴ´�.
	if (!*ppFind)
		return;

	if ((*ppFind)->pLeft && (*ppFind)->pRight)
	{
		S_Node** ppMaxNode = findMaxNode(&((*ppFind)->pLeft));
		//printf("ppMaxNode : %d\n", (*ppMaxNode)->nData);
		(*ppFind)->nData = (*ppMaxNode)->nData;
		ppFind = ppMaxNode;
	}

	// �ݵ�� �ڽ� ��尡 �ϳ��� �����Ѵ�.
	S_Node* pNodeChildOfFind = (*ppFind)->pLeft;
	if((*ppFind)->pRight)
		pNodeChildOfFind = (*ppFind)->pRight;

	delete* ppFind;
	*ppFind = pNodeChildOfFind;
}
