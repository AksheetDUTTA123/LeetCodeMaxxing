#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3345 lang=cpp
 *
 * [3345] Smallest Divisible Digit Product I
 */

// @lc code=start
class Solution {
public:
    int smallestNumber(int n, int t) {
        if(n <= t) return t;
        for(int i = n; i <= 999; i++){
            int currNum = i;
            int currNumModify = i;
            int currProd = 1;
            while(currNumModify != 0){
                currProd *= (currNumModify % 10);
                currNumModify /= 10;
            }
            if (currProd % t == 0) return currNum;
        }
        return -1;
    }
};
// @lc code=end

