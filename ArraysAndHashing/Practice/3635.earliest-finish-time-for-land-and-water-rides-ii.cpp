#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3635 lang=cpp
 *
 * [3635] Earliest Finish Time for Land and Water Rides II
 */

// @lc code=start
class Solution {
    private:
    int solve(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration){
        int finish1 = INT_MAX;
        int finish2 = INT_MAX;
        for(int i = 0; i < landStartTime.size(); i++){
            finish1 = min(finish1, landDuration[i] + landStartTime[i]);
        }

        for(int i = 0; i < waterStartTime.size(); i++){
            finish2 = min(finish2, waterDuration[i] + max(finish1 , waterStartTime[i]));
        }
        return finish2;
    }
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
            int land_water =
            solve(landStartTime, landDuration, waterStartTime, waterDuration);
        int water_land =
            solve(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(land_water, water_land);
    }
};
// @lc code=end

