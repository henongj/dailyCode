#ifndef ___Average_Salary_Excluding_the_Minimum_and_Maximum_Salary_1491_h___
#define ___Average_Salary_Excluding_the_Minimum_and_Maximum_Salary_1491_h___

#include<iostream>
#include<vector>
https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/submissions/
struct testCase {
    //[48000,59000,99000,13000,78000,45000,31000,17000,39000,37000,93000,77000,33000,28000,4000,54000,67000,6000,1000,11000]
    //41111.11111
    vector<int> test_case1 = { 48000,59000,99000,13000,78000,45000,31000,17000,39000,37000,93000,77000,33000,28000,4000,54000,67000,6000,1000,11000 };  double test_case1_answer = 41111.11111;
}
class Solution {
public:
    inline int max(const int& one, const int& two)
    {
        return one < two ? two : one;
    }
    inline int min(const int& one, const int& two)
    {
        return one < two ? one : two;
    }
    double average(vector<int>& salary) {
        double maximum = 0; // max salary = 100000
        double minimum = 100000; // minimum salary = 1000
        double sum = 0;
        for (auto idx : salary)
        {
            maximum = max(maximum, idx);
            minimum = min(minimum, idx);
            sum += idx;
        }
        return (sum - maximum - minimum) / (salary.size() - 2);
    }
};

#endif // !___Average_Salary_Excluding_the_Minimum_and_Maximum_Salary_1491_h___
