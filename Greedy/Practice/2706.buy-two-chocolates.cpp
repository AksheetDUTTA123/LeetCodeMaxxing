#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=2706 lang=cpp
 *
 * [2706] Buy Two Chocolates
 */

// @lc code=start
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int minPrice1 = INT_MAX;
        int minPrice2 = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < minPrice1){
                minPrice2 = minPrice1;
                minPrice1 = prices[i];
            }
            else if(prices[i] < minPrice2){
                minPrice2 = prices[i];
            }
        }
        int currPrice = minPrice1 + minPrice2;
        if(currPrice > money) return money;
        else{
            return money - currPrice;
        }
    }
};
// @lc code=end

