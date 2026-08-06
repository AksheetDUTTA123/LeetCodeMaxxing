#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=859 lang=cpp
 *
 * [859] Buddy Strings
 */

// @lc code=start
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length()) return false;
        int diffCheck = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != goal[i]) diffCheck++;
        }
        if(diffCheck == 0){
            unordered_set<char> uniqueChars(s.begin(), s.end());
            return uniqueChars.size() < s.length();
        }
        
        vector<char> diff;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != goal[i]) diff.push_back(i);
        }
        return diff.size() == 2 && s[diff[0]] == goal[diff[1]] && s[diff[1]] == goal[diff[0]];
    }
};
// @lc code=end

