
// https://leetcode.com/problems/happy-number/
//202. Happy Number
#ifndef ___Happy_Number_202_h___
#define ___Happy_Number_202_h___
#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;
class Solution {
public:
	int get_square(int n)
	{ // ������ ���Ѵ�.
		return n * n;
	}
	vector<int> get_radix(int n)
	{ // �ڸ����� ���Ѵ�.
		vector<int> v;
		while (n)
		{
			v.push_back(n % 10);
			n /= 10;
		}
		return v;
	}

	/* 
	1. �� �ڸ����� ���ؼ� ���� sum �� �����
	2. 1�� ������ true
	3. sum�� ���ݱ��� ���� sum�� �ߺ��̸� false
		4. �ߺ��� �ƴϸ� 1,2,3 �� �ݺ�
	
	*/
	bool isHappy(int n) {
		vector<int> radixes = get_radix(n);
		unordered_map <int, bool> memo;
		int sum = 0;
		while (true)
		{
			sum = 0;
			for (auto i : radixes)
			{
				sum += get_square(i);
			}
			if (sum == 1)
			{
				return true;
			}
			if (memo.find(sum) != memo.end())
			{
				return false;
			}
			memo[sum] = true;
			radixes = get_radix(sum);
		}
		return false;
	}
};

#endif // ___Happy_Number_202_h___