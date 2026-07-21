#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // vector<int> res;
        // int carry = 1; //adding 1
        // int digitsPtr = digits.size() - 1;


        // while(digitsPtr >= 0){
        //     if(digits[digitsPtr] + carry == 10){
        //         res.push_back(0);
        //         carry = 1;
        //     }
        //     else{
        //         res.push_back(digits[digitsPtr] + carry);
        //         carry = 0;
        //     }
        //     digitsPtr--;
        // }
        // if (carry == 1) res.push_back(1);
        // reverse(res.begin(), res.end());
        // return res;

        //above solution works, but we can do this in O(1) space below

        for(int i = digits.size() - 1; i >= 0; i--){
            if(digits[i] == 9){
                digits[i] = 0;
            }
            else{
                digits[i]++;
                return digits;
            }
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};
// @lc code=end


