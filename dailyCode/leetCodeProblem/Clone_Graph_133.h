
#ifndef ___Clone_Graph_133_h___
#define ___Clone_Graph_133_h___

//https://leetcode.com/problems/clone-graph/
// 133. Clone Graph
// Definition for a Node.
#include<vector>
#include<iostream>
using namespace std;
class Node {
public:
	int val;
	vector<Node*> neighbors;
	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}
	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}
	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};
class Solution {
public:
	Node* cloneGraph(Node* node) {
		if (node == nullptr)
			return nullptr;

		unordered_map<Node*, Node*> m;
		queue<Node*> q;

		q.push(node);
		m[node] = new Node(node->val);

		while (!q.empty()) {
			Node* n = q.front();
			q.pop();
			for (Node* neighbor : n->neighbors) {
				if (m.find(neighbor) == m.end()) {
					m[neighbor] = new Node(neighbor->val);
					q.push(neighbor);
				}
				m[n]->neighbors.push_back(m[neighbor]);
			}
		}
		return m[node];
	}
};

#endif
