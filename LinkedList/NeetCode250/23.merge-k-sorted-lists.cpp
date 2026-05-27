#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct compare{
    bool operator()(ListNode* a, ListNode* b){
        return a -> val > b -> val; //min heap
    }
};
    priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
    for(ListNode * list : lists){
        if(list != nullptr){
            minHeap.push(list); //we only want to add the head of each list to the heap, since we will be adding the next nodes as we pop from the heap
        }
    }
    ListNode * dummyHead = new ListNode(-1);
    ListNode * tail = dummyHead;
    while(!minHeap.empty()){
        ListNode * minNode = minHeap.top();
        minHeap.pop();
        tail->next = minNode;
        tail = tail-> next;
        if(minNode->next != nullptr){
            minHeap.push(minNode->next); //if the minNode has a next node, we need to add it to the heap for consideration in the next iteration
        }
    }
    return dummyHead->next;
    }

};
// @lc code=end

