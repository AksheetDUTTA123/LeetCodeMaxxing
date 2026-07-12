#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        string res = "";
        if (num1 == "0" || num2 == "0") return "0"; //if either number is 0, the product is 0
        vector<int> product(num1.length() + num2.length(), 0); //the maximum length of the product of two numbers is the sum of their lengths
        for(int i = num1.length() -1; i >= 0; i--){
            for(int j = num2.length() - 1; j >= 0; j--){
                product[i + j + 1] += (num1[i] - '0') * (num2[j] - '0'); //we add the product of the two digits to the appropriate index in the product vector
                product[i+j] += product[i+j+1] / 10; //we add the carry to the next index
                product[i + j + 1] %= 10; //we keep only the last digit in the current index
            }
        }

        for(int i = 0; i < product.size(); i++){
            if((product[i] == 0) && res.length() == 0) continue; //skip leading zeros
                res += to_string(product[i]);
        }
        return res;
    }
};
// @lc code=end

