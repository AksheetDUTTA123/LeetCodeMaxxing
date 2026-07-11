#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        if(n == 0) return m;
        if (m == 0) return n;
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0)); //dp[i][j] = min distance to convert word1[0..i-1] to word2[0..j-1]

        dp[0][0] = 0; //base case, if both strings are empty, distance is 0

        for(int i = 1; i <= n; i++){
            dp[i][0] = i; //if word2 is empty, we need to delete all characters from word1
        }
        for(int i = 1; i <= m; i++){
           dp[0][i] = i; //if word1 is empty, we need to insert all characters from word2
        }

        for(int i = 1; i <= n ; i++){
            for(int j = 1; j <= m; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1]; //if the characters are the same, we don't need to do anything
                }
                else{
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}); //if the characters are different, we need to either delete, insert, or replace a character
                    // dp[i-1][j] = delete, dp[i][j-1] = insert, dp[i-1][j-1] = replace
                    //i-1 is the previous character in word1, j-1 is the previous character in word2, so we are looking at the minimum distance to convert the previous characters and adding 1 for the current operation
                }
            }
        }

        return dp[n][m];
    }
};
// @lc code=end

