#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1464 lang=cpp
 *
 * [1464] Maximum Product of Two Elements in an Array
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int firstMax = INT_MIN;
        int firstIdx = -1;
        int secondMax = INT_MIN;
        int secondIdx = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > firstMax){
                firstMax = nums[i];
                firstIdx = i;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > secondMax && i != firstIdx){
                secondMax = nums[i];
                secondIdx = i;
            }
        }
        return (secondMax-1)*(firstMax-1);
    }
};
// @lc code=end

