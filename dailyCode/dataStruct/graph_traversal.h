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
		if (depthLimitedSearch(neighbor, end, depth - 1)) // recursion
			return true;

	}
	return false;
}
int get_max_level_of_tree(Graph* root)
{
	if (root == nullptr)
	{
		return 0;
	}
	int max_level = 0;
	for (auto neighbor : root->getNeighbors())
	{
		max_level = max(max_level, get_max_level_of_tree(neighbor));
	}
	return max_level + 1;
}

// iterative deepning depth first search
// complete traversal
bool iterativeDeepeningDepthFirstSearch(Graph* start, Graph* end)
{
	cout << "max level : " << get_max_level_of_tree(start) << endl;
	int max_level = get_max_level_of_tree(start);
	for (int i = 0; i < max_level; i++)
	{
		if (depthLimitedSearch(start, end, max_level))
			return true;
	}
	return false;
}
// suggest maximum level of tree
bool iterative_deepning_depth_first_search(Graph* start, Graph* target, int max_level)
{
	if (max_level == 0)
	{
		return false;
	}
	if (start == target)
	{
		return true;
	}
	for (auto neighbor : start->getNeighbors())
	{
		if (iterative_deepning_depth_first_search(neighbor, target, max_level - 1))
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
	cout << "depth : 0 " << "is_searched: " << is_searched << endl;
	is_searched = depthLimitedSearch(graphs[0], graphs[9], 1);
	cout << "depth : 1 " << "is_searched: " << is_searched << endl;
	is_searched = depthLimitedSearch(graphs[0], graphs[9], 2);
	cout << "depth : 2 " << "is_searched: " << is_searched << endl;
	is_searched = depthLimitedSearch(graphs[0], graphs[9], 3);
	cout << "depth : 3 " << "is_searched: " << is_searched << endl;
	is_searched = depthLimitedSearch(graphs[0], graphs[9], 4);
	cout << "depth : 4 " << "is_searched: " << is_searched << endl;
	is_searched = depthLimitedSearch(graphs[0], graphs[9], 5);
	cout << "depth : 5 " << "is_searched: " << is_searched << endl << endl;

	is_searched = iterativeDeepeningDepthFirstSearch(graphs[0], graphs[9]);
	cout << "iterative deepning depth first search is_searched: " << is_searched << endl;

};

#endif