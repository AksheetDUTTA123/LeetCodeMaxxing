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
        int maxArrSize = 1;
        int inc = 1;
        int dec = 1;
        for(int i = 0; i < arr.size() - 1; i++){
            if(arr[i] < arr[i+1]){
                inc = dec + 1;
                dec = 1;
            }
            else if(arr[i] > arr[i + 1]){
                dec = inc + 1;
                inc = 1;
            }
            else{
                inc = 1;
                dec = 1;
            }
            maxArrSize = max(maxArrSize, max(inc, dec));
        }
        return maxArrSize;
    }
};
// @lc code=end

