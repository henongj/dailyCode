#pragma once


//https://school.programmers.co.kr/learn/courses/30/lessons/178871
#include <string>
#include <vector>
#include<unordered_map>
#include<utility>
using namespace std;

namespace programmers_lessons_178871
{

	void swapPair(std::pair<int, string*>& pairA, std::pair<int, string*>& pairB)
	{
		std::pair<int, string*> tempPair = pairA;
		pairA = pairB;
		pairB = tempPair;
	}
	void swapString(std::string& strA, std::string& strB)
	{
		std::string tempStr = strA;
		strA = strB;
		strB = tempStr;
	}

	vector<string> solution(vector<string> players, vector<string> callings)
	{
		vector<string> answer = players;
		unordered_map<string, std::pair<int, string*>> playerMap{};
		size_t szPlayers = answer.size();
		size_t szCallings = callings.size();
		int nPlayerRank{};

		nPlayerRank = 0;
		for (int i = 0; i < szPlayers; i++)
		{
			std::pair<int, string*> playerRank = std::make_pair(nPlayerRank, &answer[i]);
			playerMap.insert(std::make_pair(answer[i], playerRank));
			nPlayerRank++;
		}

		for (int i = 0; i < szCallings; i++)
		{
			std::string* strPlayer = &callings[i];

			int nOutRuner = playerMap[*strPlayer].first;
			std::string* strOutRunerName = playerMap[*strPlayer].second;

			int nOutRunned = nOutRuner - 1;
			std::string* strOutRunnedName = &answer[nOutRunned];

			swapPair(playerMap[*strOutRunerName], playerMap[*strOutRunnedName]);
			swapString(*strOutRunerName, *strOutRunnedName);
		}

		return answer;
	}


}


/*


int mainSpace01_20230512(void)
{

	vector<string> players{ "mumu", "soe", "poe", "kai", "mine" };
	vector<string> callings{ "kai", "kai", "mine", "mine"};
	vector<string> answer = solution(players, callings);

	for (int i = 0; i < answer.size(); i++)
	{
		std::cout << answer[i] << std::endl;
	}

	return 0;
}


*/