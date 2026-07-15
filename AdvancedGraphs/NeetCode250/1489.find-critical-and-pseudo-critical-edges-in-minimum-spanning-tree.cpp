#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1489 lang=cpp
 *
 * [1489] Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree
 */

// @lc code=start
class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(int n){
        parent.resize(n);
        rank.resize(n, 0);
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int i){
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    bool unite(int i, int j){
        int rootI = find(i);
        int rootJ = find(j);

        if(rootI == rootJ) return false; //alr in same component


        if(rank[rootI] < rank[rootJ]){
            parent[rootI] = rootJ;
        }
        else if (rank[rootI] > rank[rootJ]){
            parent[rootJ] = rootI;
        }
        else{
            parent[rootJ] = rootI;
            rank[rootI]++;
        }
        return true;
    }
};
class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> newEdges = edges;
        for(int i = 0; i < edges.size(); i++){
            newEdges[i].push_back(i); //add the index of the edge to the edge list, so we can keep track of which edge is which
        }

        sort(newEdges.begin(), newEdges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2]; //sort the edges by weight, so we can use Kruskal's algorithm to find the MST. Sorted from smallest to largest weight
        });


        UnionFind uf(n);
        int mstWeight = 0;
        int stdEdges = 0;
        for(int i = 0; i < edges.size(); i++){
            if(uf.unite(newEdges[i][0], newEdges[i][1])){
                mstWeight += newEdges[i][2];
                stdEdges++;
            }
        }

        vector<vector<int>> res(2);
        //in res, we store the critical edges in res[0] and the pseudo-critical edges in res[1]

        //first, lets find the critical edges, which are the edges that if removed, will increase the weight of the MST

        for(int i = 0; i < newEdges.size(); i++){
            UnionFind uf2(n);
            int ignoreWeight = 0;
            int ignoreEdgesCt = 0;
            for(int j = 0; j < newEdges.size(); j++){
                if(newEdges[j][3] == newEdges[i][3]) continue;
                if(uf2.unite(newEdges[j][0], newEdges[j][1])){
                    ignoreWeight += newEdges[j][2];
                    ignoreEdgesCt++;
                }
            }

            if(ignoreEdgesCt < n - 1 || ignoreWeight > mstWeight){ //
                res[0].push_back(newEdges[i][3]); //if the number of edges in the MST is less than n - 1, or the weight of the MST is greater than the original MST weight, then this edge is critical
            }
            else{
                //now we gotta check if the edge is pseudo-critical, which means that if we include this edge in the MST, the weight of the MST will be the same as the original MST weight
                UnionFind uf3(n);
                int forceWeight = 0;
                int forceEdges = 0;
                uf3.unite(newEdges[i][0], newEdges[i][1]);
                forceWeight += newEdges[i][2];
                forceEdges++;
                for(int j = 0; j < newEdges.size(); j++){
                if(newEdges[j][3] == newEdges[i][3]) continue;
                if(uf3.unite(newEdges[j][0], newEdges[j][1])){
                    forceWeight += newEdges[j][2];
                    forceEdges++;
                }
            }

            if(forceEdges == n - 1 && forceWeight == mstWeight) res[1].push_back(newEdges[i][3]); //if the number of edges in the MST is equal to n - 1, and the weight of the MST is equal to the original MST weight, then this edge is pseudo-critical
            }
        }

        return res;
    }
};
// @lc code=end

