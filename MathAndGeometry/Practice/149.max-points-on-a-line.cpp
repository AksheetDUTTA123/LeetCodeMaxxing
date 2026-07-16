#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */

// @lc code=start
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        //we will go through each point and treat it like an anchor
        int maxPts = 0;
        for(int i = 0; i < points.size(); i++){
            unordered_map<string, int> slopeCheck;

            for(int j = 0; j < points.size(); j++){
                if (i == j)  continue;
                int deltaY = points[j][1] - points[i][1];
                int deltaX = points[j][0] - points[i][0];
                if(deltaX < 0){
                    deltaX = -deltaX;
                    deltaY = -deltaY;
                }
                string slopeStr = to_string(deltaY / gcd(abs(deltaY), abs(deltaX))) + '_' + to_string(deltaX / gcd(abs(deltaY), abs(deltaX)));
                slopeCheck[slopeStr]++;
                if (slopeCheck[slopeStr] > maxPts) maxPts = slopeCheck[slopeStr];
            }
        }
        return maxPts + 1; //need to add by 1 to account for the anchor point itself, because we are only counting the points that are on the same line as the anchor point, but we need to include the anchor point itself in the count
    }
};
// @lc code=end

