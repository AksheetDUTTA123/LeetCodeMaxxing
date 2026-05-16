#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> sums;
    if(nums.size() < 4){
        return sums;
    }
        sort(nums.begin(), nums.end()); //need to sort, common rule for two ptr, n log n
        for(int i = 0; i < nums.size()- 3; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j = i+1; j < nums.size() - 2; j++){
            if(nums[j] == nums[j-1] && j>i+1){ //if i pointer is the same, then keep going to avoid duplicates
                continue;
            }
            int left = j + 1; //start the window right after i
            int right = nums.size() - 1; //go till the end
            while(left < right){ //keep going until right and left meet at same place, all combos been looked at
                if((long long)nums[i] + nums[j] + nums[left] + nums[right] == target){ //if match, add triplet
                    sums.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++; //must rememebr to keep going left
                    right--; //and going right, to check more possible combos
                    while(left < right && nums[left]== nums[left - 1]){
                        left++; //if the next left is same as old left, keep going right
                    }
                    while(left < right && nums[right]== nums[right+1]){ 
                        right--; //if new right is the same as the old right, keep moving left
                    }
                }
                else if((long long)nums[i] + nums[j] + nums[left] + nums[right] < target){
                    left++; //if less than 0, need to increase the sum, move left pointer to the right 
                }
                else{
                    right--; //if greater than 0, need to decrease the sum, move right pointer to the left
                }
            }
        }
        }
        return sums;
    }
};
// @lc code=end

