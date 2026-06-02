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
                result += MaxL - height[l]; //The amount of water trapped at the current left pointer is the difference between the maxL and the height of the current bar at the left pointer. We add this to our result, and then move the left pointer to the right to continue checking for more trapped water.
                //think of result being the depth, kind of like a basin, and the height of the current bar is the floor of the basin. The maxL is the ceiling of the basin, so the difference between them is how much water can be trapped in that basin.
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

