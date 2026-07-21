#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution {
private:
vector<vector<int>> res;
void backtracking(vector<int>& currVec, int currSum, int k, int n, int currIdx){
    if(currVec.size() == k && currSum == n){
        res.push_back(currVec);
    }

    for(int i = currIdx; i <= 9; i++){
        if(i + currSum <= n && currVec.size() + 1 <= k){
            currSum += i;
            currVec.push_back(i);
            backtracking(currVec, currSum, k, n, i + 1);
            currSum -= i;
            currVec.pop_back();
        }
    }

}
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n < (int) (((k) * (k + 1) )/ 2)) return res;
        vector<int> currVec;
        int currSum = 0;
        backtracking(currVec, currSum, k, n, 1);
        return res;
    }
};
// @lc code=end

