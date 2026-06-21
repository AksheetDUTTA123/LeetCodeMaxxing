#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3159 lang=cpp
 *
 * [3159] Find Occurrences of an Element in an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> res;
        vector<int> positions;

        for(int i = 0; i < nums.size(); i++){
            if (nums[i] == x) positions.push_back(i);
        }
        for(int i = 0; i < queries.size(); i++){
            if (queries[i] <= positions.size()){
                res.push_back(positions[queries[i] - 1]); //need to do queries[i] - 1 because queries are 1 indexed, but positions is 0 indexed
            }
            else{
                res.push_back(-1);
            } 
        }
        return res;
    }
};
// @lc code=end

