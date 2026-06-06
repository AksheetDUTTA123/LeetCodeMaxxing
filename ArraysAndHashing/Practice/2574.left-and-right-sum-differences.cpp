#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=2574 lang=cpp
 *
 * [2574] Left and Right Sum Differences
 */

// @lc code=start
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        // vector<int> leftSum(nums.size());
        // vector<int> rightSum(nums.size());
        // vector<int> result(nums.size());
        // leftSum[0] = 0;
        // rightSum[nums.size() - 1] = 0;
        // for(int i = 1; i < leftSum.size(); i++){
        //     leftSum[i] = leftSum[i-1] + nums[i-1]; 
        //     // std::cout<< "LeftSum " << i << " : " << leftSum[i] << std::endl;
        // }
        // for(int i = leftSum.size() - 2; i >= 0; i--){
        //     rightSum[i] = rightSum[i+1] + nums[i+1]; 
        //     // std::cout<< "RightSum " << i << " : " << rightSum[i] << std::endl;

        // }
        // for(int i = 0; i < result.size(); i++){
        //     result[i] = abs(leftSum[i] - rightSum[i]);
        // }
        // return result;
        //this is the non optimal O(n) space solution, below is the O(1) space solution

        vector<int> result(nums.size());
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        int leftSum = 0;
        for(int i = 0; i < nums.size(); i++){
            int rightSum = sum - leftSum - nums[i]; //easy way to look at it, leftSum + nums[i] + rightSum = sum, just reorder it
            result[i] = abs(leftSum - rightSum);
            leftSum += nums[i];
        }
        return result;
    }
};
// @lc code=end

