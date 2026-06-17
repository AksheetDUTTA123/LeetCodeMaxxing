#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

// @lc code=start
class KthLargest {
private:
    int limit;
    std::priority_queue<int, vector<int>, greater<int>> pq; //this is the key optimization, instead of storing a maxHeap that stores every element
    //store a minHeap of size k, and the smallest element in the pq is the kth largest element
public:
    KthLargest(int k, vector<int>& nums) {
            limit = k;
            for(int i = 0; i < nums.size(); i++){
                pq.push(nums[i]);

                if(pq.size() > limit){
                    pq.pop();
                }
            };
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > limit){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

