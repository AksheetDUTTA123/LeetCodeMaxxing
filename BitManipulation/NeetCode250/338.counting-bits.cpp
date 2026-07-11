#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;

        for(int i = 1; i <= n; i++){
            dp[i] = dp[i & i - 1] + 1; //this is the key, this operation removes the rightmost 1 bit from i, so we can count how many 1 bits are in i by counting how many times we can do this operation before i becomes 0
        }

        return dp;
    }
};
// @lc code=end

