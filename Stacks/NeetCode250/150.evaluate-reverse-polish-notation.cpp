#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> tokenStk;
        for(int i = 0; i < tokens.size(); i++){
        if(tokens[i] != "+" &&
        tokens[i] != "-" &&
        tokens[i] != "*" &&
        tokens[i] != "/" 
        )  {
            tokenStk.push(std::stoi(tokens[i]));
            continue;
        }

            int num1 = tokenStk.top();
            tokenStk.pop();
            int num2 = tokenStk.top();
            tokenStk.pop();
        if(tokens[i] == "+"){
            tokenStk.push(num1+num2);
        }
        else if(tokens[i] == "-"){
            tokenStk.push(num2-num1);
        }
        else if(tokens[i] == "*"){
            tokenStk.push(num1*num2);
        }
        else{
            tokenStk.push(num2/num1);
        }
        }

        return tokenStk.top();
    }
};
// @lc code=end

