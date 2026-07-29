#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=835 lang=cpp
 *
 * [835] Image Overlap
 */

// @lc code=start
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int, int>> img1Pts;
        vector<pair<int, int>> img2Pts;
        for(int i = 0; i < img1.size(); i++){
            for(int j = 0; j < img1[0].size(); j++){
                if(img1[i][j] == 1) img1Pts.push_back({i, j});
                if(img2[i][j] == 1) img2Pts.push_back({i, j});
            }
        }
        unordered_map<string, int> slopeCts;
        int max = 0;
        for(auto pair1 : img1Pts){
            for(auto pair2 : img2Pts){
               int dr = pair2.first - pair1.first;
                int dc = pair2.second - pair1.second;
                string hash = to_string(dr) + "->" + to_string(dc);
                slopeCts[hash]++;
                if(slopeCts[hash] > max){
                    max = slopeCts[hash];
                }
            }
        }
        return max;
    }
};
// @lc code=end

