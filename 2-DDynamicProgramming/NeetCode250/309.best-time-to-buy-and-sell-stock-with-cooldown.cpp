#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //three states, hold, sold, cooldown

        int hold = -prices[0]; //max profit if we buy on day 0
        int sold  = 0; //we cant sell on day 0, so max profit is 0
        int rest = 0; //cant rest on day 0, max profit is 0;

        //max profit can only be achieved by selling or resting, keep that in mind

        for (int i = 1; i < prices.size(); i++){
            int prevSold = sold; //store this because we will need it to update the rest state
            hold = max(hold, rest - prices[i]); //either keep holding or we buy today
            sold = hold + prices[i]; //we can only sell if we are holding, so we add the price to the hold state
            rest = max(rest, prevSold); //rest represents doing nothing today and we just move our cash yesterday. PrevSold is if we sold yesterday, we must rest today and move that cash forward

            //if prevSold is higher, it means we sold yesterday and we must rest today, so we move that cash forward. If rest is higher, it means we did nothing yesterday and we can continue to do nothing today, so we keep that cash forward
        }

        return max(sold, rest); //we return the max of sold and rest because we cant be holding at the end, we want to maximize profit
    }
};
// @lc code=end

