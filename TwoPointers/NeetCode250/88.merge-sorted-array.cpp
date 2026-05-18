#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //need three pointers for this question
        //go right to left for indexing purposes here
        int ptrNums1 = m - 1; //nums1 position
        int ptrWrite = m + n - 1; //current write position
        int ptrNums2 = n - 1; //nums2 position
        while(ptrWrite >= 0 && ptrNums1 >= 0 && ptrNums2 >= 0){
            int maxNum = max(nums1[ptrNums1], nums2[ptrNums2]);
            if(nums1[ptrNums1] > nums2[ptrNums2]){
                ptrNums1--;
            }
            else{
                ptrNums2--;
            }
            nums1[ptrWrite] = maxNum;
            ptrWrite--;
        }
        while (ptrNums2 >= 0){
            nums1[ptrWrite] = nums2[ptrNums2];
            ptrNums2--;
            ptrWrite--;
        }
    }
};
// @lc code=end

