#include "forum.h"


void C_ForumSystem::init(void)
{
	m_nCommentIdCounter = 1;
	m_pCommentRoot = new Comment{};
	m_vCommentList.push_back(m_pCommentRoot);

}

bool C_ForumSystem::addComment(const std::string& strText, int nWriterId)
{
	if (strText.empty())
		return false;
	
	Comment* pComment = new Comment{};
	
	pComment->m_nWriterId = nWriterId;
	pComment->m_strText = strText;
	pComment->m_pReplyId = nullptr;
	pComment->m_nCommentId = m_nCommentIdCounter;

	m_nCommentIdCounter++;
	m_vCommentList.push_back(pComment);

	return true;
}

