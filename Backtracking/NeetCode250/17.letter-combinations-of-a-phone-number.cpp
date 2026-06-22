#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
private:
vector<string> combs;
public:

    void backtracking(string digits, int index, string& curr, unordered_map<char, string> &maps){
        if (curr.length() == digits.length()){
            combs.push_back(curr);
            return;
        }


        char number = digits[index];
        for(int i = 0; i < maps[number].length(); i++){
            curr += maps[number][i];
            backtracking(digits, index + 1, curr, maps);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> maps = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}

        };

            string curr = "";
            backtracking(digits, 0, curr, maps);
            return combs;
    }
};
// @lc code=end

