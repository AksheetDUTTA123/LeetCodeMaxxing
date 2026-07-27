#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=261 lang=cpp
 *
 * [261] Graph Valid Tree
 */

// @lc code=start
class UnionFind{
    private:
    vector<int> parent;
    vector<int> rank;
    public:

    UnionFind(int n){
        rank.resize(n, 0);
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int i){
        if (parent[i] == i) return i;
        else return parent[i] = find(parent[i]);
    }

    bool unite(int i, int j){
        int parentI = find(i);
        int parentJ = find(j);

        if(parentI == parentJ) return false;


        if(rank[parentI] > rank[parentJ]){
            parent[parentJ] = parentI;
        }
        else if(rank[parentI] < rank[parentJ]){
            parent[parentI] = parentJ;
        }
        else{
            parent[parentJ] = parentI;
            rank[parentJ]++;
     
        }

        return true;
    }
};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) return false;
        UnionFind uf(n);
        for(auto edge : edges){
            if(!uf.unite(edge[0], edge[1])) return false;
        }
    return true;
    }
};
// @lc code=end

