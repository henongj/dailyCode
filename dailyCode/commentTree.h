#pragma once
#include<string>
#include<vector>

class c_CommentTree
{
private:
	struct reply;
	struct comment;
	
	struct comment
	{
		int m_nId;
		int m_nParentID;
		std::string m_strText;
		
		reply* m_pLeftReply;
		comment* m_pRightComment;
	};
	struct reply
	{
		int m_nId;
		int m_nParentID;
		std::string m_strText;

		reply* m_pLeftReply;
		reply* m_pRightParentReply;
	};


private:
	comment* m_pRoot;
	std::vector<comment*> m_vComments;
	int m_nIdCounter;
	void printAllCommentRecursive(comment* pComment);
	void printReplyRecursive(reply* pReply);
	
public:
	c_CommentTree() = default;
	~c_CommentTree() = default;

	c_CommentTree(const c_CommentTree& other) = delete;
	c_CommentTree& operator=(const c_CommentTree& other) = delete;

	void init(void);
	void release(void);
	
	bool findNodeIndex(const int nTargetID, int& nResult);
	bool addReply(int nParentId, const std::string& text);
	bool addComment(const std::string& text);

	comment* getRightMostComment(void);
	reply* getLeftMostReply(reply* pReply);
	reply* getRightMostParentReply(reply* pReply);
	void printComment(void);
	
};
