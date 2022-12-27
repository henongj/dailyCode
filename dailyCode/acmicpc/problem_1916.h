
//https://www.acmicpc.net/problem/1916
//최소비용 구하기
#ifndef ___acmicpc_1916_h___
#define ___acmicpc_1916_h___
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

void data_input(vector<vector<pair<int, int>>>& adj, int& N, int& M, int& start, int& end)
{
	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
	}
	cin >> start >> end;
}

void get_minimum_dist(void)
{
	int N, M;
	int start, end;
	vector<vector<pair<int, int>>> adj(N + 1, vector<pair<int, int>>());

	vector<int> dist(N + 1, 987654321);
	dist[start] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost)
			continue;
		for (int i = 0; i < adj[here].size(); ++i)
		{
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			if (dist[there] > nextDist)
			{
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	cout << dist[end] << endl;
}

/*
int main(void)
{
	get_minimum_dist();
	return 0;
}


*/
#endif // ___acmicpc_1916_h___