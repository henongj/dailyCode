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
	auto reset = [&count, &flag]() -> void { count = 1; flag = true; };
	
	for (int row = 0; row < map.size(); row++)
	{
		int len = map[row].size();
		for (int col = 0; col < len - 1; col++)
		{
			int gap = diff(map[row][col], map[row][col + 1]);

			// 1. 현재 위치의 높이가 다음 위치의 높이와 같다면 count++
			if (gap == 0)
			{
				count++;
				// 3.1 내리막 경사로 설치 가능한 경우 설치
				if (flag == false && count >= L)
					reset();
			}
			// 2. 오르막이면서
			else if (gap == 1)
			{
				// 경사로 길이가 충분 X
				if (count < L)
					break;
				// 충분 O
				count = 1;
			}
			// 3. 내리막이면서 
			else if (gap == -1)
			{
				//막 내려왔으면 false로 표시
				if (flag)
					reset();
				// 3.2 이미 내려왔는데
				if (!flag)
				{
					// 경사로 길이가 충분 X
					if (count < L)
						break;
					// 충분 O
					count = 1;
				}
			}
			// 4. 높이차가 2이상이면 경사로 설치 불가
			else
				break;

			//
			if (col == len - 2)
			{
				if ((flag == false && count >= L) || flag == true)
				{
					reset();
					answer++;
				}
			}
		}
	}

	reset();
	for (int col = 0; col < map.size(); col++)
	{
		int len = map[col].size();
		for (int row = 0; row < len - 1; row++)
		{
			int gap = diff(map[row][col], map[row + 1][col]);

			// 1. 현재 위치의 높이가 다음 위치의 높이와 같다면 count++
			if (gap == 0)
			{
				count++;
				// 3.1 내리막 경사로 설치 가능한 경우 설치
				if (flag == false && count >= L)
					reset();
			}
			// 2. 오르막이면서
			else if (gap == 1)
			{
				// 경사로 길이가 충분 X
				if (count < L)
					break;
				// 충분 O
				count = 1;
			}
			// 3. 내리막이면서 
			else if (gap == -1)
			{
				//막 내려왔으면 false로 표시
				if (flag)
					reset();
				// 3.2 이미 내려왔는데
				if(!flag)
				{
					// 경사로 길이가 충분 X
					if (count < L)
						break;
					// 충분 O
					count = 1;
				}
			}
			// 4. 높이차가 2이상이면 경사로 설치 불가
			else
				break;

			//
			if (row == len - 2)
			{
				if ((flag == false && count >= L) || flag == true)
				{
					reset();
					answer++;
				}
			}
		}
	}

	cout << answer << endl;
}
#endif // ___problem_14890_h___

int main(void)
{
	solution();
	return 0;
}

