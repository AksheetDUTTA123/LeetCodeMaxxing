#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 */

// @lc code=start
class Solution {
private:
    unordered_map<char, int> dict;
public:
    bool wordOrder(string& s1, string& s2){
        for(int i = 0; i < s1.length() && i < s2.length(); i++){
            if(s1[i] == s2[i]) continue;
            else{
                if(dict[s2[i]] < dict[s1[i]]) return false;
                else return true; //this is where order is determined, once first difference is found, can make distinction right there
            }
        }
        if(s1.length() > s2.length()) return false;
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        int ctr = 1;
        for(char c : order){
            dict[c] = ctr;
            ctr++;
        }
        
        for(int i = 0; i < words.size() - 1; i++){
            if(!wordOrder(words[i], words[i+1])) return false;
        }
        return true;
    }
};
// @lc code=end

