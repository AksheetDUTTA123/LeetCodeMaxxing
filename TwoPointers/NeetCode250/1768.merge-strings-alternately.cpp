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
        int i = 0;
        string result = "";
            while (i < word1.size() || i < word2.size()) {
        if (i < word1.size()) result += word1[i];
        if (i < word2.size()) result += word2[i];
        i++;
    }
    return result;
//     int ptr1 = 0;
// int ptr2 = 0;
//         string result = "";
// while(ptr1 < word1.size() && ptr2 < word2.size()){
// result += word1[ptr1];
// result += word2[ptr2];
// ptr1++;
// ptr2++;
//         }
// if(ptr1 == word1.size() && ptr2 < word2.size()){
// while(ptr2 < word2.size()){
// result += word2[ptr2];
// ptr2++;
//         }
//         }
// else if(ptr1 < word1.size() && ptr2 == word2.size()){
// while(ptr1 < word1.size()){
// result += word1[ptr1];
// ptr1++;
//         }
//         }
// else{
// return result;
//         }
// return result;
//     }
    }
};
// @lc code=end

