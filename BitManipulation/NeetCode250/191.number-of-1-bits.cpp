#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n != 0){
            n = n & (n-1); //this is the key, this operation removes the rightmost 1 bit from n, so we can count how many 1 bits are in n by counting how many times we can do this operation before n becomes 0
            count++;
        }

        return count;
    }
};
// @lc code=end

