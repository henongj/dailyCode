#include<iostream>
#include<list>
#include<vector>
#include<set>

int mainSpace01_20230524(void);
int mainSpace02_20230524(void);
int mainSpace03_20230524(void);

int mainSpace02_20230524(void)
{
	std::set<int> sTree{};
	std::pair<std::set<int>::iterator, bool> result{};

	result = sTree.insert(3);
	if (result.second)
		std::cout << "성 공" << std::endl;
	else
		std::cout << "실 패" << std::endl;

	result = sTree.insert(3);

	if (result.second)
		std::cout << "성 공" << std::endl;
	else
		std::cout << "실 패" << std::endl;

	if (sTree.insert(5).first == sTree.end())
		std::cout << "실 패" << std::endl;
	else
		std::cout << "성 공" << std::endl;

	return 0;
}

int mainSpace03_20230524(void)
{
	std::set<int> tree{};

	tree.insert(4);
	tree.insert(47);
	tree.insert(14);
	tree.insert(2);
	tree.insert(1);

	std::set<int>::iterator iter = tree.begin();
	while (iter != tree.end())
	{
		std::cout << *iter << " ";
		iter++;
	}

	return 0;
}

int mainSpace01_20230524(void)
{
	std::vector<int> vData{};

	vData.reserve(7);
	//arrayList적인 사용
	vData.push_back(1);
	vData.push_back(2);
	vData.push_back(3);
	vData.push_back(4);
	vData.push_back(5);
	vData.push_back(6);
	vData.push_back(7);

	for (int i = 0; i < vData.size(); i++)
	{
		std::cout << vData[i] << " ";
	}
	std::cout << std::endl;

	//array적인 사용
	vData.resize(10);
	for (int i = 0; i < vData.size(); i++)
	{
		std::cout << vData[i] << " ";
	}

	return 0;
}
