#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head-> next) return head;

        ListNode * dummy = new ListNode(0, head);
        ListNode* first = dummy;
        ListNode* second = head;
        while(second){
        if(( second->next &&  second->val == second -> next -> val)){
while(second->next && second->val == second -> next -> val){
            second = second -> next;
        }
            first ->next = second -> next;
        } 
        else{
            first = first -> next;

        }  
        second = second -> next;

        }
        return dummy -> next;    
    }
};
// @lc code=end

