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

bool c_CommentTree::addReply(int nParentId, const std::string& text)
{
	if (m_vComments.empty() || m_vComments.size() < nParentId || m_vComments[nParentId] == nullptr)
		return false;

	reply* pReply{};
	comment* pComment{};
	pReply = new reply{};
	pComment = m_vComments[nParentId];

	pReply->m_nId = m_nIdCounter;
	pReply->m_nParentID = nParentId;
	pReply->m_pLeftReply = nullptr;
	pReply->m_pRightParentReply = nullptr;
	pReply->m_strText = text;

	if (pComment->m_pLeftReply)
		getRightMostParentReply(pComment->m_pLeftReply)->m_pRightParentReply = pReply;
	else
		pComment->m_pLeftReply = pReply;

	return true;
}

bool c_CommentTree::addComment(const std::string& text)
{
	comment* pComment{};

	pComment = new comment{};

	pComment->m_nId = m_nIdCounter;
	pComment->m_nParentID = pComment->m_nId;
	pComment->m_pLeftReply = nullptr;
	pComment->m_pRightComment = nullptr;
	pComment->m_strText = text;

	comment* pLastComment = getRightMostComment();
	pLastComment->m_pRightComment = pComment;
	m_vComments.push_back(pComment);

	return true;
}

c_CommentTree::comment* c_CommentTree::getRightMostComment(void)
{
	comment* pFinder = m_pRoot;

	while (pFinder->m_pRightComment != nullptr)
		pFinder = pFinder->m_pRightComment;

	return pFinder;
}

c_CommentTree::reply* c_CommentTree::getLeftMostReply(reply* pReply)
{
	reply* pFinder = pReply;

	while (pFinder->m_pLeftReply != nullptr)
		pFinder = pFinder->m_pLeftReply;

	return pFinder;
}

c_CommentTree::reply* c_CommentTree::getRightMostParentReply(reply* pReply)
{
	reply* pFinder = pReply;

	while (pFinder->m_pRightParentReply != nullptr)
		pFinder = pFinder->m_pRightParentReply;
	
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
	printf("\n%s\n", pComment->m_strText.c_str());

	printReplyRecursive(pComment->m_pLeftReply);
	printAllCommentRecursive(pComment->m_pRightComment);
}

void c_CommentTree::printReplyRecursive(reply* pReply)
{
	if (pReply == nullptr)
		return;

	printf(" ㄴ 아이디 : %d ", pReply->m_nId);
	printf(" 답글 대상 : %d ", pReply->m_nParentID);
	printf("\n   %s\n", pReply->m_strText.c_str());

	printReplyRecursive(pReply->m_pLeftReply);
	printReplyRecursive(pReply->m_pRightParentReply);
}
