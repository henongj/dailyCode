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
#include<cmath>
using namespace std;

//https://www.acmicpc.net/problem/1406
//¿¡µðÅÍ

void acmicpc1406(void)
{
	string str;
	cin >> str;
	int n;
	cin >> n;
	stack<char> left, right;
	for (int i = 0; i < str.size(); i++)
		left.push(str[i]);
	while (n--)
	{
		char c;
		cin >> c;
		if (c == 'L')
		{
			if (!left.empty())
			{
				right.push(left.top());
				left.pop();
			}
		}
		else if (c == 'D')
		{
			if (!right.empty())
			{
				left.push(right.top());
				right.pop();
			}
		}
		else if (c == 'B')
		{
			if (!left.empty())
				left.pop();
		}
		else if (c == 'P')
		{
			char ch;
			cin >> ch;
			left.push(ch);
		}
	}
	while (!left.empty())
	{
		right.push(left.top());
		left.pop();
	}
	while (!right.empty())
	{
		cout << right.top();
		right.pop();
	}
}