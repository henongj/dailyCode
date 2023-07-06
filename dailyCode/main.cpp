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
	
	forumSys.addComment("1�� ���!", 0);
	forumSys.addComment("2�� ���!", 1);
	forumSys.addComment("3�� ���!", 2);
	forumSys.addComment("4�� ���!", 0);
	forumSys.addReply("1�� ����� 1�� ���", 3, 0, C_ForumSystem::eCommentType::Comment);
	forumSys.addReply("1�� ����� 2�� ���", 4, 0, C_ForumSystem::eCommentType::Comment);
	forumSys.addReply("1�� ����� 1�� ����� 1�����", 4, 0, C_ForumSystem::eCommentType::Reply);
	forumSys.addReply("1�� ����� 1�� ����� 2�����", 4, 2, C_ForumSystem::eCommentType::Reply);

	forumSys.printAll();

	forumSys.release();
	
	return 0;
}
