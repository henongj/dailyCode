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
	string testCaseWord1 = "ABCCED";
	string testCaseWord2 = "SEE";
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
	{ // first : 행 second : 열
		return (0 <= position.first && position.first < board.size()) && (0 <= position.second && position.second < board[ position.first ].size());
	}

	int BFS(const std::vector<std::vector<char>>& board, const string& word, const pair<int,int>& startPos)
	{
		vector<vector<char>> visited = board;
		int counter = 0;
		queue<pair<int, int>> q;
		pair<int, int> movePos[4] = { {-1,0},{1,0},{0,-1},{0,1} }; // 상하좌우 행렬
		
		// 시작 좌표를 집어넣는다
		q.push(startPos);
		++counter;
		
		visited[startPos.first][startPos.second] = 0;
		auto back = q.back();

		while (!q.empty())
		{ // queue가 빌때까지 BFS
			back = q.back();
			
			//올바른 문자를 pop;
			q.pop();

			bool counterFlag = false;
			for (int i = 0; i < 4; i++)
			{// 근처 상하좌우 (안 && 첫 방문 word와 && 일치하는 글자)
				pair<int,int> near = pair<int,int>(back.first + movePos[i].first , back.second + movePos[i].second);
				if (isInside(board, near) && visited[near.first][near.second] && word[counter] == board[near.first][near.second])
				{
					counterFlag = true;
					q.push(near);
					visited[near.first][near.second] = 0;
				}

			}
			if (counterFlag)
			{
				++counter;
				if (counter == word.length())
					break;
			}
		}
		
		return counter;
		
	}

    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        
		pair<int, int> position = { 0,0 };
		// move (행(first), 열(second)) {up,down,left,right}
		
		//iterate 2d vector
		

		for (int row = 0; row < board.size(); row++)
		{//y pos
			
			for (int col = 0; col < board[row].size(); col++)
			{// x pos
//				cout << row << ", " << col << "\n";
				if (board[row][col] == word[0])
				{
					
					int result = BFS( board, word, pair<int, int>(row, col));
					if (result == word.length())
						return true;
					
				}
			}
		}
		return false;
		

		
    }
};

#endif
