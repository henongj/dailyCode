#pragma once
#include <string>
#include <vector>
//https://leetcode.com/problems/design-browser-history/
class BrowserHistory {
public:
    std::vector<std::string>browser;
    int pos = 0;
    BrowserHistory(std::string homepage) {
        browser.push_back(homepage);
    }

    void visit(std::string url) {
        pos++;
        if (pos <= browser.size() - 1) {
            browser[pos] = url;
            browser.resize(pos + 1);
        }
        else browser.push_back(url);
    }
    std::string back(int steps) {
        pos -= steps;
        if (pos < 0)pos = 0;
        return browser[pos];
    }

    std::string forward(int steps) {
        pos += steps;
        if (pos > browser.size() - 1)pos = browser.size() - 1;
        return browser[pos];
    }
};