#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int length = 0;
        ListNode * curr = head;
        while(curr && length < k){
            curr = curr -> next;
            length++;
        }
        if(length < k){
            return head;
        }
        ListNode * prev = nullptr;
        ListNode * next = nullptr;
        curr = head;
        while(length > 0){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            length--;
        }
        head -> next = reverseKGroup(curr, k);
        head = prev;
        return head;
    }
};
// @lc code=end

