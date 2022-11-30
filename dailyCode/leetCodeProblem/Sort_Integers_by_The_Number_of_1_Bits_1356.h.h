
//https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/?envType=study-plan&id=programming-skills-i
// 1356. Sort Integers by The Number of 1 Bits
#ifndef ___Sort_Integers_by_The_Number_of_1_Bits_1356_h___
#define ___Sort_Integers_by_The_Number_of_1_Bits_1356_h___
//make function how many '1'bits on int, use bit operator 
#include<algorithm>
#include<iostream>
#include<map>
#include<queue>
#include<string>
#include<unordered_map>
#include<utility>
#include<vector>
#include<sstream>
using namespace std;
int hammingWeight(int n) {
	int count = 0;
	while (n != 0) {
		if (n & 1) {
			count++;
		}
		n = n >> 1;
	}
	return count;
}
bool compare_by_bits(const int n1, const int n2)
{
	int n1_bits = hammingWeight(n1);
	int n2_bits = hammingWeight(n2);
	if (n1_bits < n2_bits)
		return n1_bits < n2_bits;
	if (n1_bits == n2_bits)
		return n1 < n2;

	return n1_bits < n2_bits;
}

class Solution {
public:
	vector<int> sortByBits(vector<int>& arr) {

		sort(arr.begin(), arr.end(), compare_by_bits);

		return arr;

	}
};
/*
	// [1111,7644,1107,6978,8742,1,7403,7694,9193,4401,377,8641,5311,624,3554,6631]
	vector<int> arr = { 1111,7644,1107,6978,8742,1,7403,7694,9193,4401,377,8641,5311,624,3554,6631 };
	for (auto i : arr)
	{// test hamming weight
		cout << i << " : " << hammingWeight(i) << endl;
	}

*/
#endif // ___Sort_Integers_by_The_Number_of_1_Bits_1356_h___
