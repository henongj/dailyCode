#ifndef ___word_search_79_h___
#define ___word_search_79_h___
#include<utility>
#include<vector>
#include<iostream>
#include<string>
#include<queue>
using namespace std;

struct testCase
{
	vector<vector<char>> testCase1 = vector<vector<char>>{
	{'A','B','C','E'},
	{'S','F','C','S'},
	{'A','D','E','E'}
	};
	string testCaseWord1 = "AACCED";
	
	vector<vector<char>> testCase3 = vector<vector<char>>{
			{'A','B','C','E'},
			{'S','F','C','S'},
			{'A','D','E','E'}
	};
	string testCaseWord3 = "ABCB"; // output : false

	
};

class Solution {
public:
	
	inline bool isInside(const std::vector<std::vector<char>>& board, const pair<int, int>& position)
	{
		return (0 <= position.second && position.second < board.size()) && (0 <= position.first && position.first < board[0].size());
	}

	int BFS(const std::vector<std::vector<char>>& board, const string& word, const pair<int,int>& startPos)
	{
		vector<vector<char>> checked = board;
		int counter = 0;
		queue<pair<int, int>> q;
		pair<int, int> movePos[4] = { {0,-1},{0,1},{-1,0},{1,0} };
		// 시작 좌표를 집어넣는다
		q.push(startPos);
		checked[startPos.second][startPos.first] = 0;
		auto back = q.back();
		while (!q.empty())
		{ // queue가 빌때까지 BFS
			back = q.back();
			
			//올바른 문자를 pop;
			q.pop();
			counter++;
			bool counterFlag = false;
			for (int i = 0; i < 4; i++)
			{// 근처 상하좌우 안 && word와 일치하는 글자 && 첫 방문
				pair<int,int> near = pair<int,int>(back.first + movePos[i].first , back.second + movePos[i].second);
				if (isInside(board, near) && word[counter] == board[near.second][near.first] && checked[near.second][near.first] != 0)
				{
					counterFlag = true;
					q.push(near);
				}

			}
			if (counterFlag)
				counter++;
		}
		
		return counter;
		
	}

    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        
		pair<int, int> position = { 0,0 };
		// move (xpos, ypos) {up,down,left,right}
		
		for (int i = 0; i < board.size(); i++)
		{//y pos
			for (int j = 0; j < board[i].size(); j++)
			{// x pos
				
			}
		}

		

		
    }
};

#endif
