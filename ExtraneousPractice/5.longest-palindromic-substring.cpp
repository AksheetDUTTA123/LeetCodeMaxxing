#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
private:
string PalindromeCheck(string& str, int idxL, int idxR){
    while(idxL >= 0 && idxR < str.length() && str[idxL] == str[idxR]){
                idxL--;
                idxR++;
    }
    return str.substr(idxL + 1, idxR - idxL - 1);
}
public:
    string longestPalindrome(string s) {
        string longestStr = "";
        for(int i = 0; i < s.length(); i++){
            string longestPossOdd = PalindromeCheck(s, i, i);
            string longestPossEven = PalindromeCheck(s, i, i + 1);
            if(longestPossOdd.length() > longestStr.length()) longestStr = longestPossOdd;
            if(longestPossEven.length() > longestStr.length()) longestStr = longestPossEven;
        }
        return longestStr;
    }
};
// @lc code=end

