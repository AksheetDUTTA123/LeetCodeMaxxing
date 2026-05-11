#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //look at left and right, array store left products and another array stores right products
        //genius idea, calculate left array, and then right array only needs to store a number, then multiply with left array
        vector<int> ans;
        ans.push_back(1); //first number going from left side will always be 1;
        int leftTrack = 1;
        for(int i = 1; i < nums.size(); i++){
            leftTrack *= nums[i-1]; //as you keep going, keep multiplying by the one you just moved past
            ans.push_back(leftTrack); //push it back to array, goes untul end of the array
        }
        int rightTrack = 1; //start going from the right
        //right element of ans is correct, start from before
    for(int i = nums.size()-2; i >-1;  i--){ //why -2? b/c -1 is to get to the index of last element, and -2 because -1 will always be the same as 
    //the left array's final value
            rightTrack *= nums[i+1]; //iterate from right to left, as you move left, multiply the value on the right you moved on from
            ans[i] = rightTrack * ans[i]; //observation that ans = left * right, ans before multipliying is left
        }
        return ans;
    }
};
// @lc code=end

