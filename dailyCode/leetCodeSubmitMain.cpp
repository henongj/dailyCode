#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;


int main(void)
{
	vector<int> ingredient1 = { 2, 1, 1, 2, 3, 1, 2, 3, 1 };
	vector<int> ingredient2 = { 1, 3, 2, 1, 2, 1, 3, 1, 2 };
	cout << "answer : " << solution(ingredient1) << endl;
	char c;
	cin >> c;
	return 0;
}

