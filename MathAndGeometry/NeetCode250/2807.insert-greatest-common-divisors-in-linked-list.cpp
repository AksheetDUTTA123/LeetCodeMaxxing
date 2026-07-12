#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=2807 lang=cpp
 *
 * [2807] Insert Greatest Common Divisors in Linked List
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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* front = head;
        if(!head->next) return head;

        while(head -> next){
        int node1 = head -> val;
        int node2 = head -> next -> val;
        int nodeGCD = gcd(node1, node2);
        ListNode* newNode = new ListNode(nodeGCD);
        newNode->next = head -> next;
        head -> next = newNode;
        head = head -> next -> next;
        }

        return front;
    }
};
// @lc code=end

