#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int start = 0;
        int end = arr.size() - 1;
        while (end - start + 1 > k){
            if(x - arr[start] <= arr[end] - x){
                end--;  // Left is closer or equal → remove right element
            }
            else{
                start++; // Right is closer → remove left element
            }
        }
        return std::vector<int>(arr.begin() + start, arr.begin() + start + k);
    }
};
// @lc code=end

