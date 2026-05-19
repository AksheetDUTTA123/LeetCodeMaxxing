#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        //O(n) memory would be more inefficient here, you would store the maxL and maxR from each 
        if(height.empty()) return 0;
        int result = 0;
        int l = 0;
        int r = height.size() - 1;
        int MaxL = height[l];
        int MaxR = height[r];
        while(l < r){
            if(MaxL < MaxR){ //if the maxL is less than maxR, then we know that the maxL is the limiting factor for how much water can be trapped at the current left pointer. 
            //This is because the water level at the left pointer cannot exceed the height of the tallest bar to the left, right side can potentially hold more water. 
            //If we were to move the right pointer instead, we might miss out on trapping water at the left pointer, since the maxL is the smaller of the two.
                l++;
                MaxL = max(MaxL, height[l]);
                result += MaxL - height[l];
            }
            else{
               r--;
                MaxR = max(MaxR, height[r]);
                result += MaxR - height[r];
            }
    }
            return result;
    }
};
// @lc code=end

