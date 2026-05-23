#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1095 lang=cpp
 *
 * [1095] Find in Mountain Array
 */

// @lc code=start
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int left = 0;
        int right = mountainArr.length() - 1;
        int peak = -1;
        int midHolder = -1;
        bool foundInLeft = false;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(mountainArr.get(mid) < mountainArr.get(mid + 1)){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        peak = left;

        if(mountainArr.get(peak) == target){
            return peak;
        }
        //do binary search here

        int left1 = 0;
        int right1 = peak - 1;
        while (left1 <= right1){
            int mid = left1 + (right1 - left1) / 2;
            if(mountainArr.get(mid) == target){
                foundInLeft = true;
                return mid;
            }
            else if(mountainArr.get(mid) < target){
                left1 = mid + 1;
            }
            else{
                right1 = mid - 1;
            }

        }

        if(!foundInLeft){
             int right2 = mountainArr.length() -1;
        int left2 = peak + 1;
        while (left2 <= right2){
            int mid = left2 + (right2 - left2) / 2;
            if(mountainArr.get(mid) == target){
                return mid;
            }
            else if(mountainArr.get(mid) < target){
                right2 = mid - 1;
            }
            else{
                left2 = mid + 1;
            }
        }
    }
    return -1;
    }
};
// @lc code=end

