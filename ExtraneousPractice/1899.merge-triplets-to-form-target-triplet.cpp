#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1899 lang=cpp
 *
 * [1899] Merge Triplets to Form Target Triplet
 */

// @lc code=start
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool target1 = false;
        bool target2 = false;
        bool target3 = false;
        for(int i = 0; i < triplets.size(); i++){
            if(triplets[i][0] > target[0] || triplets[i][1] > target[1]|| triplets[i][2] > target[2]) continue;

            if(triplets[i][0] == target[0]) target1 = true;
            if(triplets[i][1] == target[1]) target2 = true;
            if(triplets[i][2] == target[2]) target3 = true;
        }


        return (target1 && target2 && target3);
    }
};
// @lc code=end

