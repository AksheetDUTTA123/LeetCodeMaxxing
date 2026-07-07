#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> lcs(text1.length() + 1, vector<int>(text2.length() + 1, 0));
        lcs[0][0] = 0;

        for(int i = 1; i <= text1.length(); i++){
            for(int j = 1 ; j <= text2.length(); j++){
                if(text1[i-1] == text2[j-1]){
                    lcs[i][j] = lcs[i-1][j-1] + 1; //this is a match, we look diagonally up left and add 1, new character to substr
//                     If the characters are the same, it means this letter can be part of our common subsequence! We take the longest subsequence length we had before discovering this letter and add 1 to it.
// Where was that previous length? Diagonally up and to the left!
                }
                else{
                    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]); //musmatch, take the best from the top or the left
                    //The best we can do is inherit the maximum common subsequence found so far by
                    // either ignoring the current character of text1 or ignoring the current character of text2.
                }
            }
        }
        return lcs[text1.length()][text2.length()];
    }
};
// @lc code=end

