#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=678 lang=cpp
 *
 * [678] Valid Parenthesis String
 */

// @lc code=start
class Solution {
public:
    bool checkValidString(string s) {
        int openCount = 0; //this is the count of open parentheses, we will increment it when we see an open parenthesis or a star,
        // and decrement it when we see a close parenthesis
        int closeCount = 0; //this is the count of close parentheses, we will increment it when we see a close parenthesis or a star,
        // and decrement it when we see an open parenthesis
        int length = s.length() - 1;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '*') {
                openCount++;
            }
            else{
                openCount--;
            }

            if(s[length - i] == ')' || s[length - i] == '*') {
                closeCount++;
            }
            else{
                closeCount--;
            }

            if(openCount < 0 || closeCount < 0) return false;
            //the reason this works is because we are checking the string from both ends, 
            //and we are keeping track of the number of open and close parentheses, if at any point the number of open parentheses is less than 0, it means that there are more close parentheses than open parentheses, which is invalid, and vice versa for the close parentheses.
        }
        return true;
    }
};
// @lc code=end

