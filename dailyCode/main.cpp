//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>
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

#include"commentTree.h"

int main(void)
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	c_CommentTree commentTree{};
	commentTree.init();
	std::string strInput{};
	
	strInput = "this is the 0 comment";
	commentTree.addComment(strInput, c_CommentTree::e_CommentType::Comment);
	strInput = "this is the 1 comment";
	commentTree.addComment(strInput, c_CommentTree::e_CommentType::Comment);
	strInput = "this is the 2 comment";
	commentTree.addComment(strInput, c_CommentTree::e_CommentType::Comment);
	strInput = "this is the 3 comment";
	commentTree.addComment(strInput, c_CommentTree::e_CommentType::Comment);

	strInput = "this is the 4 comment, 1 Reply";
	commentTree.addReply(1, strInput, c_CommentTree::e_CommentType::Reply);
	strInput = "this is the 5 comment, 2 Reply";
	commentTree.addReply(1, strInput, c_CommentTree::e_CommentType::Reply);
	strInput = "this is the 6 comment, 3 Reply";
	commentTree.addReply(4, strInput, c_CommentTree::e_CommentType::Reply);
	strInput = "this is the 7 comment, 4 Reply";
	commentTree.addReply(5, strInput, c_CommentTree::e_CommentType::Reply);
	strInput = "this is the 8 comment, 5 Reply";
	commentTree.addReply(4, strInput, c_CommentTree::e_CommentType::Reply);

	commentTree.printComment();

	commentTree.release();
	return 0;
}
