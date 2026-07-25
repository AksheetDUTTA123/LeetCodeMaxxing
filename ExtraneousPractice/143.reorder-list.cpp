#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    void reorderList(ListNode* head) {
        ListNode* curr = head;
        ListNode* secondptr = head;
        while(secondptr && secondptr -> next){
            curr = curr -> next;
            secondptr = secondptr -> next -> next;
        }

        //curr is now at the midpoint

        //we will now have to reverse this part of the linkedlist

        ListNode* prev = nullptr;
        ListNode* currentNode = curr;

        while(currentNode){
            ListNode* next = currentNode -> next;
            currentNode -> next = prev;
            prev = currentNode;
            currentNode = next;
        }

        //ok now we reversed the second half, now we make the list

        ListNode* first = head;
        ListNode* second = prev;
        while(second -> next){
            ListNode* tmp1 = first -> next;
            ListNode* tmp2 = second -> next;
            first -> next = second;
            second -> next = tmp1; //second -> next = first -> next
            first = tmp1;
            second = tmp2;
        }        
    }
};
// @lc code=end

