#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
class Solution {
public:
    int characterReplacement(string s, int k) {
        //AABABBA
        //maxStreak = 2
        //k = 1
        //left = 0
        //right = 2
        //A: 2 B : 1
        //(right - left + 1) > k
        unordered_map<char, int> mp; //we are mapping characters to freq
        int maxStreak = 0;
        int left = 0;
        int right = 0;
        int globalMax = -INT_MAX;
        while(right < s.length()){
            mp[s[right]]++;
            if(mp[s[right]] > maxStreak) {
                maxStreak = mp[s[right]];
            }
            if((right - left + 1) > maxStreak + k) {
                mp[s[left]]--;
                left++;
            }
            globalMax = max(right - left + 1, globalMax);
            right++;
        }   
        return globalMax;
    }
};
// @lc code=end

