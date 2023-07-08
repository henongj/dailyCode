#pragma once

#include<string>
#include<set>
#include<vector>

class C_ForumSystem
{
	struct Comment;
	struct Reply;
public:
	enum class eCommentType
	{
		Comment,
		Reply
	};
private:
	struct Comment
	{
		int m_nCommentId;
		//int m_nWriterId;

		std::string m_strText;

		std::vector<int> m_vReplyId;
	};
	struct Reply
	{
		int m_nReplyId;
		//int m_nWriterId;

		std::string m_strText;

		int m_nParentId;
		eCommentType m_eParentType;

		std::vector<int> m_vReplyId;
	};


private:
	int m_nCommentIdCounter;
	int m_nReplyIdCounter;

	std::vector<Comment*> m_vCommentList;
	std::vector<Reply*> m_vReplyList;
public:
	C_ForumSystem() = default;
	~C_ForumSystem() = default;

	C_ForumSystem(const C_ForumSystem& forumSys) = delete;
	C_ForumSystem& operator=(const C_ForumSystem& forumSys) = delete;

public:
	void init(void);
	void release(void);

	bool addComment(const std::string& strText, int nWriterId);
	bool addReply(const std::string& strText, int nWriterId, int nIdReplyTarget, eCommentType eTypeToTarget);

	void printAll(void);
	void printComment(const Comment* pComment);
	void printReply(const Reply* pReply);
};


/*
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include<algorithm>
#include<iostream>
#include<map>
#include<queue>
#include<string>
#include<unordered_map>
#include<utility>
#include<vector>
#include<sstream>
#include<stack>
#include<cmath>
#include<set>

#include"forum.h"

int main(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	C_ForumSystem forumSys{};

	forumSys.init();

	forumSys.addComment("1¹ø ´ñ±Û!", 0);
	forumSys.addComment("2¹ø ´ñ±Û!", 1);
	forumSys.addComment("3¹ø ´ñ±Û!", 2);
	forumSys.addComment("4¹ø ´ñ±Û!", 0);
	forumSys.addReply("1¹ø ´ñ±ÛÀÇ 1¹ø ´ä±Û", 3, 0, C_ForumSystem::eCommentType::Comment);
	forumSys.addReply("1¹ø ´ñ±ÛÀÇ 2¹ø ´ä±Û", 4, 0, C_ForumSystem::eCommentType::Comment);
	forumSys.addReply("1¹ø ´ñ±ÛÀÇ 1¹ø ´ä±ÛÀÇ 1¹ø´ä±Û", 4, 0, C_ForumSystem::eCommentType::Reply);
	forumSys.addReply("1¹ø ´ñ±ÛÀÇ 1¹ø ´ä±ÛÀÇ 2¹ø´ä±Û", 4, 2, C_ForumSystem::eCommentType::Reply);

	forumSys.printAll();

	forumSys.release();

	return 0;
}

*/