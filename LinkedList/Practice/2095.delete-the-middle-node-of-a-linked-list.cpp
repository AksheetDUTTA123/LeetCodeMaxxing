#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=2095 lang=cpp
 *
 * [2095] Delete the Middle Node of a Linked List
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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head -> next == nullptr){
            return nullptr;
        }
        ListNode * slow = head;
        ListNode * fast = head -> next->next; //need to give fast a head start of 2 nodes, because we want slow to be at the node before the middle node when fast reaches the end of the list, 
        //this way we can easily delete the middle node by updating the next pointer of the slow node to skip the middle node and point to the node after the middle node, if we give fast a head start of 1 node, 
        //then slow will be at the middle node when fast reaches the end of the list, and we won't be able to easily delete the middle node because we won't have a reference to the node before the middle node, so we need to give fast a head start of 2 nodes, this way slow will be at the node before the middle node when fast reaches the end of the list, and we can easily delete the middle node by updating the next pointer of the slow node to skip the middle node
        // and point to the node after the middle node
        while (fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        slow -> next = slow -> next -> next; //this deletes the node after the slow node, 
        //which is the middle node, because when fast reaches the end of the list, slow will be at the node before the middle node, so we can easily delete the middle node 
        //by updating the next pointer of the slow node to skip the middle node and point to the node after the middle node
        return head;
    }
};
// @lc code=end

