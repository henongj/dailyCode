

#ifndef ___acmicpc_11279_h___
#define ___acmicpc_11279_h___
//https://www.acmicpc.net/problem/11279
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
using namespace std;
namespace acmicpc_11279
{

	void solution(void) {

		priority_queue<int> pq;
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			if (num == 0) {
				if (pq.empty()) {
					cout << 0 << '\n';
				}
				else {
					cout << pq.top() << '\n';
					pq.pop();
				}
			}
			else {
				pq.push(num);
			}
		}
	}
}
#endif // ___acmicpc_11279_h___