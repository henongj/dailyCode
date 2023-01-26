//https://leetcode.com/problems/cheapest-flights-within-k-stops/
//787. Cheapest Flights Within K Stops
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
#include<unordered_set>
using namespace std;

class Solution {
public:
    // timelimit exceeded
    int findCheapestPrice_TLE(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //solve it with Dijkstra's Algorithm

        vector<vector<pair<int, int>>> graph(n);
        for (auto& flight : flights) {
            graph[flight[0]].push_back({ flight[1], flight[2] });
        }

        //create a priority queue
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({ 0, src, k + 1 });

        //start Dijkstra's Algorithm
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int price = top[0];
            int city = top[1];
            int stops = top[2];

            if (city == dst) {
                return price;
            }

            if (stops > 0) {
                for (auto& neighbor : graph[city]) {
                    pq.push({ price + neighbor.second, neighbor.first, stops - 1 });
                }
            }
        }

        return -1;
    }

        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
            int k) {
            vector<vector<pair<int, int>>> graph(n);
            using T = tuple<int, int, int>;  // (d, u, stops)
            priority_queue<T, vector<T>, greater<>> minHeap;
            vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

            minHeap.emplace(0, src, k + 1);  // Start with node src with d == 0
            dist[src][k + 1] = 0;

            for (const vector<int>& f : flights) {
                const int u = f[0];
                const int v = f[1];
                const int w = f[2];
                graph[u].emplace_back(v, w);
            }

            while (!minHeap.empty()) {
                const auto [d, u, stops] = minHeap.top();
                minHeap.pop();
                if (u == dst)
                    return d;
                if (stops > 0)
                    for (const auto& [v, w] : graph[u]) {
                        const int newDist = d + w;
                        if (newDist < dist[v][stops - 1]) {
                            dist[v][stops - 1] = newDist;
                            minHeap.emplace(newDist, v, stops - 1);
                        }
                    }
            }

            return -1;
        }
    };
};