#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class UnionFind{
    private:
        vector<int> parent;
        vector<int> rank;
    public:
        UnionFind(int n){
            parent.resize(n);
            rank.resize(n);
            iota(parent.begin(), parent.end(), 0);
        }

        int find (int i){
            if(parent[i] == i) return i;
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
                parent[findI] = findJ;
                rank[findJ]++;
            }
            return true;
        }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        UnionFind uf(isConnected.size());
        int numProvinces = isConnected.size();
        for(int i = 0; i < isConnected.size(); i++){
            for(int j = 0; j < isConnected[0].size(); j++){
               if(isConnected[i][j]){
                 if(uf.unite(i, j)) numProvinces--;  
               }
            }
        }
        return numProvinces;
    }
};
// @lc code=end

