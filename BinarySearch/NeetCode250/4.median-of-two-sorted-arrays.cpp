#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
//This is a hard problem, definitely one of the hardest problems on LeetCode. The key to solving this problem is to use binary search to find the correct partition of the two arrays. We want to partition the two arrays into two halves such that the left half of the first array and the left half of the second array together contain the same number of elements as the right half of the first array and the right half of the second array. We can then calculate the median based on the maximum of the left halves and the minimum of the right halves. The time complexity of this solution is O(log(min(m, n))) where m and n are the lengths of the two arrays, because we are doing binary search on the shorter array.
//REVIEW THIS QUESTION
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if(nums1.size() > nums2.size()) { //nums1 always has to be the shorter array because we are doing binary search on the first array, so we want to minimize the number of operations we have to do. If nums1 is the longer array, we can just swap the two arrays and call the func again.
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int left = 0;
        int right = nums1.size();
        while(left <= right){
            int mid1 = left + (right - left) / 2; //binary search the first array, find index of the first half of the array.
            int mid2 = (nums1.size() + nums2.size() + 1) / 2 - mid1; //we want to split the two arrays into two halves, so we need to find the index of the second half of the second array. We can do this by taking the total length of the two arrays, adding 1 to it (to account for odd lengths), and then dividing by 2 to get the index of the second half of the second array. We then subtract mid1 from this index to get the index of the second half of the first array.
            int left1 = mid1 == 0 ? INT_MIN : nums1[mid1 - 1]; //if mid1 is 0, then there are no elements in the left half of the first array, so we can set left1 to be negative infinity to ensure that it does not affect the median calculation. Otherwise, we can set left1 to be the last element of the left half of the first array, which is nums1[mid1 - 1];
            int left2 = mid2 == 0 ? INT_MIN : nums2[mid2 - 1];
            int right1 = mid1 == nums1.size() ? INT_MAX : nums1[mid1];
            int right2 = mid2 == nums2.size() ? INT_MAX : nums2[mid2];
            if(left1 <= right2 && left2 <= right1){ //need to check if left half of the first array is less than the second half of the second array, and if the first half of the second array is less than the second half of the first array. If both of these conditions are true, then we have found the correct partition of the two arrays, and we can calculate the median based on the maximum of the left halves and the minimum of the right halves. If the total length of the two arrays is even, then the median is the average of the maximum of the left halves and the minimum of the right halves. If the total length of the two arrays is odd, then the median is simply the maximum of the left halves, since there will be one extra element in one of the halves.
                if((nums1.size() + nums2.size()) % 2 == 0){
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
                else{
                    return (max(left1, left2));
                }
            }
                else if(left1 > right2){ //if the left half of the first array is greater than the right half of the second array, then we need to move the partition in the first array to the left, which means we need to decrease mid1. This is because we want to find a smaller value in the left half of the first array that can be paired with a larger value in the right half of the second array to satisfy the condition for finding the median.
                    right = mid1 - 1;
                }
                else{
                    left = mid1 + 1;
                }
            }
        return 0.0;
        }
};
// @lc code=end

