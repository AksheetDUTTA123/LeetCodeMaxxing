#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= s.length(); i++){
            if(s[i-1] >= '1' && s[i-1] <= '9'){
                dp[i] += dp[i- 1];
            }
            int twoDigit = stoi(s.substr(i-2, 2));
            if(twoDigit >= 10 && twoDigit <= 26){
                dp[i] += dp[i-2];
            }
        }
        return dp[s.length()];
    }
};
// @lc code=end

