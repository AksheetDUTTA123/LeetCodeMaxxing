#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
        if(!head) return nullptr;
        if(!head-> next) return head;
        ListNode* curr = head;
        ListNode* nextNode = head -> next;
        while(nextNode){ //always need to check if nextNode is not null, otherwise we will get a segmentation fault when we try to access nextNode->val
            while(nextNode && curr->val == nextNode-> val){
                nextNode = nextNode -> next;
            }
            curr -> next = nextNode;
            curr = nextNode;
            if(nextNode) nextNode = nextNode -> next;
        }
        return head;
    }
};
// @lc code=end

