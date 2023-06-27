#include "commentTree.h"

void c_CommentTree::init(void)
{
	m_pRoot = new comment{};
	m_vComments.reserve(15);
	m_nIdCounter = 0;
}

void c_CommentTree::release(void)
{
	size_t nSize{};

	nSize = m_vComments.size();
	for (int i = 0; i < nSize; i++)
		delete m_vComments[i];

	m_pRoot = nullptr;
}

bool c_CommentTree::findNodeIndex(const int nTargetID, int& nResultIndex)
{
	comment* pFinder = m_pRoot;
	size_t nSize{};

	nSize = m_vComments.size();
	for (int i = 0; i < nSize; i++)
	{
		if (m_vComments[i]->m_nId == nTargetID)
		{
			nResultIndex = i;
			return true;
		}
	}

	return false;
}

bool c_CommentTree::addReply(int nParentId, const std::string& text, e_CommentType type)
{
	size_t nCommmentLength = m_vComments.size();

	if (nParentId > nCommmentLength)
		return false;

	comment* cComment{};
	cComment = new comment{};

	cComment->m_nId = m_nIdCounter;

	cComment->m_pLeftReply = nullptr;
	cComment->m_pRightComment = nullptr;
	cComment->m_strText = text;

	m_nIdCounter++;
	m_vComments.push_back(cComment);

	cComment->m_nParentID = nParentId;
	getLeftMostNode(m_vComments[nParentId])->m_pLeftReply = cComment;

	return true;
}

bool c_CommentTree::addComment(const std::string& text, e_CommentType type)
{
	comment* cComment{};
	cComment = new comment{};

	cComment->m_nId = m_nIdCounter;

	cComment->m_pLeftReply = nullptr;
	cComment->m_pRightComment = nullptr;
	cComment->m_strText = text;

	cComment->m_nParentID = cComment->m_nId = m_nIdCounter;
	m_nIdCounter++;
	m_vComments.push_back(cComment);

	comment* cRightLeafNode = getRightLeafNode();
	cRightLeafNode->m_pRightComment = cComment;

	return true;
}

c_CommentTree::comment* c_CommentTree::getRightLeafNode(void)
{
	comment* pFinder = m_pRoot;
	if (pFinder == nullptr)
		return m_pRoot;

	while (pFinder->m_pRightComment != nullptr)
		pFinder = pFinder->m_pRightComment;

	return pFinder;
}

c_CommentTree::comment* c_CommentTree::getLeftMostNode(comment* pComment)
{
	comment* pFinder = pComment;
	while (pFinder->m_pLeftReply != nullptr)
		pFinder = pFinder->m_pLeftReply;

	return pFinder;
}

void c_CommentTree::printComment()
{
	printAllCommentRecursive(m_pRoot->m_pRightComment);
}

void c_CommentTree::printAllCommentRecursive(comment* pComment)
{
	if (pComment == nullptr)
		return;

	printf("아이디 : %d ", pComment->m_nId);
	if (pComment->m_nParentID != pComment->m_nId)
		printf(" 답글 대상 : %d ", pComment->m_nParentID);
	printf("\n%s\n", pComment->m_strText.c_str());

	printAllCommentRecursive(pComment->m_pLeftReply);
	printAllCommentRecursive(pComment->m_pRightComment);
	
}
