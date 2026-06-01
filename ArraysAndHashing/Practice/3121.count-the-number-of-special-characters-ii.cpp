#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3121 lang=cpp
 *
 * [3121] Count the Number of Special Characters II
 */

// @lc code=start
class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> lastLower;
        unordered_map<char, int> firstUpper;
        int specialCharCt = 0;
        for(int i = 0; i < word.size(); i++){
            char l = word[i];
            if(islower(l)){
                lastLower[l] = i;
            }
        }

        for(int i = 0; i < word.size(); i++){
            char l = word[i];
            if(isupper(l)){
                char lowerL = tolower(l);
                if(firstUpper.find(lowerL) == firstUpper.end()){
                    firstUpper[lowerL] = i;
                }
            }
        }

        for(char i = 'a'; i <= 'z'; i++){
            if((firstUpper.count(i) && lastLower.count(i) &&
            (lastLower[i] < firstUpper[i]))){
                specialCharCt++;
            }
        }
        return specialCharCt;

    }
};
// @lc code=end

