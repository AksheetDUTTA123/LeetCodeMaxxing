#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
public:
    int getNext(int n){
        int totalSum = 0;
        while(n > 0){
            int currDigit = n % 10; 
            totalSum += currDigit * currDigit;
            n /=10;
        }
        return totalSum;
    }
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(n != 1 && seen.find(n) == seen.end()){ //use a set to keep track of numbers we have seen, if we see a number again, then we are in a cycle and will never reach 1
            seen.insert(n);
            n = getNext(n);
        }
        return n == 1;
    }
};
// @lc code=end

