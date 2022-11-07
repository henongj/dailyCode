#ifndef ___graph_traversal_h___
#define ___graph_traversal_h___
#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
class Graph
{
private:
	int value;
	vector<Graph*> neighbors;

public:
	Graph(int value) : value(value) {}
	void addNeighbor(Graph* neighbor)
	{
		neighbors.push_back(neighbor);
	}
	void print()
	{
		cout << value << " ";
	}
	void printNeighbors()
	{
		for (auto neighbor : neighbors)
		{
			neighbor->print();
		}
	}
	vector<Graph*> getNeighbors()
	{
		return neighbors;
	}
};
// depth limited search
bool depthLimitedSearch(Graph* start, Graph* end, int depth)
{
	if (depth == 0)
	{
		return false;
	}
	if (start == end)
	{
		return true;
	}
	for (auto neighbor : start->getNeighbors())
	{
		if (depthLimitedSearch(neighbor, end, depth - 1))
			return true;

	}
	return false;
}

void test_depth_limited_search()
{
	vector<Graph*> graphs;
	for (int i = 0; i < 10; i++)
	{
		Graph* g = new Graph(i);
		graphs.push_back(g);
	}
	/*
	0 -> 1, 2
	1 -> 3, 4
	2 -> 5
	4 -> 6, 7
	5 -> 8
	6 -> 9
	*/
	graphs[0]->addNeighbor(graphs[1]); graphs[0]->addNeighbor(graphs[2]);
	graphs[1]->addNeighbor(graphs[3]); graphs[1]->addNeighbor(graphs[4]);
	graphs[2]->addNeighbor(graphs[5]);
	graphs[4]->addNeighbor(graphs[6]); graphs[4]->addNeighbor(graphs[7]);
	graphs[5]->addNeighbor(graphs[8]);
	graphs[6]->addNeighbor(graphs[9]);

	for (int i = 0; i < 10; i++)
	{
		cout << "Node " << i << " has neighbors: ";
		graphs[i]->printNeighbors();
		cout << endl;
	}
	bool is_searched;

	is_searched = depthLimitedSearch(graphs[0], graphs[9], 0);
	cout << "is_searched: " << is_searched << endl;
	is_searched = depthLimitedSearch(graphs[0], graphs[9], 1);
	cout << "is_searched: " << is_searched << endl;
	is_searched = depthLimitedSearch(graphs[0], graphs[9], 2);
	cout << "is_searched: " << is_searched << endl;
	is_searched = depthLimitedSearch(graphs[0], graphs[9], 3);
	cout << "is_searched: " << is_searched << endl;
	is_searched = depthLimitedSearch(graphs[0], graphs[9], 4);
	cout << "is_searched: " << is_searched << endl;
	is_searched = depthLimitedSearch(graphs[0], graphs[9], 5);
	cout << "is_searched: " << is_searched << endl;

};



#endif