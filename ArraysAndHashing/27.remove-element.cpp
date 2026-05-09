#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // std::erase(nums,val);
        // return nums.size();
        int ptr = 0; //values past the size of the vector that doesnt matter
        //val values should be sent to the back
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] != val){
                nums[ptr] = nums[i];
                ptr++;
            }
        }
        return ptr;
    }
};
// @lc code=end

