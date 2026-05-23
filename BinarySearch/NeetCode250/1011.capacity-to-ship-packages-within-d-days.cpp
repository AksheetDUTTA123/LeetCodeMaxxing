#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int right = accumulate(weights.begin(), weights.end(), 0); //max capacity that can be shipped in an entire day 
        int left = *max_element(weights.begin(), weights.end()); //minimum capacity must be the max weight in the weights array, or else it cannot be shipped at all.
        while(left < right){
            int mid = left + (right - left)/2; //capacity trying to ship with
            int daysNeeded = 1;
            int currentLoad = 0;
            for (int w : weights){ //go through the weights and see how many days it would take to ship with the current capacity (mid)
                if(currentLoad + w> mid){
                    daysNeeded++;
                    currentLoad = w;
                }
                else{
                    currentLoad += w;
                }
            }

            if(daysNeeded <= days){
                right = mid;

            }
            else{
                left = mid + 1;
            }

        }
        return left;
    }
};
// @lc code=end

