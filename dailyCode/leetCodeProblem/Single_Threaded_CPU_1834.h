
//https://leetcode.com/problems/single-threaded-cpu/
// 1834. Single-Threaded CPU
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
#ifndef ___Single_Threaded_CPU_1834_h___
#define ___Single_Threaded_CPU_1834_h___
class Solution {
    typedef pair<int, int> T;
public:
    vector<int> getOrder(vector<vector<int>>& A) {

        priority_queue<T, vector<T>, greater<>> pq;

        long N = A.size(), time = 0, i = 0; // `time` is the current time, `i` is the read pointer

        for (int i = 0; i < N; ++i)
            A[i].push_back(i);

        sort(begin(A), end(A));
        vector<int> ans;
        while (i < N || pq.size()) {
            if (pq.empty()) {
                time = max(time, (long)A[i][0]);
            }
            while (i < N && time >= A[i][0]) {
                pq.emplace(A[i][1], A[i][2]);
                ++i;
            }
            int pro, index;
            pro = pq.top().first;
            index = pq.top().second;
            pq.pop();
            time += pro; // handle this task and increase the current time by the processingTime
            ans.push_back(index);
        }
        return ans;
    }
};
#endif // ___Single_Threaded_CPU_1834_h___
