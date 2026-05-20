#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
    while(left <= right){
        int currIndex = left + (right - left) / 2;
        if(nums[currIndex] == target){
            return currIndex;
        }
        else if(nums[currIndex] < target){
            left = currIndex+ 1;
        }
        else{
            right = currIndex - 1;
        }
}
        return -1;
    }
};
// @lc code=end

