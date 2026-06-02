#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3633 lang=cpp
 *
 * [3633] Earliest Finish Time for Land and Water Rides I
 */

// @lc code=start
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int earliestFinishTime = 1E9;
        for (int i = 0; i < landStartTime.size(); i++){
            for (int j = 0; j < waterStartTime.size(); j++){
            int finishLand = landStartTime[i] + landDuration[i]; //when land for that ride is done
            int startWater = max(finishLand, waterStartTime[j]); //can start when water ride is allowed to start, or wenever land is done, whichever comes last
            int finishWater = startWater + waterDuration[j]; //add duration to see when water ride is done
            
            int finishWater_first = waterStartTime[j] + waterDuration[j];
            int startLand = max(finishWater_first, landStartTime[i]);
            int finishLand_first = startLand + landDuration[i];

            earliestFinishTime = min(earliestFinishTime, min(finishWater, finishLand_first));
        }
        }
        return earliestFinishTime;
            
        }
};
// @lc code=end

