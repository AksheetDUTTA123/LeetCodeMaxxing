#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
class Solution {
private:
    unordered_set<string> dict;
    vector<string> res;
public:
    void backtracking(int substrIdxStart, string& curr, string& s){
        if(substrIdxStart == s.length()) {
            res.push_back(curr);
            return;
        }


        for(int substrIdxEnd = substrIdxStart; substrIdxEnd < s.length(); substrIdxEnd++){
            string word = s.substr(substrIdxStart, substrIdxEnd - substrIdxStart + 1);


            if(dict.find(word) != dict.end()){
                int prevLength = curr.length();//need to know old string length so we can return to this state
                if(curr.length() == 0){
                    curr += word;
                }
                else{
                    curr += " " + word;
                }
                backtracking(substrIdxEnd+ 1, curr, s);
                curr = curr.substr(0, prevLength); //revert back to old curr string
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(int i = 0; i < wordDict.size(); i++){
            dict.insert(wordDict[i]);
        }

        string curr = "";
        backtracking(0, curr, s);
        return res;
    }
};
// @lc code=end

