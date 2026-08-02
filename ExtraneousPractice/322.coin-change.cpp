#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int coin : coins){
                if(i >= coin){
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }
        if(dp[amount] == amount + 1) return -1;
        return dp[amount];
    }
};
// @lc code=end

