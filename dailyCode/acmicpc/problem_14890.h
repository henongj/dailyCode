
//https://www.acmicpc.net/problem/14890
//경사로
#ifndef ___problem_14890_h___
#define ___problem_14890_h___
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
using namespace std;
namespace acmicpc_14890
{

	void input_data(int& N, int& L, vector<vector<int>>& map)
	{
		cin >> N >> L;
		map.resize(N, vector<int>(N, 0));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
			}
		}
	}

	void solution(void)
	{
		int N, L;
		vector<vector<int>> map;
		input_data(N, L, map);
		int answer = 0;
		int count = 1;
		bool flag = true;

		// make lamda function to get diff value, return int 
		auto diff = [](int a, int b) -> int { return b - a; };
		// make lamda function reset count and flag
		auto reset = [&count, &flag]() -> void { count = 1; };

		for (int row = 0; row < N; row++)
		{
			int len = map[row].size();
			reset();
			for (int col = 0; col < len - 1; col++)
			{
				int difference = diff(map[row][col], map[row][col + 1]);

				if (difference == 0)
					count++;
				else if (difference == 1) // 오르막
				{
					if (count < L)
					{
						reset();
						break;
					}
					else
						count = 1;
				}
				else if (difference == -1) // 내리막
				{
					if (count < 0)
					{
						reset();
						break;
					}
					count = -L + 1;
				}
				else
				{
					reset();
					break;
				}

				if (col == len - 2 && count >= 0)
					answer++;
			}
		}

		for (int col = 0; col < N; col++)
		{
			reset();
			int len = map[col].size();
			for (int row = 0; row < len - 1; row++)
			{
				int difference = diff(map[row][col], map[row + 1][col]);

				if (difference == 0)
					count++;
				else if (difference == 1) // 오르막
				{
					if (count < L)
					{
						reset();
						break;
					}
					else
						count = 1;
				}
				else if (difference == -1) // 내리막
				{
					if (count < 0)
					{
						reset();
						break;
					}
					count = -L + 1;
				}
				else
				{
					reset();
					break;
				}

				if (row == len - 2 && count >= 0)
					answer++;
			}
		}

		cout << answer << endl;
	}
#endif // ___problem_14890_h___

	/*
	int main(void)
	{
		solution();
		return 0;
	}
	*/
}