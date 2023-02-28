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
using namespace std;

bool stringCopy(const char* strCopy, char* strDestination, int nDestinationLength);

void getCountChar(const char* str, char cToFind, int* pCount);

int testSpace(void)
{
	int nCount{};

	getCountChar("adasvas", 'a', &nCount);

	printf("%d", nCount);

}

void getCountChar(const char* str, char cToFind, int* pCount)
{
	int nIndex{};
	(*pCount) = 0;

	while (str[nIndex])
	{
		if (str[nIndex] == cToFind)
			(*pCount)++;

		nIndex++;
	}
}

bool stringCopy(const char* strSource, char* strDestination, int nDestinationLength)
{
	int nIndex{};

	//nDestinationLength - 1 , null 을 봐야해서 -1을 챙겨야 한다
	while (strSource[nIndex] && nIndex < nDestinationLength - 1)
	{
		strDestination[nIndex] = strSource[nIndex];
		nIndex++;
	}

	strDestination[nIndex] = '\0';

	if (strSource[nIndex])
		return false;

	return true;
}
