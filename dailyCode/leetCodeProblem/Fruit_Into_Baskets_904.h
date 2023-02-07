#include<iostream>
#include<unordered_map>
#include<vector>
//https://leetcode.com/problems/fruit-into-baskets/
//904. Fruit Into Baskets

class Solution {
public:
	int totalFruit(std::vector<int>& fruits) {
		int n = fruits.size();
		int i = 0, j = 0;
		int ans = 0;
		std::unordered_map<int, int> m;
		while (j < n) {
			m[fruits[j]]++;
			while (m.size() > 2) {
				m[fruits[i]]--;
				if (m[fruits[i]] == 0) {
					m.erase(fruits[i]);
				}
				i++;
			}
			ans = std::max(ans, j - i + 1);
			j++;
		}
		return ans;
	}
};
