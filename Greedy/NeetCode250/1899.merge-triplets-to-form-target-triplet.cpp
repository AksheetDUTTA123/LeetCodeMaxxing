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
        bool found1 = false;
        bool found2 = false;
        bool found3 = false;
        for(auto triplet : triplets){
            if(triplet[0] > target[0] || triplet[1] > target[1] ||triplet[2] > target[2]) continue;
            //this is key, we are pruning here, any truplets with vals larger than target are GUARANTEED not to be in the result

            if(triplet[0] == target[0]) found1 = true;
            if(triplet[1] == target[1]) found2 = true;
            if(triplet[2] == target[2]) found3 = true;

            if(found1 && found2 && found3) return true;

        }
        return (found1 && found2 && found3);
    }
};
// @lc code=end

