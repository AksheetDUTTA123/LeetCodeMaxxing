#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1472 lang=cpp
 *
 * [1472] Design Browser History
 */

// @lc code=start
//i did this with two stacks, but even more optimal way is to use a vector and a curr tracker

class BrowserHistory {
// stack<string> BackHistory;
// stack<string> ForwardHistory;
vector<string> history;
int curr;
public:
    BrowserHistory(string homepage) {
        // BackHistory.push(homepage);
        history.push_back(homepage);
        curr = 0;
    }
    
    void visit(string url) {
        // BackHistory.push(url);
        // while(!ForwardHistory.empty()) ForwardHistory.pop();
        history.resize(curr + 1);
        history.push_back(url);
        curr++;
    }
    
    string back(int steps) {
        // int x = steps;
        // if(steps >= BackHistory.size()) x = BackHistory.size() - 1;
        // for(int i = 0; i < x; i++){
        //     auto top = BackHistory.top();
        //     BackHistory.pop();
        //     ForwardHistory.push(top);
        // }
        // return BackHistory.top();
        if(steps > curr) steps = curr;
        curr -= steps;
        return history[curr];
    }
    
    string forward(int steps) {
        // int x = steps;
        // if(steps > ForwardHistory.size()) x = ForwardHistory.size();
        // for(int i = 0; i < x; i++){
        //     auto top = ForwardHistory.top();
        //     ForwardHistory.pop();
        //     BackHistory.push(top);
        // }
        // return BackHistory.top();
        if(steps + curr >= history.size()) steps = history.size() - curr - 1;
        curr += steps;
        return history[(curr)];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
// @lc code=end

