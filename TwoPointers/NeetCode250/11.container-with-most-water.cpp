#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxAreaVal = 0;
        int leftSide = 0;
        int rightSide = height.size() - 1;
        while(leftSide < rightSide){
            maxAreaVal = max(maxAreaVal, min(height[leftSide], height[rightSide]) * (rightSide - leftSide));
            if(height[leftSide] < height[rightSide]){
                leftSide++;
            }
            else{
                rightSide--;
            }
        }
        return maxAreaVal;
    }
};
// @lc code=end

