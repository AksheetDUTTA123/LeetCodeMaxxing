#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3838 lang=cpp
 *
 * [3838] Weighted Word Mapping
 */

// @lc code=start
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        unordered_map<char, int> mapping;
        for(int i = 0; i < weights.size(); i++){
            mapping['a' + i] = weights[i];
        }
        string ans = "";
        for(int i = 0; i < words.size(); i++){
        int stringVal = 0;
            for(int j = 0; j < words[i].length(); j++){
                stringVal += mapping[words[i][j]];
            }
            ans += 'z' - (stringVal % 26);
        }
        return ans;
    }
};
// @lc code=end

