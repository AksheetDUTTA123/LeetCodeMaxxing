#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        string currMax = "";
        int currMaxLength = 0;
        int l = 0;
        int r = 0;
        for(int i = 0; i < s.length(); i++){ 
                l = i; //for odd length palindromes, we can start with the center at i and expand outwards
                r = i;
                while(l >= 0 && r < s.length() && s[l] == s[r]){
                    if((r - l + 1) > currMaxLength){
                        currMaxLength = r - l + 1;
                        currMax = s.substr(l, currMaxLength);
                    }
                    l--;
                    r++;
                }

                l = i; //for even length palindromes, we can start with the center at i and i + 1 and expand outwards
                r = i + 1;
                while(l >= 0 && r < s.length() && s[l] == s[r]){
                    if((r - l + 1) > currMaxLength){
                        currMaxLength = r - l + 1;
                        currMax = s.substr(l, currMaxLength);
                    }
                    l--;
                    r++;
                }
        }
        return currMax;
    }
};
// @lc code=end

