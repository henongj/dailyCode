
#ifndef ___Detect_Capital_520_h___
#define ___Detect_Capital_520_h___
//https://leetcode.com/problems/detect-capital/description/
//520. Detect Capital
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

class Solution {
public:
	bool detectCapitalUse(string word) {

		int count = 0;
		int len = word.length();
		bool capital = false;

		if (len == 1)
			return true;

		// ù ���ڰ� �빮���ΰ�?
		if (word[0] <= 'Z')
			capital = true;

		for (int i = 0; i < len; i++)
			(char)word[i] < 'a' ? count++ : count--;

		cout << count << endl;

		// 1 ��� �빮�ڰų�
		if (count == len)
			return true;
		// 2 ��� �ҹ��ڰų�
		if (count == len * -1)
			return true;
		// 3 ù���ڸ� �빮��, �������� �ҹ���
		if (count == len * -1 + 2 && capital == true)
			return true;

		return false;
	}
};
#endif // ___Detect_Capital_520_h___
