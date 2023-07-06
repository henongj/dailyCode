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

bool C_ForumSystem::addReply(const std::string& strText, int nWriterId, int nCommentId, eCommentType eType)
{
	if (strText.empty())
		return false;
	
	Reply* pReply = new Reply{};

	pReply->m_nReplyId = m_nReplyIdCounter;
	pReply->m_nWriterId = nWriterId;
	pReply->m_strText = strText;
	//pReply->m_pReplyToReplyId = new int{};
	//*pReply->m_pReplyToReplyId = nCommentId;
	pReply->m_eParentType = eType;

	m_nReplyIdCounter++;
	
	Comment* pCommentTarget{};
	Reply* pReplyTarget{};
	//if (eType == C_ForumSystem::eCommentType::Comment)
	//{
	//	pCommentTarget = m_vCommentList[nCommentId];
	//	pCommentTarget->m_pReplyId = new int{};
	//	*pCommentTarget->m_pReplyId = pReply->m_nReplyId;
	//}
	//else
	//{
	//	pReplyTarget = m_vReplyList[nCommentId];
	//	pReplyTarget->m_pReplyToReplyId = new int{};
	//	*pReplyTarget->m_pReplyToReplyId = pReply->m_nReplyId;
	//}
	
	return true;
}


