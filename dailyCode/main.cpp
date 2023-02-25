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

void funcGetGMS(void);
bool getQuotientFourSeven(int nNumber, int* pFour, int* pSeven);
void expressNumberForSevenAndFour(int nFourQuotient, int nSevenQuotient, vector<int>* vResult);
void getNumberDigit(int nNumber, size_t* pDigit);

int main(void)
{

	funcGetGMS();

	return 0;
}


void funcGetGMS(void)
{
	int nNumber{};
	int nSevenQuotient{};
	int nFourQuotient{};
	bool isGMS{};

	vector<int> vecGMS{};
	vecGMS.reserve(1000);

	cin >> nNumber;

	isGMS = getQuotientFourSeven(nNumber, &nFourQuotient, &nSevenQuotient);

	if (isGMS == false)
	{
		cout << "-1";
		return;
	}

	// ���� 4�� 7�� ������, 4�� 7�θ� �̷���� ���� ǥ���Ѵ�
	expressNumberForSevenAndFour(nFourQuotient, nSevenQuotient, &vecGMS);
	sort(vecGMS.begin(), vecGMS.end());
	
	//���
	for (auto iter = vecGMS.begin(); iter != vecGMS.end(); ++iter)
	{
		cout << *iter << " ";
	}

}

bool getQuotientFourSeven(int nNumber, int* pFour, int* pSeven)
{
	if(nNumber < 4)
		return false;

	int nSevenQuotient{};
	int nFourQuotient{};

	int nFourRemainder{};
	int nSevenRemainder{};

	// 4�� ���� ��, ������
	nFourQuotient = nNumber / 4;
	nFourRemainder = nNumber % 4;

	// 4�� ������ �������� �ʴ� ���, ���� 1�� ���̸鼭 �������� 4�� ���ϰ� 7�� ������ ���������� Ȯ��
	while (nFourQuotient >= 0)
	{
		nSevenQuotient = nFourRemainder / 7;
		nSevenRemainder = nFourRemainder % 7;

		if (nSevenRemainder == 0)
			break;

		nFourQuotient--;
		nFourRemainder += 4;
	}

	// ���� �� ���� ���
	if (nNumber == nFourRemainder - 4)
		return false;

	*pFour = nFourQuotient;
	*pSeven = nSevenQuotient;

	return true;
}

void expressNumberForSevenAndFour(int nFourQuotient, int nSevenQuotient, vector<int>* vResult)
{
	vector<int> vDigit{};
	size_t nDigitIndex{};

	size_t nDigitFour{};
	size_t nDigitSeven{};
	size_t nBigDigit{};
	size_t nSmallDigit{};

	vResult->reserve(1000);
	vDigit.reserve(10);
	vDigit = { 0,1,10,100,1000,10000,100000,1000000,10000000, 1000000000 };

	getNumberDigit(nFourQuotient, &nDigitFour);
	getNumberDigit(nSevenQuotient, &nDigitSeven);
	nBigDigit = max(nDigitFour, nDigitSeven);
	nSmallDigit = min(nDigitFour, nDigitSeven);

	//2. nFourQuotient�� nSevenQuotient�� �ִ��� ū ���� ���� result�� ���δ�
	while (nFourQuotient != 0 || nSevenQuotient != 0)
	{
		int nNumber{};
		
		nDigitIndex = 9;
		nNumber = 0;
		for (nDigitIndex; nDigitIndex > 0; nDigitIndex--)
		{
			if (nSevenQuotient >= vDigit[nDigitIndex])
			{
				nNumber += (7 * vDigit[nDigitIndex]);
				nSevenQuotient -= vDigit[nDigitIndex];
				continue;
			}
			if (nFourQuotient >= vDigit[nDigitIndex])
			{
				nNumber += (4 * vDigit[nDigitIndex]);
				nFourQuotient -= vDigit[nDigitIndex];
				continue;
			}
		}
		
		vResult->push_back(nNumber);
	}
	
	//3. nFourQuotient nSevenQuotient �� 0�� �� ������ 2�� �ݺ��Ѵ�

}

void getNumberDigit(int nNumber, size_t* pDigit)
{
	string strNumber{};
	strNumber = to_string(nNumber);
	*pDigit = strNumber.length();
}

