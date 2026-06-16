#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        int idx = 0;
        unordered_map<char, int> map;
        for(char c : s){
            map[c]++;
        }
        for(char c:s){
            if(map[c] == 1){
                return idx;
            }
            idx++;
        }
        return -1;
    }
};
// @lc code=end

