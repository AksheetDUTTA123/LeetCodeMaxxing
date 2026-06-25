#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= i; j++){
                if(i - j >= 0) dp[i] = max(dp[i], max(j *dp[i -j], j * (i-j)));
                //this is the logic, we are trying to break the number i into two parts, j and i-j, and we are trying to find the maximum product of these two parts. 
                //We are also trying to find the maximum product of j and the maximum product of i-j, which is dp[i-j]. We are also trying to find the maximum product of j and i-j,
                // which is j * (i-j). We are taking the maximum of these two products and storing it in dp[i].
                //logically, j * (i - j) would be the max if we dont break up the remainder, and j * dp[i - j] would be the max if we break up the remainder. 
                //So we are taking the max of these two products and storing it in dp[i].
            }
        }
        return dp[n];
    }
};
// @lc code=end

