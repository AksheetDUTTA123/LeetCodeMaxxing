#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> slidingWindow;
        int leftPtr = 0;
        int rightPtr = 0;
        while(rightPtr < nums.size()){
            if(slidingWindow.find(nums[rightPtr]) != slidingWindow.end()){
                return true;
            }
            slidingWindow.insert(nums[rightPtr]);
            if(slidingWindow.size() > k){
                slidingWindow.erase(nums[leftPtr]);
                leftPtr++;
            }
            rightPtr++;
        }
        return false;
    }
};
// @lc code=end

