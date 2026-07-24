#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */

// @lc code=start
class StockSpanner {
private:
    stack<pair<int, int>> s;
    int idx = 0;
public:
    StockSpanner() {
        //dont need to do anything here
    }
    
    int next(int price) {
        idx++;
        if(s.empty()){
            s.push({price, idx});
            return 1;
        }

        while(!s.empty()){
            auto top = s.top();
            if(top.first <= price) {
                s.pop();
               continue;
            }
            else{
                s.push({price, idx});
                return idx - top.second;
            }
        }
        //if stack becomes empty, need to push still
        s.push({price, idx});
        return idx;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

