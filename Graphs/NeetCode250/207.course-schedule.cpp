#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); //need an adjency list here, kind of like a map
        vector<int> degree(numCourses, 0);
        int ctr = 0;
        queue<int> q;
        for(auto pair : prerequisites){
            adj[pair[1]].push_back(pair[0]); //map prereq -> [list of courses that can be taken after]
            degree[pair[0]]++; //course 0 depends on an additional course, need to keep track of how many courses course 0 needs
        }

        for(int i = 0; i < numCourses; i++){
            if(degree[i] == 0) q.push(i);
        }

        while (!q.empty()){
            auto front = q.front();
            q.pop();
            ctr++;
        for(int neighbor : adj[front]){
            degree[neighbor]--;
            if(degree[neighbor] == 0){
                q.push(neighbor);
            }
        }
        }

        return (ctr == numCourses);
    }


};
// @lc code=end

