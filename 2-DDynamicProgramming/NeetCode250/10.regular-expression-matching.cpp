#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        if(p.empty()) return s.empty();
        dp[0][0] = true;
        for(int i = 1; i < p.length(); i++){
            if(p[i] == '*' && dp[0][i-1]) dp[0][i+1] = true; //if the pattern has a '*' and the previous character can match the empty string, then the current character can also match the empty string
        }

        for(int i = 1; i <= s.length(); i++){
            for(int j = 1; j <= p.length(); j++){
                if(s[i-1] == p[j-1] || p[j-1] == '.'){ //if the characters match or the pattern has a '.', then the current character can match the previous character
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*'){ //if the pattern has a '*', then we can either ignore the '*' and the previous character, or we can use the '*' to match the current character
                    dp[i][j] = dp[i][j-2] || (dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
                    //dp[i][j-2] is the 0 occurences branch, we ignore the '*' and the previous character, 
                    //dp[i-1][j] is the 1 or more occurences branch, we check if the previous character in s matches the character before the '*' in p, or if the character before the '*' is a '.', then we can use the '*' to match the current character
                }
                else{
                    dp[i][j] = false;
                }

            }
        }

        return dp[s.length()][p.length()];
    }
};
// @lc code=end

