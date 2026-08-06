#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for(int i = 0; i < dp.size(); i++){
            dp[i][0] = 1;
        }
        for(int i = 0; i < dp[0].size(); i++){
            dp[0][i] = 1;
        }
        for(int i = 1; i < dp.size(); i++){
            for(int j = 1; j < dp[0].size(); j++){
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};
// @lc code=end

