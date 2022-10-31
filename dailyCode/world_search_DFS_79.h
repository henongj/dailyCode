#ifndef ___word_search_DFS_79_h___
#define ___word_search_DFS_79_h___
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

	vector<vector<char>> testCase4 = vector<vector<char>>{
		{'C', 'A', 'A'},
		{'A', 'A', 'A'},
		{'B', 'C', 'D'}
	};
	string testCaseWord4 = "AAB";

	/* [["A", "B", "C", "E"], ["S", "F", "E", "S"], ["A", "D", "E", "E"]]
		"ABCESEEEFS"*/
	vector<vector<char>> testCase5 = vector<vector<char>>{
		{'A', 'B' ,'C' ,'E' },
		{'S' ,'F' ,'E' ,'S' },
		{'A' ,'D' ,'E' ,'E' }
	};
	string testCaseWord5 = "ABCESEEEFS";


};

inline void print_pair(const pair<int, int>& p)
{
	cout << p.first << " " << p.second << endl;
}

class Solution {
public:

	inline bool isInside(const std::vector<std::vector<char>>& board, const pair<int, int>& position)
	{ // first : 행 second : 열
		return (0 <= position.first && position.first < board.size()) && (0 <= position.second && position.second < board[position.first].size());
	}

	// depth first search, for vector<vector<pair<int,int>>
	bool DFS(const std::vector<vector<char>>& board, vector<vector<char>> check, const pair<int,int>& position, int& len, const string& word, bool& flag)
	{
		// 상하좌우 탐색할 좌표.
		pair<int, int> movePos[4] = { {position.first - 1 , position.second + 0},{position.first + 1,position.second + 0},{position.first + 0,position.second - 1},{position.first + 0,position.second + 1} }; // 상하좌우
		
		if (board[position.first][position.second] == word[len])
		{ // 탐색 대상이 찾는 글자다
			len++;
			check[position.first][position.second] = 0;
			if (len == word.size())
				flag = true;
		}
		else
		{// 글자 아니면 돌아가야죠
			return len == word.length() ? true : flag;
		}
		
		
		for (int idx = 0; idx < 4 ; idx++)
		{
			if (!isInside(board, movePos[idx])) // 밖이면 제낌
				continue;
			if( check[movePos[idx].first][movePos[idx].second] == 0 ) // 이미 방문한 곳이면 제낌
				continue;
			
			if (len < word.length()) //  찾을 글자가 더 있으면
			{
				flag = DFS(board, check, movePos[idx], len, word, flag);
				if (flag) return flag;
			}
			else if (len == word.length()) // 다 찾았으면
				return true;
			else
				return flag;
		}
		
		len--;
		check[position.first][position.second] = 1;

		return flag;
	}

	bool exist(std::vector<std::vector<char>> board, std::string word) {
		
		vector<vector<char>> check = board;
		bool flag = false;

		for (int row = 0; row < board.size(); row++)
		{
			for (int col = 0; col < board[row].size() ; col++)
			{
				if (board[row][col] == word[0])
				{
					int len = 0;
					if (DFS(board, check, make_pair(row, col), len,word,flag))
					{
						return true;
					}
				}
			}
		}
		return false;
		
	}
};

#endif
