#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1056 lang=cpp
 *
 * [1056] Confusing Number
 */

// @lc code=start
class Solution {
public:
    bool confusingNumber(int n) {
        string holder = "";
        string num = to_string(n);
        for(int i = 0; i < num.length(); i++){
            if (num[i] == '0'){
                holder += "0";
            }
            else if (num[i] == '1'){
                holder += "1";
            }
            else if (num[i] == '6'){
                holder += "9";
            }
            else if (num[i] == '8'){
                holder += "8";
            }
            else if (num[i] == '9'){
                holder += "6";
            }
            else{
                return false;
            }
        }
        reverse(holder.begin(), holder.end());
        if(holder == num){
            return false;
        }
        return true;
    }
};
// @lc code=end

