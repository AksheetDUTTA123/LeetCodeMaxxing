#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyTime = 0;
        int sellTime = 1;
        int maxProfit = 0;
        for(; sellTime < prices.size(); sellTime++){
            if(prices[buyTime] < prices[sellTime]){
                maxProfit = max(maxProfit, prices[sellTime] - prices[buyTime]); //if price at buy is less than sell, then profit could be made, check if it is the biggest so far
            }
            else{
                buyTime = sellTime; //found a cheaper price, so this becomes the new buy price
            }
        }
        return maxProfit;
    }
};
// @lc code=end

