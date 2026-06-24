#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */

// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAvg = -INT_MAX;
        double currWindow = 0;
        for(int i = 0; i < k; i++){
            currWindow += nums[i];
        }
        maxAvg = currWindow / k;

        for(int j = k; j < nums.size(); j++){
            currWindow -= nums[j-k];
            currWindow += nums[j];
            maxAvg = max(maxAvg, currWindow / k);
        }
        return maxAvg;
    }
};
// @lc code=end

