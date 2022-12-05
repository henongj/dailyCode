
//https://leetcode.com/problems/fibonacci-number/?envType=study-plan&id=dynamic-programming-i
//509. Fibonacci Number
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
using namespace std;
#ifndef ___Fibonacchi_Number_509_h___
#define ___Fibonacchi_Number_509_h___
class Solution {
public:
    void get_fibonacchi_number(int target, int* memo)
    {
        // F(n) = F(n - 1) + F(n - 2), for n > 1. 이고
        // target -1 target-2 0이 아닐 때까지 재귀
        cout << "target : " << target << "\n";
        if (memo[target - 2] == 0 || memo[target - 1] == 0)
            get_fibonacchi_number(target - 1, memo);

        memo[target] = memo[target - 2] + memo[target - 1];
    }

    int fib(int n) {
        int memo[100] = { 0 };
        memo[1] = 1;
        memo[2] = 1;

        if (n == 0)
            return 0;
        else
            get_fibonacchi_number(n, memo);

        return memo[n];
    }
};


#endif // ___Fibonacchi_Number_509_h___
