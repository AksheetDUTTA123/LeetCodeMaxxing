#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 */

// @lc code=start
class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k >= num.length()) return "0";
        stack<char> stk; //a stack to keep track of the digits we want to keep
        string res = "";
        int resCurrLen = 0; //a variable to keep track of the current length of the result string
        for(char c : num){
                while (!stk.empty() && (c - '0') < (stk.top() - '0') && k > 0){ // here we are checking if the current digit is less than the top of the stack, and if we still have k digits to remove, then we pop the top of the stack, and decrement k
                //the digit at the top of the stack represents the last digit we have added to the result string, so if the current digit is less than the last digit we have added to the result string, then we want to remove the last digit we have added to the result string,
                // because it will make the result string smaller
                    stk.pop();
                    k--;
                }
                stk.push(c);
            }

while (!stk.empty() && k > 0){
        stk.pop();
        k--; //if we still have k digits to remove, then we pop the top of the stack, and decrement k
    }

    while(!stk.empty()){
        res += stk.top();
        stk.pop();
    }
    reverse(res.begin(), res.end());

    int startPos = 0;
    while(startPos < res.length() && res[startPos] == '0'){ //we want to remove leading zeros from the result string, 
    //so we increment the startPos variable until we find a non-zero digit
        startPos++;
    }
    res = res.substr(startPos);
    if(res.empty()) return "0";
    return res;
    }
};
// @lc code=end

