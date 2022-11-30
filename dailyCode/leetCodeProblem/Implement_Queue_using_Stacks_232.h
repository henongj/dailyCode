
//https://leetcode.com/problems/implement-queue-using-stacks/?envType=study-plan&id=programming-skills-i
// 232. Implement Queue using Stacks
#ifndef ___Implement_Queue_using_Stacks_232_h___
#define ___Implement_Queue_using_Stacks_232_h___
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
class MyQueue {
private:
	stack<int> s0;
	stack<int> s1;
public:
	// constructor
	MyQueue() {
	}
	//push
	void push(int x) {
		s0.push(x);
	}
	//pop
	int pop() {
		if (s1.empty()) {
			while (!s0.empty()) {
				s1.push(s0.top());
				s0.pop();
			}
		}
		int ret = s1.top();
		s1.pop();
		return ret;
	}

	// peak
	int peek() {
		if (s1.empty()) {
			while (!s0.empty()) {
				s1.push(s0.top());
				s0.pop();
			}
		}
		return s1.top();
	}
	//empty
	bool empty() {
		return s0.empty() && s1.empty();
	}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */


#endif // ___Implement_Queue_using_Stacks_232_h___