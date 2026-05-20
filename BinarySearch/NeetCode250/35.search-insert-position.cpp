#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        //int returnIdx = 0;
        while(left <= right){
            int currIndex = left + (right - left)/2;
            if(nums[currIndex] == target){
                return currIndex;
            }
            else if(nums[currIndex] < target){
                left = currIndex + 1;
            }
            else{
                right = currIndex - 1;
            }
        }
        return left; //left is the index where the target would be inserted, 
        //because if the target is not found in the array, left will end up being the index of the first element that is greater than the target, 
        //which is where the target should be inserted to maintain the sorted order of the array.

        /*
        Key Pattern:

Notice that left always ends up at the correct insertion position:

When target is smaller than all elements → left stays 0
When target belongs between two elements → left points to where it should go
When target is larger than all elements → left becomes nums.size()
        */

    }
};
// @lc code=end

