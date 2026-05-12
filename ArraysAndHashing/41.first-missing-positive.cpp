#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){ //go thru the nums array
            while(nums[i] >= 1 && nums[i] <= nums.size() && nums[nums[i]- 1] != nums[i]){ //check validity for if you can swap
            //1 or greater (positive) less than/equal to nums size (so it can be indexed properly in a 1-indexed array)
            //and check if the value at the index you want to swap to if nums[6] = 3, check if nums[2] has 3 in it or not already
                swap(nums[i], nums[nums[i]- 1]);
            }
        }
        for(int i= 0; i < nums.size(); i++ ){ //validation loop
            if(nums[i] != i+1){ //check if index has the right value, remember c++ vectors are 0 indexed, so have to check i + 1
                       return i+1;
            }
        }
        return nums.size() + 1; //if everything is correct, then nums.size() + 1 is just return, if array size 9 has 1-9, then 10 is returned
    }
};
// @lc code=end

