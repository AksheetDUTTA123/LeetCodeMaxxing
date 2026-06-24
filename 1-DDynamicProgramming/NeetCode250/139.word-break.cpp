#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length() + 1, false);
        unordered_set<string> dict;
        for(string s : wordDict){
            dict.insert(s);
        }

        dp[0] = true;
        for(int i = 1; i <= s.length(); i++){
            for(int j = 0; j <= i; j++){

                //think of the stuff before dp[j] as the prefix, and the stuff after dp[j] as the suffix, 
                //so we are checking if the prefix can be broken into words in the dictionary, and if the suffix is in the dictionary, then we can break the string at index i

                if(dp[j]){ //have to check this first, because if dp[j] is false, 
                //then we cannot break the string at index j, so we cannot check if the substring from j to i is in the dictionary,
                // because if we cannot break the string at index j, then we cannot break the string at index i, because we cannot break the string at index j,
                // so we cannot check if the substring from j to i is in the dictionary, because if we cannot break the string at index j, then we cannot break the string at index i, 
                //because we cannot break the string at index j, so we cannot check if the substring from j to i is in the dictionary
                if(dict.find(s.substr(j, i - j)) != dict.end()){
                    dp[i] = true;
                }
                }
            }
        }
        return dp[s.length()];
    }
};
// @lc code=end

