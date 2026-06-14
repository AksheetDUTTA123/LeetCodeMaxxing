#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=2130 lang=cpp
 *
 * [2130] Maximum Twin Sum of a Linked List
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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast){
            fast = fast -> next->next;
            slow = slow -> next;
        }

        //now we have to reverse the linked list
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while(curr){
            ListNode* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        ListNode * left = head;
        ListNode * mid = prev;
        int maxSum = -1;
        while(mid){
            maxSum = max(maxSum, left->val + mid->val);
            left = left -> next;
            mid = mid -> next;
        }
        return maxSum;
    }
};
// @lc code=end

