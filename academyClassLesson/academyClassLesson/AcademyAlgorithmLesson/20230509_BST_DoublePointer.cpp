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
	
	// 중복 데이터를 허용하지 않는다
	// nullptr이 아니라면 이미 데이터가 존재한다는 뜻이다.
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

	//대상이 존재하지 않는다.
	if (!*ppFind)
		return;

	if ((*ppFind)->pLeft && (*ppFind)->pRight)
	{
		S_Node** ppMaxNode = findMaxNode(&((*ppFind)->pLeft));
		//printf("ppMaxNode : %d\n", (*ppMaxNode)->nData);
		(*ppFind)->nData = (*ppMaxNode)->nData;
		ppFind = ppMaxNode;
	}

	// 반드시 자식 노드가 하나만 존재한다.
	S_Node* pNodeChildOfFind = (*ppFind)->pLeft;
	if((*ppFind)->pRight)
		pNodeChildOfFind = (*ppFind)->pRight;

	delete* ppFind;
	*ppFind = pNodeChildOfFind;
}
