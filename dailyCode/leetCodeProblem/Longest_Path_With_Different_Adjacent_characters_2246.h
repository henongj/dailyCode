
#ifndef ___Longest_Path_With_Different_Adjacent_characters_2246_h___
#define ___Longest_Path_With_Different_Adjacent_characters_2246_h___
//https://leetcode.com/problems/longest-path-with-different-adjacent-characters/
//2246. Longest Path With Different Adjacent Characters
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
    vector<int> child[100001];
    int ans;
    int dfs(string& s, int curr_node)
    {
        if (child[curr_node].empty())
            return 1;
        int mx1 = 0, mx2 = 0;

        for (auto& child_node : child[curr_node])
        {

            int len = dfs(s, child_node);
            ans = max(ans, len);
            if (s[curr_node] == s[child_node])continue;
            if (len > mx1)
            {
                mx2 = mx1;
                mx1 = len;
            }
            else mx2 = max(mx2, len);
        }
        ans = max(ans, 1 + mx1 + mx2);
        return 1 + mx1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        for (int i = 1; i < n; i++)child[parent[i]].push_back(i);
        ans = 1;
        dfs(s, 0);
        return ans;
    }
};
#endif // ___Longest_Path_With_Different_Adjacent_characters_2246_h___