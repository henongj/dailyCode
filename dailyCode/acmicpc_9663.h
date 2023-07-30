#pragma once
//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>
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
#include <fstream>
#include<functional>
//https://www.acmicpc.net/problem/9663
//N-Queen
namespace acmicpc_9663{
    bool isPromising(int nRow, const std::vector<int>& vQueen);
    void dfs(int nRow, int nNumber, std::vector<int>& vQueen, int& nCount);
    void solution_acmicpc9663(void);

    int mainSpace_acmicpc9663(void)
    {
        //_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
        solution_acmicpc9663();
        return 0;
    }

    void solution_acmicpc9663(void) {
        int nNumber{};
        int nCount{};

        std::cin >> nNumber;

        std::vector<int> vQueen(nNumber, 0);

        dfs(0, nNumber, vQueen, nCount);

        std::cout << nCount << "\n";
    }

    bool isPromising(int nRow, const std::vector<int>& vQueen) {
        for (int i = 0; i < nRow; ++i) {
            if (vQueen[i] == vQueen[nRow] || std::abs(vQueen[i] - vQueen[nRow]) == nRow - i) {
                return false;
            }
        }
        return true;
    }

    void dfs(int nRow, int nNumber, std::vector<int>& vQueen, int& nCount) {
        if (nRow == nNumber) {
            ++nCount;
            return;
        }

        for (int i = 0; i < nNumber; ++i) {
            vQueen[nRow] = i;
            if (isPromising(nRow, vQueen)) {
                dfs(nRow + 1, nNumber, vQueen, nCount);
            }
        }
    }
}
