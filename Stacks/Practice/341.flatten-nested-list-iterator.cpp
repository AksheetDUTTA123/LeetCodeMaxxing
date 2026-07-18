#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=341 lang=cpp
 *
 * [341] Flatten Nested List Iterator
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    vector<int> res;
    int idx = 0;
    void recursive(vector<NestedInteger> &nestedList){
    for(auto& element : nestedList){
        if(element.isInteger()){
            res.push_back(element.getInteger());
        } 
        else{
            recursive(element.getList());
        }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        recursive(nestedList);
    }
    int next() {
        return res[idx++];
    }
    
    bool hasNext() {
        if (idx >= res.size()) return false;
        return true;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end

