#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1979 lang=cpp
 *
 * [1979] Find Greatest Common Divisor of Array
 */

// @lc code=start
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smallestNum = INT_MAX;
        int biggestNum = -99999;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > biggestNum){
                biggestNum = nums[i];
            }
            if(nums[i] < smallestNum){
                smallestNum = nums[i];
            }
        }
        return gcd(smallestNum, biggestNum);
    }
};
// @lc code=end

