#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        unordered_map<char, int> s1char; //character and frequency
                unordered_map<char, int> s2char; //character and frequency

        for(int i = 0; i < s1.size(); i++){s1char[s1[i]]++;}
        for(int i = 0; i < s1.size(); i++){
            s2char[s2[i]]++; //go up until the size of s1, then we will start sliding the window
        }
        if(s1char == s2char){
            return true;
        }

        for(int i = s1.size(); i < s2.size(); i++){
             s2char[s2[i]]++;
             s2char[s2[i - s1.size()]]--;
             if(s2char[s2[i - s1.size()]] == 0){
                s2char.erase(s2[i - s1.size()]);
             }
                     if(s1char == s2char){
            return true;
        }
        }
        return false;

    }
};
// @lc code=end

