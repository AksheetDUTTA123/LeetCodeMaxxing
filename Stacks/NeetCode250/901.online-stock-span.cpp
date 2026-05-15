#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */

// @lc code=start
class StockSpanner {
public:
    StockSpanner() {
        //dont need to do anything here
    }
    
    int next(int price) {
        int countCheck= 1;
            while(!Stk.empty() && price >= Stk.top().first){
                countCheck += Stk.top().second;
                Stk.pop();
            }
            Stk.push({price, countCheck});
            return countCheck;
    }
private:
    stack<pair<int, int>> Stk; //insight, score both the price and the span, 
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

