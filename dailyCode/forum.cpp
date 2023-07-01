#include "forum.h"

void C_ForumSystem::init(void)
{
	// root is empty 
	m_pRoot = new Comment{};

	m_vCommentList.reserve(10);
	m_vReplyList.reserve(10);

	m_nCommentCounter = 1;
	m_nReplyCounter = 1;
	
}

void C_ForumSystem::release(void)
{
	for (int i = 0; i < m_vCommentList.size(); ++i)
		delete m_vCommentList[i];

	for (int i = 0; i < m_vReplyList.size(); ++i)
		delete m_vReplyList[i];

	m_vCommentList.clear();
	m_vReplyList.clear();

	delete m_pRoot;
	m_pRoot = nullptr;
}
