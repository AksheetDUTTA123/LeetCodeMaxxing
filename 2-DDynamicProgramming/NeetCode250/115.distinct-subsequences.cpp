#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        int sLen = s.length();
        int tLen = t.length();

        vector<vector<unsigned long long>> dp(sLen + 1, vector<unsigned long long>(tLen + 1, 0)); //dp[i][j] = number of distinct subsequences of s[0..i-1] which equals t[0..j-1]


        //base case
        for(int i = 0; i < dp.size(); i++){
            dp[i][0] = 1; //if t is empty, there is one subsequence of s that equals t, which is the empty subsequence
        }


        for(int i = 1; i <= sLen; i++){
            for(int j = 1; j <= tLen; j++){
                if(s[i-1] == t[j-1]){ //if the characters match, we can either use the character or not use the character
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j]; //if we use the character, we look at the previous characters in both strings, if we don't use the character, we look at the previous characters in s only
                    //dp[i-1][j-1] represents the number of distinct subsequences of s[0..i-2] which equals t[0..j-2], and dp[i-1][j] represents the number of distinct subsequences of s[0..i-2] which equals t[0..j-1]
                    //  dp[i-1][j] is skip it, preserve what we already have, dp[i-1][j-1] is use it, add to what we already have
                }
                else{
                    dp[i][j] = dp[i-1][j]; //if the characters don't match, we can only not use the character in s

                }
            }
        }
        return (int) dp[sLen][tLen];
    }
};
// @lc code=end

