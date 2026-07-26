#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int globalMaxProduct = nums[0];
        int minSoFar = nums[0];
        int maxSoFar = nums[0];
        for(int i = 1; i < nums.size(); i++){ //need to start from 1, not 0
            int tempMax = maxSoFar; //store temp max so when calculating minSoFar, we can use tempMax to use the old maxSoFar
            maxSoFar = max(nums[i], max(maxSoFar * nums[i], minSoFar * nums[i]));
            minSoFar = min(nums[i], min(minSoFar * nums[i], tempMax * nums[i]));
            globalMaxProduct = max(globalMaxProduct, maxSoFar);
        }
        return globalMaxProduct;
    }
};
// @lc code=end

