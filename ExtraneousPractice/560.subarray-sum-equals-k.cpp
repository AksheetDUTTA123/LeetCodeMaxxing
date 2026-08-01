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
        unordered_map<int, int> prefix;
        int totalSubarrays = 0;
        int currSum = 0;
        prefix.insert({0, 1});
        for(int i = 0; i < nums.size(); i++){
            currSum += nums[i];
            if(prefix.find(currSum - k) != prefix.end()){
                totalSubarrays += prefix[currSum - k];
            }
            prefix[currSum]++;
        }
        return totalSubarrays;
    }
};
// @lc code=end

