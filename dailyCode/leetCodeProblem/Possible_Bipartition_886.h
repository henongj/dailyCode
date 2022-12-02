
//https://leetcode.com/problems/possible-bipartition/
//886. Possible Bipartition
#ifndef ___Possible_Bipartition_886_h___
#define ___Possible_Bipartition_886_h___
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

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        int catetory1 = 1;
        int category2 = 2;
		
		vector<int> category(n + 1, 0);
		vector<vector<int>> graph(n + 1, vector<int>());
		for (auto& dislike : dislikes) {
			graph[dislike[0]].push_back(dislike[1]);
			graph[dislike[1]].push_back(dislike[0]);
		}
		
		for (int i = 1; i <= n; ++i) {
			if (category[i] == 0) {
				queue<int> q;
				q.push(i);
				// ���� �ϳ� ����
				category[i] = catetory1;
				while (!q.empty()) {
					// �� ���̶� �ٸ��ɷ� �� ĥ�ϱ�
					int cur = q.front();
					q.pop();
					// ���� ���� ����� ������ Ȯ��
					for (auto& neighbor : graph[cur]) {
						// �� ĥ������ ĥ�ϰ� push
						if (category[neighbor] == 0) {
							category[neighbor] = category[cur] == catetory1 ? category2 : catetory1;
							q.push(neighbor);
						}
						// ĥ�� �� �ִµ� ���� ���̸� false
						else if (category[neighbor] == category[cur]) {
							return false;
						}
					}
				}
			}
		}
		return true;
    }
};


#endif // ___Possible_Bipartition_886_h___