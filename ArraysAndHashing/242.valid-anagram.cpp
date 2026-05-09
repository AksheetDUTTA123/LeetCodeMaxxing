#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, int> charCount;
        for(char c : s){
            charCount[c]++;        }

        for(char c : t){
            if(charCount[c] - 1 < 0){
                return false;
            }
            charCount[c]--;

        if(charCount[c] == 0){
                charCount.erase(c);
            }
        }
        return true;
    }
};
// @lc code=end

