#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1331 lang=cpp
 *
 * [1331] Rank Transform of an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        std::map<int, int> valToRank; //using a map to store the unique values in arr and their corresponding ranks, the key is the value in arr, and the value is the rank of that value
        //map is sorted by default, so we can iterate through the map to assign ranks to the unique values in arr
        vector<int> rankArr;
        for(int num : arr){
            valToRank[num] = 0; //initialize the map with the unique values in arr, the value will be updated to the rank later
        }
        int currRank = 1;
        for(auto& pair : valToRank) pair.second = currRank++;
        for(int num : arr) rankArr.push_back(valToRank[num]);
        return rankArr;
    }
};
// @lc code=end

