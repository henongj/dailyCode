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
//����
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
			
			// 1. ���� ��ġ�� ���̰� ���� ��ġ�� ���̿� ���ٸ� count++ ���� ��ġ�� �̵�
			if (map[row][col] == map[row][col + 1])
				count++;
			// 2. ���� ��ġ�� ���̰� ���� ��ġ�� ���̺��� 1 ���� count >= L �̸� count = 1 ���� ��ġ�� �̵�
			if (map[row][col] == map[row][col + 1] + 1 && count >= L)
				count = 1;
			// 3. ���� ��ġ�� ���̰� ���� ��ġ�� ���̺��� 1 ������ count = 1 ���� ��ġ�� �̵�
			// 3.1 count�� L��ŭ ���� ���ϸ� break
		}
	}

	
}
#endif // ___problem_14890_h___

int main(void)
{

	return 0;
}

