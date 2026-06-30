#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1967 lang=cpp
 *
 * [1967] Number of Strings That Appear as Substrings in Word
 */

// @lc code=start
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int stringCt = 0;
        for(string s : patterns){
            if(s.length() > word.length()) continue;
            for(int i = 0; i <= (int) word.length() - (int) s.length(); i++){
                if (word.substr(i, s.length()) == s){
                    stringCt++;
                    break;
                }
            }
        }
        return stringCt;
    }
};
// @lc code=end

