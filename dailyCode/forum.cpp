#include "forum.h"


void C_ForumSystem::init(void)
{
	m_nCommentIdCounter = 0;
	m_nReplyIdCounter = 0;

}

void C_ForumSystem::release(void)
{
	for (int i = 0; i < m_vCommentList.size(); i++)
		delete m_vCommentList[i];
	for (int i = 0; i < m_vReplyList.size(); i++)
		delete m_vReplyList[i];
}

bool C_ForumSystem::addComment(const std::string& strText, int nWriterId)
{
	if (strText.empty())
		return false;
	
	Comment* pComment = new Comment{};
	
	//pComment->m_nWriterId = nWriterId;
	pComment->m_strText = strText;
	pComment->m_vReplyId = std::vector<int>{};
	pComment->m_nCommentId = m_nCommentIdCounter;

	m_nCommentIdCounter++;
	m_vCommentList.push_back(pComment);

	return true;
}

bool C_ForumSystem::addReply(const std::string& strText, int nWriterId, int nIdReplyTarget, eCommentType eTypeToTarget)
{
	if (strText.empty())
		return false;
	
	Reply* pReply = new Reply{};

	pReply->m_nReplyId = m_nReplyIdCounter;
	//pReply->m_nWriterId = nWriterId;
	pReply->m_strText = strText;
	
	pReply->m_nParentId = nIdReplyTarget;
	pReply->m_eParentType = eTypeToTarget;

	m_nReplyIdCounter++;
	m_vReplyList.push_back(pReply);
	
	if (eTypeToTarget == eCommentType::Comment)
		m_vCommentList[nIdReplyTarget]->m_vReplyId.push_back(pReply->m_nReplyId);
	else
		m_vReplyList[nIdReplyTarget]->m_vReplyId.push_back(pReply->m_nReplyId);
	
	return true;
}

void C_ForumSystem::printAll(void)
{
	for (int i = 0; i < m_vCommentList.size(); i++)
	{
		printComment(m_vCommentList[i]);
	}
}

void C_ForumSystem::printComment(const Comment* pComment)
{
	printf("comment id : %d\ntext : %s\n天天天天天天天天天天天天天天天天天天天\n", pComment->m_nCommentId, pComment->m_strText.c_str());
	
	for(int i = 0 ; i < pComment->m_vReplyId.size(); i++)
	{
		printReply(m_vReplyList[pComment->m_vReplyId[i]]);
	}
}

void C_ForumSystem::printReply(const Reply* pReply)
{
	printf("reply id : %d, reply to : %d\n, text : %s\n天天天天天天天天天天天天天天天天天天天\n", pReply->m_nReplyId, pReply->m_nParentId, pReply->m_strText.c_str());
	
	for (int i = 0; i < pReply->m_vReplyId.size(); i++)
	{
		printReply(m_vReplyList[pReply->m_vReplyId[i]]);
	}
}


