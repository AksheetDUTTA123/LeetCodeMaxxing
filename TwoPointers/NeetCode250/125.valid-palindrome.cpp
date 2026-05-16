#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        string result = "";
        for(char &c : s){
            if(isalnum(static_cast<unsigned char>(c))){
                result += tolower(c);
            }
        }
        for(int i = 0; i < result.size() / 2; i++){
            if(result[i] != result[(result.size()-1) - i]){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

