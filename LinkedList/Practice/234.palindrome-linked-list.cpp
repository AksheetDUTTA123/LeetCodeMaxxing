#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {
        ListNode* first = head;
        ListNode* second = head;
        while(second && second->next){
            first = first -> next;
            second = second -> next -> next;
        }
        //this gets us to the middle, now have to reverse linked list from first to end
        ListNode * curr = first;
        ListNode * prev = nullptr;
        ListNode * next = nullptr;

        while(curr){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        ListNode* left = head;
        ListNode* right = prev;
        while(right){
            if(left->val != right-> val) return false;
            left = left -> next;
            right = right ->next;
        }
        return true;

    }
};
// @lc code=end

