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
      //key insight for this question 
      //find the midpoint of the linked list, use slow/fast ptrs for this
      //then, you need to reverse the second half of the linked list
      //then merge the two lists together.
      //lot of pointers  
      ListNode* slow = head;
      ListNode* fast = head;
      
      

      while (fast && fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
      }

      //now need to reverse everything from slow to the end
      ListNode* next = nullptr;
      ListNode* prev = nullptr;
      ListNode * second = slow -> next; //this is the start of the second half of the linked list, we want to reverse this part
    slow -> next = nullptr; //this is to break the linked list into two halves, now we have two separate linked lists, one from head to slow and one from second to the end
      while(second){
        next = second -> next; //standard reverse linked list steps
        second -> next = prev;
        prev = second;
        second = next;
      }
      ListNode* left = head; //this is the start of the first half of the linked list, we want to merge this with the reversed second half which starts at prev
      ListNode * right = prev; //this is the start of the reversed second half of the linked list, we want to merge this with the first half which starts at left 
      while(right){ //while right is not null, we need to merge the two linked lists together, if right is shorter than left, then we know we are done merging because we are merging in the order of left, right, left, right, so if right is shorter than left, then we know we have merged all of right into left and we are done
      ListNode* nextLeft = left -> next; 
      ListNode* nextRight = right -> next; 
        left -> next = right; //merge the two linked lists together, left points to right, then right points to left
        right -> next = nextLeft; //right points to the next node in the left linked list
        left = nextLeft;
        right = nextRight;
      }
    }
};
// @lc code=end

