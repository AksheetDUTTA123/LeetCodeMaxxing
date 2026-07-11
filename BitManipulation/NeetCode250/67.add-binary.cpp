#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int AIdx = a.length() - 1;
        int BIdx = b.length() - 1;
        string res = "";
        int carry = 0;
        while(AIdx >= 0 || BIdx>=0 || carry > 0){
            int sum = carry;
            if(AIdx >= 0){
                sum += (a[AIdx] - '0');
                AIdx--;
            }
            if(BIdx >= 0){
                sum += (b[BIdx] - '0');
                BIdx--;
            }

            res.push_back((sum % 2) + '0');
            carry = sum / 2; //if sum = 2, carry = 1, if not, 0
        }

        reverse(res.begin(), res.end());
        return res;

    }
};
// @lc code=end

