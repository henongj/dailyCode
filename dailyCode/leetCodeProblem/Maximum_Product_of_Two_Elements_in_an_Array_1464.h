
// priority queue
//1464. ___Maximum_Product_of_Two_Elements_in_an_Array_1464_h___
//https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/


#include<iostream>
#include<vector>
using namespace std;
class MaxHeap
{
private:
	vector<int> arr;
	void heapify(int idx)
	{
		int left = 2 * idx + 1;
		int right = 2 * idx + 2;
		int parent = idx;
		if (left < arr.size() && arr[left] > arr[parent])
		{
			swap(left, parent);
			heapify(left);
		}
		if (right < arr.size() && arr[right] > arr[parent])
		{
			swap(right, parent);
			heapify(right);
		}
	}
	void swap(int idx1, int idx2)
	{
		int t = arr[idx1];
		arr[idx1] = arr[idx2];
		arr[idx2] = t;
	}
public:
	MaxHeap(vector<int> arr) {
		this->arr = arr;
		for (int i = arr.size() / 2 - 1; i >= 0; i--)
			heapify(i);
	}
	int size(void)
	{
		return arr.size();
	}
	int front(void)
	{
		return arr[0];
	}
	void pop(void)
	{
		swap(0, arr.size() - 1);
		arr.pop_back();
		heapify(0);
	}
	void push(int num)
	{
		arr.push_back(num);
		swap(0, arr.size() - 1);
		heapify(0);
	}
	void print()
	{
		for (int i = 0; i < arr.size(); i++)
			cout << arr[i] << " ";
		cout << endl;
	}
};

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		MaxHeap heap = MaxHeap(nums);
		heap.print();
		int max1 = heap.front();
		heap.pop();
		int max2 = heap.front();
		heap.pop();
		return (max1 - 1) * (max2 - 1);
	}
};