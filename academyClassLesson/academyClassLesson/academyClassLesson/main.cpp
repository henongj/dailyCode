#include<iostream>
#include<set>

int main(void)
{
	std::multiset<int> setData{};
	
	setData.insert(1);
	setData.insert(2);
	setData.insert(3);
	setData.insert(5);
	setData.insert(3);
	setData.insert(5);
	setData.insert(5);
	setData.insert(7);
	setData.insert(2);

	std::multiset<int>::iterator iter = setData.find(5);
	if (iter != setData.end())
		setData.erase(iter);

	//print
	for (iter = setData.begin(); iter != setData.end(); iter++)
		std::cout << *iter << std::endl;
	
	return 0;
}