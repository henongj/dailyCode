
#ifndef ___acmicpc_1197_h___
#define ___acmicpc_1197_h___
namespace acmicpc_1197
{
	//https://www.acmicpc.net/problem/1197
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
	int V, E;
	int parent[10001];
	int find(int x) {
		if (parent[x] == x) return x;
		return parent[x] = find(parent[x]);
	}
	void union_find(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		parent[y] = x;
	}
	void solution(void)
	{
		cin >> V >> E;
		vector<pair<int, pair<int, int>>> edges;
		for (int i = 0; i < E; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			edges.push_back({ c,{a,b} });
		}
		sort(edges.begin(), edges.end());
		for (int i = 1; i <= V; i++) {
			parent[i] = i;
		}
		int ans = 0;
		for (int i = 0; i < E; i++) {
			int cost = edges[i].first;
			int a = edges[i].second.first;
			int b = edges[i].second.second;
			if (find(a) != find(b)) {
				union_find(a, b);
				ans += cost;
			}
		}
		cout << ans;
	}
}
#endif // !___acmicpc_1197_h___