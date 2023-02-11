#pragma once
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

//https://www.acmicpc.net/problem/25304
//¿µ¼öÁõ
void fDataInput(int& nSumOfProduct, int& nNumOfProduct, vector<pair<int, int>>& vProducts)
{
	cin >> nSumOfProduct;
	cin >> nNumOfProduct;

	vProducts.reserve(nNumOfProduct);
	for (int i = 0; i < nNumOfProduct; i++)
	{
		int nPrice;
		int nNum;
		cin >> nPrice;
		cin >> nNum;
		vProducts.push_back(pair<int, int>(nPrice, nNum));
	}
}

void fGetSumOfProducts(int& nSum, const vector<pair<int, int>>& vProducts)
{
	nSum = 0;
	int nSizeOfProducts = vProducts.size();
	for (int i = 0; i < nSizeOfProducts; i++)
	{
		nSum = nSum + (vProducts[i].first * vProducts[i].second);
	}
}

/*
int main(void)
{
	int nSumOfProductInReceipt;
	int nNumOfProduct;
	int nSumOfCalculatedProduct;
	vector<pair<int, int>> vProducts;
	fDataInput(nSumOfProductInReceipt, nNumOfProduct, vProducts);
	fGetSumOfProducts(nSumOfCalculatedProduct, vProducts);

	if(nSumOfProductInReceipt == nSumOfCalculatedProduct)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}

*/

