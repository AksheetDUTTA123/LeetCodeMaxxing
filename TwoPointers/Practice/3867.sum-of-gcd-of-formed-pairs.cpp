#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3867 lang=cpp
 *
 * [3867] Sum of GCD of Formed Pairs
 */

// @lc code=start
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<long long> gcdSums(nums.size(), 0);
        int currMax = nums[0];
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] > currMax){
                currMax = nums[i];
            }
            gcdSums[i] = (long long) gcd(nums[i], currMax);
        }
        sort(gcdSums.begin(), gcdSums.end());
        long long totalSum = 0;
        int left = 0;
        int right = gcdSums.size() - 1;
        while(left < right){
            totalSum += gcd(gcdSums[left], gcdSums[right]);
            left++;
            right--;
        }
        return totalSum;
    }
};
// @lc code=end

