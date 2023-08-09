#pragma once

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
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
#include <fstream>
#include<functional>

//https://www.acmicpc.net/problem/1753
//최단경로
namespace acmicpc_1753
{
	using namespace std;

	void solution(void);

	void solution(void)
	{
		int nVertex{};
		int nEdge{};
		int startVertex{};
		const int nMax = 0xFFFFFFF;

		cin >> nVertex >> nEdge >> startVertex;

		//use prioirty queue, for dijkstra
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		vector<vector<pair<int, int>>> graph(nVertex + 1);
		vector<int> dist(nVertex + 1, nMax);

		for (int i = 0; i < nEdge; ++i)
		{
			int from{}, to{}, weight{};
			cin >> from >> to >> weight;
			graph[from].push_back({ to, weight });
		}

		dist[startVertex] = 0;
		pq.push({ 0, startVertex });

		while (!pq.empty())
		{
			int curVertex = pq.top().second;
			int curWeight = pq.top().first;
			pq.pop();

			if (dist[curVertex] < curWeight)
			{
				continue;
			}

			for (int i = 0; i < graph[curVertex].size(); ++i)
			{
				int nextVertex = graph[curVertex][i].first;
				int nextWeight = graph[curVertex][i].second;

				if (dist[nextVertex] > curWeight + nextWeight)
				{
					dist[nextVertex] = curWeight + nextWeight;
					pq.push({ dist[nextVertex], nextVertex });
				}
			}
		}

		for (int i = 1; i <= nVertex; ++i)
		{
			if (dist[i] == nMax)
			{
				cout << "INF" << endl;
			}
			else
			{
				cout << dist[i] << endl;
			}
		}

	}


}
