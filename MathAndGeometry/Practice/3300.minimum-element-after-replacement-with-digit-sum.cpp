#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3300 lang=cpp
 *
 * [3300] Minimum Element After Replacement With Digit Sum
 */

// @lc code=start
class Solution {
public:
    int minElement(vector<int>& nums) {
        int minNum = 1E9;
        for(int i = 0; i < nums.size(); i++){
            int elemSum = 0;
            int n = 0;
            int length = nums[i];
            while(length != 0){
                elemSum += (nums[i] / int(std::pow(10, n))) % 10;
                length /= 10;
                n++;
            }
            if(elemSum < minNum){
                minNum = elemSum;
            }
        }
        return minNum;
    }
};
// @lc code=end

