#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k > nums.size()){
            k = k % nums.size();
        }
        for(int i = 0; i < nums.size() / 2; i++){
            swap(nums[i], nums[(nums.size() - 1) - i]);
        }
        //need to reverse for each half
        for(int i = 0; i < k/2; i++){
            swap(nums[i], nums[(k - 1) - i]);
        }
        int left = k;
        int right = nums.size() - 1;
        while(left < right){
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
};
// @lc code=end

