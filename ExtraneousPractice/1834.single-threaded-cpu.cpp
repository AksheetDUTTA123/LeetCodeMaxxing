#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1834 lang=cpp
 *
 * [1834] Single-Threaded CPU
 */

// @lc code=start
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> res;
        long long  currTime = 1;
        int idx = 0;
        for(int i = 0; i < tasks.size(); i++){
            tasks[i].push_back(idx);
            idx++;
        }
        sort(tasks.begin(), tasks.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int taskIdx = 0;

        while(taskIdx < tasks.size() || !pq.empty()){
            if(taskIdx < tasks.size() && currTime < tasks[taskIdx][0] && pq.empty()){ //cpu is idle, jump to the right time
                currTime = tasks[taskIdx][0];
            }

            while(taskIdx < tasks.size() && currTime >= tasks[taskIdx][0]){
                pq.push({tasks[taskIdx][1], tasks[taskIdx][2]});
                taskIdx++;
            }

            auto [currProcessingTime, curridx] = pq.top();
            pq.pop();

            currTime += currProcessingTime;
            res.push_back(curridx);
        }
     return res;
    }
};
// @lc code=end

