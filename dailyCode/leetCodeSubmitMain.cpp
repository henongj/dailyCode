#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

// https://school.programmers.co.kr/learn/courses/30/lessons/133502
// 햄버거 만들기 lv1
#ifndef ___make_hamburger_h___
#define ___make_hamburger_h___
#include<iostream>
#include <string>
#include <vector>
#include<stack>
#include<queue>
using namespace std;

int solution(vector<int> ingredient) {
	int answer = 0;
	stack<int> s;
	stack<int> poped;
	vector<int> hamburger = { 1,3,2,1 }; // 아래에서부터 빵 야채 고기 빵 1 3 2 1
	int idx = 0;
	for (int i = 0; i < ingredient.size(); i++)
		s.push(ingredient[i]);
	
	while (!s.empty())
	{
		// make hambergur at inredient
		// used stuff have to gone, don't used stuff can use
		// hamburger must make adjacent stuff
		int stuff = s.top();
		cout << "stuff : " << stuff << " hamburger[stuff_idx] " << hamburger[idx] << "\n";
		s.pop();
		poped.push(stuff); // if can't make hamberger, have to input at stack

		if (stuff == hamburger[idx])
		{
			idx = idx + 1;
			if (idx == 4)
			{
				cout << "poped size : " << poped.size() << "\n";
				idx = 0;
				poped.pop(); poped.pop(); poped.pop(); poped.pop();
				while (!poped.empty())
				{
					s.push(poped.top());
					poped.pop();
				}
				answer++;
			}
		}
		else if (stuff != hamburger[idx])
		{
			idx = idx + 1;
		}
		
	}

	return answer;
}
// testcasae 	[2, 1, 1, 2, 3, 1, 2, 3, 1]
//[1, 3, 2, 1, 2, 1, 3, 1, 2]
#endif // ___make_hamburger_h___

int main(void)
{
	vector<int> ingredient = { 2, 1, 1, 2, 3, 1, 2, 3, 1 };
	vector<int> ingredient2 = { 1, 3, 2, 1, 2, 1, 3, 1, 2 };
	cout << solution(ingredient2) << endl;
	
	return 0;
}

