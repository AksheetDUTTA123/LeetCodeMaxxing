#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int totalSubarrays = 0; //track the number of total possible subarrays that sum to k
        int currentSum = 0; //incrementing sum of the entire array
        unordered_map<int, int> preFixSumMinusK; //map to track number of times a prefix sum has been seen so far
        preFixSumMinusK.insert({0, 1}); //sum 0 has been seen once, this is the base case
        for(int i = 0; i < nums.size(); i++){ //go through the entire array
            currentSum += nums[i]; //add the current number to the current sum
            if(preFixSumMinusK.find(currentSum - k) != preFixSumMinusK.end()){ //check if the current sum - k has been seen before, if so, add the number of times it has been seen to the total subarrays
            //if currentSum - k has been seen before, then there are preFixSumMinusK[currentSum - k] number of subarrays that sum to k, because if currentSum - k has been seen before, then there are preFixSumMinusK[currentSum - k] number of subarrays that sum to currentSum - k, and if we add the current number to those subarrays, then they will sum to k
                totalSubarrays += preFixSumMinusK[currentSum - k];
            }
                preFixSumMinusK[currentSum]++; //always increment the times currentSum has been seen, this is important for making future possible subarrays that sum up to k
        }
        return totalSubarrays;

    }
};
// @lc code=end

