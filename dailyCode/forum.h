#pragma once

#include<string>
#include<list>

class C_ForumSystem
{
	struct Comment;
	struct Reply;
private:
	
	struct Comment
	{
		int m_nId;
		std::string m_strText;
		
		std::list<Reply*> m_vReplyList;
	};
	struct Reply
	{
		int m_nId;
		int m_nParentId;
		std::string m_strText;
		
	};

private:
	int m_nCommentCounter;
	int m_nReplyCounter;

	std::list<Comment*> m_vCommentList;

private:
	

public:
	C_ForumSystem() = default;
	~C_ForumSystem() = default;

	C_ForumSystem(const C_ForumSystem& forumSys) = delete;
	C_ForumSystem& operator=(const C_ForumSystem& forumSys) = delete;

public:
	void init(void);
	void release(void);

};
