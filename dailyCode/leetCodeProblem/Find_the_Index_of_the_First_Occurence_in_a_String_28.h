//https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/?envType=study-plan&id=programming-skills-ii
//28. Find the Index of the First Occurrence in a String
#ifndef ___Find_the_Index_of_the_First_Occurence_in_a_String_28_h___
#define ___Find_the_Index_of_the_First_Occurence_in_a_String_28_h___
#include<algorithm>
#include<iostream>
#include<map>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {

        int idx = haystack.find(needle);

        if (idx == haystack.length())
            return -1;

        return idx;
    }
};
#endif //___Find_the_Index_of_the_First_Occurence_in_a_String