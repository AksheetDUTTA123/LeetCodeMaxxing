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
        vector<int> dp(s.length() + 1, 0);

        if(s[0] == '0') return 0; //if the first character is 0, there are no ways to decode it
        dp[0] = 1; //empty string base case
        dp[1] = 1; //first number base case
        for(int i = 2; i <= s.length(); i++){
           if(s[i-1] != '0'){
            dp[i] += dp[i-1]; //if the current character is not 0, we can decode it as a letter, so we add the number of ways to decode the string up to i-1
           }
           int twoDigit = stoi(s.substr(i - 2, 2));
           if(twoDigit >= 10 && twoDigit <= 26){
            dp[i] += dp[i-2]; //if the two digit number is between 10 and 26, we can decode it as a letter, 
            //so we add the number of ways to decode the string up to i-2, we use i - 2 because we are looking at the two digit number that ends 
            //at index i-1, so we need to look at the number of ways to decode the string up to i-2
           }
        }
        return dp[s.length()];
    }
};
// @lc code=end

