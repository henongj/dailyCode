
#ifndef ___Subtract_the_Product_and_Sum_of_Digits_of_an_Integer_1281_h___
#define ___Subtract_the_Product_and_Sum_of_Digits_of_an_Integer_1281_h___

/*
1281. Subtract the Product and Sum of Digits of an Integer
https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/?envType=study-plan&id=programming-skills-i

*/
class Solution {
public:
	vector<int> get_all_radix(const int& n)
	{
		vector<int> result;
		int temp = n;
		while (temp > 0)
		{
			result.push_back(temp % 10);
			temp /= 10;
		}
		return result;
	}
	int get_sum_of_vector(const vector<int>& v)
	{
		int sum = 0;
		for (auto i : v)
			sum += i;
		return sum;
	}
	int get_product_of_vector(const vector<int>& v)
	{
		int product = 1;
		for (auto i : v)
			product *= i;
		return product;
	}
    int subtractProductAndSum(int n) {
		vector<int> radixes = get_all_radix(n);
		int sub = get_product_of_vector(radixes) - get_sum_of_vector(radixes);
		return sub;
    }
};
#endif