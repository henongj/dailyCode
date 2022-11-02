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
	/* 반례
	[["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"]]
"AAAAAAAAAAAAAAB"
	*/

};

inline void print_pair(const pair<int, int>& p)
{
	cout << p.first << " " << p.second << endl;
}


class Solution {
public:


	class Solution {
	public:

		inline bool isInside(const std::vector<std::vector<char>>& board, const pair<int, int>& position)
		{ // first : 행 second : 열
			return (0 <= position.first && position.first < board.size()) && (0 <= position.second && position.second < board[position.first].size());
		}

		// depth first search, for vector<vector<pair<int,int>>
		bool DFS(std::vector<vector<char>>& board, const pair<int, int>& position, int& len, const string& word)
		{
			if (len == word.size()) // 다 찾았으면 true
				return true;
			if (!isInside(board, position)) // 밖이면 제껴
				return false;
			if ((board[position.first][position.second] != word[len]))
				return false;

			// 현재 위치에서 word[len]과 같은 문자를 찾았다면
			board[position.first][position.second] = 0; // 방문했다고 표시
			len++;

			bool result = DFS(board, { position.first + 1, position.second }, len, word) ||
				DFS(board, { position.first - 1, position.second }, len, word) ||
				DFS(board, { position.first, position.second + 1 }, len, word) ||
				DFS(board, { position.first, position.second - 1 }, len, word);


			board[position.first][position.second] = word[len - 1]; // 방문했다고 표시한거 다시 원상복구
			len--;

			return result;

		}

		bool exist(std::vector<std::vector<char>> board, std::string word) {

			for (int row = 0; row < board.size(); row++)
			{
				for (int col = 0; col < board[row].size(); col++)
				{
					int len = 0;
					vector<vector<char>> check = board;

					if (word[0] == board[row][col] && DFS(board, pair<int, int>(row, col), len, word))
						return true;
				}
			}

			return false;

		}
	};

};

#endif
