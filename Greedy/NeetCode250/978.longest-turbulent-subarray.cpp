#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=978 lang=cpp
 *
 * [978] Longest Turbulent Subarray
 */

// @lc code=start
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int incStreak = 1;
        int decStreak = 1;
        int maxSize = 1;
        for(int i = 1; i < arr.size(); i++){
            if(arr[i-1] > arr[i]){
                decStreak = incStreak + 1; //if the previous element is greater than the current element, 
                //then we can increase the decreasing streak by 1, and reset the increasing streak to 1
                incStreak = 1;
            }
            else if (arr[i-1] < arr[i]){
                incStreak = decStreak + 1; //if the previous element is less than the current element, 
                //we can increase the increasing streak by 1, and reset the decreasing streak to 1
                decStreak = 1;
            }
            else{
                incStreak = 1; //if equal, reset both streaks to 1
                decStreak = 1;
            }
            maxSize = max({decStreak, incStreak, maxSize}); //at each step, we check the max of the current increasing streak, 
            //decreasing streak, and the max size so far
        }

        return maxSize;
    }
};
// @lc code=end

