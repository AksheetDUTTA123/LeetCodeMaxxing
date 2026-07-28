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
        int write = 0;
        int read = 1;
        while(read < nums.size()){
            if(nums[read] == nums[write]){
                read++; //duplicate, we need to move to next elem
            }
            else{
                write++; //move write ptr to enxt open slot
                nums[write] = nums[read]; //add new unique point
                read++; //move to new read, keep moving on
            }
        }
        return write + 1; //# of unique elem, write is 0 index so have to add 1
    }
};
// @lc code=end

