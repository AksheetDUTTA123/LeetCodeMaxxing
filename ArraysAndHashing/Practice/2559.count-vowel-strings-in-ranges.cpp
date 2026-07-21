#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=2559 lang=cpp
 *
 * [2559] Count Vowel Strings in Ranges
 */

// @lc code=start
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> res(words.size(), 0);
        vector<int> ans(queries.size(), 0);
        for(int i = 0; i < words.size(); i++){
            if((words[i].front() == 'a' || words[i].front() == 'e' || words[i].front() == 'i' || words[i].front() == 'o' || words[i].front() == 'u')
             && (words[i].back() == 'a' || words[i].back() == 'e' || words[i].back() == 'i' || words[i].back() == 'o' || words[i].back() == 'u')){
                res[i] = 1;
             }
        }

        for(int i = 1; i < res.size(); i++){
            res[i]+= res[i-1];
        }

        for(int i = 0; i < queries.size(); i++){
            int leftTerm = queries[i][0];
            int rightTerm = queries[i][1];

            int L = 0;
            if(leftTerm > 0){
                L = res[leftTerm - 1]; //the reason we have to do this is because we want to get the number of vowel strings in the range [leftTerm, rightTerm], and res[rightTerm] gives us the number of vowel strings in the range [0, rightTerm], so we have to subtract the number of vowel strings in the range [0, leftTerm - 1] to get the number of vowel strings in the range [leftTerm, rightTerm]
            }
            ans[i] = res[rightTerm] - L;
        }
        return ans;
    }
};
// @lc code=end

