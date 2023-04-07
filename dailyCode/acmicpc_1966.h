#pragma once


//https://www.acmicpc.net/problem/1966
//프린터 큐
void printerQueue(void)
{
	int testCase = 0;
	std::cin >> testCase;

	for (int i = 0; i < testCase; ++i)
	{
		int n = 0, m = 0;
		std::cin >> n >> m;

		std::queue<std::pair<int, int>> q;
		std::priority_queue<int> pq;

		for (int j = 0; j < n; ++j)
		{
			int priority = 0;
			std::cin >> priority;
			q.push(std::make_pair(j, priority));
			pq.push(priority);
		}

		int count = 0;
		while (!q.empty())
		{
			int index = q.front().first;
			int priority = q.front().second;
			q.pop();

			if (priority == pq.top())
			{
				++count;
				pq.pop();
				if (index == m)
				{
					std::cout << count << std::endl;
					break;
				}
			}
			else
			{
				q.push(std::make_pair(index, priority));
			}
		}
	}
}

