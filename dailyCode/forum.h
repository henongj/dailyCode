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
