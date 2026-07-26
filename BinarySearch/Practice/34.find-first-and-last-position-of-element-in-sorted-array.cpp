#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int targetIdx = 0;
        if(nums.size() == 1 && nums[0] == target) return {0, 0};
        vector<int> range;
        while(left <= right){
            int mid = left + ((right - left)/2);

            if(nums[mid] == target){
                targetIdx = mid;
                //now that we found target, we shoudl now look to see how many times it occurs
                //find the starting index
                int startLeft = left;
                int startRight = mid;

                while (startLeft <= startRight){
                    int startMid = startLeft + ((startRight - startLeft) / 2);


                    if(nums[startMid] == target && (startMid == 0 ||nums[startMid - 1] != target)){
                        range.push_back(startMid);
                        break;
                    }
                    else if (nums[startMid] < target){
                        startLeft = startMid + 1;
                    }
                    else{
                        startRight = startMid - 1;
                    }
                }
                //find the ending index

                int endLeft = mid;
                int endRight = right;

                while(endLeft <= endRight){
                    int endMid = endLeft + ((endRight - endLeft + 1)/ 2);


                    if(nums[endMid] == target && (endMid == nums.size() - 1 || nums[endMid + 1] != target)){
                        range.push_back(endMid);
                        break;
                    }
                    else if (nums[endMid] > target) {
                        endRight = endMid - 1;
                    }
                else {
                endLeft = endMid + 1; // Move right to find the later occurrence
                }
                }

                return range;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return {-1, -1};
    }
};
// @lc code=end

