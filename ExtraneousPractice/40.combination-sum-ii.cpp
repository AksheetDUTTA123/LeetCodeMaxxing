#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
private:
vector<vector<int>> res;

void backtracking(vector<int>& candidates,vector<int>& curr, int currIdx, int target){
    if(target == 0){
        res.push_back(curr);
        return;
    }

    for(int i = currIdx; i < candidates.size(); i++){
        if(candidates[i] > target) break;
        if(i > currIdx && candidates[i] == candidates[i-1]) continue;
        curr.push_back(candidates[i]);
        backtracking(candidates, curr, i + 1, target - candidates[i]);
        curr.pop_back();
    }
}
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, curr, 0, target);
        return res;
    }
};
// @lc code=end

