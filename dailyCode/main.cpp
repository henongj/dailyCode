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

//https://www.acmicpc.net/problem/10866
//µ¦
class DEQUE
{
private:
	std::vector<int> m_vDeque;
	int m_nFrontIndex;
	int m_nBackIndex;
	int m_nSize;
public:
	DEQUE() = default;
	void push_front(int nNum);
	void push_back(int nNum);
	void pop_front();
	void pop_back();
	void size();
	void empty();
	void front();
	void back();
};

void acmicpc_10866(void)
{
	DEQUE cDeque{};
	int nNumOfCommand{};
	std::string strCommand{};
	int nInputData{};
	
	// connect map and DEQUE function
	std::map<std::string, void(DEQUE::*)(int)> mapCommand{};
	mapCommand["push_front"] = &DEQUE::push_front;
	mapCommand["push_back"] = &DEQUE::push_back;
	
	

	
}

int main(void)
{
	return 0;
}

DEQUE::DEQUE()
{
	m_vDeque.reserve(1000);
	m_nFrontIndex = 0;
	m_nBackIndex = 0;
	m_nSize = 0;
}

void DEQUE::push_front(int nNum)
{
	m_vDeque.insert(m_vDeque.begin(), nNum);
	m_nSize++;
	m_nBackIndex++;
}

void DEQUE::push_back(int nNum)
{
	m_vDeque.push_back(nNum);
	m_nSize++;
	m_nBackIndex++;
}

void DEQUE::pop_front()
{
	if (m_nSize == 0)
		printf("-1\n");
	
	int nTemp{};

	nTemp = m_vDeque[m_nFrontIndex];
	m_vDeque.erase(m_vDeque.begin());
	m_nSize--;
	m_nBackIndex--;
	
	printf("%d\n", nTemp);
}

void DEQUE::pop_back()
{
	if (m_nSize == 0)
		printf("-1\n");

	int nTemp{};

	nTemp = m_vDeque[m_nBackIndex];
	m_vDeque.pop_back();
	m_nSize--;
	m_nBackIndex--;

	printf("%d\n", nTemp);
}

void DEQUE::size()
{
	printf("%d\n", m_nSize);
}

void DEQUE::empty()
{
	if (m_nSize == 0)
		printf("1\n");
	else
		printf("0\n");
}

void DEQUE::front()
{
	if (m_nSize == 0)
		printf("-1\n");
	else
		printf("%d\n", m_vDeque[m_nFrontIndex]);
}

void DEQUE::back()
{
	if (m_nSize == 0)
		printf("-1\n");
	else
		printf("%d\n", m_vDeque[m_nBackIndex]);
}

