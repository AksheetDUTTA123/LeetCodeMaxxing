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
        if (parent[i] == i) return i;
        else return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j){
        int findI = find(i);
        int findJ = find(j);

        if(findI == findJ) return false;

        if(rank[findI] > rank[findJ]){
            parent[findJ] = findI;
        }
        else if(rank[findI] < rank[findJ]){
            parent[findI] = findJ;
        }
        else{
            parent[findJ] = findI;
            rank[findI]++;
        }
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind uf(edges.size() + 1);
        vector<int> res;
        for(auto edge : edges){
            if(!uf.unite(edge[0], edge[1])) return edge;
        }
        return res;
    }
};
// @lc code=end

