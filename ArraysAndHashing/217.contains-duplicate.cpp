#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seenVals;
        for(int i = 0; i< nums.size(); i++){
            if(seenVals.find(nums[i]) != seenVals.end()){
                return true;
            }
            else{
                seenVals.insert(nums[i]);
            }
        }
        return false;
    }
};
// @lc code=end

