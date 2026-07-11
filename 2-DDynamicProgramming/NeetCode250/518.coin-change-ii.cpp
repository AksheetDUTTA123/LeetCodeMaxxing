#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change II
 */

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);

        dp[0] = 1; //one way to make 0 coins
        for(int coin : coins){ //loop through coin first, and then if coin can be placed in existing amount, 
        //we add to i because with i -coin, adding a coin will get the change we want
            for(int i = coin; i <= amount; i++){
                dp[i] += dp[i - coin];
            }
        }

        return dp[amount];
    }
};
// @lc code=end

