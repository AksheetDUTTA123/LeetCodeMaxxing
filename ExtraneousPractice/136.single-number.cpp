#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int single = 0;
        for(int num : nums){
            single = single ^ num;
        }
        return single;
    }
};
// @lc code=end

