
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

namespace programmers_lessons_133502
{
	int solution(vector<int> ingredient) {
		int answer = 0;
		string str = "";
		for (int i = 0; i < ingredient.size(); i++)
			str += to_string(ingredient[i]);
		string hamburger = "1231";
		int idx = 0;
		while (idx != -1)
		{
			idx = str.find(hamburger);
			if (idx != -1)
			{
				answer++;
				str.erase(idx, 4);
			}
			cout << str << endl;
		}


		return answer;
	}
}
// testcasae 	[2, 1, 1, 2, 3, 1, 2, 3, 1]
//[1, 3, 2, 1, 2, 1, 3, 1, 2]
#endif // ___make_hamburger_h___