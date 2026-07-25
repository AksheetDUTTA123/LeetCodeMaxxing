#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1498 lang=cpp
 *
 * [1498] Number of Subsequences That Satisfy the Given Sum Condition
 */

// @lc code=start
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int MOD = 1e9 + 7;
        // if(nums.size() == 1 && target == nums[0]) return 0;
        int numSeq = 0;
        vector<int> pow(nums.size() + 1);
        pow[0] = 1;
        for(int i = 1; i < pow.size(); i++) pow[i] = (pow[i - 1] * 2) % MOD;
        for(int i = 0; i < nums.size(); i++){
            int currNum = nums[i];
            int maxAllowed = target - nums[i];
            int left = i;
            int right = nums.size() - 1;
            int finalMid = -1;
            while(left <= right){
                int mid = left + ((right - left) / 2);

                if(nums[mid] > maxAllowed){
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                    finalMid = mid;
                }
            }
        if(finalMid == - 1){
             break;
        }
        numSeq = (numSeq + pow[finalMid - i]) % MOD;
        }
        return numSeq;
    }
};
// @lc code=end

