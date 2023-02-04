
//https://www.acmicpc.net/problem/2525
//¿Àºì ½Ã°è

void fGetEndTimeOfCook(void)
{
	int nHour{};
	int nMinute{};
	int nCookTime{};

	cin >> nHour >> nMinute >> nCookTime;

	nMinute += nCookTime;
	nHour += nMinute / 60;
	nMinute %= 60;
	nHour %= 24;

	cout << nHour << " " << nMinute;
}