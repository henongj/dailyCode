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
	/* �ݷ�
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
		{ // first : �� second : ��
			return (0 <= position.first && position.first < board.size()) && (0 <= position.second && position.second < board[position.first].size());
		}

		// depth first search, for vector<vector<pair<int,int>>
		bool DFS(std::vector<vector<char>>& board, const pair<int, int>& position, int& len, const string& word)
		{
			if (len == word.size()) // �� ã������ true
				return true;
			if (!isInside(board, position)) // ���̸� ����
				return false;
			if ((board[position.first][position.second] != word[len]))
				return false;

			// ���� ��ġ���� word[len]�� ���� ���ڸ� ã�Ҵٸ�
			board[position.first][position.second] = 0; // �湮�ߴٰ� ǥ��
			len++;

			bool result = DFS(board, { position.first + 1, position.second }, len, word) ||
				DFS(board, { position.first - 1, position.second }, len, word) ||
				DFS(board, { position.first, position.second + 1 }, len, word) ||
				DFS(board, { position.first, position.second - 1 }, len, word);


			board[position.first][position.second] = word[len - 1]; // �湮�ߴٰ� ǥ���Ѱ� �ٽ� ���󺹱�
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
