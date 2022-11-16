#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

// priority queue
class MaxHeap
{
private:
	// str , frequency
	vector<pair<string,int>> arr;
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
		pair<string,int> t = arr[idx1];
		arr[idx1] = arr[idx2];
		arr[idx2] = t;
	}
public:
	MaxHeap(vector<pair<string,int>> arr) {
		this->arr = arr;
		for (int i = arr.size() / 2 - 1; i >= 0; i--)
			heapify(i);
	}
	int size(void)
	{
		return arr.size();
	}
	pair<string,int> front(void)
	{
		return arr[0];
	}
	void pop(void)
	{
		swap(0, arr.size() - 1);
		arr.pop_back();
		heapify(0);
	}
	void push(pair<string,int> num)
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
//https://leetcode.com/problems/top-k-frequent-words/
//692. ___Top_K_Frequent_Words_692_h___
#ifndef ___Top_K_Frequent_Words_692_h___
#define ___Top_K_Frequent_Words_692_h___
class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		vector<string> result;
		vector<pair<string, int>> converter;
		unordered_map<string, int> m;
		for (auto word : words)
		{
			if (m.count(word))
				m[word] = m[word] + 1;
			if (!m.count(word))
				m[word] = 1;
		}
		
		for (auto data : m)
			converter.push_back(pair<string, int>(data.first, data.second));

		MaxHeap heap = MaxHeap(converter);

		// 사전순으로 정렬해야함
		for (int i = 0; i < k; i++)
		{
			result.push_back(heap.front().first);
			heap.pop();
		}
		return result;
	}

};
#endif

int main(void)
{
	return 0;
}
