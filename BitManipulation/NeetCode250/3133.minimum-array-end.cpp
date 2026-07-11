#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3133 lang=cpp
 *
 * [3133] Minimum Array End
 */

// @lc code=start
class Solution {
public:
    long long minEnd(int n, int x) {
       long long res = x;
       long long remaining = n -1;
       for(int i = 0; i < 64; i++){
        if((res & (1LL << i)) == 0){
            res |= (remaining & 1) << i; //if the ith bit of res is 0, 
            //we can set it to 1 if the ith bit of remaining is 1, this will minimize res while still using up all the remaining bits
            remaining >>= 1;
        }
        if(remaining == 0) break;
       }
       return res;
    }
};
// @lc code=end

