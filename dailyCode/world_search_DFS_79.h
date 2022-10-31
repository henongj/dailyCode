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
	/* ¹Ý·Ê
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

	inline bool isInside(const std::vector<std::vector<char>>& board, const pair<int, int>& position)
	{ // first : Çà second : ¿­
		return (0 <= position.first && position.first < board.size()) && (0 <= position.second && position.second < board[position.first].size());
	}

	// depth first search, for vector<vector<pair<int,int>>
	bool DFS(const std::vector<vector<char>>& board, vector<vector<char>> check, const pair<int, int>& position, int& len, const string& word)
	{

		if (len == word.length())
			return true;
		if (!isInside(board, position)) // ¹ÛÀÌ¸é
			return false;
		if (check[position.first][position.second] == 0) // ÀÌ¹Ì ¹æ¹®ÇÑ °÷ÀÌ¸é Á¦³¦
			return false;
		if (board[position.first][position.second] != word[len]) // ¾ÈÀÎµ¥ ±ÛÀÚ°¡ ´Ù¸£¸é Á¦³¦
			return false;

		// »óÇÏÁÂ¿ì Å½»öÇÒ ÁÂÇ¥.
		pair<int, int> movePos[4] = {
			{position.first - 1 , position.second + 0},
			{position.first + 1,position.second + 0},
			{position.first + 0,position.second - 1},
			{position.first + 0,position.second + 1}
		}; // »óÇÏÁÂ¿ì


		len++;
		check[position.first][position.second] = 0;

		bool flag = DFS(board, check, movePos[0], len, word) ||
			DFS(board, check, movePos[1], len, word) ||
			DFS(board, check, movePos[2], len, word) ||
			DFS(board, check, movePos[3], len, word);

		len--;
		check[position.first][position.second] = 1;

		return flag;
	}

	bool exist(std::vector<std::vector<char>> board, std::string word) {

		for (int row = 0; row < board.size(); row++)
		{
			for (int col = 0; col < board[row].size(); col++)
			{
				int len = 0;
				vector<vector<char>> check = board;
				bool flag = false;
				if (word[0] == board[row][col] && DFS(board, check, make_pair(row, col), len, word))
					return true;
			}
		}

		return false;

	}
};

#endif
