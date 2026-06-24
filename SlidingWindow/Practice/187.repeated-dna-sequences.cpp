#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 */

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seq;
        unordered_set<string> resBeta;
        vector<string> res;
        if(s.length() < 10) return res;
        int index = 0;
        while (index <= s.length() - 10){
            if(seq.find(s.substr(index, 10)) != seq.end()) {
                resBeta.insert(s.substr(index, 10));
            }
            else{
                seq.insert(s.substr(index, 10));
            }
            index++;
        }
        for(auto str : resBeta) res.push_back(str);
        return res;
    }
};
// @lc code=end

