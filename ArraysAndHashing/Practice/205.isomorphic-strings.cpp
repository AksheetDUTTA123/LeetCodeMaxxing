#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> stot;
        unordered_map<char, char> ttos;
        for(int i = 0; i < s.size(); i++){
            if(stot.find(s[i]) == stot.end() && ttos.find(t[i]) == ttos.end()){
                stot[s[i]] = t[i];
                ttos[t[i]] = s[i];
            }
            else if(stot[s[i]] != t[i] || ttos[t[i]] != s[i]){
                return false;
            }
        }
        return true;

    }
};
// @lc code=end

