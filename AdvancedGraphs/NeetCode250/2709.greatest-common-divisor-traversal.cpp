#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=2709 lang=cpp
 *
 * [2709] Greatest Common Divisor Traversal
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
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int i){
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    bool unite(int i, int j){
        int rootI = find(i);
        int rootJ = find(j);

        if(rootI == rootJ) return false;
        if(rank[rootI] < rank[rootJ]){
            parent[rootI] = rootJ;
        }
        else if(rank[rootI] > rank[rootJ]){
            parent[rootJ] = rootI;
        }
        else{
            parent[rootJ] = rootI;
            rank[rootI]++; //we increment the rank of the root of the tree that we are merging into, because it is now the root of a larger tree
        }
    return true;
    }
};
class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        UnionFind dsu(nums.size());
        unordered_map<int, int> primeToIndex;
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i]; //we will find the prime factors of num, and for each prime factor, we will check if
            // it has been seen before. If it has, we will unite the current index with the index of the previous occurrence of that prime factor. This way, all numbers that share a common prime factor will be in the same connected component.
            for(int j = 2; j * j <= num; j++){ //the reasonn we square j is because we only need to check for factors up to the square root of num,
            // because if num has a factor larger than its square root, it must also have a factor smaller than its square root. This way, we can find all prime factors of num efficiently.
                if(num % j == 0){
                    if(primeToIndex.count(j)){
                        dsu.unite(i, primeToIndex[j]); //if prime is already in the map, we unite the current index with the index of the previous occurrence of that prime factor
                    }
                    primeToIndex[j] = i;
                    while(num % j == 0) num /= j; //we divide num by j until it is no longer divisible by j, so that we only consider each prime factor once. This is important because we only want to unite the current index with the index of the first occurrence of each prime factor, not with every occurrence of that prime factor.
                }
            }
            if(num > 1){ //if num is still greater than 1, then it is a prime factor itself, and we need to check if it has been seen before
                if(primeToIndex.count(num)){
                    dsu.unite(i, primeToIndex[num]);
                }
                primeToIndex[num] = i;
            }
        }

        int root = dsu.find(0); //we find the root of the first index, and we will check if all other indices have the same root. If they do, then all numbers are connected through their prime factors, and we can traverse all pairs.
        for(int i = 1; i < nums.size(); i++){
            if(dsu.find(i) != root) return false;
        }
        return true;
    }
};
// @lc code=end

