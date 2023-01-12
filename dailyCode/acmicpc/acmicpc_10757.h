
//https://www.acmicpc.net/problem/10757
//Å« ¼ö A+B
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
using namespace std;
#ifndef ___acmicpc_10757_h___
#define ___acmicpc_10757_h___
void addBigNumber(void)
{
	string a, b;
	cin >> a >> b;
	int aSize = a.size();
	int bSize = b.size();
	int max = aSize > bSize ? aSize : bSize;

	//make string to store result
	string result(max, '0');

	//add big number
	int carry = 0;
	for (int i = 0; i < max; i++)
	{
		int aNum = 0;
		int bNum = 0;
		if (i < aSize)
		{
			aNum = a[aSize - 1 - i] - '0';
		}
		if (i < bSize)
		{
			bNum = b[bSize - 1 - i] - '0';
		}
		int sum = aNum + bNum + carry;
		carry = sum / 10;
		result[max - 1 - i] = sum % 10 + '0';
	}
	if (carry > 0)
	{
		result.insert(result.begin(), carry + '0');
	}
	cout << result << endl;

}
/*
int main() {
	addBigNumber();
	return 0;
}
*/
#endif // ___acmicpc_10757_h___