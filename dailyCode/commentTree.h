#pragma once
#include<string>
#include<vector>
class c_CommentTree
{
private:
	struct comment
	{
		int m_nId;
		int m_nParentID;
		std::string m_strText;
		
		comment* m_pLeftReply;
		comment* m_pRightComment;
	};

private:
	comment* m_pRoot;
	std::vector<comment*> m_vComments;
	int m_nIdCounter;
	void printAllCommentRecursive(comment* pComment);
public:
	enum class e_CommentType
	{
		Comment,
		Reply,
	};
	
public:
	c_CommentTree() = default;
	~c_CommentTree() = default;

	c_CommentTree(const c_CommentTree& other) = delete;
	c_CommentTree& operator=(const c_CommentTree& other) = delete;

	void init(void);
	void release(void);
	
	bool findNodeIndex(const int nTargetID, int& nResult);
	bool addReply(int nParentId, const std::string& text, e_CommentType type);
	bool addComment(const std::string& text, e_CommentType type);

	comment* getRightLeafNode(void);
	comment* getLeftMostNode(comment* pComment);
	void printComment(void);
};
