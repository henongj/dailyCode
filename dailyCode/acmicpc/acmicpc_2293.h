
//https://www.acmicpc.net/problem/2293
//µ¿Àü 1
bool fIsInside(vector<int>& vDataField, int nIndex)
{
	if (nIndex < 0 || nIndex >= vDataField.size())
		return false;
	return true;
}

// incorrect answer
void fGetNumberOfCases(void)
{
	int	nNumberOfCoins{};
	int nTargetValue{};
	vector<int> vCoins{};
	vector<int> vNumberOfCases{};

	cin >> nNumberOfCoins >> nTargetValue;
	vCoins.reserve(nNumberOfCoins);
	vNumberOfCases.reserve(nTargetValue + 1);

	for (int i = 0; i < nNumberOfCoins; i++)
	{
		int nCoin{};
		cin >> nCoin;
		vCoins.push_back(nCoin);
	}

	vNumberOfCases.push_back(0);
	vNumberOfCases.push_back(1);
	for (int index = 2; index <= nTargetValue; index++)
	{
		vNumberOfCases.push_back(0);
		for (int coin = 0; coin < nNumberOfCoins; coin++)
		{
			if (fIsInside(vNumberOfCases, index - vCoins[coin]))
				vNumberOfCases[index] += vNumberOfCases[index - vCoins[coin]];
		}
	}

	cout << vNumberOfCases[nTargetValue];
}

void fGetNumberOfCases2(void)
{
	int nCoinCount{};
	int nTargetValue{};
	int nResult{};
	vector<int> vCoinValue;
	vector<int> vDataField;

	cin >> nCoinCount >> nTargetValue;
	vCoinValue.resize(nCoinCount);
	vDataField.resize(nTargetValue + 1);

	for (int i = 0; i < nCoinCount; i++)
		cin >> vCoinValue[i];

	sort(vCoinValue.begin(), vCoinValue.end());

	vDataField[0] = 1;
	for (int i = 0; i < nCoinCount; i++)
	{
		for (int j = vCoinValue[i]; j <= nTargetValue; j++)
		{
			vDataField[j] += vDataField[j - vCoinValue[i]];
		}
	}

	printf("%d", vDataField[nTargetValue]);

}