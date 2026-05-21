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
        int left = 1;
        int right = x;
        int answer = 0;
        while(left <= right){
            int mid = left + (right - left) / 2; //dont forget the (right - left) / 2
            if((long long)mid * mid == x){ //remember (long long) since big number, need it to avoid overflow
                return mid;
            }
            else if ((long long)mid * mid < x){
                answer = mid;
                left = mid + 1;
            }
            else{
                //cant be a potential answer, since we only want lower numbers
                right = mid - 1;
            }
        }
        return answer;
    }
};
// @lc code=end

