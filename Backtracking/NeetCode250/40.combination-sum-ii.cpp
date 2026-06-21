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
public:
    void backtracking(vector<int>& candidates, int& target, vector<int>& curr, int startIdx){
        if(target == 0){
            res.push_back(curr);
            return;
        }

        for(int i = startIdx; i < candidates.size(); i++){
            if(target - candidates[i] < 0) break;
            //we break here instead of continue,
            // because the candidates array is sorted, so if we have already found a number 
            //that is greater than the target, then we know that all the numbers that come after it will also be
            // greater than the target, so there is no point in continuing to check those numbers,
            // we can just break out of the loop and stop checking for combinations that include those numbers, this will allow us to optimize our 
            //backtracking process and avoid unnecessary checks for combinations that will never sum up to the target

            //i > start is the key to skipping duplicates,
            // because we only want to skip duplicates that are in the same branch 
            //of the backtracking tree, if we have already used a number in the current 
            //branch of the backtracking tree, then we want to skip any duplicate numbers that come after it in the candidates array, because those duplicate numbers will be in the same branch of the backtracking tree and
            // will lead to the same combination being generated multiple times, so we need to check if i > start to make sure
            // that we are only skipping duplicates that are in the same branch of the backtracking tree, and then we can check if candidates[i] == candidates[i - 1] to check if the current number is a duplicate of the previous number, if it is, then we can skip it, because it will lead to the same 
            //combination being generated multiple times
            if(i > startIdx && candidates[i] == candidates[i - 1]) continue;

            target -= candidates[i];
            curr.push_back(candidates[i]);
            backtracking(candidates, target, curr, i + 1); //i + 1 because we cannot reuse the same number,
            // this is the key difference between this problem and the previous problem, in the previous problem we could reuse the same number,
            //so we passed i as the next index to backtrack from, but in this problem we cannot reuse the same number, so we need to pass i + 1 as the next index to backtrack from, 
            //this will ensure that we do not reuse the same number in the same combination, and it will also allow us to skip over duplicate numbers in the candidates array, because if we have
            // duplicate numbers that are adjacent to each other in the candidates array, then we will skip over them in the backtracking process, because we will only check for combinations that include the first instance of the duplicate number, and we will skip over any subsequent instances of the duplicate number, this will allow us to avoid generating duplicate combinations
            target += candidates[i];
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        int start = 0;
        backtracking(candidates, target, curr, start);
        return res;
    }
};
// @lc code=end

