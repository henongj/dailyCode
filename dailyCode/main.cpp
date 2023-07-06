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
