#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // for(int i = nums.size() - 2; i >= 0; i--){ //this soltuion is non-optimal but it does work.
        //     int duplicatePtr = i+1; 
        //     if(nums[i] == nums[duplicatePtr]){
        //         nums.erase(nums.begin() + duplicatePtr);
        //     }
        // }
        // return nums.size();

    //optimal solution requires two ptr approach
    if(nums.empty()) {
        return 0;
    }
    int write = 1; //write marks the index where the next unique value should be placed
    for(int read = 1; read < nums.size(); read++){ //read is scanning for each unique value
        if(nums[read] != nums[read -1]){
            nums[write] = nums[read];
            write++;
        }
    }
    return write;
    }
};
// @lc code=end

