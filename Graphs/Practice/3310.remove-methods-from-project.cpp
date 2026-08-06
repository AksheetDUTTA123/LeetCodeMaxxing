#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3310 lang=cpp
 *
 * [3310] Remove Methods From Project
 */

// @lc code=start
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto invocation : invocations){
            adj[invocation[0]].push_back(invocation[1]);
        }
        stack<int> s;
        unordered_set<int> corrupt;
        s.push(k);
        corrupt.insert(k);
        while(!s.empty()){
            int top = s.top();
            s.pop();

            for(int nodes : adj[top]){
                if(corrupt.find(nodes) == corrupt.end()){
                    corrupt.insert(nodes);
                    s.push(nodes);
                }
            }
        }
        vector<int> res;
        for(auto invocation : invocations){
            if(corrupt.find(invocation[0]) == corrupt.end() && corrupt.find(invocation[1]) != corrupt.end()){
                for(int i = 0; i < n; i++){
                    res.push_back(i);
                }
                return res;
            }
        }

        for(int i = 0; i < n; i++){
            if(corrupt.find(i) == corrupt.end()) res.push_back(i);
        }
        return res;
    }
};
// @lc code=end

