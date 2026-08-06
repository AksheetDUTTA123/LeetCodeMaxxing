#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3160 lang=cpp
 *
 * [3160] Find the Number of Distinct Colors Among the Balls
 */

// @lc code=start
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballColor;
        unordered_map<int, int> coloredBalls;
        vector<int> res;
        int currCt = 0;
        for(auto query : queries){
            if(coloredBalls.find(query[0]) == coloredBalls.end() && ballColor.find(query[1]) == ballColor.end()){
                coloredBalls[query[0]] = query[1];
                ballColor[query[1]]++;
                currCt++;
                res.push_back(currCt);
            }
            else if(coloredBalls.find(query[0]) != coloredBalls.end() && ballColor.find(query[1]) == ballColor.end()){
                ballColor[coloredBalls[query[0]]]--;
                if(ballColor[coloredBalls[query[0]]] == 0){
                    currCt--;
                    ballColor.erase(coloredBalls[query[0]]);
                }
                ballColor[query[1]]++;
                currCt++;
                coloredBalls[query[0]] = query[1];
                res.push_back(currCt);
            }
            else if(coloredBalls.find(query[0]) == coloredBalls.end() && ballColor.find(query[1]) != ballColor.end()){
                ballColor[query[1]]++;
                coloredBalls[query[0]] = query[1];
                res.push_back(currCt);
            }   
            else{
                ballColor[coloredBalls[query[0]]]--;
                if(ballColor[coloredBalls[query[0]]] == 0){
                    currCt--;
                    ballColor.erase(coloredBalls[query[0]]);
                }
                ballColor[query[1]]++;
                if(ballColor[query[1]] == 1) currCt++;
                coloredBalls[query[0]] = query[1];
                res.push_back(currCt);
            }
        }
        return res;
    }
};
// @lc code=end

