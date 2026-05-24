#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next){
            return false;
        }

        ListNode* slowPtr = head; //both start at the beginning
        ListNode* fastPtr = head;

        while(fastPtr && fastPtr->next){ //while fastPtr has something after it and is valid, not a nullptr
            slowPtr = slowPtr -> next; //slow moves one at a time
            fastPtr = fastPtr -> next -> next; //fast moves two at a time
            if(slowPtr == fastPtr){
                return true; //if slow and fast ever become equal, that means pastPtr must have entered a cycle to loop back to where slowPtr is
            }
        }
        return false;

    }
};
// @lc code=end

