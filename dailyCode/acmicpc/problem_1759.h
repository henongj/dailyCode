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

#ifndef ___problem_1759_h___
#define ___problem_1759_h___
//https://www.acmicpc.net/problem/1759
// 1759. 암호 만들기

void data_input(vector<char>& data, int& L, int& C) {
	cin >> L >> C;
	data.resize(C);
	for (int i = 0; i < C; i++) {
		cin >> data[i];
	}
}

//cehck_bowel
bool check(vector<char>& data, vector<bool>& visited) {

	int vowel = 0;
	int consonant = 0;
	for (int i = 0; i < data.size(); i++) {
		if (visited[i]) {
			if (data[i] == 'a' || data[i] == 'e' || data[i] == 'i' || data[i] == 'o' || data[i] == 'u') {
				vowel++;
			}
			else {
				consonant++;
			}
		}
	}

	return vowel >= 1 && consonant >= 2 ? true : false;
}

//select
void select(vector<char> data, vector<bool>& visited, int idx, int count, const int& L, const int& C) {

	if (count == L)
	{
		if (check(data, visited))
		{
			for (int i = 0; i < data.size(); i++)
				if (visited[i] == true)
					cout << data[i];
			cout << endl;
		}
		return;
	}

	if (idx == C)
		return;

	// select
	visited[idx] = 1;
	select(data, visited, idx + 1, count + 1, L, C);

	// not select
	visited[idx] = 0;
	select(data, visited, idx + 1, count, L, C);

	return;
}

void solution(void)
{
	vector<char> data;

	int L, C;


	data_input(data, L, C);
	vector<bool> visited(data.size(), false);

	sort(data.begin(), data.end());

	// 1. data에서 왼쪽 idx부터 L개의 글자를 고른다 (조합)
	// 2. 고른 글자들이 모음과 자음의 조합이 맞는지 확인한다
	// 3. 맞으면 출력한다
	select(data, visited, 0, 0, L, C);

}

#endif // ___problem_1759_h___

/*

int main(void)
{
	solution();

	return 0;
}


*/
