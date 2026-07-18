#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::stringstream ss(s);
        unordered_map<string, char> strToLetter;
        unordered_map<char, string> charToString;
        string word;
        for(int i = 0; i < pattern.size(); i++){
            ss >> word;
            if(strToLetter.find(word) == strToLetter.end() && charToString.find(pattern[i]) == charToString.end()){
                strToLetter[word] = pattern[i];
                charToString[pattern[i]] = word;
            }
            else if(strToLetter[word] != pattern[i] || charToString[pattern[i]] != word) return false;
        }

        if (ss >> word) return false; //have to check if there are leftovers
        return true;
    }
};
// @lc code=end

