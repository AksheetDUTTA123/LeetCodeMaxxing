#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode * dummy = new ListNode(0);
        dummy -> next = head;
        ListNode * pre = dummy;
        for(int i = 0; i < left - 1; i++){
            pre = pre -> next;
        }
        ListNode * start = pre -> next;
        ListNode * tail = start;
        for(int i = 0; i < (right - left); i++){
            tail = tail -> next;
        }
        ListNode * after = tail -> next; //after is the node after the tail, we want to reverse from start to tail, and then connect pre to tail and start to after

        ListNode * curr = start;
        ListNode * prev = nullptr;
        ListNode * next = nullptr;
        //now we got to reverse the linked list

        while(curr != after){
            next = curr-> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        //now have to set pre and after next ptr

        pre-> next = prev; //pre is the node before the start, so we want to connect it to the tail, which is now the head of the reversed linked list. at this point, prev is the tail, and curr is the node after the tail.
        //prev is at the end of the reversed linked list. Prev will move up near the beginning of the linked list, and we connect it with pre, which is the node before the start.
        start -> next = after; //start is the node at the beginning before the reverse, so after the reverse, this is the end. We then have to connect it to the node after the tail, which is after
        return dummy -> next;
    }
};
// @lc code=end

