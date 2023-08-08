
#ifndef ___acmicpc_1011_h___
#define ___acmicpc_1011_h___
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

namespace acmicpc_1101
{

	//https://www.acmicpc.net/problem/1011
	//Fly me to the Alpha Centauri

	using namespace std;
	void data_input(vector<int>& distance)
	{
		int len;
		cin >> len;
		for (int i = 0; i < len; i++)
		{
			int a, b;
			cin >> a >> b;
			distance.push_back(b - a);
		}
	}

	void solution()
	{
		vector<int> distance;
		data_input(distance);

		for (int i = 0; i < distance.size(); i++)
		{
			int result = 0;
			int root = sqrt(distance[i]);
			root* root == distance[i] ? result = root * 2 - 1 : result = root * 2;

			if (distance[i] > root * (root + 1))
				result = result + 1;
			cout << result << endl;
		}
	}
}

/*

 time complexity : n(O)
 time limit, it can't use

int get_leap_times(int target, vector<int>& square_list)
{
	int result = 0;
	int remain = target;
	// make lamda function to get root of target

	int root = 0;
	// target�� �������� square_list���� ã�´�
	for (int i = 1; i < square_list.size(); i++)
	{
		if (square_list[i] > target)
		{
			root = i - 1;
			break;
		}
	}

	// ��Ʈ���� �� ����
	remain -= root * root;
	result = root * 2 - 1;

	// remain�� root ���� ������ ��� ����, �� ������ result 1�� ����
	while (remain > 0)
	{

		if (remain >= root)
		{
			remain -= root;
			result++;
		}
		else
			root = root - 1;
	}
	return result;
}

void solution()
{
	vector<int> square_list;
	square_list.push_back(1);
	int max_int = 2147483647;
	for (int i = 1; i < 46341; i++)
	{
		square_list.push_back(i*i);
	}

	vector<int> distance;
	data_input(distance);

	for (int i = 0; i < distance.size(); i++)
	{
		int result = 0;
		int root = sqrt(distance[i]);
		root* root == distance[i] ? result = root * 2 - 1 : result = root * 2;

		if (distance[i] > root * (root + 1))
			result = result + 1;
		cout << result << endl;
	}
}
*/
#endif // ___acmicpc_1011_h___

