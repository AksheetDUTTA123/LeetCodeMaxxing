#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */

// @lc code=start
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
    int left = *max_element(nums.begin(), nums.end());
    int right = accumulate(nums.begin(), nums.end(), 0); //max capacity
    int smallestSubarraySum = 0;
    while(left < right){
        int mid = left + (right - left)/2;
        if(splitCheck(nums, k, mid)){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    
    }
    return left;

    }
private:

    bool splitCheck(vector<int>& nums, int k, int maxSum){
        int subArrayCt =1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(sum + nums[i] > maxSum){
                subArrayCt++;
                sum = nums[i];
                if(subArrayCt > k) return false;
            }
            else{
                sum += nums[i];
            }
        }
        return subArrayCt <= k;

    }
};
// @lc code=end

