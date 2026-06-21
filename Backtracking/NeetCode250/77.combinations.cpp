#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
public:
    void backtrack(int index, vector<int>& curr, int n,   int k){
        if(curr.size() == k){
            res.push_back(curr);
            return;
        }

        // for(int i = index; i <= n - (k - curr.size()) + 1 ; i++){ //pruning, if we have n = 5, k = 3, and curr.size() = 1,
        // // then we need to have at least 2 more numbers to add to curr, so we need to start our loop at index and end it at n - (k - curr.size()) + 1, because if we start our loop at index and end it at n, then we might end up with a combination that is too long and 
        // //we won't be able to add enough numbers to curr to reach k, so we need to prune our loop by ending it at n - (k - curr.size()) + 1, 
        // //this way we can ensure that we have enough numbers left to add to curr to reach k
        //         curr.push_back(i);
        //         backtrack(n, curr, i + 1, k);
        //         curr.pop_back();
        // }

        for(int i = index; i<= n; i++){
            curr.push_back(i);
            backtrack(i + 1, curr, n, k);
            curr.pop_back();
        }


        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        //dont even need a candidates vector as you initially did, use method of pruning here
        backtrack(1, curr, n, k);
        return res;
    }
};
// @lc code=end

