#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=2336 lang=cpp
 *
 * [2336] Smallest Number in Infinite Set
 */

// @lc code=start
class SmallestInfiniteSet {
private:
    int currVal = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    //in the pq, we will only store elements that were popped and now we add it back
    unordered_set<int> duplicates;
public:
    SmallestInfiniteSet() {
        currVal = 1;
    }
    
    int popSmallest() {
        if(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            duplicates.erase(top);
            return top;
        }
        return currVal++;
    }
    
    void addBack(int num) {
        if(num < currVal && duplicates.find(num) == duplicates.end()){ //check that it is not in duplicates already before adding it
            pq.push(num);
            duplicates.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
// @lc code=end

