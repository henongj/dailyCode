#include<iostream>
#include<list>
#include<vector>

void printList_20230523(std::list<int>::iterator iterBegin, std::list<int>::iterator iterEnd);
int mainSpace02_20230523(void)
{
	std::vector<int> vData{};
	vData.reserve(10);
	for (int i = 0; i < 11; i++)
	{
		vData.push_back(i);
		printf("전체 크기 : %zd, 사용 범쥐 : %zd\n", vData.size(), vData.capacity());
	}
	return 0;
}
int mainSpace01_20230523(void)
{
	std::list<int> listData{};

	listData.push_back(1);
	listData.push_back(2);
	listData.push_back(3);
	listData.push_front(4);
	listData.push_front(5);
	listData.push_front(6);

	printList_20230523(listData.begin(), listData.end());
	std::list<int>::iterator iter = listData.begin();
	while (iter != listData.end())
	{
		//delete if *iter > 5
		if (*iter > 5)
			iter = listData.erase(iter);
		else
			iter++;
	}

	printList_20230523(listData.begin(), listData.end());

	//오름차순 정렬
	listData.sort();
	printList_20230523(listData.begin(), listData.end());

	// 내림차순 정렬
	listData.sort(std::greater<int>());
	printList_20230523(listData.begin(), listData.end());



	return 0;
}

void printList_20230523(std::list<int>::iterator iterBegin, std::list<int>::iterator iterEnd)
{
	std::list<int>::iterator iter = iterBegin;
	while (iter != iterEnd)
	{
		std::cout << *iter << " ";
		iter++;
	}
	std::cout << "\n";
}

void func(int i)
{
	std::cout << i << " ";
}
