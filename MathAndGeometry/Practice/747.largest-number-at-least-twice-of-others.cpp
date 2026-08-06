#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=747 lang=cpp
 *
 * [747] Largest Number At Least Twice of Others
 */

// @lc code=start
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largestElem = 0;
        int largestElemIndex = -1;
        int secondLargestElem = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > largestElem){
                largestElem = nums[i];
                largestElemIndex = i;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > secondLargestElem && nums[i] != largestElem){
                secondLargestElem = nums[i];
            }
        }
        if(secondLargestElem * 2 > largestElem) return -1;
        else return largestElemIndex;
    }
};
// @lc code=end

