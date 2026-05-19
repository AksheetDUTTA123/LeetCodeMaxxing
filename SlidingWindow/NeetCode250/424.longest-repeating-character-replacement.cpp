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
        unordered_map<char,int> freq;
        int l = 0;
        int maxFreq = 0;
        int longest = 0;
        for(int i = 0; i < s.size(); i++){
            freq[s[i]]++;
            maxFreq = max(maxFreq, freq[s[i]]);
            while((i - l + 1) - maxFreq > k){ //need to update window, will shrink
            freq[s[l]]--;
            l++;
            }
            longest = max(longest, i - l + 1);
        }
        return longest;
    }
};
// @lc code=end

