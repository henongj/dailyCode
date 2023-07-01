#pragma once

#include<string>
#include<set>
#include<list>

class C_ForumSystem
{
	struct Comment;
	struct Reply;
private:
	
	struct Comment
	{
		int m_nCommentId;
		int m_nWriterId;
		
		std::string m_strText;
		
		std::list<Reply*> m_vReplyList;
	};
	struct Reply
	{
		int m_nReplyId;
		int m_nWriterId;
		int m_nCommentId;
		std::string m_strText;
		
		std::list<Reply*> m_vReplyList;
	};
	
private:
	int m_nCommentId;
	int m_nReplyId;
	std::list<Comment*> m_listComment;
	
public:
	C_ForumSystem() = default;
	~C_ForumSystem() = default;

	C_ForumSystem(const C_ForumSystem& forumSys) = delete;
	C_ForumSystem& operator=(const C_ForumSystem& forumSys) = delete;

public:
	bool addComment(int nWriterId, const std::string& strText);
	bool addReply(int nWriterId, int nCommentId, const std::string& strText);

};
