#pragma once

#include<string>
#include<set>
#include<vector>

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
		
		int* m_pReplyId;
	};
	struct Reply
	{
		int m_nReplyId;
		int m_nWriterId;
	
		std::string m_strText;
		
		int* m_pReplyNext;
		int* m_pReplyToReplyId;
	};
	
private:
	int m_nCommentIdCounter;
	int m_nReplyIdCounter;
	Comment* m_pCommentRoot;
	
	std::vector<Comment*> m_vCommentList;
	std::vector<Reply*> m_vReplyList;
public:
	C_ForumSystem() = default;
	~C_ForumSystem() = default;

	C_ForumSystem(const C_ForumSystem& forumSys) = delete;
	C_ForumSystem& operator=(const C_ForumSystem& forumSys) = delete;

public:
	void init(void);
	
	bool addComment(const std::string& strText, int nWriterId);
	bool addReply(const std::string& strText, int nWriterId, int nCommentId);
};
