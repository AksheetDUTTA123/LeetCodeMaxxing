#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       if(nums.size() < 3) return nums.size(); 
       int write = 2;
       for(int read = 2; read < nums.size(); read++){
            if(nums[read] != nums[write - 2]){
                nums[write] = nums[read];
                write++;
            }
       }
        return write;
    }
};
// @lc code=end

