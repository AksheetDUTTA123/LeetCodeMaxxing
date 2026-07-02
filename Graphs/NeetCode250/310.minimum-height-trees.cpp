#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */

// @lc code=start
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<vector<int>> adj(n); //adjacency list, need it to find the neighbors of each node
        vector<int> degree(n, 0); //degree counts for each node, need it for the topological sort, 
        //because we will be removing the leaves of the tree, and we need to know when a node becomes a leaf
        queue<int> q;

        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        for(int i = 0; i < degree.size() ; i++){
            if(degree[i] == 1){
                q.push(i); //we only push the leaves of the tree into the queue, 
                //because we will be removing them in the topological sort, if degree of a ndoe is 1, it is a leaf,
                // and we will be removing it in the topological sort
            }
        }

        int remainingNodes = n;
        while(remainingNodes > 2){
            int currCt = q.size();
            remainingNodes -= currCt;
            for(int i = 0; i < currCt; i++){
                auto top = q.front();
                q.pop();

                for(auto neighbor : adj[top]){
                    degree[neighbor]--; //remove the node, so we have to update the degree of its neighbors,
                    // because we are removing the node from the tree, so its neighbors will have one less edge

                    if(degree[neighbor] == 1) q.push(neighbor); //becomes a new leaf so this will be added to the queue
                }
            }
        }

        vector<int> res;
        while(!q.empty()){ //the stuff in the queue is the remaining nodes, 
        //which are the roots of the minimum height trees
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
// @lc code=end

