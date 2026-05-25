#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * first = head;
        ListNode * second = head;
        for(int i = 0; i < n; i++){
            second = second -> next;
        }
        //this moves second to n past first ptr
        if(second == nullptr){ //if nullptr, we need to remove the head 
            return head -> next;
        }
        while(second->next != nullptr){
            second = second -> next; //moving both pointers together until we reach the end
            first = first -> next;
        }
        first-> next = first -> next -> next; //this is how to delete the node, next gets mapped to the one after the deleted node
        return head;

    }
};
// @lc code=end

