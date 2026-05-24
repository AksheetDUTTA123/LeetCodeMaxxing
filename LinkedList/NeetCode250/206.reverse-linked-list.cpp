#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    ListNode* reverseList(ListNode* head) {
       if(!head || !head->next){
        return head;
       }
       ListNode* curr = head;
       ListNode* next = nullptr;
       ListNode* prev = nullptr;

       while(curr){
        next = curr->next; //have a pointer point to the node after current
        curr -> next = prev; //reverse the currents next, now it points to prev
        prev = curr; //move prev up to current
        curr = next; //move current up to the next one, keep going
       }
       head = prev;
       return head; //this is the new head
    }
};
// @lc code=end

