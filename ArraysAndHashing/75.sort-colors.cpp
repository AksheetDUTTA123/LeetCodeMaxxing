#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int leftIndex = 0;
        int currentIndex = 0;
        int rightIndex = nums.size() - 1;

    while(currentIndex <= rightIndex){
        if(nums[currentIndex] == 0){
            std::swap(nums[leftIndex], nums[currentIndex]);
            leftIndex++;
            currentIndex++;
        }
        else if(nums[currentIndex] == 1){
            currentIndex++;
        }

       else{
            std::swap(nums[currentIndex], nums[rightIndex]);
            rightIndex--;
            //currentIndex++;
        }
    }


    }
};
// @lc code=end

