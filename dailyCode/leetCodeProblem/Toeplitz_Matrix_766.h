#ifndef ___Toeplitz_Matrix_h___
#define ___Toeplitz_Matrix_h___

#include<iostream>
#incldue<string>
using namespace std;
class Solution {
public:
    bool isInside(const vector<vector<int>> v, int ypos, int xpos)
    {
        return 0 <= ypos && ypos < v.size() && 0 <= xpos && xpos < v[0].size();
    }
    bool isSame(const vector<vector<int>> v, int ypos, int xpos)
    {
        if (!isInside(v, ypos + 1, xpos + 1)) return true;

        if (v[ypos][xpos] != v[ypos + 1][xpos + 1]) return false;

        bool a = isSame(v, ypos + 1, xpos + 1);

        return a;
    }

    bool isToeplitzMatrix(vector<vector<int>>& matrix) {

        for (int i = 0; i < matrix.size(); i++)
        {
            if (!isSame(matrix, i, 0))
                return false;
        }
        for (int i = 0; i < matrix[0].size(); i++)
        {
            if (!isSame(matrix, 0, i))
                return false;
        }

        return true;
    }
};


#endif