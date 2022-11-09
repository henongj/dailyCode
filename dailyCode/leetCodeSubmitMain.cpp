#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;


//997. find the town judge
//https://leetcode.com/problems/find-the-town-judge/
class Solution{
public:

    int findJudge(int n, vector<vector<int>>& trust) {
		
		int judge = -1;
		
		unordered_map<int, int> trust_mapping;
		
		for (auto i : trust) 
			trust_mapping[i[0]] = i[1];

		for (int i = 0; i < trust_mapping.size(); i++)
		{ // 대상이 믿는 사람이 없다면 trust_mapping에도 없다
			if (!trust_mapping.count(trust_mapping[i])) // 믿는 대상이 없을 경우
				return trust_mapping[i];
		}
		
		return judge;
    }
};
//797


int main(void)
{
	
	return 0;
}
