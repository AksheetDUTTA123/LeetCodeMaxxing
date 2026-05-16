#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sums;
        sort(nums.begin(), nums.end()); //need to sort, common rule for two ptr, n log n
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]){ //if i pointer is the same, then keep going to avoid duplicates
                continue;
            }
            int left = i + 1; //start the window right after i
            int right = nums.size() - 1; //go till the end
            while(left < right){ //keep going until right and left meet at same place, all combos been looked at
                if(nums[i] + nums[left] + nums[right] == 0){ //if match, add triplet
                    sums.push_back({nums[i], nums[left], nums[right]});
                    left++; //must rememebr to keep going left
                    right--; //and going right, to check more possible combos
                    while(left < right && nums[left]== nums[left - 1]){
                        left++; //if the next left is same as old left, keep going right
                    }
                    while(left < right && nums[right]== nums[right+1]){ 
                        right--; //if new right is the same as the old right, keep moving left
                    }
                }
                else if(nums[i] + nums[left] + nums[right] < 0){
                    left++; //if less than 0, need to increase the sum, move left pointer to the right 
                }
                else{
                    right--; //if greater than 0, need to decrease the sum, move right pointer to the left
                }
            }
        }
        return sums;
    }
};
// @lc code=end

