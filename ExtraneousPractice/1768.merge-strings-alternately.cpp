#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 */

// @lc code=start
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int currPtr1 = 0;
        int currPtr2 = 0;
        string res = "";
        while(currPtr1 < word1.length() && currPtr2 < word2.length()){
            res += word1[currPtr1];
            res+= word2[currPtr2];
            currPtr1++;
            currPtr2++;
        }

        while(currPtr1 < word1.length()){
            res += word1[currPtr1];
            currPtr1++;
        }
        while(currPtr2 < word2.length()){
            res += word2[currPtr2];
            currPtr2++;
        }
        return res;
    }
};
// @lc code=end

