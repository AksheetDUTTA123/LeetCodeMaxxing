#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int totalCt = 0;
        unordered_map<int, int> ab;
        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                ab[nums1[i] + nums2[j]]++;
            }
        }

        for(int i = 0; i < nums3.size(); i++){
            for(int j = 0; j < nums4.size(); j++){
                int currSum = nums3[i] + nums4[j];
                totalCt += ab[-currSum];
            }
        }

        return totalCt;
    }
};
// @lc code=end

