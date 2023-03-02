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
#include<set>
using namespace std;
//https://leetcode.com/problems/string-compression/
//443. String Compression
class Solution {
public:
	int compress(vector<char>& chars) {
		int n = chars.size();
		int i = 0;
		int j = 0;
		while (i < n) {
			int count = 1;
			while (i + 1 < n && chars[i] == chars[i + 1]) {
				count++;
				i++;
			}
			chars[j++] = chars[i];
			if (count > 1) {
				string s = to_string(count);
				for (int k = 0; k < s.size(); k++) {
					chars[j++] = s[k];
				}
			}
			i++;
		}
		return j;
	}
};