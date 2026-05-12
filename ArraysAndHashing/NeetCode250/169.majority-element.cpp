#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int counter = 1;
        for (int i = 1; i < nums.size(); i++){
            if(nums[i] != candidate){
                if(counter == 0){
                candidate = nums[i];
                counter = 0;
                }
                else{
                    counter--;
                }
            }
            else{
                counter++;
            }
        }
        return candidate;
    }
};
// @lc code=end

