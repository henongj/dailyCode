#include "forum.h"

bool C_ForumSystem::addComment(int nWriterId, const std::string& strText)
{
	if (!strText.empty())
		return false;

	Comment* pComment = new Comment{};

	pComment->m_nWriterId = nWriterId;
	pComment->m_nCommentId = m_nCommentId;
	pComment->m_strText = strText;
	
	m_nCommentId++;
	m_listComment.push_back(pComment);

	return true;
}

bool C_ForumSystem::addReply(int nWriterId, int nCommentId, const std::string& strText)
{
	if (!strText.empty())
		return false;

	Reply* pReply = new Reply{};

	pReply->m_nReplyId = m_nCommentId;
	pReply->m_nCommentId = nCommentId;
	pReply->m_nWriterId = nWriterId;
	pReply->m_strText = strText;

	std::list<Comment*>::iterator iterList = m_listComment.begin();

	while (iterList != m_listComment.end())
	{
		if ((*iterList)->m_nCommentId == nCommentId)
			break;
	}

	(*iterList)->m_vReplyList.push_back(pReply);
	

	return true;
}
