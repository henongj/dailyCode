
//https://school.programmers.co.kr/learn/courses/30/lessons/77884
//¾à¼öÀÇ °³¼ö¿Í µ¡¼À lv1
#include <string>
#include <vector>

using namespace std;

namespace programmers_lesston77884
{

	vector<int> getDivisor(int num)
	{
		vector<int> divisor;
		for (int i = 1; i <= num; i++)
		{
			if (num % i == 0)
				divisor.push_back(i);
		}
		return divisor;
	}

	int solution(int left, int right) {
		int answer = 0;

		for (int i = left; i <= right; i++)
		{
			vector<int> divisor = getDivisor(i);
			if (divisor.size() % 2 == 0)
				answer += i;
			else
				answer -= i;
		}

		return answer;
	}
}