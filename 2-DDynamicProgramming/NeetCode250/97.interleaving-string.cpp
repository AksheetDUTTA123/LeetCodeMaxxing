#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()) return false;

        //make a 2d dp array, where dp[i][j] is true if s3[0..i+j-1] is an interleaving of s1[0..i-1] and s2[0..j-1]
        vector<vector<bool>> dp(s1.length() + 1, vector<bool>(s2.length() + 1, false));

        dp[0][0] = true; //base case

        for(int i = 1; i < dp.size(); i++){
            dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1]; //if the previous state is true and the current character in s1 matches the current character in s3, then the current state is true
        }

        for(int i = 1; i < dp[0].size(); i++){
            dp[0][i] = dp[0][i-1] && s2[i-1] == s3[i-1]; //if the previous state is true and the current character in s2 matches the current character in s3, then the current state is true
        }
        for(int i = 1; i < dp.size(); i++){
            for(int j = 1; j < dp[0].size(); j++){
                dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
                 //if the previous state is true and the current character in s1 or s2 matches the current character in s3, then the current state is true
            }
        }



        return dp[s1.length()][s2.length()];
    }
};
// @lc code=end

