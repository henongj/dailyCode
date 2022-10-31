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
	{ // first : �� second : ��
		return (0 <= position.first && position.first < board.size()) && (0 <= position.second && position.second < board[position.first].size());
	}

	// depth first search, for vector<vector<pair<int,int>>
	bool DFS(const std::vector<vector<char>>& board, vector<vector<char>>& check, const pair<int,int>& position, int& len, const string& word, bool& flag)
	{
		// ��ǥ�� �������� �����¿츦 Ž���Ѵ�.
		pair<int, int> movePos[4] = { {position.first - 1 , position.second + 0},{position.first + 1,position.second + 0},{position.first + 0,position.second - 1},{position.first + 0,position.second + 1} }; // �����¿�
		
		for (int idx = 0; idx < 4 ; idx++)
		{
			bool f = false;
			if (isInside(board, movePos[idx]) && check[movePos[idx].first][movePos[idx].second] != 0 && word[len] == board[movePos[idx].first][movePos[idx].second]) // �� && �湮 X && word[len] �� ��ġ
			{
				f = true;
				print_pair(movePos[idx]);
				++len;
				check[movePos[idx].first][movePos[idx].second] = 0; // �湮
				if (len < word.length())
					DFS(board, check, movePos[idx], len, word, flag);
				else if (len == word.length())
					return true;
				else
					return flag;
			}
			else
			{
				if (f)
				{
					--len;
					check[movePos[idx].first][movePos[idx].second] = 1; // �湮 ���
				}
			}
		}
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
