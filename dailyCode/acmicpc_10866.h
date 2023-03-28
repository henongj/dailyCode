#pragma once


//https://www.acmicpc.net/problem/10866
//µ¦
#include<iostream>
#include<vector>
class DEQUE
{
private:
	int nSize;
	int nFront;
	int nEnd;
	std::vector<int> vDeque;
public:
	DEQUE(void) = default;
	void init(void);
	void push_front(int nNum);
	void push_back(int nNum);
	void pop_front();
	void pop_back();
	int size();
	bool empty();
	int front();
	int back();
};



void acmicpc_10866(void)
{
	DEQUE c_deque{};
	c_deque.init();
	int nCommandNum{};
	std::string strCommand{};


	std::cin >> nCommandNum;

	for (int i = 0; i < nCommandNum; i++)
	{
		std::cin >> strCommand;
		if (strCommand == "push_front")
		{
			int nNum{};
			std::cin >> nNum;
			c_deque.push_front(nNum);
		}
		else if (strCommand == "push_back")
		{
			int nNum{};
			std::cin >> nNum;
			c_deque.push_back(nNum);
		}
		else if (strCommand == "pop_front")
		{
			c_deque.pop_front();
		}
		else if (strCommand == "pop_back")
		{
			c_deque.pop_back();
		}
		else if (strCommand == "size")
		{
			c_deque.size();
		}
		else if (strCommand == "empty")
		{
			c_deque.empty();
		}
		else if (strCommand == "front")
		{
			c_deque.front();
		}
		else if (strCommand == "back")
		{
			c_deque.back();
		}
	}

}




void DEQUE::init(void)
{
	vDeque.clear();
	nSize = 0;
	nFront = -1;
	nEnd = -1;
}

void DEQUE::push_front(int nNum)
{
	if (vDeque.empty())
	{
		nFront = 0;
		vDeque.push_back(nNum);
	}
	else
		vDeque.insert(vDeque.begin(), nNum);

	nSize++;
	nEnd++;
}

void DEQUE::push_back(int nNum)
{
	if (vDeque.empty())
		nFront = 0;
	vDeque.push_back(nNum);
	nEnd++;
	nSize++;
}



void DEQUE::pop_front()
{
	if (vDeque.empty())
		printf("-1\n");
	else
	{
		printf("%d\n", vDeque.front());
		vDeque.erase(vDeque.begin());
		nSize--;
		nEnd--;
	}


}

void DEQUE::pop_back()
{
	if (vDeque.empty())
		printf("-1\n");
	else
	{
		printf("%d\n", vDeque.back());
		vDeque.pop_back();
		nSize--;
		nEnd--;
	}
}

int DEQUE::size()
{
	printf("%d\n", nSize);
	return nSize;
}

bool DEQUE::empty()
{
	bool bFlag{};

	bFlag = (nSize == 0);

	if (bFlag)
		printf("1\n");
	else
		printf("0\n");

	return bFlag;
}

int DEQUE::front()
{
	if (vDeque.empty())
		printf("-1\n");
	else
		printf("%d\n", vDeque.front());

	return nFront;
}

int DEQUE::back()
{
	if (vDeque.empty())
		printf("-1\n");
	else
		printf("%d\n", vDeque.back());
	return nEnd;
}
