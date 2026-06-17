#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
    ListNode* oddEvenList(ListNode* head) {
       
       if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* temp = head->next;
        ListNode* startSecond = temp;
        ListNode* curr = head;
        while(curr->next &&  temp->next){ //as long as there is an even node and there is a node after the even node, we can keep linking the odd nodes together and the even nodes together, 
        //because if there is no even node or there is no node after the even node, then we have reached the end of the list and we can stop linking the odd and even nodes together
            //evens counted as another linked list and then merge head of even to end of odd
            // curr -> next = temp->next; //odds next node is linked to evens next node(number after even is odd)
            // curr = curr -> next; //move pointer up

            // //have to do odds first, then even


            // temp->next = curr->next; //evens next node is linked to odds next node(number after odd is even)
            // temp = temp -> next; //move pointer up
            curr->next = curr->next->next;
            temp->next = temp->next->next;
            curr = curr->next;
            temp = temp->next;    
        }
        curr->next = startSecond; //we saved the head of the even node, link the end of the odd node to the head of the even node
        return head;
    }
};
// @lc code=end

