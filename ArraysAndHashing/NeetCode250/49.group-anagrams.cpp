#include <bits/stdc++.h>
#include <string>
using namespace std;

/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> stringMap;
        for (auto str : strs){
        int count[26] = {0};
        for (char c: str){
            count[c - 'a']++; //this makes the array for the string, how many occurences of each letter in the string
        }

        string key = "";
        for(int i = 0; i < 26; i++){
            key += '#' + to_string(count[i]);
        }
        stringMap[key].push_back(str);
        }
        vector<vector<string>> resultVec;
        for(auto str: stringMap){
            resultVec.push_back(move(str.second));
        }
        return resultVec;
    }
};
// @lc code=end

