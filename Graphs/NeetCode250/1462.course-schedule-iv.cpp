#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1462 lang=cpp
 *
 * [1462] Course Schedule IV
 */

// @lc code=start
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // vector<bool> res;
        // vector<vector<bool>> isPrereq(numCourses, vector<bool>(numCourses, false));
        // vector<vector<int>> adj(numCourses);
        // vector<int> degree(numCourses, 0);
        // queue<int> q;
        // for(auto prereq: prerequisites){
        //     isPrereq[prereq[0]][prereq[1]] = true;
        //     degree[prereq[1]]++;
        //     adj[prereq[0]].push_back(prereq[1]);
        // }
        // for(int i = 0; i < numCourses; i++){
        //     if(degree[i] == 0) q.push(i);
        // }

        // while(!q.empty()){
        //     auto front = q.front();
        //     q.pop();
        //     for(int neighbor : adj[front]){
        //         degree[neighbor]--;
        //         for(int i = 0; i < numCourses; i++){
        //             if(isPrereq[i][front]) isPrereq[i][neighbor] = true; //if i is a prerequisite of front, then i is also a prerequisite of neighbor
        //         }
        //         if(degree[neighbor] == 0){
        //             q.push(neighbor);
        //         }
        //     }
        // }

        // for(auto query : queries){
        //     if(isPrereq[query[0]][query[1]] == true){
        //         res.push_back(true);
        //     }
        //     else{
        //         res.push_back(false);
        //     }
        // }
        // return res;


        vector<vector<bool>> isPrereq(numCourses, vector<bool>(numCourses, false));
        for (auto preq : prerequisites){
            isPrereq[preq[0]][preq[1]] = true;
        }

        //this is the floyd warshall

        for(int via = 0; via < numCourses; via++){
            for(int i = 0; i < numCourses; i++){
                for(int j = 0; j < numCourses; j++){
                    if(isPrereq[i][via] && isPrereq[via][j]) isPrereq[i][j] = true;
                }
            }
        }
            vector<bool> res;
            for(auto query : queries){
            if(isPrereq[query[0]][query[1]] == true){
                res.push_back(true);
            }
            else{
                res.push_back(false);
            }
        }
        return res;

    }
};
// @lc code=end

