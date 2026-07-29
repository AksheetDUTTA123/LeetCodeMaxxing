#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        long long left = 0;
        long long right = x;
        int res = 0;
        while(left <= right){
            long long mid = left + (right - left) / 2;
            long long square = mid * mid;
            if(square == x) return mid;
            else if(square < x){
                res = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return res;
    }
};
// @lc code=end

