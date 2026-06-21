#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
public:
    void backtrack(vector<int>& candidates, vector<int>& curr, int& target, int index){ //smart trick, decrement until target is 0
        if(target == 0){
            res.push_back(curr);
            return;
        } 
        for(int i = index; i < candidates.size(); i++){
            if(target - candidates[i] < 0){
                break;
            }
        else{
            target -= candidates[i];
            curr.push_back(candidates[i]);
            backtrack(candidates, curr, target, i);
            target += candidates[i];
            curr.pop_back();
        }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        std::sort(candidates.begin(), candidates.end());
        backtrack(candidates, curr, target, 0);
        return res;
    }
};
// @lc code=end

