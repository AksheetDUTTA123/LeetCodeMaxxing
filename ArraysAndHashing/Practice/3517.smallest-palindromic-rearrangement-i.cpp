#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3517 lang=cpp
 *
 * [3517] Smallest Palindromic Rearrangement I
 */

// @lc code=start
class Solution {
public:
    string smallestPalindrome(string s) {
        if(s.length() == 1) return s;
        if(s.length() % 2 == 0){
            string firstHalf = s.substr(0, s.length() / 2); //get the substr first, then sort
            sort(firstHalf.begin(), firstHalf.end());
            string reverseHalf = std::string(firstHalf.rbegin(), firstHalf.rend());
            return firstHalf + reverseHalf;
        }
        else{
            string firstHalf = s.substr(0, (s.length() / 2));
            sort(firstHalf.begin(), firstHalf.end());
            string reverseHalf = std::string(firstHalf.rbegin(), firstHalf.rend());
            return firstHalf + s[s.length() / 2] + reverseHalf;
        }
    }
};
// @lc code=end

