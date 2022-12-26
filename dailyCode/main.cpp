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

			// 1. ���� ��ġ�� ���̰� ���� ��ġ�� ���̿� ���ٸ� count++
			if (gap == 0)
			{
				count++;
				// 3.1 ������ ���� ��ġ ������ ��� ��ġ
				if (flag == false && count >= L)
					reset();
			}
			// 2. �������̸鼭
			else if (gap == 1)
			{
				// ���� ���̰� ��� X
				if (count < L)
					break;
				// ��� O
				count = 1;
			}
			// 3. �������̸鼭 
			else if (gap == -1)
			{
				//�� ���������� false�� ǥ��
				if (flag)
					reset();
				// 3.2 �̹� �����Դµ�
				if (!flag)
				{
					// ���� ���̰� ��� X
					if (count < L)
						break;
					// ��� O
					count = 1;
				}
			}
			// 4. �������� 2�̻��̸� ���� ��ġ �Ұ�
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

			// 1. ���� ��ġ�� ���̰� ���� ��ġ�� ���̿� ���ٸ� count++
			if (gap == 0)
			{
				count++;
				// 3.1 ������ ���� ��ġ ������ ��� ��ġ
				if (flag == false && count >= L)
					reset();
			}
			// 2. �������̸鼭
			else if (gap == 1)
			{
				// ���� ���̰� ��� X
				if (count < L)
					break;
				// ��� O
				count = 1;
			}
			// 3. �������̸鼭 
			else if (gap == -1)
			{
				//�� ���������� false�� ǥ��
				if (flag)
					reset();
				// 3.2 �̹� �����Դµ�
				if(!flag)
				{
					// ���� ���̰� ��� X
					if (count < L)
						break;
					// ��� O
					count = 1;
				}
			}
			// 4. �������� 2�̻��̸� ���� ��ġ �Ұ�
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

