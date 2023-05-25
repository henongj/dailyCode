#include<map>
#include<stdio.h>

int mainSpace01_20230525(void)
{
	std::map<int, float> mapData{};

	std::pair<int, float> pairData{};
	pairData.first = 10;
	pairData.second = 1.5f;

	mapData.insert(pairData);
	mapData.insert(std::pair<int, float>(9, 2.5f));
	mapData.insert(std::make_pair<int, float>(19, 12.5f));
	mapData.insert(std::map<int, float>::value_type(30, 1.1f));
	mapData[40] = 8.8f; // 쓰지마라
	mapData.insert({ 123,321.123f });

	std::map<int, float>::iterator mapIter = mapData.begin();
	while (mapIter != mapData.end())
	{
		printf("%d, %f\n", (*mapIter).first, mapIter->second);
		mapIter++;
	}
	printf("-----------------------------------------------------------------\n");
	mapIter = mapData.find(19);

	if (mapIter != mapData.end())
		printf("있다 %d, %f\n", (*mapIter).first, mapIter->second);
	else
		printf("not found\n");

	// 만들어버림
	printf("%f\n", mapData[-3]);

	mapIter = mapData.begin();
	// 덮어써버림
	mapData[40] = 123123.123f;
	while (mapIter != mapData.end())
	{
		printf("%d, %f\n", (*mapIter).first, mapIter->second);
		mapIter++;
	}
	printf("-----------------------------------------------------------------\n");

	return 0;
}
