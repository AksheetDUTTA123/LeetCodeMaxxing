#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> freqCt;
        for(char c : s){
            freqCt[c]++;
        }
        for(char c : t){
            freqCt[c]--;
            if(freqCt[c] < 0) return c;
        }
        return 'a';
    }
};
// @lc code=end

