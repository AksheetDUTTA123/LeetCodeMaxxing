#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<vector<int>> adj(numCourses);
        vector<int> degree(numCourses, 0);
        int ctr = 0;
        queue<int> q;
        for(auto pair : prerequisites){
            adj[pair[1]].push_back(pair[0]);
            degree[pair[0]]++;
        }
        for(int i = 0; i < numCourses; i++){
            if(degree[i] == 0) q.push(i);
        }

        while (!q.empty()){
            auto front = q.front();
            q.pop();
            res.push_back(front);
            ctr++;
            for(int neighbor : adj[front]){
                degree[neighbor]--;
                if(degree[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }
        vector<int> empty;
        if(ctr != numCourses){
            return empty;
        }
        else{
            return res;
        }
    }
};
// @lc code=end

