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
        int maxArr = 0;
        int leftPtr = 0;
        int rightPtr = height.size() - 1;


        while(leftPtr < rightPtr){
            int wallHeight = min(height[leftPtr], height[rightPtr]);
            int currArea = wallHeight * (rightPtr - leftPtr);
            maxArr = max(currArea, maxArr);
            if(height[leftPtr] < height[rightPtr]){
                leftPtr++;
            }
            else{
                rightPtr--;
            }
        }
        return maxArr;
    }
};
// @lc code=end

