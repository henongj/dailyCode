
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
	{ // 제곱을 구한다.
		return n * n;
	}
	vector<int> get_radix(int n)
	{ // 자릿수를 구한다.
		vector<int> v;
		while (n)
		{
			v.push_back(n % 10);
			n /= 10;
		}
		return v;
	}

	/* 
	1. 각 자릿수를 구해서 더한 sum 을 만든다
	2. 1이 나오면 true
	3. sum이 지금까지 나온 sum중 중복이면 false
		4. 중복이 아니면 1,2,3 를 반복
	
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