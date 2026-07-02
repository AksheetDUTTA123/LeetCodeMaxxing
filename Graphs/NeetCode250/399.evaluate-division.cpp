#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

// @lc code=start
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph; //this will store the graph of equations, 
        //where the key is the variable, and the value is a vector of pairs, where each pair is a variable and the value of the equation
        for(int i = 0; i < equations.size(); i++){
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            graph[u].push_back({v, val});
            graph[v].push_back({u, 1.0/val}); //this is the inverse of the equation, because if u / v = val, then v / u = 1/val
        }

        vector<double> res;
        for(auto query : queries){
        queue<pair<string, double>> q;
        unordered_set<string> visited;
            string start = query[0];
            string end = query[1];
            if(graph.find(start) == graph.end() || graph.find(end) == graph.end()){  //if either the start or end variable is not in the graph, then we cannot evaluate the equation, so we return -1.0
                res.push_back(-1.0);
                continue;
            }
            if(start == end){  //if the start and end variable are the same, then we can evaluate the equation, so we return 1.0
                res.push_back(1.0);
                continue;
            }

            q.push({start, 1.0}); //this is the starting point of the BFS, where we start with the start variable and a value of 1.0, because we are evaluating the equation start / start = 1.0
            visited.insert(start);
            bool found = false;
            while(!q.empty()){
                auto top = q.front();
                q.pop();

                if(top.first == end){
                    res.push_back(top.second);
                    found = true;
                    break;
                }

                for(auto num : graph[top.first]){
                    string newNode = num.first;
                    double nextWeight = num.second;

                    if(visited.find(newNode) == visited.end()){
                        visited.insert(newNode);
                        q.push({newNode, top.second * nextWeight});
                    }
                }
            }

            if(!found){
                res.push_back(-1.0);
            }

        }

        return res;
    }
};
// @lc code=end

