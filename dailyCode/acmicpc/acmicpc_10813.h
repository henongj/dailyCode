
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
#include<set>

//https://www.acmicpc.net/problem/10813
int mainSpace(void)
{
	int N, M;
	std::cin >> N >> M;
	std::vector<int> v(N);
	for (int i = 0; i < N; ++i)
		v[i] = i + 1;

	for (int i = 0; i < M; ++i)
	{
		int a, b;
		std::cin >> a >> b;
		std::swap(v[a - 1], v[b - 1]);
	}

	for (int i = 0; i < N; ++i)
		std::cout << v[i] << " ";

	return 0;
}