//https://leetcode.com/problems/top-k-frequent-elements/
//347. Top K Frequent Elements
#ifndef ___Top_K_Frequent_Elements_347_h___
#define ___Top_K_Frequent_Elements_347_h___
#include<vector>
#include<iostream>
using namespace std;

class MaxHeap
{
private:
	// num , frequency
	vector<pair<int, int>> arr;
	void heapify(int idx)
	{
		int left = 2 * idx + 1;
		int right = 2 * idx + 2;
		int parent = idx;
		if (left < arr.size() && arr[left].second > arr[parent].second)
		{
			swap(left, parent);
			heapify(left);
		}
		if (right < arr.size() && arr[right].second > arr[parent].second)
		{
			swap(right, parent);
			heapify(right);
		}
	}
	void swap(int idx1, int idx2)
	{
		pair<int, int> t = arr[idx1];
		arr[idx1] = arr[idx2];
		arr[idx2] = t;
	}
public:
	MaxHeap(vector<pair<int, int>> arr) {
		this->arr = arr;
		for (int i = arr.size() / 2 - 1; i >= 0; i--)
			heapify(i);
	}
	int size(void)
	{
		return arr.size();
	}
	pair<int, int> front(void)
	{
		return arr[0];
	}
	void pop(void)
	{
		swap(0, arr.size() - 1);
		arr.pop_back();
		heapify(0);
	}
	void push(pair<int, int> num)
	{
		arr.push_back(num);
		swap(0, arr.size() - 1);
		heapify(0);
	}
	void print()
	{
		for (int i = 0; i < arr.size(); i++)
			cout << arr[i].first << " " << arr[i].second << " ";
		cout << endl;
	}
};

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		vector<int> result;
		unordered_map<int, int> m;
		for (auto num : nums)
		{
			if (m.count(num))
				m[num] = m[num] + 1;
			if (!m.count(num))
				m[num] = 1;
		}
		vector<pair<int, int>> p;
		for (auto i : m)
		{
			pair<int, int> temp(i.first, i.second);
			p.push_back(temp);
		}
		MaxHeap heap = MaxHeap(p);

		for (int i = 0; i < k; i++)
		{
			pair<int, int> temp = heap.front();
			heap.pop();
			result.push_back(temp.first);
		}

		return result;
	}
};
#endif