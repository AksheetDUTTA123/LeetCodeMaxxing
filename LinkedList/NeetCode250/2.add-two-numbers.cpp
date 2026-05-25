#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //start by making a new linked list
        ListNode* newLL = new ListNode(0); //this is now to create a new linked list, make a new node and this is the start
        ListNode * curr = newLL;
        int carry = 0;

        while((l1 || l2) || carry != 0){ //if carry not 0 and l1 and l2 done, need to make a new node and add the carry over
            int val1 = 0;
            int val2 = 0;
            if(l1 != nullptr){ //have to check if nullptr, if not then use val
                val1 = l1->val;
            }
            else{
                val1 = 0; //it is possible that list alr ended, so just set val1 as 0 so l2 numbers can be added
            }
            if(l2 != nullptr){
                val2 = l2->val;
            }
            else{
                val2 = 0;
            }
            curr -> next = new ListNode((val1+ val2 + carry) % 10); // 9 + 9 = 18, node will have 8 and carry will be 1
            carry = (val1+ val2 + carry) / 10; 
            curr = curr -> next; //move to next node of answer linked list
            if(l1) l1 = l1->next;  //advnace linked list if not nullptr
            if(l2) l2 = l2->next; //advnace linked list if not nullptr
        }
        return newLL->next; //return the linked list 
    }
};
// @lc code=end

