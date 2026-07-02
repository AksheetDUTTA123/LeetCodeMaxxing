#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

// @lc code=start
class UnionFind{
    private:
        vector<int> parent;
        vector<int> rank;

    public:
        UnionFind(int n){
            parent.resize(n);
            rank.resize(n, 0);
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int i){
            if(parent[i] == i) return i;
            return parent[i] = find(parent[i]);
        }

        bool unite(int i, int j){
            int rootI = find(i);
            int rootJ = find(j);

            if(rootI == rootJ) return false;//alr same component

            if(rank[rootI] < rank[rootJ]){
                parent[rootI] = rootJ;
            }
            else if(rank[rootJ] < rank[rootI]){
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind dsu(edges.size() + 1);
        vector<int> res;
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            if(!dsu.unite(u,v)){
                return edge;
            }
        }
        return res;
    }
};
// @lc code=end

