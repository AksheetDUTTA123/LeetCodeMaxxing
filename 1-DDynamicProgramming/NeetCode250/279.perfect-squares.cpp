#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
//this is a derivation of coin change
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 9999);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= n; j++){
                if(i - (j*j) >= 0) dp[i] = min(dp[i], dp[i - (j*j)] + 1);
            }
        }
        return dp[n];
    }
};
// @lc code=end

