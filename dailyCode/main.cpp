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
	input_data(N,L,map);
	int answer = 0;

	int count = 1;
	bool flag = true;
	for (int row = 0; row < map.size(); row++)
	{
		for (int col = 0; col < map[0].size(); col++)
		{
			
			// 1. 현재 위치의 높이가 다음 위치의 높이와 같다면 count++ 다음 위치로 이동
			if (map[row][col] == map[row][col + 1])
				count++;
			// 2. 현재 위치의 높이가 다음 위치의 높이보다 1 높고 count >= L 이면 count = 1 다음 위치로 이동
			if (map[row][col] == map[row][col + 1] + 1 && count >= L)
				count = 1;
			// 3. 현재 위치의 높이가 다음 위치의 높이보다 1 낮으면 count = 1 다음 위치로 이동
			// 3.1 count를 L만큼 쌓지 못하면 break
		}
	}

	
}
#endif // ___problem_14890_h___

int main(void)
{

	return 0;
}

